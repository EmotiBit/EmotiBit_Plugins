# Porting an algorithm from C++ to Python

## Why?
The goal of this project is to allow users to take an algorithm written in C++ and translate that into runnable Python code.
This could allow a user to develop C++ code and run it on the EmotiBit's firmware, software, and through Python hitting three different metrics.

## How it works
- We use pybind11 to create bindings for existing c++ code to a dynamic python library. These bings get added to a bindings_<srcFileName>.cpp.
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
  - Build hte files created in the previous tep to create the `.pyd` file


## Creating python-env with pybind11
_These instructions have been tested on Windows_

### Creating an environment in python
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

# Example-Rounder 
## Steps to Run Example

- cd to `pyExample_alg01`
- run the following commands
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
- The following comman runs the python example. The expected result is for the script to round the input.
```bash
python3 example.py -i 3.4
```

# Adapting this to your C++ code
- Add pybind11 bindings to your C++ source. Refer the [pybind11 documentation](https://pybind11.readthedocs.io/en/stable/basics.html) for more information.
- Create a new CMakeLists.txt file that
  - includes your source files in SOURCES
  - provides path to the pybind11_DIR
  - defines a new project
- Run cmake to create visual studio solution
- build the visual studio solution to create the `.pyd` file
- use the `.pyd` file in your python script

# Example EmotiBitPacket
- Notes:
  - The EmotiBit Packet .h/.cpp files (and any dependencies) were copied to the `EmotiBit_Plugins\src`. This was primarily done because the pybind11 bindinds had to be added to the EmotiBitPacket class. ToDo: figure out a way where this copy/paste is not required. We will probably have to wait till a point where the pybind11 bindings are added to the EmotiBitPacket header in the XPlat_Utils main release.
## Building the example
- cd to `pyExample_emotibitPacket` 
- Run the following command to generate the visual studio solution file. `cmake -S . -B build`
- Open the Visual Studio solution file created inside the `build` folder.
- Build the solution in Release mode. The python dynamic library will be built inside the `build\Rlease\` folder.
- Run the Python example script `pyExample_emotibitPacket\example.py` 


