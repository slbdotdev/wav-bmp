// CSC1061C01 Capstone Project
// wav.cpp
// 2023-11-29
// Stephen Lee Belden

#include "wav.h"

// primary data-loading conversion constructor definition
wav::wav(std::ifstream& infile) {
    // Discard bytes in header before what we need
    long offsetToDataSize = 40;
    char byteDiscard;
    for (long i = 0; i < offsetToDataSize; i++) {
        infile.get(byteDiscard);
    }

    // Read data size
    infile.read(reinterpret_cast<char*>(&length), sizeof(length));

    // Data size is in bytes, we want number of samples (2 bytes each)
    length = length / 2;

    // Read samples
    data = new short[length] {};
    for (long i = 0; i < length && !infile.eof(); i++) {
        infile.read(reinterpret_cast<char*>(&data[i]), sizeof(short));
    }
}


// length-only constructor definition
wav::wav(int sampleCount) {
    // set member variables
    length = sampleCount;
    data = new short[sampleCount];

    // initialize all samples to zero
    for (int i = 0; i < sampleCount; i++) {
        data[i] = static_cast<short>(0);
    }
}


// deep copy constructor definition
wav::wav(const wav& copy) {
    length = copy.length;
    data = new short[length];

    for (int i = 0; i < length; i++) {
        data[i] = copy.data[i];
    }
}


// getter
const long wav::getLength() {
    return length;
}


// Returns the average magnitude of samples within the range
// from startIndex to startIndex + count.
short wav::getAverage(long startIndex, long count) {
    // bounds checking
    if (startIndex >= length) {
        startIndex = length - count - 1;
    }
    
    // avoid division by zero
    if (count <= 0) count = 1;

    // calculate average
    long long accumulator = 0;
    for (long i = startIndex; i < startIndex + count; i++) {
        accumulator += abs(data[i]);
    }

    return static_cast<short>(accumulator / count);
}


// array operator overloading
const short& wav::operator[](int index) {
    if(0 <= index && index < length)
        return data[index];
    throw std::out_of_range("wav sample index out of bounds");
}

const short& wav::operator[](int index) const {
    if (0 <= index && index < length)
        return data[index];
    throw std::out_of_range("wav sample index out of bounds");
}


// destructor for dynamically allocated data
wav::~wav() {
    delete[] data;
}
