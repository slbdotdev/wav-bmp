// CSC1061C01 Capstone Project
// bmpWave.h
// 2023-12-05
// Stephen Lee Belden

#ifndef bmpwave_h
#define bmpwave_h

#include <stdexcept>

#include "bmp.h"
#include "waveformSettings.h"

// A bmpWave "is a" bmp image.
// Adds functionality for addressing the image column-by-column.
// Adds information from waveformSettings.
class bmpWave : public bmp {
public:
    // Uses base class custom constructor
    bmpWave(waveformSettings sets);

    // Fills the first n columns based on the fill values in the array
    void fillColumns(double fillVals[], int n);

private:
    // Helper function to fill entire image with a solid color
    void fillBackground(pixel color);

    // Helper function to fill one column with the foreground color
    void paintColumn(int colIndex, double fillPercent);

    // Store settings from initialization
    waveformSettings settings;
};

#endif
