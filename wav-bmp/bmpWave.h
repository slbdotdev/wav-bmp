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
    bmpWave(int w, int h) : bmp(w, h) {};

    // Fill entire image with a solid color
    void fillBackground(pixel color);

    // Fill columns with waves
    void paintColumn(int colIndex, double fillPercent, pixel color);
};

#endif
