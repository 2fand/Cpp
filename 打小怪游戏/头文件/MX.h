#pragma once
#include <iostream>
using namespace std;
#include "moster.h"
class MX : public moster {
private:
	char** m_pcpp;//玩家的地点，不用xy坐标
	char(*m_strmap)[11][11];//地牢的指针
	char m_strmapr[11][11];//刚刚创建完成之后的地牢
	char m_cc;//盖住的块
	pair<int, int>pxy;//怪物的xy坐标
	bool setb;//帮助设置怪物的一些属性
public:
	MX();//构造函数
	void set(vector<trir>* v = NULL, char** cpp = NULL, int iheal = 3, map<char**, WASD>* = NULL, char** pcpp = NULL, char(*strmap)[11][11] = NULL, int = 0, int = 0, bool = 0, bool = 0);//设置怪物MX的一些属性
	void mosterdo();//执行怪物MX要做的事
	void exset(char strmapr[11][11]);//额外设置怪物MX的一些属性
	char getm();//获取怪物MX的类型
	char getm(bool);//获取怪物MX的盖住的块
};
