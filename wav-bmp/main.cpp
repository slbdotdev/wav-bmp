// CSC1061C01
// Capstone Project: Draft
// 2023-11-03
// Stephen Lee Belden

#include "wav.h"
#include "tests.h"

#include <iostream>

using namespace std;

int main() {
    // code testing
    tests::runAll();

    // program
    wav sound(1000);
    cout << "sound has " << sound.getLength() << " samples." << endl;
}
