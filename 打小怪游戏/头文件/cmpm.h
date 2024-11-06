#pragma once
#ifndef oncec
#define oncec
#include <iostream>
using namespace std;
#include "moster.h"
class cmpm {
public:
	bool operator()(moster* mp, moster* mpa);
};
#endif