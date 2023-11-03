// wav.cpp
// Definitions for class wav
// 2023-11-03
// Stephen L. Belden

#include "wav.h"

int wav::getLength()
{
	return length;
}

wav::~wav()
{
	delete[] data;
}
