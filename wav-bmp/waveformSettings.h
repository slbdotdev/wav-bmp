// CSC1061C01 Capstone Project
// wavformSettings.h
// 2023-12-04
// Stephen Lee Belden

#ifndef wavformsettings_h
#define wavformsettings_h

#include <string>
#include <iostream>

#include "pixel.h"

class waveformSettings {
public:
    // Default constructor choses reasonable default values
    waveformSettings()
        : inputFilepath("meow.wav"),
        outputFilepath("defaultOutput.bmp"),
        outputWidth(333),
        outputHeight(80),
        backgroundColor(pixel(10, 10, 175)), // light blue
        foregroundColor(pixel(10, 10, 75)) {} // dark blue

    // Ask the user to input custom settings at the terminal
    void promptUser();

    // All data members are public for access like a c-struct
    std::string inputFilepath;
    std::string outputFilepath;
    unsigned int outputWidth;
    unsigned int outputHeight;
    pixel backgroundColor;
    pixel foregroundColor;
};

#endif wavformsettings_h