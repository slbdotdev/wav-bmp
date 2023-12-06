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
    image.paintColumn(1, 1.0, pixel(200, 10, 175));

    // open output file
    ofstream outFile(sets.outputFilepath, ios::binary);

    // write to disk
    image.writeToFile(outFile);
}
