// CSC1061C01 Capstone Project
// pixel.h
// 2023-12-04
// Stephen Lee Belden

#ifndef pixel_h
#define pixel_h

// Class for holding the color of a single pixel
class pixel {
public:
    // Default constructor creates a blank black pixel
    pixel() : red(0), gre(0), blu(0) {};

    // Custom constructor is a simple initialization
    pixel(unsigned char r, unsigned char g, unsigned char b)
        : red(r), gre(g), blu(b) {};

    // Getters
    const unsigned char r() const;
    const unsigned char g() const;
    const unsigned char b() const;

private:
    // RBG pixel values are single bytes from 0 to 255
    unsigned char red;
    unsigned char gre;
    unsigned char blu;
};

#endif pixel_h