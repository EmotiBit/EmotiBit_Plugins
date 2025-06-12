#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // unlocks standard template, giving access to create packet with a vector of strings
#include "EmotiBitPacket.h"
namespace py = pybind11;

PYBIND11_MODULE(EmotiBitPacket, m) {
	py::class_<EmotiBitPacket>(m, "EmotiBitPacket");
	m.def("createHeader", &EmotiBitPacket::createHeader);
	m.def("headerToString", &EmotiBitPacket::headerToString);
	//m.def("createPacket", &EmotiBitPacket::createPacket); 
	m.def("createPacket", static_cast<std::string(*)(const std::string&, const uint16_t&, const vector<std::string>&, const uint8_t&, const uint8_t&)>(&EmotiBitPacket::createPacket));
	py::class_<EmotiBitPacket::Header>(m, "Header")
		.def(py::init<>());
}
