# Porting an algorithm from C++ to Python

## Table of Contents
- [Why?](#why?)
- [How it works](#how-it-works)
- [Requirements](#Requirements)
  - [Setting up Python virtual environment](#setting-up-python-virtual-environment)
- [Adapting this to your C++ code](#adapting-this-to-your-c-code)
- [Examples](#Examples)
  - [Rounder](#Rounder)
  - [EmotiBitPacket](#EmotiBitPacket)
  - [Brainflow SpO2 Algorithm](#brainflow-spo2-algorithm)

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
### Setting up Python Virtual Environment
- Open a new command prompt window
- `cd` to `EmotiBit_Plugins/py_envs`
- Run the following command `python -m venv plugins`
  - This creates a new folder called `plugins` containing the virtual Python environment
- Activate the new environment:
  - Windows (cmd): `.\plugins\Scripts\activate.bat`
  - Windows (PowerShell): `.\plugins\Scripts\Activate.ps1`
  - macOS/Linux (bash/zsh): `source plugins/bin/activate`
- Run the following command to install pybind11. `pip install pybind11==2.13.5`

## Adapting this to your C++ code
- Add pybind11 bindings to a file `bindings_<srcName>.cpp`. Refer the [pybind11 documentation](https://pybind11.readthedocs.io/en/stable/basics.html) for more information.
- Create a new CMakeLists.txt file that
  - creates a lib from your source files
  - creates the pyd file from the src library
- Run the `cmake` commands from the examples below to create a build the project.  

Refer to the examples below to see what `bindings.cpp` and `CMakeLists.txt` should look like. 

## Examples
### Rounder 
- cd to `pyExample_alg01`
- run the following commands
```bash
cmake -B build
cmake --build build --config Release
```
- The following command runs the python example. The expected result is for the script to round the input.
```bash
python example.py -i 3.4
```

### EmotiBitPacket
- To make this example work, you will need to copy/clone the `EmotiBit_XPlat_Utils` repository into the `src` folder.
  - cd to the `src` folder.
  - clone using `git clone https://github.com/EmotiBit/EmotiBit_XPlat_Utils`. Checkout the following commit `393b611ee0d0c1f1cec70e243fd5b643c2e25250`
- cd to `pyExample_emotibitPacket` and run the following commands
```bash
cmake -B build
cmake --build build --config Release
```
- Run the Python example script `pyExample_emotibitPacket\example.py` 

### Brainflow SpO2 Algorithm
Refer to the EmotiBit Brainflow SpO2 Algorithm [repo](https://github.com/EmotiBit/EmotiBit_Brainflow_SpO2_Algorithm/tree/master/pybind) for detailed instructions on how to compile the algorithm using pybind.