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
    // respect the size of the variable.

    // Size of whole file
    bmpFile.write((char*)&totalFileSize, sizeof(unsigned int));

    // Data offset information
    bmpFile.write((char*)&reservedBytes, sizeof(unsigned int));
    bmpFile.write((char*)&bytesInHeader, sizeof(unsigned int));

    // Info header section
    bmpFile.write((char*)&sizeOfInfoHeader, sizeof(unsigned int));

    // Image dimensions
    bmpFile.write((char*)&width, sizeof(int));
    bmpFile.write((char*)&height, sizeof(int));

    // Color settings
    bmpFile.write((char*)&numberOfColorPlanes, sizeof(unsigned short));
    bmpFile.write((char*)&colorDepth, sizeof(unsigned short));

    // Image data settings
    bmpFile.write((char*)&compressionMethod, sizeof(unsigned int));
    bmpFile.write((char*)&rawBitmapDataSize, sizeof(unsigned int));

    // Real-world size (for printing)
    bmpFile.write((char*)&horizontalPrintResolution, sizeof(int));
    bmpFile.write((char*)&verticalPrintResolution, sizeof(int));

    // Color palate lookup table information (unused)
    bmpFile.write((char*)&colorTableEntries, sizeof(unsigned int));
    bmpFile.write((char*)&importantColors, sizeof(unsigned int));
}


// Returns total size of BMP file given a specified width and height.
// Calculates padding. Each row must be a multiple of 4 bytes.
unsigned int bmpHeader::calculateSize(const unsigned int width,
    const unsigned int height) {
    uint32_t bytesInRow = width * bytesPerPixel;
    while (bytesInRow % 4 > 0) bytesInRow++;
    uint32_t bytesInBody = bytesInRow * height;
    return bytesInHeader + bytesInBody;
}
