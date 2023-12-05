// CSC1061C01 Capstone Project
// bmp.h
// 2023-12-04
// Stephen Lee Belden

#ifndef bmp_h
#define bmp_h

#include <stdexcept>

#include "pixel.h"

// Class for storing and writing a .bmp image file
class bmp {
public:
    // Constructor with size only, for testing, all pixels black
    bmp(unsigned int w, unsigned int h)
        : width(w), height(h), data(new pixel[w * h]) {};

    // Copy constructor for deep copy of data referenced by pointer
    bmp(const bmp& copy);

    // Getters
    const unsigned int getPixelCount();

    // operator overloads
    const pixel& operator[](int index);
    const pixel& operator[](int index) const;

    // Assignment is typically overloaded for classes with pointers,
    // but in this case the class contains constant member values,
    // so modifying an object after construction is not permitted.
    const bmp& operator=(const bmp&) = delete;

    // Destructor for deleting dynamic memory
    ~bmp();

private:
    const unsigned int width;  // non-negative column count
    const unsigned int height; // non-negative row count
    pixel* data;               // contiguous set of pixels
};

#endif bmp_h