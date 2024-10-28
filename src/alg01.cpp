#include "alg01.h"

int Rounder::round(double num) {
    return static_cast<int>(std::round(num));
}

// Pybind11 config is not in a separate file as it is dependant on the algorithm, unlike the DLL_config
#ifdef PYBIND11_ENABLED

#include<pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(rounder, m) {
    py::class_<Rounder>(m, "Rounder")
        .def(py::init<>())
        .def("round", &Rounder::round);
}
#endif
