// CSC1061C01 Capstone Project
// main.cpp
// 2023-11-03
// Stephen Lee Belden

#include "bmpWave.h"
#include "tests.h"
#include "wav.h"
#include "waveformSettings.h"

#include <iostream>

using namespace std;

int main() {
    // code testing
    tests::runAll();

    // get settings
    waveformSettings sets;

    // read wav audio
    wav sound(1000);
    cout << "sound has " << sound.getLength() << " samples." << endl;

    // generate bmp image
    bmpWave image(sets.outputWidth, sets.outputHeight);
    image.fillBackground(sets.backgroundColor);
    image.paintColumn(0, 0.95, sets.foregroundColor);

    // open output file as raw binary to avoid carriage return issues
    ofstream outFile(sets.outputFilepath, ios::binary);

    // write to disk
    image.writeToFile(outFile);

    // close file
    outFile.close();
}
