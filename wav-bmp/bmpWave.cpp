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

    // Fill (or don't fill) each pixel in the column
    for (int rowIndex = 0; rowIndex < height; rowIndex++) {
        // split fill height above and below middle of image
        int middle = height / 2;
        double halfFill = fillPercent / 2;
        int upperBound
            = static_cast<int>(ceil(middle + (height * halfFill)));
        int lowerBound
            = static_cast<int>(floor(middle - (height * halfFill)));

        // use bounds to determine if this pixel gets painted
        if (rowIndex >= lowerBound && rowIndex < upperBound) {
            int pixelIndex = colIndex + (rowIndex * width);
            data[pixelIndex] = color;
        }
    }
}
