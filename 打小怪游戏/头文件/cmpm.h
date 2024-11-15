#pragma once
#ifndef oncec
#define oncec
#include <iostream>
using namespace std;
#include "moster.h"
class cmpm {
public:
	bool operator()(moster* mp, moster* mpa);//用于升序排列的假函数
};
#endif
