/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include <iostream>
#include <stdio.h>
#include "mat_v4/mat_v4.h"
#include "Eigen/Core"
#include "Eigen/Dense"

int main() {
  /* Output file */
  FILE *file = fopen("test.mat", "w");
  /* Matrix */
  Eigen::MatrixXd m(3, 3);
  m(0, 0) = 0.1;  m(0, 1) = 0.4;  m(0, 2) = 0.7;
  m(1, 0) = 0.2;  m(1, 1) = 0.5;  m(1, 2) = 0.8;
  m(2, 0) = 0.3;  m(2, 1) = 0.6;  m(2, 2) = 0.9;
  bfs::MatWrite("m", m, file);
  /* Array */
  std::array<uint8_t, 6> n;
  for (std::size_t i = 0; i < 6; i++) {
    n[i] = i;
  }
  bfs::MatWrite("n", n, file);
  /* Vector */
  std::vector<float> o;
  for (std::size_t i = 0; i < 10; i++) {
    o.push_back(static_cast<float>(i) / 10);
  }
  bfs::MatWrite("o", o, file);
}
