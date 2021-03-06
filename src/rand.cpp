#include <stdlib.h> 
#include "rand.h"

#define UINT_MAX   4294967295U
float getRand() {
	static unsigned ix = rand() % 4294967295 + 1;
	ix = ix * 69069U + 1;
	return ix / ((double)UINT_MAX + 1.0);
}

float getRandInRange(float low, float high) {
	float tmp = getRand();
	float diff = high - low;
	return low + diff * tmp;
}
