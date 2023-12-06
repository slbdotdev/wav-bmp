// CSC1061C01 Capstone Project
// wavformSettings.h
// 2023-12-04
// Stephen Lee Belden

#ifndef except_h
#define except_h

#include <stdexcept>
#include <string>

// Custom exception classes for input prompting
class option_not_recognised : public std::exception {
public:
    option_not_recognised() {};
    const char* what();
};

class invalid_input : public std::exception {
public:
    invalid_input() {};
    const char* what();
};

#endif