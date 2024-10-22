# Porting an algorithm from C++ to a DLL

## Why?
The goal of this project is to allow users to take an algorithm written in C++ and translate that into a DLL to be used in the EmotiBit software.
This could allow a user to develop C++ code and run it on the EmotiBit's firmware, software, and through Python hitting three different metrics.

## Installation Steps
* ***This guide must be followed on a Windows machine***
* Follow [this README](README.md) for installation steps and then follow the example below.
  * *The cd command changes your directory that you are in and will be pivotal moving forward.*

## How to Run this Example
* Using the same Anaconda Powershell Prompt from earlier run the following commands:
```bash
cd ../ofExample_alg01/src
cmake -S . -B build
cmake --build build --config Release
cd .\build\Release
./rounder_test.exe
```
* This command above should output 5, meaning the 5.223 in the program was successfully rounded to 5.
