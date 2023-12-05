// CSC1061C01 Capstone Project
// tests.h
// 2023-11-29
// Stephen Lee Belden

#ifndef tests_h
#define tests_h

#include "wav.h"

// Functions for testing code during development
namespace tests {
    // check everything
    void runAll();

    // individual tests
    void wavConstructorCopiesDeep();
    void bmpConstructorCopiesDeep();
    void wavArrayOpBounds();
    void bmpArrayOpBounds();
}

#endif