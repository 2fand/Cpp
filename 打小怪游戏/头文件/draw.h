#pragma once
#include <iostream>
using namespace std;
struct draw {
	int iy;//画“#”的画笔起始y坐标
	int ix;//画“#”的画笔起始x坐标
	int iwalk;//画笔往哪个方向走几步
	bool brd;//画壁画的方向(0> 1v)
};
