// wav.h
// Class for reading and storing .wav file data
// 2023-11-03
// Stephen Lee Belden

#ifndef wav_h
#define wav_h

class wav {
public:
    // getters
    int getLength();

    // operator overloads
    int& operator[](int index);

    // length must be specified at time of construction
    wav(int sampleCount)
        : length(sampleCount), data(new int[sampleCount]) {};

    // copy constructor
    wav(const wav& copy);

    // destructor for deleting dynamic memory
    ~wav();

private:
    int* data;
    int length;
};

#endif