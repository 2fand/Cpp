#pragma once
#include <iostream>
using namespace std;
#ifndef onceb
#define onceb
enum WASD {
	W,
	A,
	S,
	D,
	E
};
WASD& operator++(WASD& w);
#endif