/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#ifndef INCLUDE_MAT_V4_MAT_V4_H_
#define INCLUDE_MAT_V4_MAT_V4_H_

#include <iostream>
#include <cstdint>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
#include "Eigen/Core"
#include "Eigen/Dense"

namespace mat_v4 {

/* Write double matrices, arrays, and vectors */
template<int M, int N>
void Write(std::string name, const Eigen::Matrix<double, M, N> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 0,
    .mrows = ref.rows(),
    .ncols = ref.cols(),
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(double), header.mrows * header.ncols, file);
}
template<std::size_t M>
void Write(std::string name, const std::array<double, M> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 0,
    .mrows = M,
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(double), header.mrows * header.ncols, file);
}
void Write(std::string name, const std::vector<double> &ref, FILE* file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 0,
    .mrows = ref.size(),
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(double), header.mrows * header.ncols, file);
}
/* Write float matrices, arrays, and vectors */
template<int M, int N>
void Write(std::string name, const Eigen::Matrix<float, M, N> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 10,
    .mrows = ref.rows(),
    .ncols = ref.cols(),
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(float), header.mrows * header.ncols, file);
}
template<std::size_t M>
void Write(std::string name, const std::array<float, M> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 10,
    .mrows = M,
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(float), header.mrows * header.ncols, file);
}
void Write(std::string name, const std::vector<float> &ref, FILE* file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 10,
    .mrows = ref.size(),
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(float), header.mrows * header.ncols, file);
}
/* Write int32_t matrices, arrays, and vectors */
template<int M, int N>
void Write(std::string name, const Eigen::Matrix<int32_t, M, N> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 20,
    .mrows = ref.rows(),
    .ncols = ref.cols(),
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(int32_t), header.mrows * header.ncols, file);
}
template<std::size_t M>
void Write(std::string name, const std::array<int32_t, M> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 20,
    .mrows = M,
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(int32_t), header.mrows * header.ncols, file);
}
void Write(std::string name, const std::vector<int32_t> &ref, FILE* file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 20,
    .mrows = ref.size(),
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(int32_t), header.mrows * header.ncols, file);
}
/* Write int16_t matrices, arrays, and vectors */
template<int M, int N>
void Write(std::string name, const Eigen::Matrix<int16_t, M, N> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 30,
    .mrows = ref.rows(),
    .ncols = ref.cols(),
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(int16_t), header.mrows * header.ncols, file);
}
template<std::size_t M>
void Write(std::string name, const std::array<int16_t, M> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 30,
    .mrows = M,
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(int16_t), header.mrows * header.ncols, file);
}
void Write(std::string name, const std::vector<int16_t> &ref, FILE* file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 30,
    .mrows = ref.size(),
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(int16_t), header.mrows * header.ncols, file);
}
/* Write uint16_t matrices, arrays, and vectors */
template<int M, int N>
void Write(std::string name, const Eigen::Matrix<uint16_t, M, N> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 40,
    .mrows = ref.rows(),
    .ncols = ref.cols(),
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(uint16_t), header.mrows * header.ncols, file);
}
template<std::size_t M>
void Write(std::string name, const std::array<uint16_t, M> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 40,
    .mrows = M,
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(uint16_t), header.mrows * header.ncols, file);
}
void Write(std::string name, const std::vector<uint16_t> &ref, FILE* file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 40,
    .mrows = ref.size(),
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(uint16_t), header.mrows * header.ncols, file);
}
/* Write uint8_t matrices, arrays, and vectors */
template<int M, int N>
void Write(std::string name, const Eigen::Matrix<uint8_t, M, N> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 50,
    .mrows = ref.rows(),
    .ncols = ref.cols(),
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(uint8_t), header.mrows * header.ncols, file);
}
template<std::size_t M>
void Write(std::string name, const std::array<uint8_t, M> &ref, FILE *file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 50,
    .mrows = M,
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(uint8_t), header.mrows * header.ncols, file);
}
void Write(std::string name, const std::vector<uint8_t> &ref, FILE* file) {
  /* Mat header */
  struct Header {
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
  } header = {
    .type = 50,
    .mrows = ref.size(),
    .ncols = 1,
    .imagf = 0,
    .namelen = name.length() + 1
  };
  /* Write the header */
  fwrite(&header, sizeof(header), 1, file);
  /* Write the name */
  fwrite(name.c_str(), sizeof(char), header.namelen, file);
  /* Write the data */
  fwrite(ref.data(), sizeof(uint8_t), header.mrows * header.ncols, file);
}

};

#endif  // INCLUDE_MAT_V4_MAT_V4_H_
