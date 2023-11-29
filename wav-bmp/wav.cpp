// CSC1061C01 Capstone Project
// wav.cpp
// 2023-11-03
// Stephen Lee Belden

#include "wav.h"

// Definitions for class wav

// getters
int wav::getLength() {
    return length;
}


// array operator overloading
int& wav::operator[](int index) {
    return data[index];
}


// copy constructor for deep copy
wav::wav(const wav& copy) {
    length = copy.length;
    data = new int[length];

    for (int i = 0; i < length; i++) {
        data[i] = copy.data[i];
    }
}


// destructor for dynamically allocated data
wav::~wav() {
    delete[] data;
}
