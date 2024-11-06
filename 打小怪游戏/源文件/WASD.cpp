#include <iostream>
using namespace std;
#include "WASD.h"
WASD& operator++(WASD& w) {
	WASD warr[5] = { W,A,S,D,E };
	w < E && (w = warr[w + 1]);
	return w;
}