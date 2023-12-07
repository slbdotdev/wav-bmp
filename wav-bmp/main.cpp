// CSC1061C01 Capstone Project
// main.cpp
// 2023-11-03
// Stephen Lee Belden

#include "bmpWave.h"
#include "tests.h"
#include "wav.h"
#include "waveformSettings.h"

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    // code testing
    tests::runAll();

    // get settings from user
    waveformSettings sets(cin, cout);

    // open and load wav file
    ifstream inFile(sets.inputFilepath);
    wav audio(inFile);

    // initialize bmp image from settings
    bmpWave image(sets);
    
    // do some quick math
    double idealSamplesPerColumn
        = static_cast<double>(audio.getLength()) / sets.outputWidth;
    long trueSamplesPerCol
        = static_cast<long>(ceil(idealSamplesPerColumn));

    // generate binned averages
    short* avgs = new short[sets.outputWidth];
    for (long i = 0; i < sets.outputWidth; i++) {
        long start = static_cast<long>(floor(i * idealSamplesPerColumn));
        avgs[i] = audio.getAverage(start, trueSamplesPerCol);
    }

    // convert averages to percentages
    double* avgFills = new double[sets.outputWidth];
    for (int i = 0; i < sets.outputWidth; i++) {
        avgFills[i] = static_cast<double>(avgs[i]) / SHRT_MAX;
    }

    // draw wave
    image.fillColumns(avgFills, sets.outputWidth);

    // open output file as raw binary to avoid carriage return issues
    ofstream outFile(sets.outputFilepath, ios::binary);

    // write to disk
    image.writeToFile(outFile);

    // give feedback to user
    cout << sets.inputFilepath << " has " << audio.getLength() << " samples."
        << endl;
    cout << "Output resolution is " << sets.outputWidth << " columns." << endl;
    cout << "Resulting samples per column: " << trueSamplesPerCol << endl;
    cout << "Output folder is VS Solution directory," << endl;
    cout << "Image written to: " << sets.outputFilepath << endl;

    // cleanup
    outFile.close();
    delete[] avgs;
    delete[] avgFills;
}
