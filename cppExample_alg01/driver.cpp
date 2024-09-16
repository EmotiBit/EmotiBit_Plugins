#include<cmath>
#include<iostream>

#ifdef PYBIND11_ENABLED
#include<pybind11/pybind11.h>
#endif

class Rounder {
    public:
        void round(double& num) {
            num = std::round(num);
        }
};

int main() {
    Rounder r;
    double num = 5.223;
    r.round(num);
    std::cout << num << std::endl;
}

#ifdef PYBIND11_ENABLED
namespace py = pybind11;

PYBIND11_MODULE(rounder, m) {
    py::class_<Rounder>(m, "Rounder")
        .def(py::init<>())
        .def("round", &Rounder::round);
}
#endif
