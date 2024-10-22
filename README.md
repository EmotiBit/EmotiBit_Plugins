# EmotiBit_Plugins
Examples and information to make EmotiBit plugins. The intention for this repo is to explain through examples and READMEs how to create algorithms and deploy them in different contexts (python, OF, Arduino, others). This is intended as an instructional repo as it's expected that algorithms will be distributed in many different repos hosted by many different users/organizations.

## Installation Steps
* ***This guide must be followed on a Windows machine***
* Follow [this link](https://github.com/EmotiBit/EmotiBit_Plugins) and clone the repository onto your machine.
* Install Visual Studio 2022, this was tested successfully with 17.11.02.
* Download [Anaconda](https://www.anaconda.com/download/) as shown here.
* ***Do not close out of the Anaconda Powershell Prompt until completely done with an example***
* Open an ***Anaconda Powershell Prompt*** through the search feature on your machine and run the command below:
```bash
cd C:\path\to\your\EmotiBit_Plugins\pyExample_alg01
conda config --set channel_priority flexible
conda env update --name EmotiBit-pyenv-modern --file .\EmotiBit-pyenv-modern.yml
conda activate EmotiBit-pyenv-modern
```
  * *After following the steps above, follow one of the README's below to accomplish your goal*

## From C++ to Python

[Read this README](README_py.md)

## From C++ to EmotiBit Software

[Read this README](README_of.md)

## From C++ to firmware

[Read this README](README_ard.md)
