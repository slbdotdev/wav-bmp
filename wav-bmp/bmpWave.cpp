// CSC1061C01 Capstone Project
// wav.cpp
// 2023-12-05
// Stephen Lee Belden

#include "bmpWave.h"

void bmpWave::paintColumn(int colIndex, float fillPercent, pixel color) {
    // Exception checking
    if (colIndex < 0) {
        throw std::out_of_range("bmpWave colIndex smaller than zero");
    }
    if (colIndex >= width) {
        throw std::out_of_range("bmpWave colIndex larger than image width");
    }
    if (fillPercent < 0.0) {
        throw std::out_of_range("bmpWave fillPercent less than zero");
    }
    if (fillPercent > 1.0) {
        throw std::out_of_range("bmpWave fillPercent larger than 100%");
    }

    // Fill (or don't fill) each pixel in the column
    for (int rowIndex = 0; rowIndex < height; rowIndex++) {
        // determine this row's height as a percentage
        float rowPercent = static_cast<float>(rowIndex + 1) / height;

        // use fill percentage to determine if this pixel gets painted
        if (rowPercent <= fillPercent) {
            data[colIndex + (rowIndex * width)] = color;
        }
    }
}
