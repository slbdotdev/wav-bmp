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

	// test for address difference
	assert(&a[0] != &b[0]);

	// wav destructor deletes data when objects go out of scope
}
