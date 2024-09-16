# Welcome to a Toy PyBind11 Algorithm

## Why?
The goal of this project is to allow users to take an algorithm written in C++ and translate that into runnable Python code.
This could allow a user to develop C++ code and run it on the EmotiBit's firmware, software, and through Python hitting three different metrics.

## Installation Steps
* Follow ['this link'](https://github.com/EmotiBit/EmotiBit_Biometric_Lib/tree/master/py) for details on how to setup a basic Anaconda environment.
  * Everything up to downloading Spyder is a necessary step in the process. Skip downloading the Anaconda environment given, you can find the correct one in the GitHub repo below.
* Afterwards, follow [this link](url), and import the pyExample_alg01/EmotiBit-pyenv-modern file into your Anaconda environments.
* Install Visual Studio 2022 and update to the latest version if possible.

## Steps to Run Example
* Clone ['this'](https://github.com/EmotiBit/EmotiBit_Plugins) GitHub Repo onto your machine.
* Open a ***Anaconda*** terminal and cd into EmotiBit_Plugins/cppExample_alg01
* Once inside the cloned folder run the commands below:
```bash
mkdir build
cd build
cmake ..
```
* After this you should see a rounder.sln file inside your Visual Studio explorer. Open this file.
  * After you open this file, navigate to the top of Visual Studio and find Build > Build Solution.
  * This will create a rounder.pyd file in either the debug or release folder depending on your machine.
  * Move the rounder.pyd file into the pyExample_alg01 folder.
* Now you can try running the pyExample_alg01.py file and you should see numbers correctly being rounded.
