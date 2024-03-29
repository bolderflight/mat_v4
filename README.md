![Bolder Flight Systems Logo](img/logo-words_75.png)

# mat_v4
This library provides a C++ interface to write data in MATLAB mat v4 binary format to a file. It is compatible with CMake and would be easy to add to other projects, consisting of a single header-only file.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

## Installation
CMake is used to build this library, which is exported as a library target called *mat_v4*. The header is added as:

```
#include "mat_v4/mat_v4.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library and an example executable called *mat_example*. The example executable source files are located at *examples/mat_example.cc*.

## Documentation
Additional documentation on the MATLAB mat file format is located in the *docs* folder.

## Namespace

This library is within the namespace *bfs*

## Functions

**void MatWrite(std::string name, const DATA &ref, FILE &ast;file)** This function writes data to the file given a MATLAB variable name, a reference to the data, and a pointer to the file. Data can be a matrix from the [Eigen library](http://eigen.tuxfamily.org), an array, or a vector. Static and dynamic matrices are supported and, in the case of a matrix, the matrix dimensions are used to determine the dimensions of the written data. Arrays and vectors are always written as row vectors. The data types supported are: double, float, int32_t, int16_t, uint16_t, and uint8_t.

```C++
  /* Output file */
  FILE *file = fopen("test.mat", "w");
  /* A dynamic matrix of doubles */
  Eigen::MatrixXd m(3, 3);
  m(0, 0) = 0.1;  m(0, 1) = 0.4;  m(0, 2) = 0.7;
  m(1, 0) = 0.2;  m(1, 1) = 0.5;  m(1, 2) = 0.8;
  m(2, 0) = 0.3;  m(2, 1) = 0.6;  m(2, 2) = 0.9;
  bfs::MatWrite("m", m, file);
  /* An array of uint8_t */
  std::array<uint8_t, 6> n;
  for (std::size_t i = 0; i < 6; i++) {
    n[i] = i;
  }
  bfs::MatWrite("n", n, file);
  /* A vector of floats */
  std::vector<float> o;
  for (std::size_t i = 0; i < 10; i++) {
    o.push_back(static_cast<float>(i) / 10);
  }
  bfs::MatWrite("o", o, file);
```
