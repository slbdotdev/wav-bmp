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
    bmpFile.write((char*)&totalFileSize, sizeof(totalFileSize));

    // Data offset information
    bmpFile.write((char*)&reservedBytes, sizeof(reservedBytes));
    bmpFile.write((char*)&bytesInHeader, sizeof(bytesInHeader));

    // Info header section
    bmpFile.write((char*)&sizeOfInfoHeader, sizeof(sizeOfInfoHeader));

    // Image dimensions
    bmpFile.write((char*)&width, sizeof(width));
    bmpFile.write((char*)&height, sizeof(height));

    // Color settings
    bmpFile.write((char*)&numberOfColorPlanes, sizeof(numberOfColorPlanes));
    bmpFile.write((char*)&colorDepth, sizeof(colorDepth));

    // Image data settings
    bmpFile.write((char*)&compressionMethod, sizeof(compressionMethod));
    bmpFile.write((char*)&rawBitmapDataSize, sizeof(rawBitmapDataSize));

    // Real-world size (for printing)
    bmpFile.write((char*)&horizontalPrintResolution,
        sizeof(horizontalPrintResolution));
    bmpFile.write((char*)&verticalPrintResolution,
        sizeof(verticalPrintResolution));

    // Color palate lookup table information (unused)
    bmpFile.write((char*)&colorTableEntries, sizeof(colorTableEntries));
    bmpFile.write((char*)&importantColors, sizeof(importantColors));
}


// Returns total size of BMP file given a specified width and height.
// Calculates padding. Each row must be a multiple of 4 bytes.
unsigned int bmpHeader::calculateSize(const unsigned int width,
    const unsigned int height) {
    unsigned int bytesInRow = width * bytesPerPixel;
    while (bytesInRow % 4 > 0) bytesInRow++;
    unsigned int bytesInBody = bytesInRow * height;
    return bytesInHeader + bytesInBody;
}
