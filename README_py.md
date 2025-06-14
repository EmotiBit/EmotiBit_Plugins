# Porting an algorithm from C++ to Python

## Table of Contents
- [Why?](#why?)
- [How it works](#how-it-works)
- [Requirements](#Requirements)
  - [Creating python-env with pybind11](#Creating-python-env-with-pybind11)
    - [Using venv (recommended)](#Using-venv)
    - [Using anaconda](#Using-anaconda)
- [Examples](#Examples)
  - [Rounder](#Rounder)
  - [EmotiBitPacket](#EmotiBitPacket)
- [Adapting this to your C++ code](#Adapting-this-to-your-C++-code)

## Why?
The goal of this project is to allow users to take an algorithm written in C++ and translate it into runnable Python code.
This could allow a user to develop C++ code and run it on the EmotiBit's firmware, software, and through Python, hitting three different metrics.

## How it works
- We use pybind11 to create bindings for existing c++ code to a dynamic python library. These bings get added to a bindings_\<srcFileName\>.cpp.
- These bindings essentially define the class/function prototypes, in the pybind11 format. An example of a binding would look like
```c++
PYBIND11_MODULE(EmotiBitPacket, m) {
	py::class_<EmotiBitPacket>(m, "EmotiBitPacket")
		.def(py::init<>());
	m.def("createHeader", &EmotiBitPacket::createHeader);
	m.def("headerToString", &EmotiBitPacket::headerToString);
	//m.def("createPacket", &EmotiBitPacket::createPacket); 
	py::class_<EmotiBitPacket::Header>(m, "Header")
		.def(py::init<>());
}
```
- The pybind11 python library (installed in the virtual environment) performs the mapping from c++ file to a `.pyd` file.
- The flow to go from .cpp to .pyd looks like
  - Create a CMakeLists that lists the pybind module and its dependency on the source file library.
  - Run cmake to create build files
  - Build the files created in the previous step to create the `.pyd` file

## Requirements
### Creating python-env with pybind11
#### Using venv
- Open a new command prompt window
- `cd` to the EmotiBit_Plugins repository
- Run the following command `python -m venv .\py_envs\<env-name>`
  - replace `<env-name>` with the environment name
- Activate the new environment by running the command `.\py_envs\<env-name>\Scripts\activate.bat`
  - You will see the prompt in the terminal change. It now shows the python environment in parenthesis.
- Run the following command to install bypind11. `pip install pybind11==2.13.5`

#### Using anaconda
- Download [Anaconda](https://www.anaconda.com/download/) as shown here.
- ***Do not close out of the Anaconda Powershell Prompt until completely done with an example***
- Open an Anaconda Powershell Prompt through the search feature on your machine and run the command below
```bash
cd C:\path\to\your\EmotiBit_Plugins\pyExample_alg01
conda config --set channel_priority flexible
conda env update --name EmotiBit-pyenv-modern --file .\EmotiBit-pyenv-modern.yml
conda activate EmotiBit-pyenv-modern
```

## Examples
### Rounder 
#### Steps to Run Example

- cd to `pyExample_alg01`
- run the following commands
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
- The following command runs the python example. The expected result is for the script to round the input.
```bash
python example.py -i 3.4
```

### EmotiBitPacket
#### Building the example
- To make this example work, you will need to copy/clone the `EmotiBit_XPlat_Utils` repository into the `src` folder.
  - cd to the `src` folder.
  - clone using `git clone https://github.com/EmotiBit/EmotiBit_XPlat_Utils`. Checkout the following commit `393b611ee0d0c1f1cec70e243fd5b643c2e25250`
- cd to `pyExample_emotibitPacket` and run the following commands
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
- Run the Python example script `pyExample_emotibitPacket\example.py` 

## Adapting this to your C++ code
- Add pybind11 bindings to a file `bindings_<srcName>.cpp`. Refer the [pybind11 documentation](https://pybind11.readthedocs.io/en/stable/basics.html) for more information.
- Create a new CMakeLists.txt file that
  - creates a lib from your source files
  - creates the pyd file from the src library
- Run the cmake commands above to create a build the project.

