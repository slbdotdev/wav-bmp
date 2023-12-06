// CSC1061C01 Capstone Project
// bmp.cpp
// 2023-11-29
// Stephen Lee Belden

#include "bmp.h"

// copy constructor definition
bmp::bmp(const bmp& copy)
    : width(copy.width), height(copy.height), head(copy.head) {

    // Initialize
    const int pixelCount = width * height;
    data = new pixel[pixelCount];

    // Copy
    for (int i = 0; i < pixelCount; i++) {
        data[i] = copy.data[i];
    }
}


// Getter
const unsigned int bmp::getPixelCount() {
    return width * height;
}


// Write
void bmp::writeToFile(std::ofstream& outFile) {
    // write header first
    head.write(outFile);

    // write data in rows after header
    for (unsigned int rowIndex = 0; rowIndex < height; rowIndex++) {
        writeRow(rowIndex, outFile);
    }
}


// array operator overloading
const pixel& bmp::operator[](unsigned int index) {
    if (0 <= index && index < width * height)
        return data[index];
    throw std::out_of_range("bmp pixel index out of bounds");
}

const pixel& bmp::operator[](unsigned int index) const {
    if (0 <= index && index < width * height)
        return data[index];
    throw std::out_of_range("bmp pixel index out of bounds");
}


// destructor for dynamically allocated data
bmp::~bmp() {
    delete[] data;
}


// Private helper functions

// Write a single row of the image with proper padding according to
// .BMP filetype specification.
void bmp::writeRow(int rowIndex, std::ofstream& bmpFile) const {
    // local declaration
    int rowBytes = 0;

    // pointer arithmetic
    pixel* rowBaseAddress = data + (rowIndex * width);

    // write each pixel in this row
    for (unsigned int column = 0; column < width; column++) {
        // pointer arithmetic
        pixel* currentPixel = rowBaseAddress + column;

        // write colors in .BMP order
        bmpFile << currentPixel->b()
                << currentPixel->g()
                << currentPixel->r();
        rowBytes += 3;
    }

    // The length of each row of a valid BMP file must be a multiple of 4
    // bytes. Add null chars (bytes) to reach that multiple.
    while (rowBytes % 4 > 0) {
        bmpFile << (unsigned char)0u;
        rowBytes++;
    }
}
