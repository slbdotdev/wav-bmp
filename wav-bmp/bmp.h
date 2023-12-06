// CSC1061C01 Capstone Project
// bmp.h
// 2023-12-04
// Stephen Lee Belden

#ifndef bmp_h
#define bmp_h

#include <fstream>
#include <stdexcept>

#include "bmpHeader.h"
#include "pixel.h"

// Class for storing and writing a .bmp image file
class bmp {
public:
    // Constructor requires fixed height and width,
    // initializes pixels to black
    bmp(unsigned int w, unsigned int h)
        : width(w), height(h),
        data(new pixel[w * h]),
        head(bmpHeader(w, h)) {};

    // Copy constructor for deep copy of data referenced by pointer
    bmp(const bmp& copy);

    // Getters
    const unsigned int getPixelCount();

    // Write this bmp image to the specified output file
    void writeToFile(std::ofstream&);

    // operator overloads
    const pixel& operator[](unsigned int index);
    const pixel& operator[](unsigned int index) const;

    // Assignment is typically overloaded for classes with pointers,
    // but in this case the class contains constant member values,
    // so modifying an object after construction is not permitted.
    const bmp& operator=(const bmp&) = delete;

    // Destructor for deleting dynamic memory
    ~bmp();

protected:
    // It is important for the width and height of the image to be
    // constant, because these values are used to initialize the size
    // of the data array, to determine row boundaries, for array bounds
    // checking, and in the header.
    const unsigned int width;  // non-negative column count
    const unsigned int height; // non-negative row count
    const bmpHeader head;      // .BMP file format header
    pixel* data;               // contiguous set of pixels

private:
    // Private helper functions
    void writeRow(int rowIndex, std::ofstream& bmpFile) const;
};

#endif bmp_h
