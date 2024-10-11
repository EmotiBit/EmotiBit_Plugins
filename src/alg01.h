#ifndef ALG_01
#define ALG_01

#include<cmath>
#ifdef PYBIND11_ENABLED
#include<pybind11/pybind11.h>
#endif

class Rounder {
    public:
	int round(double num);
};

#ifdef PYBIND11_ENABLED
namespace py = pybind11;

PYBIND11_MODULE(rounder, m) {
    py::class_<Rounder>(m, "Rounder")
        .def(py::init<>())
        .def("round", &Rounder::round);
}
#endif

#endif
