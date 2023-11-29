// CSC1061C01 Capstone Project
// wav.h
// 2023-11-03
// Stephen Lee Belden

#ifndef wav_h
#define wav_h

// Class for reading and storing .wav audio file data
class wav {
public:
    // getters
    int getLength();

    // operator overloads
    int& operator[](int index);

    // Assignment is typically overloaded for classes with pointers,
    // but in this case the class is designed to be immutable,
    // so modifying an object after construction is not permitted.
    const wav& operator=(const wav&) = delete;

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