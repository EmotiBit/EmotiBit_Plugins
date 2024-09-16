# Welcome to a Toy C++ Algorithm

## Why?
The goal of this project is to allow users to take an algorithm written in C++ and translate that into runnable Python code.
This could allow a user to develop C++ code and run it on the EmotiBit's firmware, software, and through Python hitting three different metrics.

## Installation Steps
* Install Visual Studio 2022 and update to the latest version if possible.
* Install the latest version of g++ or use your compiler of choice.

## Steps to Run Example
* Clone ['this'](https://github.com/EmotiBit/EmotiBit_Plugins) GitHub Repo onto your machine.
* cd into EmotiBit_Plugins/cppExample_alg01
* Once inside the cloned folder run the commands below:
```bash
g++ -o rounder driver.cpp
./rounder
```
* This should output the number 5. If it does so, the algorithm is working on your machine.
