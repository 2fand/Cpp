#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "Player.h"
#include "moster.h"
class MO : public moster {
private:
	WASD m_wasd;//方向
	map<char**, WASD>m_m;//[strmap point, wasd]...
	pair<int, int> m_pxy;//怪物 xy坐标
	static pair<int, int> s_m_pxy;//玩家 xy坐标
	int imove;//追踪的时候充当定时器用，每到这个数模MOWAIT这个宏加1的结果为宏MOWAIT，就开始移动
public:
	void set(vector<trir>* v = NULL, char** cpp = NULL, int iheal = 3, map<char**, WASD>* m = NULL, char** = NULL, char(*)[11][11] = NULL, int ix = 0, int iy = 0, bool = 0, bool = 0);//设置怪物MO的一些属性
	MO();//构造函数
	void set_s_pxy(int ix, int iy);//监听玩家的xy坐标
	void mosterdo();//执行怪物MO要做的事
	char getm();//获取怪物MO的类型
};
