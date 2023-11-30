// CSC1061C01 Capstone Project
// wav.cpp
// 2023-11-03
// Stephen Lee Belden

#include "wav.h"

// primary data-loading constructor definition
wav::wav(std::ifstream& infile) {
    // TODO
}


// length-only constructor definition
wav::wav(int sampleCount) {
    // set member variables
    length = sampleCount;
    data = new int16_t[sampleCount];

    // initialize all samples to zero
    for (int i = 0; i < sampleCount; i++) {
        data[i] = static_cast<int16_t>(0);
    }
}


// deep copy constructor definition
wav::wav(const wav& copy) {
    length = copy.length;
    data = new int16_t[length];

    for (int i = 0; i < length; i++) {
        data[i] = copy.data[i];
    }
}


// getter
const int wav::getLength() {
    return length;
}


// array operator overloading
const int16_t& wav::operator[](int index) {
    if(0 <= index && index < length)
        return data[index];
    throw std::out_of_range("wav sample index out of bounds");
}

const int16_t& wav::operator[](int index) const {
    return operator[](index);
}


// destructor for dynamically allocated data
wav::~wav() {
    delete[] data;
}
