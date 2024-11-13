#pragma once
#include <iostream>
using namespace std;
#include "Player.h"
#include "WASD.h"
#include <map>
class moster {
protected:
	char** m_cpp;//怪物的位置
	int m_iheal;//怪物的血量数
	vector<trir>* m_v;//指向玩家射出的子弹
	char* tempcp;//用于在移动怪物的位置的时候防出bug
public:
	moster();//moster抽象基类的构造函数
	virtual void set(vector<trir>* v = NULL, char** cpp = NULL, int iheal = 3, map<char**, WASD>* = NULL, char** = NULL, char(*)[11][11] = NULL, int = 0, int = 0, bool = 0, bool = 0);//设置怪物的一些属性
	void hunt();//受伤函数
	int getheal();//获取怪物的血量数
	virtual void mosterdo() = 0;//执行每种怪物要做的事
	virtual char getm() = 0;//获取怪物的类型，用多态实现
	char*& getcp();//获取怪物的位置
};
