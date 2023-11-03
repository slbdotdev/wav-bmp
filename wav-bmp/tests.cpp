// tests.cpp
// Definitions for tests
// 2023-11-03
// Stephen Lee Belden

#include <cassert>

#include "tests.h"

void tests::runAll() {
	wavConstructorCopiesDeep();
}

void tests::wavConstructorCopiesDeep() {
	int samples = 3;

	// create and copy
	wav a(samples);
	wav b(a);

	// modify only one
	a[0] = 2121;

	// test
	assert(b[0] != 2121);

	// wav destructor deletes data when objects go out of scope
}
