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
  Eigen::MatrixXd m(3, 3);
  m(0, 0) = 1;  m(0, 1) = 4;  m(0, 2) = 7;
  m(1, 0) = 2;  m(1, 1) = 5;  m(1, 2) = 8;
  m(2, 0) = 3;  m(2, 1) = 6;  m(2, 2) = 9;
  FILE *file = fopen("test.mat", "w");
  mat_v4::Write("m", m, file);
  std::array<uint8_t, 6> n;
  for (std::size_t i = 0; i < 6; i++) {
    n[i] = i;
  }
  mat_v4::Write("n", n, file);
  std::vector<double> o;
  for (std::size_t i = 0; i < 10; i++) {
    o.push_back(2*i);
  }
  mat_v4::Write("o", o, file);
}
