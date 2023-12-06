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

    // get settings from user
    waveformSettings sets(cin, cout);

    // read wav audio
    wav sound(1000);
    cout << "sound has " << sound.getLength() << " samples." << endl;

    // initialize bmp image from settings
    bmpWave image(sets);

    // draw wave
    const int length = 5;
    double fillVales[length] = { 0.2, 0.3, 0.4, 0.5, 0.6 };
    image.fillColumns(fillVales, length);

    // open output file as raw binary to avoid carriage return issues
    ofstream outFile(sets.outputFilepath, ios::binary);

    // write to disk
    image.writeToFile(outFile);

    // close file
    outFile.close();
}
