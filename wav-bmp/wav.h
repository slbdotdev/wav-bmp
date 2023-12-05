// CSC1061C01 Capstone Project
// wav.h
// 2023-11-29
// Stephen Lee Belden

#ifndef wav_h
#define wav_h

#include <cassert>
#include <fstream>
#include <stdexcept>

// Immutable class for reading and storing .wav audio file data
class wav {
public:
    // primary conversion constructor, the only way to load data.
    // all wav objects are immutable after construction.
    wav(std::ifstream& infile);

    // length-only constructor, for testing. all samples are set to 0.
    wav(int sampleCount);

    // copy constructor for deep copy of data referenced by pointer
    wav(const wav& copy);

    // getters
    const int getLength();

    // operator overloads
    const int16_t& operator[](int index);
    const int16_t& operator[](int index) const;

    // assignment is typically overloaded for classes with pointers,
    // but in this case the class is designed to be immutable,
    // so modifying an object after construction is not permitted.
    const wav& operator=(const wav&) = delete;

    // destructor for deleting dynamic memory
    ~wav();

private:
    int16_t* data;
    int length;
};

#endif