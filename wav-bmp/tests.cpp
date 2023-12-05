// CSC1061C01 Capstone Project
// tests.cpp
// 2023-11-29
// Stephen Lee Belden

#include <cassert>

#include "bmp.h"
#include "tests.h"

// Definition for running all tests
void tests::runAll() {
    wavConstructorCopiesDeep();
    bmpConstructorCopiesDeep();
    wavArrayOpBounds();
    bmpArrayOpBounds();
}


// Tests for deep copy in data referenced by class member pointer
void tests::wavConstructorCopiesDeep() {
    // create test object
    int samples = 3;
    wav a(samples);

    // copy
    wav b(a);

    // test for address difference
    assert(&a[0] != &b[0]);
}

void tests::bmpConstructorCopiesDeep() {
    // create test object
    int width = 4;
    int height = 3;
    bmp a(width, height);

    // copy
    bmp b(a);

    // test for address difference
    assert(&a[0] != &b[0]);
}


// Test bounds-checking on overloaded array subscript operators
void tests::wavArrayOpBounds() {
    // create test object
    int samples = 3;
    wav a(samples);

    // attempt to access past end of array
    try {
        int16_t temp = a[samples + 1];

        // code only reached if exception not thrown
        assert((samples + 1) < samples);
    }
    catch (std::out_of_range) {
        // do nothing, correct result
    }
}

void tests::bmpArrayOpBounds() {
    // create test object
    int width = 4;
    int height = 3;
    int pixelCount = width * height;
    bmp a(width, height);

    // attempt to access past end of array
    try {
        pixel temp = a[pixelCount + 1];

        // code only reached if exception not thrown
        assert((pixelCount + 1) < pixelCount);
    }
    catch (std::out_of_range) {
        // do nothing, correct result
    }
}