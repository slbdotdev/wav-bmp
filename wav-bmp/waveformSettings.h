// CSC1061C01 Capstone Project
// wavformSettings.h
// 2023-12-04
// Stephen Lee Belden

#ifndef wavformsettings_h
#define wavformsettings_h

#include <fstream>
#include <string>
#include <iostream>

#include "except.h"
#include "pixel.h"

using namespace std;

class waveformSettings {
public:
    // Default constructor choses reasonable default values
    waveformSettings();

    // Custom constructor interactively prompts user for input
    waveformSettings(istream& in, ostream& out);

    // Ask the user to input custom settings at the terminal
    void promptUser();

    // Functions to prompt the user to input just one new setting
    void setInput();
    void setOutput();
    void setWidth();
    void setHeight();

    // All data members are public for access like a c-struct
    std::string inputFilepath;
    std::string outputFilepath;
    int outputWidth;
    int outputHeight;
    pixel backgroundColor;
    pixel foregroundColor;

private:
    // Helper functions used during interactive prompts
    char readChar();
    void doOption(char opt);
    void loadDefaults();
    void customInput();
    void checkInputFile();
    void checkOutputFile();
    void checkWidth();
    void checkHeight();
};

#endif wavformsettings_h