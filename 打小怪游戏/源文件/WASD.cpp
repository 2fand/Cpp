#include <iostream>
using namespace std;
#include "WASD.h"
WASD& operator++(WASD& w) {
	WASD warr[5] = { W,A,S,D,E };//把WASD枚举类型的每一种东西都转化成数字
	w < E && (w = warr[w + 1]);//warr[w + 1](WASD) == w + 1(int)
	return w;
}
