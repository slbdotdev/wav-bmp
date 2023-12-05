// CSC1061C01 Capstone Project
// bmp.cpp
// 2023-11-29
// Stephen Lee Belden

#include "bmp.h"

// copy constructor definition
bmp::bmp(const bmp& copy)
    : width(copy.width), height(copy.height) {

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

void bmp::writeToFile(std::ofstream& outFile) const {
    // write header first
    writeHeader(outFile);

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

// Write a header with proper information according to .BMP file type.
void bmp::writeHeader(std::ofstream& bmpFile) const {
    // Bitmap signature bytes
    const char B = 'B';
    const char M = 'M';
    bmpFile.write((char*)&B, sizeof(uint8_t));
    bmpFile.write((char*)&M, sizeof(uint8_t));

    // Bitmap file size in bytes
    const uint32_t bytesInHeader = 54;
    const uint32_t bytesPerPixel = 3;
    // Each row is padded out to a multiple of 4 bytes.
    uint32_t bytesInRow = width * bytesPerPixel;
    while (bytesInRow % 4 > 0) bytesInRow++;
    uint32_t bytesInBody = bytesInRow * height;
    uint32_t size = bytesInHeader + bytesInBody;
    bmpFile.write((char*)&size, sizeof(uint32_t));

    // Data offset information
    uint32_t reservedBytes = 0;
    bmpFile.write((char*)&reservedBytes, sizeof(uint32_t));
    uint32_t offset = bytesInHeader;
    bmpFile.write((char*)&offset, sizeof(uint32_t));

    // Info header section
    const uint32_t sizeOfInfoHeader = 40;
    bmpFile.write((char*)&sizeOfInfoHeader, sizeof(uint32_t));

    // Image dimensions
    int32_t w = static_cast<int32_t>(width);
    int32_t h = static_cast<int32_t>(height);
    bmpFile.write((char*)&w, sizeof(int32_t));
    bmpFile.write((char*)&h, sizeof(int32_t));

    // Color settings
    const uint16_t numberOfColorPlanes = 1; // must be 1
    const uint16_t colorDepth = 24; // 3 byes per pixel
    bmpFile.write((char*)&numberOfColorPlanes, sizeof(uint16_t));
    bmpFile.write((char*)&colorDepth, sizeof(uint16_t));

    // Image data settings
    const uint32_t compressionMethod = 0; // no compression
    const uint32_t rawBitmapDataSize = 0; // generally ignored
    bmpFile.write((char*)&compressionMethod, sizeof(uint32_t));
    bmpFile.write((char*)&rawBitmapDataSize, sizeof(uint32_t));

    // Real-world size (for printing)
    const int32_t horizontalResolution = 3780; // in pixel per meter
    const int32_t verticalResolution = 3780; // in pixel per meter
    bmpFile.write((char*)&horizontalResolution, sizeof(int32_t));
    bmpFile.write((char*)&verticalResolution, sizeof(int32_t));

    // Color palate lookup table information (unused)
    const uint32_t colorTableEntries = 0; // not used in this implementation
    const uint32_t importantColors = 0; // not used in this implementation
    bmpFile.write((char*)&colorTableEntries, sizeof(uint32_t));
    bmpFile.write((char*)&importantColors, sizeof(uint32_t));
}

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

        unsigned char red = currentPixel->r();
        unsigned char blu = currentPixel->g();
        unsigned char gre = currentPixel->b();
        bmpFile.write((char*)&red, sizeof(unsigned char));
        bmpFile.write((char*)&gre, sizeof(unsigned char));
        bmpFile.write((char*)&blu, sizeof(unsigned char));
        rowBytes += 3;
    }

    // The length of each row of a valid BMP file must be a multiple of 4
    // bytes. Add null chars (bytes) to reach that multiple.
    while (rowBytes % 4 > 0) {
        unsigned char blank = 0u;
        bmpFile.write((char*)&blank, sizeof(unsigned char));
        rowBytes++;
    }
}
