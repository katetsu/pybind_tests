#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <pybind11/pytypes.h>
#include <vector>
#include <iostream>
#include <pybind11/eigen.h>
#include <chrono> 
PYBIND11_MAKE_OPAQUE(std::vector<float>);
namespace py = pybind11;

class MyClass {
    Eigen::MatrixXd big_mat = Eigen::MatrixXd::Zero(3,3);

public:
    Eigen::Ref<Eigen::MatrixXd> getMatrix() { return big_mat; }

    void setMatrix(const Eigen::Ref<Eigen::MatrixXd>& mat) { big_mat = mat;}
    void changeMatrix(Eigen::Ref<Eigen::MatrixXd>& mat) { mat(1,1) = 5;}

};


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
        auto j = i*3;
    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    return elapsed.count();

}
using namespace pybind11::literals; 
PYBIND11_MODULE(example, m) {
    py::bind_vector<std::vector<float>>(m, "VectorFloat");
    m.def("test_float", &test_float);

    m.def("test_cpp", &test_cpp);
    m.def("test_vector", &test_vector);


    py::class_<MyClass>(m, "MyClass")
    .def(py::init<>())
    .def("get_matrix", &MyClass::getMatrix, py::return_value_policy::reference_internal)
    .def("set_matrix", &MyClass::setMatrix, "mat"_a.noconvert())
    .def("change_matrix", &MyClass::changeMatrix, py::arg().noconvert())
    ;
}
