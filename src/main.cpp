#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <pybind11/pytypes.h>
#include <vector>
#include <iostream>
#include <chrono> 
PYBIND11_MAKE_OPAQUE(std::vector<float>);
namespace py = pybind11;

std::vector<float> test_float(size_t s) {
    return std::vector<float> (s, 10e9);
}


float test_cpp(py::list& s) {
    auto start = std::chrono::high_resolution_clock::now();

    for (auto& i : s){
        continue;
    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    return elapsed.count();

}

float test_vector(size_t s) {

    auto data = std::vector<float> (s, 10e9);
    auto start = std::chrono::high_resolution_clock::now();

    for (auto& i : data){
        continue;
    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    return elapsed.count();

}

PYBIND11_MODULE(example, m) {
    py::bind_vector<std::vector<float>>(m, "VectorFloat");
    m.def("test_float", &test_float);

    m.def("test_cpp", &test_cpp);
    m.def("test_vector", &test_vector);
}
