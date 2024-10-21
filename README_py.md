# Porting an algorithm from C++ to Python

## Why?
The goal of this project is to allow users to take an algorithm written in C++ and translate that into runnable Python code.
This could allow a user to develop C++ code and run it on the EmotiBit's firmware, software, and through Python hitting three different metrics.

## Installation Steps
* ***This guide must be followed on a Windows machine***
* Follow [this README](README.md) for installation steps and then follow the example below.
  * *The cd command changes your directory that you are in and will be pivotal moving forward.*

## Steps to Run Example
* Run the following commands ***inside the same Anaconda terminal from earlier***:
```bash
cd ..\src\
mkdir build
cd build
cmake ..
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

