// tests.h
// Functions for testing code during development
// 2023-11-03
// Stephen Lee Belden

#ifndef tests_h
#define tests_h

#include "wav.h"

namespace tests {
	// check everything
	void runAll();

	// individual tests
	void wavConstructorCopiesDeep();
}

#endif