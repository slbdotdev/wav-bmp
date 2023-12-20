// CSC1061C01 Capstone Project
// bmpHeader.cpp
// 2023-12-05
// Stephen Lee Belden

#include "bmpHeader.h"

// Writes this header to bmpFile
void bmpHeader::write(std::ofstream& bmpFile) const {
    // Write bitmap signature bytes
    bmpFile << 'B' << 'M';

    // Remaining writes can not use operator << because it does not
    // respect the size of variables.

    // Size of whole file
    bmpFile.write(reinterpret_cast<const char*>(&totalFileSize),
        sizeof(totalFileSize));

    // Data offset information
    bmpFile.write(reinterpret_cast<const char*>(&reservedBytes),
        sizeof(reservedBytes));
    bmpFile.write(reinterpret_cast<const char*>(&bytesInHeader),
        sizeof(bytesInHeader));

    // Info header section
    bmpFile.write(reinterpret_cast<const char*>(&sizeOfInfoHeader),
        sizeof(sizeOfInfoHeader));

    // Image dimensions
    bmpFile.write(reinterpret_cast<const char*>(&width), sizeof(width));
    bmpFile.write(reinterpret_cast<const char*>(&height), sizeof(height));

    // Color settings
    bmpFile.write(reinterpret_cast<const char*>(&numberOfColorPlanes),
        sizeof(numberOfColorPlanes));
    bmpFile.write(reinterpret_cast<const char*>(&colorDepth),
        sizeof(colorDepth));

    // Image data settings
    bmpFile.write(reinterpret_cast<const char*>(&compressionMethod),
        sizeof(compressionMethod));
    bmpFile.write(reinterpret_cast<const char*>(&rawBitmapDataSize),
        sizeof(rawBitmapDataSize));

    // Real-world size (for printing)
    bmpFile.write(reinterpret_cast<const char*>(&horizontalPrintResolution),
        sizeof(horizontalPrintResolution));
    bmpFile.write(reinterpret_cast<const char*>(&verticalPrintResolution),
        sizeof(verticalPrintResolution));

    // Color palate lookup table information (unused)
    bmpFile.write(reinterpret_cast<const char*>(&colorTableEntries),
        sizeof(colorTableEntries));
    bmpFile.write(reinterpret_cast<const char*>(&importantColors),
        sizeof(importantColors));
}


// Returns total size of BMP file given a specified width and height.
// Calculates padding. Each row must be a multiple of 4 bytes.
unsigned int bmpHeader::calculateSize(const int width, const int height) {
    unsigned int bytesInRow = width * bytesPerPixel;
    while (bytesInRow % 4 > 0) bytesInRow++;
    unsigned int bytesInBody = bytesInRow * height;
    return bytesInHeader + bytesInBody;
}
