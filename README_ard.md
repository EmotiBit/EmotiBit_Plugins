# Porting an algorithm from C++ to the EmotiBit Firmware

## Why?
The goal of this project is to allow users to take an algorithm written in C++ and translate that into firmware code.
This could allow a user to develop C++ code and run it on the EmotiBit's firmware, software, and through Python hitting three different metrics.

## Installation Steps
* ***This guide must be followed on a Windows machine***
* Follow this [guide up to "Programming the feather"](https://github.com/EmotiBit/EmotiBit_Docs/blob/master/Keep_emotibit_up_to_date.md#setup) for installation steps and then follow the example below.
  * Note: Follow [prerequisites section](https://github.com/EmotiBit/EmotiBit_Docs/blob/master/Getting_Started.md#prerequisites) to ensure that you have proper driver's installed.
* Follow [this README](README.md) for installation steps for cloning the repository.

## How to Run this Example
* If you are following just this example you can close out of the Powershell Prompt.
* Open up the Arduino IDE installed previously and click ```File -> Open -> C:/path/to/your/EmotiBit_Plugins/ardExample_alg01/ardExample_alg01.ino```
* Next follow ```Sketch -> Add File... -> C:/path/to/your/EmotiBit_Plugins/src/alg01.h``` and ```Sketch -> Add File... -> C:/path/to/your/EmotiBit_Plugins/src/alg01.cpp```
* Now plug in your EmotiBit to your computer and ensure that your Arduino board is connected with both the correct board and port.
* Once connected, click the upload button in the top left and press CTRL + SHIFT + M to open up a serial monitor.
* Navigate to the serial monitor that is opened, and press the reset button found on top of Adafruit Feather.
* The serial monitor will print something along the lines of "Rounded Value of 4.70 is: 5" this concludes the example and ensures that everything is working.
