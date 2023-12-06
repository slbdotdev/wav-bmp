// CSC1061C01 Capstone Project
// bmpWave.h
// 2023-12-05
// Stephen Lee Belden

#ifndef bmpwave_h
#define bmpwave_h

#include <stdexcept>

#include "bmp.h"

// A bmpWave "is a" bmp image.
// Adds functionality for addressing the image column-by-column.
class bmpWave : public bmp {
public:
    // Use base class custom constructor
    bmpWave(unsigned int w, unsigned int h) : bmp(w, h) {};

    // Fill columns with waves
    void paintColumn(int colIndex, float fillPercent, pixel color);
};

#endif
