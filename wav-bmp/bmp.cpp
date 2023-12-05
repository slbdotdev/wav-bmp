// CSC1061C01 Capstone Project
// bmp.cpp
// 2023-11-29
// Stephen Lee Belden

#include "bmp.h"

// copy constructor definition
bmp::bmp(const bmp& copy)
    : width(copy.width), height(copy.height) {

    // Initialize
    const int pixelCount = width * height;
    data = new pixel[pixelCount];

    // Copy
    for (int i = 0; i < pixelCount; i++) {
        data[i] = copy.data[i];
    }
}

const unsigned int bmp::getPixelCount() {
    return width * height;
}

// array operator overloading
const pixel& bmp::operator[](int index) {
    if (0 <= index && index < width * height)
        return data[index];
    throw std::out_of_range("bmp pixel index out of bounds");
}

const pixel& bmp::operator[](int index) const {
    if (0 <= index && index < width * height)
        return data[index];
    throw std::out_of_range("bmp pixel index out of bounds");
}

// destructor for dynamically allocated data
bmp::~bmp() {
    delete[] data;
}
