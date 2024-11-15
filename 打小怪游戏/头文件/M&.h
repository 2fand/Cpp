#pragma once
#include <iostream>
using namespace std;
#include "moster.h"
class Mand: public moster {
private:
	bool mblr;//朝向(0< 1>)
public:
	void set(vector<trir>* v = NULL, char** cpp = NULL, int iheal = 3, map<char**, WASD>* = NULL, char** = NULL, char(*)[11][11] = NULL, int = 0, int = 0, bool b = 0, bool = 0);//设置怪物M&的一些属性
	Mand();//构造函数
	void mosterdo();//执行怪物M&要做的事
	char getm();//获取怪物M&的类型
};
