// CSC1061C01 Capstone Project
// wav.cpp
// 2023-12-05
// Stephen Lee Belden

#include "bmpWave.h"

// Paint everything
void bmpWave::fillBackground(pixel color) {
    // set every pixel in image
    for (int pixelIndex = 0; pixelIndex < (height * width); pixelIndex++) {
        data[pixelIndex] = color;
    }
}


// Paint just one column, centered vertically
void bmpWave::paintColumn(int colIndex, double fillPercent, pixel color) {
    // Bounds checking
    if (colIndex < 0) colIndex = 0;
    if (colIndex >= width) colIndex = width - 1;
    if (fillPercent < 0.0) fillPercent = 0.0;
    if (fillPercent > 1.0) fillPercent = 1.0;

    // split fill height above and below middle of image
    int middle = height / 2;
    double halfFillHeight = height * (fillPercent / 2);
    int upperBound = static_cast<int>(ceil(middle + halfFillHeight));
    int lowerBound = static_cast<int>(floor(middle - halfFillHeight));

    // Fill pixels in the column based on bounds
    for (int rowIndex = lowerBound; rowIndex < upperBound; rowIndex++) {
        data[colIndex + (rowIndex * width)] = color;
    }
}
