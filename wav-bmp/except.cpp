#include "except.h"

const char* option_not_recognised::what() {
    return "Option not recognized, try again.\n\n";
}

const char* invalid_input::what() {
    return "Input not valid, try again.\n\n";
}
