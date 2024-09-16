#include<cmath>
#include<iostream>
#include<pybind11/pybind11.h>

class Rounder {
    public:
        int round(double& num) {
            return std::round(num);
        }
};

int main() {
    Rounder r;
    double num = 5.223;
    r.round(num);
}

namespace py = pybind11;

PYBIND11_MODULE(rounder, m) {
    py::class_<Rounder>(m, "Rounder")
        .def(py::init<>())
        .def("round", &Rounder::round);
}

// cl /O2 /LD /I C:/Users/shark/anaconda3/envs/EmotiBit-pyenv-modern/Lib/site-packages/pybind11/include /I C:/Users/shark/anaconda3/envs/EmotiBit-pyenv-modern/Include driver.cpp /link /OUT:rounder.pyd /LIBPATH:C:/Users/shark/anaconda3/envs/EmotiBit-pyenv-modern/libs
