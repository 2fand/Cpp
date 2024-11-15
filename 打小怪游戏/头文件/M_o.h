#pragma once
#include <iostream>
#include "moster.h"
using namespace std;
class M_o : public moster {
private:
	void near();//检测是否旁边有墙
public:
	void mosterdo();//执行怪物M_o要做的事
	char getm();//获取怪物M_o的类型
};
