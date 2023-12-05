// CSC1061C01 Capstone Project
// bmpHeader.h
// 2023-12-05
// Stephen Lee Belden

#ifndef bmpheader_h
#define bmpheader_h

#include <fstream>

// Class for storing and writing all information needed for a standard
// .BMP file format header. Written at the start of every image file.
class bmpHeader {
public:
    // Constructor creates immutable object.
    bmpHeader(unsigned int w, unsigned int h)
        : width(w), height(h), totalFileSize(calculateSize(w, h)) {};

    // Write the contents of this object to outFile.
    void write(std::ofstream& bmpFile) const;

private:
    // Private helper function.
    // Static for use in constructor initialization.
    static unsigned int calculateSize(const unsigned int width,
        const unsigned int height);

    // Values composing a header, listed in header specification order
    const static unsigned int bytesInHeader = 54;
    const static unsigned int bytesPerPixel = 3;
    const unsigned int totalFileSize; // non-static
    const static unsigned int reservedBytes = 0;
    const static unsigned int sizeOfInfoHeader = 40;
    const int width; // non-static
    const int height; // non-static
    const static unsigned short numberOfColorPlanes = 1; // must be 1
    const static unsigned short colorDepth = 24; // 3 byes per pixel
    const static unsigned int compressionMethod = 0; // no compression
    const static unsigned int rawBitmapDataSize = 0; // ignored
    const static int horizontalPrintResolution = 3780; // in pixels per meter
    const static int verticalPrintResolution = 3780; // in pixels per meter
    const static unsigned int colorTableEntries = 0; // no color table
    const static unsigned int importantColors = 0; // no color table
};

#endif bmpheader_h