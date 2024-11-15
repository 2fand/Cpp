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
WASD& operator++(WASD& w);//枚举WASD类型数据的前置++，无后置++
#endif
