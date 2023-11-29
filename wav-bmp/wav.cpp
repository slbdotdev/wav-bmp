// CSC1061C01 Capstone Project
// wav.cpp
// 2023-11-03
// Stephen Lee Belden

#include "wav.h"

// Definitions for class wav

// constructor for loading data from a file
wav::wav(std::ifstream& infile) {
    // TODO
}

wav::wav(int sampleCount) {
    // set member variables
    length = sampleCount;
    data = new int16_t[sampleCount];

    // initialize all samples to zero
    for (int i = 0; i < sampleCount; i++) {
        data[i] = static_cast<int16_t>(0);
    }

}

// getters
int wav::getLength() {
    return length;
}


// array operator overloading
int16_t& wav::operator[](int index) {
    return data[index];
}


// copy constructor for deep copy
wav::wav(const wav& copy) {
    length = copy.length;
    data = new int16_t[length];

    for (int i = 0; i < length; i++) {
        data[i] = copy.data[i];
    }
}


// destructor for dynamically allocated data
wav::~wav() {
    delete[] data;
}
