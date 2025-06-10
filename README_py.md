# Porting an algorithm from C++ to Python

## Why?
The goal of this project is to allow users to take an algorithm written in C++ and translate that into runnable Python code.
This could allow a user to develop C++ code and run it on the EmotiBit's firmware, software, and through Python hitting three different metrics.

## How it works
- We use pybind11 to create bindings for existing c++ code to a dynamic python library.
- These bindings essentially define the class/function prototypes, in the pybind11 formati. An example of a binding would look like
```c++
	py::class_<EmotiBitPacket>(m, "EmotiBitPacket")
		.def(py::init<>());
	m.def("createHeader", &EmotiBitPacket::createHeader);
	m.def("headerToString", &EmotiBitPacket::headerToString);
```
- The pybind11 python library (installed in the virtual environment) contains the source code to perform the mapping from a c++ file to a `.pyd` file.
- The flow to go from .cpp to .pyd looks like
  - Create Visual Studio sln file using CMAKE
  - Build Visual Studio project to create the `.pyd` file
  - Run the python script that uses C++ cource code refernce, after adding the path/to/pyd file in the python script


## Installation Steps
***This guide must be followed on a Windows machine***

### Creating an environment in python
#### Using venv
- Open a ne comman prompt window
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

# Example EmotiBitPacket
- Notes:
  - The EmotiBit Packet .h/.cpp files (and any dependencies) were copied to the `EmotiBit_Plugins\example_emotiBitPacket`. ToDo: figure out a way where this copy/paste is not required. We will probably have to wait till a point where the pybind11 bindings are added to the EmotiBitPacket header in the XPlat_Utils main release.
## Building the example
- cd to `example_emotiBitPacket` 
- Run the following command to generate the visual studio solution file. `cmake -S . -B build`
- Open the Visual Studio solution file created inside the `build` folder.
- Build the solution in Release mode. The python dynamic library will be built inside the `build\Rlease\` folder.
- Run the Python example script `pyExample_emotibitPacket\example.py` folder

# Example-Rounder (currently uses anaconda)
## Steps to Run Example
* Run the following commands ***inside the same Anaconda terminal from earlier***:
```bash
cd ..\src\
cmake -S . -B build
```
* After cmake runs successfully, a rounder.sln created in your build folder.
  * Open this file in Visual Studio and navigate to the top and make sure it says ***Release*** and not Debug.
  * Now navigate to Build > Build Solution
  * This will create a rounder.pyd file in the release folder.
* Now cd (in the Anaconda terminal used earlier) into the EmotiBit_Plugins/pyExample_alg01 folder and run the command below:
```bash
python3 pyExample_alg01.py -i 3.4
```
* The program should output a rounded version of your number!

***NOTE: The section below remains undeveloped. Consider confronting the GitHub repository issue associated to design a better solution.***

## How to Modify this to your Use Case
* Looking at the code given you can see the following lines:
```cpp
#ifdef PYBIND11_ENABLED
#include<pybind11/pybind11.h>
#endif

// snipped

#ifdef PYBIND11_ENABLED
namespace py = pybind11;

PYBIND11_MODULE(rounder, m) {
    py::class_<Rounder>(m, "Rounder")
        .def(py::init<>())
        .def("round", &Rounder::round);
}
#endif
```
* To apply to your own use case, something similar must be done to your code. There are two approaches: if you have a class or a function.
* If you have a function you use the code below:
```cpp
PYBIND11_MODULE(your_function, m) {
  m.def("your_function", &your_function, "Descripition of your function")
}
  ```
  * This must be repeated for any function you wish to use in Python.
* If you have a class use this template:
```cpp
PYBIND11_MODULE(your_class, m) {
  py:class_<your_class>(m, "your_class")
      .def(py::init<>())
      .def("your_method", &your_class::your_method)
      .def("your_method1", &your_class::your_method1);
}
  ```

