#include "waveformSettings.h"

waveformSettings::waveformSettings() {
    loadDefaults();
}

waveformSettings::waveformSettings(std::istream& in, std::ostream& out)
    : waveformSettings() {
    promptUser();
}

void waveformSettings::promptUser() {
    // Prepare for the unexpected
    bool validChoice = false;

    // Show initial options until the user makes a valid choice
    while (!validChoice) {
        // Prompt
        cout << "Waveform Visualizer Options:" << std::endl;
        cout << "  D - Default Settings (recommended)" << std::endl;
        cout << "  C - Custom Settings" << std::endl;
        cout << "Enter the letter of your choice: ";

        // Read
        char choice = readChar();

        // Exception handling
        try {
            doOption(choice);
            validChoice = true;
        }
        catch (option_not_recognised ex) {
            cout << ex.what();
        }
    }
}

// Set input file from user prompt
void waveformSettings::setInput() {
    // Initialize
    bool valid = false;

    // Show prompt until the user makes a valid choice
    while (!valid) {
        // Prompt
        cout << "Input File, a 16-bit .wav audio file:" << std::endl;
        cout << "Enter a valid filename: ";

        // Read
        cin >> inputFile;

        // Exception handling
        try {
            checkInputFile();
            valid = true;
        }
        catch (invalid_input ex) {
            cout << ex.what();
        }
    }
}

// Set output file from user prompt
void waveformSettings::setOutput() {
    // Initialize
    bool valid = false;

    // Show prompt until the user makes a valid choice
    while (!valid) {
        // Prompt
        cout << "Output file, a 24-bit .bmp image file:" << std::endl;
        cout << "Enter a valid filename: ";

        // Read
        cin >> outputFile;

        // Exception handling
        try {
            checkOutputFile();
            valid = true;
        }
        catch (invalid_input ex) {
            cout << ex.what();
        }
    }
}

// Set output image width from user prompt
void waveformSettings::setWidth() {
    // Initialize
    bool valid = false;

    // Show prompt until the user makes a valid choice
    while (!valid) {
        // Prompt
        cout << "Enter width of output file (number of pixels): ";

        // Read
        cin >> outputWidth;

        // Exception handling
        try {
            checkWidth();
            valid = true;
        }
        catch (invalid_input ex) {
            cout << ex.what();
        }
    }
}

// Set output image height from user prompt
void waveformSettings::setHeight() {
    // Initialize
    bool valid = false;

    // Show prompt until the user makes a valid choice
    while (!valid) {
        // Prompt
        cout << "Enter height of output file (number of pixels): ";

        // Read
        cin >> outputHeight;

        // Exception handling
        try {
            checkHeight();
            valid = true;
        }
        catch (invalid_input ex) {
            cout << ex.what();
        }
    }
}


// Private members

// Read only one lowercase char and return the input to a blank safe state
char waveformSettings::readChar() {
    char c;

    // Read one char
    cin.get(c);

    // Clear any errors and ignore everything else
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Convert uppercase to lower
    return tolower(c);
}

// Interpret char option or throw an exception
void waveformSettings::doOption(char opt) {
    switch (opt) {
    case 'c':
        cout << "Custom settings..." << endl << endl;
        customInput();
        break;
    case 'd':
        cout << "Using defaults..." << endl << endl;
        loadDefaults();
        break;
    default:
        throw option_not_recognised();
    };
}

// Default values for demo
void waveformSettings::loadDefaults() {
    inputFile = "meow.wav";
    outputFile = "out.bmp";
    outputWidth = 800;
    outputHeight = 120;
    backgroundColor = pixel(10, 10, 40); // dark blue
    foregroundColor = pixel(120, 120, 250); // light blue
}

// Get all custom settings
void waveformSettings::customInput() {
    setInput();
    setOutput();
    setWidth();
    setHeight();
}

// Ensure the input file is readable or throw exception
void waveformSettings::checkInputFile() {
    // Open, check, and close file
    ifstream infile(inputFile);
    bool good = infile.good();
    infile.close();

    if (!good) {
        throw invalid_input();
    }
}

// Ensure the output file is readable or throw exception
void waveformSettings::checkOutputFile() {
    // Open, check, and close file
    ofstream outfile(outputFile);
    bool good = outfile.good();
    outfile.close();

    if (!good) {
        throw invalid_input();
    }
}

// Ensure output file width is good or throw exception
void waveformSettings::checkWidth() {
    if (outputWidth <= 0) {
        throw invalid_input();
    }
}

void waveformSettings::checkHeight() {
    if (outputHeight <= 0) {
        throw invalid_input();
    }
}
