// CSC1061C01
// Capstone Project: Draft
// 2023-11-03
// Stephen L. Belden

#include "wav.h"

#include <iostream>

using namespace std;

int main() {
    wav sound(1000);
    cout << "sound has " << sound.getLength() << " samples." << endl;
}
