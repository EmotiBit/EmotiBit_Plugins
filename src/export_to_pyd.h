#ifndef EXPORT_TO_PYD_H
#define EXPORT_TO_PYD_H

#ifdef PYBIND11_ENABLED

#include<pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(rounder, m) {
    py::class_<Rounder>(m, "Rounder")
        .def(py::init<>())
        .def("round", &Rounder::round);
}
#endif

#endif
