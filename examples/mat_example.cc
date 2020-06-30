/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
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
  mat_v4::Write("m", m, file);
  /* Array */
  std::array<uint8_t, 6> n;
  for (std::size_t i = 0; i < 6; i++) {
    n[i] = i;
  }
  mat_v4::Write("n", n, file);
  /* Vector */
  std::vector<float> o;
  for (std::size_t i = 0; i < 10; i++) {
    o.push_back(static_cast<float>(i) / 10);
  }
  mat_v4::Write("o", o, file);
}
