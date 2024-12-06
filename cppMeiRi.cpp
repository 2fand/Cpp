#include <iostream>
using namespace std;
#include <climits>
#include <deque>
#include <stack>
#include <set>
#include <numeric>
#include <vector>
#include <algorithm>
#include <list>
/*
//MX.h
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
//MO.h
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
//M&.h
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
//M^.h
#pragma once
#include <iostream>
using namespace std;
#include "moster.h"
class MUD : public moster {
private:
	bool mblr;//水平朝向(0< 1>)
	bool mbud;//垂直朝向(0^ 1v)
public:
	MUD();//构造函数
	void set(vector<trir>* v = NULL, char** cpp = NULL, int iheal = 3, map<char**, WASD>* = NULL, char** = NULL, char(*)[11][11] = NULL, int = 0, int = 0, bool b = 0, bool ba = 0);//设置怪物M^的一些属性
	void mosterdo();//执行怪物M^要做的事
	char getm();//获取怪物M^的类型
};
//M+.h
#pragma once
#include <iostream>
using namespace std;
#include "moster.h"
#include <vector>
class Mplus : public moster {
public:
	void mosterdo();//执行小BOSSM+要做的事
	char getm();//获取小BOSSM+的类型
};
//M_o.h
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
//WASD.h
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
//isvp.h
#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "moster.h"
struct isv {//地牢怪物
	string str;//判断怪物的生成
	vector<moster*> vmp;//生成的怪物
	int id;//地牢怪物所代表的id
};
//Cmp.h
#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;
class cmp {
public:
	bool operator()(trir t, trir ta);//用于升序排列的假函数
};
//cmpm.h
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
*///“在所有头文件都添加一点注释”^
/*
//Player.cpp
#include <iostream>
#include "Player.h"
#include "cmp.h"
#include <algorithm>
#include <Windows.h>
using namespace std;
//构造函数
Player::Player(){
	ijh = 0;
	blr = 1;
}
//打印地牢函数
void Player::printmap(const char strmap[11][11], const bool bwait, const int iunmd) {
	int i = 0;
	int ia = 0;
	cout << "\033[" << (!bwait || 5 < iheal ? "32;1m" : 2 < iheal ? "33m" : "31;1m") << "P * " << iheal << "\033[0m" << endl << endl << endl;//打印玩家的血量
	for (cout << "-----------@" << endl; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : 'v' == strmap[i][ia] ? "36m" : '&' == strmap[i][ia] || '^' == strmap[i][ia] || 'o' == strmap[i][ia] || 'O' == strmap[i][ia] || 'X' == strmap[i][ia] ? "31;1m" : '+' == strmap[i][ia] || '#' == strmap[i][ia] ? "33m" : '@' == strmap[i][ia] ? "33m" : 'P' == strmap[i][ia] && iunmd ? "30;1m" : "0m") << strmap[i][ia] << "\033[0m";///打印地图
		}
		cout << "|" << endl;//竖的外边框
	}
	cout << "-----------@" << endl;//底下的的外边框
}
//打印地牢函数(右偏版本)
void Player::printmap(char(*strmap)[11][11], const bool bwait, const int ir, const int iunmd) {
	int i = 0;
	int ia = 0;
	cout << "\033[" << (!bwait || 5 < iheal ? "32;1m" : 2 < iheal ? "33m" : "31;1m") << "P * " << iheal << "\033[0m" << endl << endl << endl;//打印血量
	for (cout << "-----------@" << endl; i < 11; i++) {
		for (ia = ir; 11 > ia - ir; ia++) {
			21 > ia && ia >= 12 && i && 10 != i && ((*strmap)[i][ia % 11] = ' ');//清空左边的墙(除边框)
			cout << "\033[" << ('P' == (*strmap)[i][ia % 11] && iunmd ? "40;1m" : "0m") << (*strmap)[i][ia % 11] << "\033[0m";//打印右偏之后的地图
		}
		cout << "|" << endl;//竖的外边框
	}
	cout << "-----------@" << endl;//底下的的外边框
}//跳跃函数
void Player::jump(char** cpp) {
	10 == ix || '*' == (*cpp)[11] && (ijh = JUMPHIGH);
}
//左移函数
void Player::left_move(char** cpp) {
	(iy && '*' != *(*cpp - 1) && ((*cpp)--));
	blr = false;
}
//右移函数
void Player::right_move(char** cpp) {
	10 != iy && '*' != *(*cpp + 1) && ((*cpp)++);
	blr = true;
}
//用于设置或获得玩家的x坐标，y坐标或血量
int& Player::sgetxyhs(XYHS xyhsmode) {
	switch (xyhsmode) {
	case X:
		return ix;
		break;
	case Y:
		return iy;
		break;
	case HEAL:
		return iheal;
		break;
	default:
		break;
	}
}
//设置或获得玩家射出的子弹
vector<trir>* Player::sgetxyhs() {
	return &v;
}
//使玩家上升或下坠
void Player::upOrDown(char** cpp) {
	if (ijh > 0 && ix && '*' != (*cpp)[-11]) {//跳跃后
		ijh--, *cpp -= 11;
	}
	else if ('*' != (*cpp)[11] && (!ix || '*' == (*cpp)[-11])) {//撞墙或跳好后
		ijh = 0, *cpp += 11;
	}
	else if ('*' != (*cpp)[11] && 10 != ix) {//落下时
		*cpp += 11;
	}
	if (ijh > 0 && '*' == (*cpp)[11]) {//防磕头后还能跳
		ijh = 0;
	}
}
//射击函数
void Player::shoot(int& i, char** cpp) {
	if ((!i) && (iy && (!blr) || 10 != iy && blr)) {//检测冷却时间已过并且是否在地牢的边界射过
		v.push_back({ *cpp, iy, blr, 0 });
		i = 3;
	}
}
//子弹的移动函数
void Player::shootmove(const char(*strmap)[11][11], bool bmode) {
	if (bmode) {
		for (vector<trir>::iterator it = v.begin(); v.end() != it; it++) {
			(' ' == *it->cp || '@' == *it->cp) && (*it->cp = ' ');///编译显示之前子弹的移动
			if ('*' == *it->cp || it->bk || (!it->iy && (!it->b)) || (21 == it->iy && it->b)) {
				it->iy = -1;//子弹的销毁
			}
			if (0 <= it->iy) {
				it->cp -= (1 - it->b * 2);//子弹的移动
				it->iy -= (1 - it->b * 2);//子弹y坐标的移动
				(' ' == *it->cp || '@' == *it->cp) && (*it->cp = '@');//显示
			}
		}
	}
	else {
		sort(v.begin(), v.end(), cmp());//按子弹的y坐标进行升序排列
		while ((!v.empty()) && 0 > v.begin()->iy) {
			v.erase(v.begin());//销毁子弹
		}
	}
}
//M&.cpp
#include <iostream>
using namespace std;
#include "m&.h"
Mand::Mand() {
	this->set();
}
//vector<trir>* = NULL, char** = NULL, char** = NULL, pair<int, int>* = NULL, int = 0, int = 0, int = 3, bool = 0, bool = 0
void Mand::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*, char**, char(*)[11][11], int, int, bool b, bool) {
	m_v = v;
	m_cpp = cpp;
	m_iheal = iheal;
	mblr = b;
}
void Mand::mosterdo() {
	'*' != **m_cpp && (**m_cpp = ' ');//便于移动之后的显示
	if (!mblr && '*' == (*m_cpp)[-1]) {//如果怪物M&往左移动，并且左边有墙
		mblr = 1;//怪物M&就往右移动
	}
	else if (mblr && '*' == (*m_cpp)[1]) {//如果怪物M^往右移动，并且左边有墙
		mblr = 0;//怪物M&就往左动
	}//撞墙换方向
	tempcp = *m_cpp;//防指针的链式带动
	m_cpp = NULL;
	'*' != tempcp[-(1 - 2 * mblr)] && (tempcp -= (1 - 2 * mblr));//左右移
	'*' != tempcp[11] && (tempcp += 11);//下落
	m_cpp = &tempcp;
	//后面main函数中用Mshow函数使见
}//撞墙换方向，会自然下落
char Mand::getm() {
	return '&';
}
//M^.cpp
#include <iostream>
using namespace std;
#include "m^.h"
//构造函数
MUD::MUD() {
	set();
}
//M^的设置函数
void MUD::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*, char**, char(*)[11][11], int, int, bool b, bool ba) {
	m_v = v;//vector<trir>* = NULL, char** = NULL, char** = NULL, pair<int, int>* = NULL, int = 0, int = 0, int = 3, bool = 0, bool = 0
	m_cpp = cpp;
	m_iheal = iheal;
	mblr = b;
	mbud = ba;
}
void MUD::mosterdo() {
	'*' != **m_cpp && (**m_cpp = ' ');//便于移动之后的显示
	if (!mblr && '*' == (*m_cpp)[-1]) {//如果怪物M^往左移动，并且左边有墙
		mblr = 1;//怪物M^就往右移动
	}
	else if(mblr && '*' == (*m_cpp)[1]){//如果怪物M^往右移动，并且右边有墙
		mblr = 0;//怪物M^就往左移动
	}//撞墙换方向
	tempcp = *m_cpp;//防指针的链式带动
	m_cpp = NULL;
	'*' != tempcp[-(1 - 2 * mblr)] && (tempcp -= (1 - 2 * mblr));//左右移
	if (mbud && '*' == tempcp[11]) {//如果怪物M^往下移动，并且下边有墙
		mbud = 0;//怪物M^就往上落
	}
	else if (!mbud && '*' == tempcp[-11]) {//如果怪物M^往上落，并且上边有墙
		mbud = 1;//怪物M^就往下落
	}//碰地会反转
	'*' != tempcp[-(11 * (1 - 2 * mbud))] && (tempcp -= 11 * (1 - 2 * mbud));//上下落
	m_cpp = &tempcp;
	//后面main函数中Mshow函数使见
}//撞墙换方向，碰地会反落
char MUD::getm() {
	if (mbud) {
		return 'v';
	}
	else {
		return '^';
	}
}
//MO.cpp
#include <iostream>
using namespace std;
#include "MO.h"
#define NNEG(A, B) ((A) < (B) ? 1 : (A) > (B) ? -1 : 0)//判断宏
#define MOWAIT 1//怪物等待的回合数
pair<int, int> MO::s_m_pxy = {0, 0};//玩家坐标的初始化
//构造函数
MO::MO() {
	set();
}
//MO的设置函数
void MO::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*m, char**, char(*)[11][11], int ix, int iy, bool, bool) {
	m_v = v;//vector<trir>* = NULL, char** = NULL, pair<int, int>* = NULL, int = 0, int = 0, int = 3, bool = 0, bool = 0
	m_cpp = cpp;
	m_iheal = iheal;
	m_pxy.first = ix;
	m_pxy.second = iy;
	imove = 0;
	if (m) { 
		m_m = *m;
	}
}
void MO::mosterdo() {
	'*' != **m_cpp && (**m_cpp = ' ');//便于移动之后的显示
	tempcp = *m_cpp;//防指针的链式带动
	m_cpp = NULL;
	if (!m_m.empty()) {//沿路模式
		int arr[4] = { -11, -1, 11, 1 };//怪物MO可能会移动的四个方位
		for (map<char**, WASD>::iterator it = m_m.begin(); m_m.end() != it; it++) {//改变怪物MO的方向
			E != it->second && tempcp == *it->first && (m_wasd = it->second);
		}
		switch (tempcp += (arr[m_wasd]), m_wasd) {//怪物的移动与xy坐标的变化
		case W:
			m_pxy.second--;
			break;
		case A:
			m_pxy.first--;
			break;
		case S:
			m_pxy.second++;
			break;
		case D:
			m_pxy.first++;
			break;
		default:
			break;
		}
	}
	else {//追踪模式
		MOWAIT == imove % (MOWAIT + 1)/*如果MO等待了MOWAIT回合*/ && ('*' != *(tempcp + 11 * NNEG(m_pxy.first, s_m_pxy.first))/*并且垂直移动的方向上没有墙*/ && (tempcp += 11 * NNEG(m_pxy.first, s_m_pxy.first)/*那么怪物MO就往玩家垂直地移动*/, m_pxy.first += NNEG(m_pxy.first, s_m_pxy.first)/*怪物的x坐标也随之变化*/));//根据怪物的xy坐标和玩家的xy坐标来移动
		MOWAIT == imove++ % (MOWAIT + 1) && ('*' != *(tempcp + NNEG(m_pxy.second, s_m_pxy.second)/*并且水平移动的方向上没有墙*/) && (tempcp += NNEG(m_pxy.second, s_m_pxy.second)/*那么怪物MO就往玩家水平地移动*/, m_pxy.second += NNEG(m_pxy.second, s_m_pxy.second)/*怪物的y坐标也随之变化*/));
	}
	m_cpp = &tempcp;
}//遇向则转，看路前行（1），或追玩者（2）
//设置玩家的坐标
void MO::set_s_pxy(int ix, int iy) {
	s_m_pxy = { ix, iy };
}
char MO::getm() {
	return 'O';
}
//M_o.cpp
#include <iostream>
#include <ctime>
#include "M_o.h"
using namespace std;
void M_o::near() {
	int arr[8] = { -12, -11, -10, -1, 1, 10, 11, 12 };//根据向量来检测是否旁边有墙
	int i = 0;
	for (; i < 8; i++) {
		if ('*' == (*m_cpp)[arr[i]]) {
			m_iheal = -1;//去死，并生其他怪物
			break;
		}
	}
}
void M_o::mosterdo() {
	int arr[8] = { -12, -11, -10, -1, 1, 10, 11, 12 };//可能的移动方向
	int ir = 0;//随机数
	'*' != **m_cpp && (**m_cpp = ' ');//便于移动之后的显示
	tempcp = (near(), *m_cpp);//临时一级指针，无可用二级指针
	m_cpp = NULL;//防指针的链式移动
	'*' != tempcp[arr[ir = rand() % 8]] && (tempcp -= arr[ir]);//曾有bug点：一级指针会“带动”二级指针
	m_cpp = &tempcp;//移动
}//随便移动，有墙不动
char M_o::getm() {
	return 'o';
}
//M+.cpp
#include <iostream>
using namespace std;
#include "m+.h"
#include "M_o.h"
#include "Player.h"
void Mplus::mosterdo() {
	**m_cpp = '+';//后面根据**m_cpp的内容来执行summon方法
}
char Mplus::getm() {
	return '+';
}
//MX.cpp
#include <iostream>
using namespace std;
#include <cstring>
#include "mX.h"
//怪物MX的设置函数
void MX::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*, char** pcpp, char(*strmap)[11][11], int, int, bool, bool) {
	m_v = v;//vector<trir>* = NULL, char** = NULL, char** = NULL, pair<int, int>* = NULL, char(*)[11][11] = NULL,int = 0, int = 0, int = 3, bool = 0, bool = 0
	m_cpp = cpp;
	m_pcpp = pcpp;
	strmap && (m_strmap = strmap);
	m_iheal = iheal;
	setb = 1;
}
//怪物MX的额外设置函数
void MX::exset(char strmapr[11][11]) {
	memcpy(m_strmapr, strmapr, sizeof m_strmapr);
}
//构造函数
MX::MX() {
	set();
}
void MX::mosterdo() {
	vector<trir>::iterator it = m_v->begin();
	if (setb) {
		pxy = { (*m_cpp - &(*m_strmap)[0][0]) / 11, (*m_cpp - &(*m_strmap)[0][0]) % 11 };//设置怪物MX的坐标
		m_cc = m_strmapr[pxy.first][setb = 0, pxy.second];//设置盖住的块
	}
	for (; m_v->end() != it; it++) {
		if (*m_cpp == it->cp || *m_cpp == it->cp - (1 - it->b * 2)) {//如果怪物受伤了就停止这个循环
			break;
		}
	}
	if (m_iheal && (*m_cpp == *m_pcpp || m_v->end() != it)) {//如果刚才的这个循环停止了，并且还有生命且不在玩家的位置上
		tempcp = *m_cpp;//防指针的链式移动
		char* tempcpb = tempcp;
		bool tempb = 1;//防误覆盖空位
		m_cpp = NULL;
		do {
			tempb && m_v->end() != it && (*tempcp = ' ');//便于移动之后的显示
			tempcp = &(*m_strmap)[pxy.first = rand() % 9 + 1][pxy.second = rand() % 9 + 1];//怪物MX的移动

		} while ((tempcp == &(*m_strmap)[9][1] || '@' == (*m_strmap)[pxy.first][pxy.second] || '@' == (*m_strmap)[pxy.first][pxy.second - 1] || '@' == (*m_strmap)[pxy.first][pxy.second + 1] || tempcp == *m_pcpp || '*' == tempcp[-1] || '*' == tempcp[1] || 'X' == (tempcp)[-1] || 'X' == (tempcp)[1]) && (tempb = 0, 1));//如果满足上述的条件，就把误覆盖空位的“开关”启动
		m_cpp = &tempcp;
		*tempcpb = m_cc;
		('@' != m_strmapr[pxy.first][pxy.second] || 'X' != m_strmapr[pxy.first][pxy.second] && 'P' != m_strmapr[pxy.first][pxy.second]) && (m_cc = m_strmapr[pxy.first][pxy.second]);//记录盖住的块，不记录“@”子弹，“P”玩家和“X”怪物MX自己
	}
	//main函数使见
}//被玩家碰到传，受伤传(两旁有砖不传)，并见
char MX::getm() {
	return 'X';
}
char MX::getm(bool) {
	return m_cc;
}
//cmpm.cpp
#include <iostream>
#include "cmpM.h"
#include "moster.h"
using namespace std;
bool cmpm::operator()(moster* mp, moster* mpa) {
	return mp->getheal() < mpa->getheal();//比较两个怪物的生命值
}
//Cmp.cpp
#include <iostream>
#include "Cmp.h"
#include "Player.h"
using namespace std;
bool cmp::operator()(trir t, trir ta) {
	return t.iy < ta.iy;//比较两个子弹的y坐标
}
//WASD.cpp
#include <iostream>
using namespace std;
#include "WASD.h"
WASD& operator++(WASD& w) {
	WASD warr[5] = { W,A,S,D,E };//把WASD枚举类型的每一种东西都转化成数字
	w < E && (w = warr[w + 1]);//warr[w + 1](WASD) == w + 1(int)
	return w;
}
*///“游戏已正式做完，注释已全部添加”^
/*
//Game.cpp
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>
#include <Windows.h>
#include "draw.h"
enum difficulty {//难度
	EASY,
	NORMAL,
	HARD,
	LIMIT
};
void MShow(moster*& mp) {
	('X' == mp->getm() || '*' != *mp->getcp()) && (*mp->getcp() = mp->getm());//左边条件防出bug
}
void del(moster*& mp) {
	delete mp;
}
void delvo(M_o*& mp) {
	delete mp;
}
void setMempty(moster*& mp) {
	'*' != *mp->getcp() && (*mp->getcp() = ' ');//左边条件也防出bug
}
void start(int ichoose) {//开始时打印大字函数
	switch (ichoose) {
	case 14:
		cout << "      *                  *          *           " << endl;
	case 13:
		cout << "      *                  *          * ********  " << endl;
	case 12:
		cout << "      *  ********        *          *  *     *  " << endl;
	case 11:
		cout << "   ******    *           *        * **  *   *   " << endl;
	case 10:
		cout << "      *      *           *        * * *  * *    " << endl;
	case 9:
		cout << "      * *    *        *  *  *     * *     **    " << endl;
	case 8:
		cout << "     ***     *       **  *   *   *  *   **  *   " << endl;
	case 7:
		cout << "   ** *      *      *    *    *     * **  *  ** " << endl;
	case 6:
		cout << "      *      *     *     *    **    *     *     " << endl;
	case 5:
		cout << "      *      *    *      *     *    *     *     " << endl;
	case 4:
		cout << "      *      *           *          *  *******  " << endl;
	case 3:
		cout << "      *      *           *          *     *     " << endl;
	case 2:
		cout << "      *      *           *          *     *     " << endl;
	case 1:
		cout << "    * *    * *         * *          * ********* " << endl;
	case 0:
		cout << "     *      *           *           *           " << endl;
	default:
		break;
	}
} 
void win(int ichoose) {//胜利后打印函数
	switch (ichoose) {
	case 14:
		cout << "      *   *            *           *  *                       *  *              *                     " << endl;
	case 13:
		cout << "      *   *       ************     *  *                       *  *        ************** *************" << endl;
	case 12:
		cout << "   ************        *           *  *                       *  *         *                        * " << endl;
	case 11:
		cout << "      *   *        **********     *  ********                *  ********   ************            *  " << endl;
	case 10:
		cout << "      *   *                       *  *      *                *  *      *    *       *            **   " << endl;
	case 9:
		cout << "  **************   **********    ** *      *                ** *      *     *********          **     " << endl;
	case 8:
		cout << "      *    *       *        *   * *     *                  * *     *                           *      " << endl;
	case 7:
		cout << "     *  *   *      **********     *     *                    *     *      *** ***** ***        *      " << endl;
	case 6:
		cout << "    *   *    *       *    *       *   * * *                  *   * * *    * * *   * * *        *      " << endl;
	case 5:
		cout << "  **    *     ** **************   *   * *  *      **         *   * *  *   *** *   * * *        *      " << endl;
	case 4:
		cout << "     *  **  *                     *  *  *  **     **         *  *  *  **  * * * * * ***        *      " << endl;
	case 3:
		cout << "    *   * *  *     *********      * *   *   *      *         * *   *   *  *** * * * * *        *      " << endl;
	case 2:
		cout << "   *    * *  *     *       *      *     *         *          *     *      * *   *   * *        *      " << endl;
	case 1:
		cout << "      * *          *********      *   * *        *           *   * *      * *  * * *  **     * *      " << endl;
	case 0:
		cout << "       *           *       *      *    *                     *    *      *  * *   *    *      *       " << endl;
	default:
		break;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	char strmap[11][11] = {//地牢图
		'*','*','*','*','*','*','*','*','*','*','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'P',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*','*','*','*','*','*','*','*','*','*','*',
	};
	bool ba = 1;
	bool bb = 1;
	bool bc = 1;
	char ch = 0;
	int iunmd = 0;
	vector<M_o*>vo;//小BOSS战时需要
	vector<draw>vmd[5] = { {{5,2,6,1}}, {{3,2,4,0}, {7,2,3,1}, {3,5,4,0}, {3,5,3,1}, {3,8,4,0}}, {{3,2,4,0},{3,5,4,0},{3,8,4,0},{7,2,6,1}}, {{3,2,3,1},{3,5,4,0},{7,2,6,1}}, {{5,3,4,1},{3,5,4,0}} };//<-画“#”时所需要的数组
	multimap<int, int>mwasd[4] = { {{9,1},{9,3},{3,3},{5,3},{7,3},{9,3},{8,4},{8,8},{6,8},{4,8}}, {{2,3},{9,9},{3,8},{5,8},{7,8},{9,2}}, {{2,2},{2,7},{1,9}}, {{1,1},{2,4},{4,3},{6,3},{8,3},{8,7}} };//<-画“#”时所需要的数组
	vo.reserve(99999);
	int i = 0;
	int temparr[6] = { 4, 8, 12, 15, 17, 18 };
	int ia = rand() % 10 + 1;// 后：+1 +1 +1 +1 +2 +2 +2 +2 +3 +3 +3 +3 +4 +4 +4 +5 +5 +6
	int tempir = rand() % 22;
	for (i = 0; i < 6; i++) {
		if (tempir < temparr[i]) {
			ia += (i + 1);
			break;
		}
	}
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char**, WASD>m[3];
	map<char**, WASD>em;//追踪map
	char* cparr[45] = { NULL };
	char** cpp = cparr;
	for (WASD w = W; E != w; ++w) {//第5地牢的怪物移动路线
		switch (w) {
		case W:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[10 - i][i];
				m[0].insert({cpp++, W});
			}
			break;
		case A:
			for (i = 6; i < 10; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, A});
			}
			break;
		case S:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][10 - i];
				m[0].insert({cpp++, S});
			}
			break;
		case D:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, D});
			}
			break;
		default:
			break;
		}
		for (multimap<int, int>::iterator it = mwasd[w].begin(); mwasd[w].end() != it; it++) {
			*cpp = &strmap[it->first][it->second];
			m[1].insert({ cpp++, w });
		}
	}
	const int arr[4] = { 6,9,1,5 };
	for (i = 0; i < 4; i++) {
		*cpp = &strmap[arr[i]][i % 2 + 1];
		m[2].insert({ cpp++, (WASD)(i / 2 * 2) });//注意：i / 2 * 2 != i
	}
	char strmapr[11][11];
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	vism.reserve(1000);//防bug出
	char* strcp[47] = { &strmap[9][5], &strmap[9][7], &strmap[9][3], &strmap[1][5], &strmap[1][5], &strmap[6][1], &strmap[4][9], &strmap[6][8], &strmap[3][3], &strmap[4][3], &strmap[5][3], &strmap[6][3], &strmap[7][3], &strmap[8][3], &strmap[9][3], &strmap[4][5], &strmap[5][4], &strmap[5][5], &strmap[5][6], &strmap[6][5], &strmap[1][5], &strmap[1][5], &strmap[9][5], &strmap[9][5], &strmap[1][9], &strmap[1][1], &strmap[8][2], &strmap[2][8], &strmap[8][8], &strmap[2][2], &strmap[5][5], &strmap[1][1], &strmap[2][2], &strmap[3][3], &strmap[4][4], &strmap[8][5], &strmap[5][2], &strmap[2][4], &strmap[4][9], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9], &strmap[3][4], &strmap[5][1], &strmap[5][9], &strmap[5][5]};//生成时要的怪物坐标
	vector<moster*>mpv;//mpv里一共要有的怪物们
	char tempstr[9] = "color 0";//为告知你胜利的文字颜色
	char tempstra[10][2] = { "C", "E", "A", "9", "D", "9", "A", "E", "C" };//大文字动态彩色变化数组(system("color 0" + tempstra[x(0<=x<=9)])
	mpv.reserve(10000);//也防bug出
	//随机设置地牢布置与怪物布置
	for (i = 0; ch < 11; ch++) {
		vism.push_back(ism);
		vism.back().vmp.reserve(100);//还防bug出
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {//编号id对应的地牢怪物生成
		case 0:
			for (itemp = i + 8, vism[ch].str = "O&&^^OXX"; i < itemp; i++) {
				switch (vism[ch].str[8 - (itemp - i)]) {
				case '&':
					mpv.push_back(new Mand());
					break;
				case '^':
					mpv.push_back(new MUD());
					break;
				case 'O':
					mpv.push_back(new MO());
					break;
				case 'X':
					mpv.push_back(new MX());
					break;
				default:
					break;
				}
				vism[ch].vmp.push_back(mpv[i]);
				if (8 == itemp - i) {
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &em, NULL, NULL, 9, 5);
				}
				else {
					switch (vism[ch].str[8 - (itemp - i)]) {
					case '&':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, NULL, NULL, 0, 0, itemp - i - 6);
						break;
					case '^':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 4, NULL, NULL, NULL, 0, 0, itemp - i - 4, true);
						break;
					case 'O':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &m[2], NULL, NULL, 5, 2);
						break;
					case 'X':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, &cp, &strmap);
						break;
					default:
						break;
					}
				}
			}
			break;
		case 1:
			for (itemp = i + 7; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[7 - (itemp - i) + 8], 5, &m[1], NULL, NULL, 0, 0, 10 - (i - itemp), 3);
			}
			break;
		case 2:
			for (itemp = i + 5; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 15], 3, NULL, NULL, NULL, 0, 0, 1, 1);
			}
			break;
		case 3:
			for (itemp = i + 6, vism[ch].str = "&&^^^^"; i < itemp; i++) {
				if ('&' == (vism[ch].str[6 - (itemp - i)])) {
					mpv.push_back(new Mand());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 3, NULL, NULL, NULL, 0, 0, (i - itemp) % 2);
				}
				else {
					mpv.push_back(new MUD());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 4, NULL, NULL, NULL, 0, 0, (6 - (itemp - i) - 2) & 1, (6 - (itemp - i) - 2) & 2);//qezc(键盘)
				}
			}
			break;
		case 4:
			for (itemp = i + 5, vism[ch].str = "XXXXO"; i < itemp; i++) {
				if ('X' == (vism[ch].str[5 - (itemp - i)])) {
					mpv.push_back(new MX());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 3, NULL, &cp, &strmap);
				}
				else {
					mpv.push_back(new MO());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 5, &em, NULL, NULL, 5, 5);
				}

			}
			break;
		case 5:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 31], 5, &m[0], NULL, NULL, itemp - i, itemp - i);
			}
			break;
		case 6:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MX());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 35], 3, NULL, &cp, &strmap);
			}
			break;
		case 7:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 39], 4, NULL, NULL, NULL, 0, 0, (itemp - i) % 2, (itemp - i + 1) % 2);
			}
			break;
		case 8:
			for (itemp = i + 3; i < itemp; i++) {
				mpv.push_back(new Mand());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[3 - (itemp - i) + 43], 3, NULL, NULL, NULL, 0, 0, !((itemp - i) % 2));
			}
			break;
		case 9:
		{
			char* tempcparr[20] = { NULL };
			for (itemp = i + ia; i < itemp; i++) {
				pair<bool, bool>pbb = { rand() % 2, rand() % 2 };
				pair<int, int>pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				while ((7 == pxy.first || 5 == pxy.first) && 4 == pxy.second || 7 <= pxy.first && 3 >= pxy.second) {
					pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				}
				tempcparr[itemp - i] = &strmap[pxy.first][pxy.second];
				switch (rand() % 7) {
				case 0:
				case 1:
					mpv.push_back(new Mand());
					vism[ch].str += '&';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 3, NULL, NULL, NULL, 0, 0, pbb.first);
					break;
				case 2:
				case 3:
					mpv.push_back(new MUD());
					if (pbb.second) {
						vism[ch].str += 'v';
					}
					else {
						vism[ch].str += '^';
					}
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 2, NULL, NULL, NULL, 0, 0, pbb.first, pbb.second);
					break;
				case 4:
				case 5:
					mpv.push_back(new MX());
					vism[ch].str += 'X';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 3, NULL, &cp, &strmap);
					break;
				case 6:
					mpv.push_back(new MO());
					vism[ch].str += 'O';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 5, &em, NULL, NULL, pxy.first, pxy.second);
					break;
				default:
					break;
				}
			}
		}
		break;
		default:
			break;
		}
	}
	random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除本次游戏不需要的地牢
	}
	vism.push_back(ism);//小BOSS的创建
	vism.back().id = 10;
	mpv.push_back(new Mplus());
	vism.back().vmp.push_back(mpv.back());
	vism.back().vmp.back()->set(p.sgetxyhs(), &strcp[46], 10);
	int ishoot = 0;
	int bosswait = 0;
	bool b = 0;
	char str[9] = "color 0";
	difficulty d = EASY;//初始值(EASY)
	//开始界面
	for (i = 0; i < 15; i++) {//大文字缓缓出现
		system("cls");
		start(i);
		Sleep(10);
	}
	Sleep(10);
	for (i = 0; i < 9; i++) {//使大文字变成动态的彩色
		strcat(tempstr, tempstra[i]);
		system(tempstr);
		tempstr[7] = 0;
		Sleep(100);
	}
	system("color 07");
	Sleep(500);
	cout << endl << endl << endl;//游戏的开始界面
	cout << " \033[33m@---------------------------------------------@" << endl;
	cout << " |                                             |" << endl;
	cout << " |   \033[0m1. 游戏规则           \033[32;1m2. 开始游戏(简单)\033[0;33m   |" << endl;
	cout << " |                                             |" << endl;
	cout << " |   3. 开始游戏(普通)     \033[31;1m4. 开始游戏(困难)\033[0;33m   |" << endl;
	cout << " |                                             |" << endl;
	cout << " |   \033[31m5. 开始游戏(极限)\033[1m     0. 退出\033[0;33m             |" << endl;
	cout << " |                                             |" << endl;
	cout << " @---------------------------------------------@\033[0m" << endl;
	cout << endl << endl << endl;
	while ('1' == ch || '0' > ch || ch > '5') {//输入错误或者输入“1”(游戏规则时)重新输入
		cin >> ch;
		if ('1' == ch) {//1.游戏规则(打印游戏规则)
			cout << "游戏规则：" << endl;
			cout << "    “P”是你，“*”是墙，a键左移，d键右移，w键跳，s及其其他键让时间流逝，上面显示你的\033[32;1m生\033[0;33m命\033[31;1m值\033[0m，如果你生命值\033[31m归0\033[0m，那么你就\033[31;1m失败\033[0m，在遇到\033[31;1m怪物\033[0m的时候，你要按下z键用枪射出\033[33m子弹射\033[31;1m死\033[0m各种各样的\033[31;1m怪物\033[0m，\033[31;1m怪物\033[0m是怎么样的你自己看，如果你碰到了\033[31;1m怪物\033[0m，那么你就会被\033[31;1m怪物伤到\033[0m，\033[31;1m血量减1\033[0m，而打败\033[31;1m小BOSS\033[0m“\033[33m+\033[0m”并从\033[31;1m小BOSS\033[0m的房间中\033[32;1m走出去\033[0m即可\033[32;1m胜利\033[0m。而这个游戏有四种可游玩的模式：一种是\033[32;1m简单模式\033[0m，一种是\033[33m普通模式\033[0m，一种是\033[31;1m困难模式\033[0m，一种是\033[31m极限模式\033[0m，其中，\033[32;1m简单模式\033[0m会让你开始时有\033[32;1m8滴血\033[0m，\033[33m普通模式\033[0m会让你开始时有\033[33m5滴血\033[0m，\033[31;1m困难模式\033[0m会让你开始时有\033[31;1m3滴血\033[0m，而\033[31m极限模式\033[0m会让你开始时\033[31;4m只有1滴血\033[0m；同样，\033[4m我们也会根据你选择的\033[31;1m难度\033[0;4m来选择不同的告知你\033[32;1m胜利方式\033[0m：\033[4m如果你选择了\033[31;1m难玩的难度\033[0;4m，那么告知你\033[32;1m胜利方式\033[0;4m也更\033[32;1m新奇\033[0;4m；反之如果你选择了\033[32;1m易玩的难度\033[0;4m，那么告知你\033[32;1m胜利方式\033[0;4m也\033[31;1m更不新奇\033[0m，并且不同的\033[31;1m难度\033[0m也有不同的\033[32;1m战前回血概率\033[0m与\033[31;1m小BOSS\033[32m战前回血概率\033[0m，\033[4m越\033[31;1m难\033[0;4m这个概率就越\033[31;1m小\033[0m。这就是这个打小怪游戏的规则，你听明白了吗?" << endl << endl;
		}
		else if ('0' > ch || ch > '5') {//输入错误
			cout << "\033[31;1m输入错误，请重新输入\033[0m" << endl << endl;
		}
		rewind(stdin);
	}
	if ('0' == ch) {//退出
		cout << endl << "欢迎下次游玩" << endl;
		return 0;
	}
	d = (difficulty)(ch - '2');//难度选择('2'~'5') - '2' = (0~3)
	int temparra[4] = { 8, 5, 3, 1 };
	p.sgetxyhs(HEAL) = temparra[d];//根据玩家选的难度来设置玩家的生命
	system("cls");
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && (&strmap[9][1] == cp || &strmap[8][1] == cp)) {
			b = 1;
			strmap[9][0] = '*';
			for (i = 1; i < 10; i++) {
				for (ch = 1; ch < 10; ch++) {
					'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
				}
			}
			switch (vism.front().id) {//地牢的生成
			case 0:
				for (ch = 3; ch < 8; ch++) {
					for (i = 3; i < 8; i++) {
						strmap[ch][i] = '*';
					}
				}
				{
					int arr[10] = { 1, 2, 5, 2, 7, 1, 1, 8, 6, 7 };
					for (i = 0; i < 10; i += 2) {
						strmap[arr[i]][arr[i + 1]] = (8 != i ? '*' : strmap[7][7] = ' ');
					}
				}
				break;
			case 1:
				strmap[2][8] = '*';
				break;
			case 2:
				strmap[4][6] = '*';
				strmap[7][7] = '*';
				break;
			case 3:
			{
				char* cparr[6] = { &strmap[2][4], &strmap[4][1], &strmap[4][7], &strmap[8][1], &strmap[8][7], &strmap[6][4] };
				for (ch = 0; ch < 3; ch++) {
					for (i = 0; i < 6; i++) {
						*cparr[i]++ = '*';
					}
				}
			}
			break;
			case 4:
				for (i = 2; i < 9; i += 2) {
					for (ch = 2; ch < 9; ch += 2) {
						strmap[i][ch] = '*';
					}
				}
				{
					int arr[12] = { 8, 5, 6, 3, 6, 7, 4, 5, 8, 9, 4, 1 };
					for (i = 0; i < 12; i += 2) {
						strmap[arr[i]][arr[i + 1]] = '*';
					}
				}
				break;
			case 6:
			{
				int temparr[5] = { 8,5,2,4,9 };//8,5 5,2 2,4 4,9
				for (ch = 2; ch < 9; ch++) {
					strmap[ch][ch] = '*';
					strmap[ch][10 - ch] = '*';
					if (ch < 6) {
						strmap[temparr[ch - 2]][temparr[ch - 1]] = '*';
					}
				}
				break;
			}
			case 7:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 8:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 9:
				strmap[4][5] = '*';
				strmap[7][5] = '*';
				break;
			case 10:
				for (i = 1; i < 10; i++) {
					for (ch = 1; ch < 10; ch++) {
						'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				for (i = 2; i <= 8; i += 6) {
					for (ch = 4; ch < 7; ch++) {
						strmap[i][ch] = '+';
						strmap[ch][i] = '+';
					}
					for (ch = 2; ch <= 8; ch++) {
						'+' != strmap[i][ch] && (strmap[i][ch] = '-');
						'+' != strmap[ch][i] && (strmap[ch][i] = '-');
					}
				}
				for (i = 2; i <= 8; i++) {
					for (ch = 2; ch <= 8; ch++) {
						'-' == strmap[i][ch] && (strmap[i][ch] = '*');
						'+' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				strmap[5][1] = '*';
				strmap[5][9] = '*';
				break;
			default:
				break;
			}
			memcpy(strmapr, strmap, sizeof strmap);
			strmapr[9][1] = ' ';
			for (ch = 0; vism.front().vmp[ch] != vism.front().vmp.back(); ch++) {
				if ('X' == vism.front().vmp[ch]->getm()) {
					((MX*)vism.front().vmp[ch])->exset(strmap);
				}
			}
			if ('X' == vism.front().vmp[ch]->getm()) {
				((MX*)vism.front().vmp[ch])->exset(strmap);
			}
			for (ch = 0; vism.front().vmp.size() != ch; ch++) {
				*vism.front().vmp[ch]->getcp() = vism.front().vmp[ch]->getm();
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.shootmove(&strmap, 0);//子弹删
		if (vism.size()) {//开始前画“#”以用来告知人们地牢的变化
			for (vector<draw>::iterator it = vmd[5 - vism.size()].begin(); &strmap[9][0] == cp && vmd[5 - vism.size()].back().iwalk + 1; it++) {
				for (char* drawcp = &strmap[it->ix][it->iy]; it->iwalk + 1; drawcp += (1 + 10 * it->brd), it->iwalk--) {
					*drawcp = '#';
				}
			}
		}
		p.printmap(strmap, ba, iunmd);//显示游戏的游玩界面
		ba = 1;
		cin >> ch;
		rewind(stdin);
		'*' != *cp && (*cp = ' ');
		//玩弹怪依次动
		//玩动
		switch (ch) {
		case 'a':
			p.left_move(&cp);
			break;
		case 'd':
			p.right_move(&cp);
			break;
		case 'w':
			p.jump(&cp);
			break;
		case 'z':
			p.shoot(ishoot, &cp);
		default:
			break;
		}
		p.upOrDown(&cp);
		(iunmd || ' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, iunmd = 2, "\a");
		//有怪物使你扣血
		ishoot > 0 && ishoot--;
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (bc ? 2 : rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MUD());
						break;
					case 2:
						mpv.push_back(new MO());
						break;
					case 3:
						mpv.push_back(new MX());
						break;
					default:
						break;
					}
					vism.front().vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					const int arr[8] = { -12, -11, -10, -1, 1, 10, 11, 12 };
					while (!cpa || ' ' != *cpa) {
						int ira = rand() % (cpa = vism.front().vmp.front()->getcp(), 8);
						int imx = (vism.front().vmp.front()->getcp() - &strmap[0][0]) / 11;
						int imy = (vism.front().vmp.front()->getcp() - &strmap[0][0]) % 11;
						bool boolarr[8] = { (imx || imy), !!imx, (imx || 10 != imy), !!imy, 10 != imy, (10 != imx || imy), 10 != imx, (imx || 10 != imy) };
						boolarr[ira] && (cpa += arr[ira]);
					}
					mx = (cpa - &strmap[0][0]) / 11;
					my = (cpa - &strmap[0][0]) % 11;
					switch (bc ? (bc = 0, 2) : ir) {
					case 0:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 2, NULL, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, &em, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 5, NULL, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				'*' != *vism.front().vmp.back()->getcp() && (*vism.front().vmp.back()->getcp() = vism.front().vmp.back()->getm());
				if ('X' == vism.front().vmp.back()->getm()) {
					((MX*)vism.front().vmp.back())->exset(strmapr);
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				'*' != *vism.front().vmp.front()->getcp() && it == vism.front().vmp.end() && (*vism.front().vmp.front()->getcp() = ' ');
				'X' == vism.front().vmp.front()->getm() && (*vism.front().vmp.front()->getcp() = ((MX*)vism.front().vmp.front())->getm(0));
				'*' != *vism.front().vmp.front()->getcp() && (*vism.front().vmp.front()->getcp() = ' ');
				if ('+' == vism.front().vmp.front()->getm()) {
					for_each(vism.front().vmp.begin(), vism.front().vmp.end(), setMempty);
					vism.front().vmp.clear();
					bb = 0;
				} 
				bb && (vism.front().vmp.erase(vism.front().vmp.begin()), 0);//删除怪物
			}
		}
		p.shootmove(&strmap, 1);//子弹动
		if (b && '*' == strmap[9][10]) {//怪物动
			vector<moster*>::iterator vfvp = vism.front().vmp.begin();
			while (!vism.front().vmp.empty() && '+' != (*vfvp)->getm()) {
				if (vism.front().vmp.end() == ++vfvp) {
					break;
				}
			}
			if (1 == vism.size() && bb && (!bosswait || (bosswait--, 0))) {
				char* setcp = &strmap[5][5];
				vo.push_back(new M_o());
				vism.front().vmp.push_back(vo.back());
				vism.front().vmp.back()->set(p.sgetxyhs(), &setcp, 5);
				bosswait = 15;
			}//**会变**
			for (vector<moster*>::iterator it = vism.front().vmp.begin(); vism.front().vmp.end() != it/* || ((*it)->getcp() = tempcp, 0)*/; it++) {
				(*it)->hunt();
				(*it)->mosterdo();
				(*it)->hunt();
			}
			for (vector<trir>::iterator it = p.sgetxyhs()->begin(); p.sgetxyhs()->end() != it; it++) {
				-2 >= it->iy && it->iy++;
			}
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		(iunmd || ' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, iunmd = 2, "\a");
		'*' != *cp && (*cp = 'P');
		//没血使怪物死亡
		system("cls");//清屏
		//如果vism的第0项vmp或者vism为空，那么开门，并头删
		if ((vism.empty() || vism.front().vmp.empty()) && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if (bb && 'P' == strmap[9][10]) {
			b = 0;
			for (vector<trir>::iterator it = p.sgetxyhs()->begin(); p.sgetxyhs()->end() != it; it++) {
				'*' != *it->cp && (*it->cp = ' ');
			}
			p.sgetxyhs()->clear();
			for (i = 0; i < 10; i++) {
				p.printmap(&strmap, ba, i, iunmd);
				!i && (strmap[9][0] = ' ');
				Sleep(100);
				system("cls");
			}
			//下一地牢初始化
			////( <- 分界 )
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			////
			p.printmap(&strmap, ba, 11, iunmd);
			Sleep(100);
			system("cls");
			bool temparrb[8] = { 1, 1, !(rand() % 2), 1, !(rand() % 4), !(rand() % 2), 0, 0};
			if (1 != vism.size()) {//恢复血量
				temparrb[d * 2] && temparra[d] > p.sgetxyhs(HEAL) && (p.sgetxyhs(HEAL)++, ba = 0);
		    }
		    else {
				temparrb[d * 2 + 1] && temparra[d] > p.sgetxyhs(HEAL) && (p.sgetxyhs(HEAL)++, ba = 0);
			}
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
		iunmd && iunmd--;
	}
	char tempstrb[6] = "C2AA7";//胜利
	str[7] = tempstrb[(!bb) * (d + 1)];
	system(str);
	switch ((!bb) * (d + 1)) {//告知你胜利的方式
	case 0:
		cout << "很遗憾，你输了" << endl;
		break;
	case 1:
	case 2:
		cout << "恭喜你，你赢了" << endl;
		break;
	case 3:
		cout << "@------------------@" << endl;
		cout << "|                  |" << endl;
		cout << "|  恭喜你，你赢了  |" << endl;
		cout << "|                  |" << endl;
		cout << "@------------------@" << endl;
		break;
	case 4:
		for (i = 0; i < 15; i++) {
			system("cls");
			win(i);
			Sleep(10);
		}
		for (i = 0; i < 27; i++) {
			strcat(tempstr, tempstra[i % 9]);
			system(tempstr);
			tempstr[7] = 0;
			Sleep(100);
		}
		system("color 0A");
		break;
	default:
		break;
	}
	for_each(mpv.begin(), mpv.end(), del);//释放mpv和vo里new出来的怪物对象
	for_each(vo.begin(), vo.end(), delvo);//释放mpv和vo里new出来的怪物对象
	return 0;
}
*///“删除一些无用的注释”^
/*
bool b_(bool b) {//取反
	if ((b = !b) && (b_(b))) {
		return -114514;
	}
	return b;
}
int main() {
	cout << b_(0) << " " << b_(true) << endl;
}
*///“装B取反”^
/*
//Game.cpp
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>
#include <Windows.h>
#include "draw.h"
enum difficulty {//难度
	EASY,
	NORMAL,
	HARD,
	LIMIT
};
void MShow(moster*& mp) {
	('X' == mp->getm() || '*' != *mp->getcp()) && (*mp->getcp() = mp->getm());//左边条件防出bug
}
void del(moster*& mp) {
	delete mp;
}
void delvo(M_o*& mp) {
	delete mp;
}
void setMempty(moster*& mp) {
	'*' != *mp->getcp() && (*mp->getcp() = ' ');//左边条件也防出bug
}
void start(int ichoose) {//开始时打印大字函数
	switch (ichoose) {
	case 14:
		cout << "      *                  *          *           " << endl;
	case 13:
		cout << "      *                  *          * ********  " << endl;
	case 12:
		cout << "      *  ********        *          *  *     *  " << endl;
	case 11:
		cout << "   ******    *           *        * **  *   *   " << endl;
	case 10:
		cout << "      *      *           *        * * *  * *    " << endl;
	case 9:
		cout << "      * *    *        *  *  *     * *     **    " << endl;
	case 8:
		cout << "     ***     *       **  *   *   *  *   **  *   " << endl;
	case 7:
		cout << "   ** *      *      *    *    *     * **  *  ** " << endl;
	case 6:
		cout << "      *      *     *     *    **    *     *     " << endl;
	case 5:
		cout << "      *      *    *      *     *    *     *     " << endl;
	case 4:
		cout << "      *      *           *          *  *******  " << endl;
	case 3:
		cout << "      *      *           *          *     *     " << endl;
	case 2:
		cout << "      *      *           *          *     *     " << endl;
	case 1:
		cout << "    * *    * *         * *          * ********* " << endl;
	case 0:
		cout << "     *      *           *           *           " << endl;
	default:
		break;
	}
} 
void win(int ichoose) {//胜利后打印函数
	switch (ichoose) {
	case 14:
		cout << "      *   *            *           *  *                       *  *              *                     " << endl;
	case 13:
		cout << "      *   *       ************     *  *                       *  *        ************** *************" << endl;
	case 12:
		cout << "   ************        *           *  *                       *  *         *                        * " << endl;
	case 11:
		cout << "      *   *        **********     *  ********                *  ********   ************            *  " << endl;
	case 10:
		cout << "      *   *                       *  *      *                *  *      *    *       *            **   " << endl;
	case 9:
		cout << "  **************   **********    ** *      *                ** *      *     *********          **     " << endl;
	case 8:
		cout << "      *    *       *        *   * *     *                  * *     *                           *      " << endl;
	case 7:
		cout << "     *  *   *      **********     *     *                    *     *      *** ***** ***        *      " << endl;
	case 6:
		cout << "    *   *    *       *    *       *   * * *                  *   * * *    * * *   * * *        *      " << endl;
	case 5:
		cout << "  **    *     ** **************   *   * *  *      **         *   * *  *   *** *   * * *        *      " << endl;
	case 4:
		cout << "     *  **  *                     *  *  *  **     **         *  *  *  **  * * * * * ***        *      " << endl;
	case 3:
		cout << "    *   * *  *     *********      * *   *   *      *         * *   *   *  *** * * * * *        *      " << endl;
	case 2:
		cout << "   *    * *  *     *       *      *     *         *          *     *      * *   *   * *        *      " << endl;
	case 1:
		cout << "      * *          *********      *   * *        *           *   * *      * *  * * *  **     * *      " << endl;
	case 0:
		cout << "       *           *       *      *    *                     *    *      *  * *   *    *      *       " << endl;
	default:
		break;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	char strmap[11][11] = {//地牢图
		'*','*','*','*','*','*','*','*','*','*','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'P',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*','*','*','*','*','*','*','*','*','*','*',
	};
	bool ba = 1;
	bool bb = 1;
	bool bc = 1;
	char ch = 0;
	int iunmd = 0;
	vector<M_o*>vo;//小BOSS战时需要
	vector<draw>vmd[5] = { {{5,2,6,1}}, {{3,2,4,0}, {7,2,3,1}, {3,5,4,0}, {3,5,3,1}, {3,8,4,0}}, {{3,2,4,0},{3,5,4,0},{3,8,4,0},{7,2,6,1}}, {{3,2,3,1},{3,5,4,0},{7,2,6,1}}, {{5,3,4,1},{3,5,4,0}} };//<-画“#”时所需要的数组
	multimap<int, int>mwasd[4] = { {{9,1},{9,3},{3,3},{5,3},{7,3},{9,3},{8,4},{8,8},{6,8},{4,8}}, {{2,3},{9,9},{3,8},{5,8},{7,8},{9,2}}, {{2,2},{2,7},{1,9}}, {{1,1},{2,4},{4,3},{6,3},{8,3},{8,7}} };//<-画“#”时所需要的数组
	vo.reserve(99999);
	int i = 0;
	int temparr[6] = { 4, 8, 12, 15, 17, 18 };
	int ia = rand() % 10 + 1;// 后：+1 +1 +1 +1 +2 +2 +2 +2 +3 +3 +3 +3 +4 +4 +4 +5 +5 +6
	int tempir = rand() % 22;
	for (i = 0; i < 6; i++) {
		if (tempir < temparr[i]) {
			ia += (i + 1);
			break;
		}
	}
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char**, WASD>m[3];
	map<char**, WASD>em;//追踪map
	char* cparr[45] = { NULL };
	char** cpp = cparr;
	for (WASD w = W; E != w; ++w) {//第5地牢的怪物移动路线
		switch (w) {
		case W:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[10 - i][i];
				m[0].insert({cpp++, W});
			}
			break;
		case A:
			for (i = 6; i < 10; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, A});
			}
			break;
		case S:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][10 - i];
				m[0].insert({cpp++, S});
			}
			break;
		case D:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, D});
			}
			break;
		default:
			break;
		}
		for (multimap<int, int>::iterator it = mwasd[w].begin(); mwasd[w].end() != it; it++) {
			*cpp = &strmap[it->first][it->second];
			m[1].insert({ cpp++, w });
		}
	}
	const int arr[4] = { 6,9,1,5 };
	for (i = 0; i < 4; i++) {
		*cpp = &strmap[arr[i]][i % 2 + 1];
		m[2].insert({ cpp++, (WASD)(i / 2 * 2) });//注意：i / 2 * 2 != i
	}
	char strmapr[11][11];
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	vism.reserve(1000);//防bug出
	char* strcp[47] = { &strmap[9][5], &strmap[9][7], &strmap[9][3], &strmap[1][5], &strmap[1][5], &strmap[6][1], &strmap[4][9], &strmap[6][8], &strmap[3][3], &strmap[4][3], &strmap[5][3], &strmap[6][3], &strmap[7][3], &strmap[8][3], &strmap[9][3], &strmap[4][5], &strmap[5][4], &strmap[5][5], &strmap[5][6], &strmap[6][5], &strmap[1][5], &strmap[1][5], &strmap[9][5], &strmap[9][5], &strmap[1][9], &strmap[1][1], &strmap[8][2], &strmap[2][8], &strmap[8][8], &strmap[2][2], &strmap[5][5], &strmap[1][1], &strmap[2][2], &strmap[3][3], &strmap[4][4], &strmap[8][5], &strmap[5][2], &strmap[2][4], &strmap[4][9], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9], &strmap[3][4], &strmap[5][1], &strmap[5][9], &strmap[5][5]};//生成时要的怪物坐标
	vector<moster*>mpv;//mpv里一共要有的怪物们
	char tempstr[9] = "color 0";//为告知你胜利的文字颜色
	char tempstra[10][2] = { "C", "E", "A", "9", "D", "9", "A", "E", "C" };//大文字动态彩色变化数组(system("color 0" + tempstra[x(0<=x<=9)])
	mpv.reserve(10000);//也防bug出
	//随机设置地牢布置与怪物布置
	for (i = 0; ch < 11; ch++) {
		vism.push_back(ism);
		vism.back().vmp.reserve(100);//还防bug出
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {//编号id对应的地牢怪物生成
		case 0:
			for (itemp = i + 8, vism[ch].str = "O&&^^OXX"; i < itemp; i++) {
				switch (vism[ch].str[8 - (itemp - i)]) {
				case '&':
					mpv.push_back(new Mand());
					break;
				case '^':
					mpv.push_back(new MUD());
					break;
				case 'O':
					mpv.push_back(new MO());
					break;
				case 'X':
					mpv.push_back(new MX());
					break;
				default:
					break;
				}
				vism[ch].vmp.push_back(mpv[i]);
				if (8 == itemp - i) {
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &em, NULL, NULL, 9, 5);
				}
				else {
					switch (vism[ch].str[8 - (itemp - i)]) {
					case '&':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, NULL, NULL, 0, 0, itemp - i - 6);
						break;
					case '^':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 4, NULL, NULL, NULL, 0, 0, itemp - i - 4, true);
						break;
					case 'O':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &m[2], NULL, NULL, 5, 2);
						break;
					case 'X':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, &cp, &strmap);
						break;
					default:
						break;
					}
				}
			}
			break;
		case 1:
			for (itemp = i + 7; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[7 - (itemp - i) + 8], 5, &m[1], NULL, NULL, 0, 0, 10 - (i - itemp), 3);
			}
			break;
		case 2:
			for (itemp = i + 5; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 15], 3, NULL, NULL, NULL, 0, 0, 1, 1);
			}
			break;
		case 3:
			for (itemp = i + 6, vism[ch].str = "&&^^^^"; i < itemp; i++) {
				if ('&' == (vism[ch].str[6 - (itemp - i)])) {
					mpv.push_back(new Mand());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 3, NULL, NULL, NULL, 0, 0, (i - itemp) % 2);
				}
				else {
					mpv.push_back(new MUD());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 4, NULL, NULL, NULL, 0, 0, (6 - (itemp - i) - 2) & 1, (6 - (itemp - i) - 2) & 2);//qezc(键盘)
				}
			}
			break;
		case 4:
			for (itemp = i + 5, vism[ch].str = "XXXXO"; i < itemp; i++) {
				if ('X' == (vism[ch].str[5 - (itemp - i)])) {
					mpv.push_back(new MX());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 3, NULL, &cp, &strmap);
				}
				else {
					mpv.push_back(new MO());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 5, &em, NULL, NULL, 5, 5);
				}

			}
			break;
		case 5:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 31], 5, &m[0], NULL, NULL, itemp - i, itemp - i);
			}
			break;
		case 6:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MX());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 35], 3, NULL, &cp, &strmap);
			}
			break;
		case 7:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 39], 4, NULL, NULL, NULL, 0, 0, (itemp - i) % 2, (itemp - i + 1) % 2);
			}
			break;
		case 8:
			for (itemp = i + 3; i < itemp; i++) {
				mpv.push_back(new Mand());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[3 - (itemp - i) + 43], 3, NULL, NULL, NULL, 0, 0, !((itemp - i) % 2));
			}
			break;
		case 9:
		{
			char* tempcparr[20] = { NULL };
			for (itemp = i + ia; i < itemp; i++) {
				pair<bool, bool>pbb = { rand() % 2, rand() % 2 };
				pair<int, int>pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				while ((7 == pxy.first || 5 == pxy.first) && 4 == pxy.second || 7 <= pxy.first && 3 >= pxy.second) {
					pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				}
				tempcparr[itemp - i] = &strmap[pxy.first][pxy.second];
				switch (rand() % 7) {
				case 0:
				case 1:
					mpv.push_back(new Mand());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 3, NULL, NULL, NULL, 0, 0, pbb.first);
					break;
				case 2:
				case 3:
					mpv.push_back(new MUD());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 2, NULL, NULL, NULL, 0, 0, pbb.first, pbb.second);
					break;
				case 4:
				case 5:
					mpv.push_back(new MX());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 3, NULL, &cp, &strmap);
					break;
				case 6:
					mpv.push_back(new MO());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 5, &em, NULL, NULL, pxy.first, pxy.second);
					break;
				default:
					break;
				}
			}
		}
		break;
		default:
			break;
		}
	}
	random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除本次游戏不需要的地牢
	}
	vism.push_back(ism);//小BOSS的创建
	vism.back().id = 10;
	mpv.push_back(new Mplus());
	vism.back().vmp.push_back(mpv.back());
	vism.back().vmp.back()->set(p.sgetxyhs(), &strcp[46], 10);
	int ishoot = 0;
	int bosswait = 0;
	bool b = 0;
	char str[9] = "color 0";
	difficulty d = EASY;//初始值(EASY)
	//开始界面
	for (i = 0; i < 15; i++) {//大文字缓缓出现
		system("cls");
		start(i);
		Sleep(10);
	}
	Sleep(10);
	for (i = 0; i < 9; i++) {//使大文字变成动态的彩色
		strcat(tempstr, tempstra[i]);
		system(tempstr);
		tempstr[7] = 0;
		Sleep(100);
	}
	system("color 07");
	Sleep(500);
	cout << endl << endl << endl;//游戏的开始界面
	cout << " \033[33m@---------------------------------------------@" << endl;
	cout << " |                                             |" << endl;
	cout << " |   \033[0m1. 游戏规则           \033[32;1m2. 开始游戏(简单)\033[0;33m   |" << endl;
	cout << " |                                             |" << endl;
	cout << " |   3. 开始游戏(普通)     \033[31;1m4. 开始游戏(困难)\033[0;33m   |" << endl;
	cout << " |                                             |" << endl;
	cout << " |   \033[31m5. 开始游戏(极限)\033[1m     0. 退出\033[0;33m             |" << endl;
	cout << " |                                             |" << endl;
	cout << " @---------------------------------------------@\033[0m" << endl;
	cout << endl << endl << endl;
	while ('1' == ch || '0' > ch || ch > '5') {//输入错误或者输入“1”(游戏规则时)重新输入
		cin >> ch;
		if ('1' == ch) {//1.游戏规则(打印游戏规则)
			cout << "游戏规则：" << endl;
			cout << "    “P”是你，“*”是墙，a键左移，d键右移，w键跳，s及其其他键让时间流逝，上面显示你的\033[32;1m生\033[0;33m命\033[31;1m值\033[0m，如果你生命值\033[31m归0\033[0m，那么你就\033[31;1m失败\033[0m，在遇到\033[31;1m怪物\033[0m的时候，你要按下z键用枪射出\033[33m子弹射\033[31;1m死\033[0m各种各样的\033[31;1m怪物\033[0m，\033[31;1m怪物\033[0m是怎么样的你自己看，如果你碰到了\033[31;1m怪物\033[0m，那么你就会被\033[31;1m怪物伤到\033[0m，\033[31;1m血量减1\033[0m，而打败\033[31;1m小BOSS\033[0m“\033[33m+\033[0m”并从\033[31;1m小BOSS\033[0m的房间中\033[32;1m走出去\033[0m即可\033[32;1m胜利\033[0m。而这个游戏有四种可游玩的模式：一种是\033[32;1m简单模式\033[0m，一种是\033[33m普通模式\033[0m，一种是\033[31;1m困难模式\033[0m，一种是\033[31m极限模式\033[0m，其中，\033[32;1m简单模式\033[0m会让你开始时有\033[32;1m8滴血\033[0m，\033[33m普通模式\033[0m会让你开始时有\033[33m5滴血\033[0m，\033[31;1m困难模式\033[0m会让你开始时有\033[31;1m3滴血\033[0m，而\033[31m极限模式\033[0m会让你开始时\033[31;4m只有1滴血\033[0m；同样，\033[4m我们也会根据你选择的\033[31;1m难度\033[0;4m来选择不同的告知你\033[32;1m胜利方式\033[0m：\033[4m如果你选择了\033[31;1m难玩的难度\033[0;4m，那么告知你\033[32;1m胜利方式\033[0;4m也更\033[32;1m新奇\033[0;4m；反之如果你选择了\033[32;1m易玩的难度\033[0;4m，那么告知你\033[32;1m胜利方式\033[0;4m也\033[31;1m更不新奇\033[0m，并且不同的\033[31;1m难度\033[0m也有不同的\033[32;1m战前回血概率\033[0m与\033[31;1m小BOSS\033[32m战前回血概率\033[0m，\033[4m越\033[31;1m难\033[0;4m这个概率就越\033[31;1m小\033[0m。这就是这个打小怪游戏的规则，你听明白了吗?" << endl << endl;
		}
		else if ('0' > ch || ch > '5') {//输入错误
			cout << "\033[31;1m输入错误，请重新输入\033[0m" << endl << endl;
		}
		rewind(stdin);
	}
	if ('0' == ch) {//退出
		cout << endl << "欢迎下次游玩" << endl;
		return 0;
	}
	d = (difficulty)(ch - '2');//难度选择('2'~'5') - '2' = (0~3)
	int temparra[4] = { 8, 5, 3, 1 };
	p.sgetxyhs(HEAL) = temparra[d];//根据玩家选的难度来设置玩家的生命
	system("cls");
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && (&strmap[9][1] == cp || &strmap[8][1] == cp)) {
			b = 1;
			strmap[9][0] = '*';
			for (i = 1; i < 10; i++) {
				for (ch = 1; ch < 10; ch++) {
					'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
				}
			}
			switch (vism.front().id) {//地牢的生成
			case 0:
				for (ch = 3; ch < 8; ch++) {
					for (i = 3; i < 8; i++) {
						strmap[ch][i] = '*';
					}
				}
				{
					int arr[10] = { 1, 2, 5, 2, 7, 1, 1, 8, 6, 7 };
					for (i = 0; i < 10; i += 2) {
						strmap[arr[i]][arr[i + 1]] = (8 != i ? '*' : strmap[7][7] = ' ');
					}
				}
				break;
			case 1:
				strmap[2][8] = '*';
				break;
			case 2:
				strmap[4][6] = '*';
				strmap[7][7] = '*';
				break;
			case 3:
			{
				char* cparr[6] = { &strmap[2][4], &strmap[4][1], &strmap[4][7], &strmap[8][1], &strmap[8][7], &strmap[6][4] };
				for (ch = 0; ch < 3; ch++) {
					for (i = 0; i < 6; i++) {
						*cparr[i]++ = '*';
					}
				}
			}
			break;
			case 4:
				for (i = 2; i < 9; i += 2) {
					for (ch = 2; ch < 9; ch += 2) {
						strmap[i][ch] = '*';
					}
				}
				{
					int arr[12] = { 8, 5, 6, 3, 6, 7, 4, 5, 8, 9, 4, 1 };
					for (i = 0; i < 12; i += 2) {
						strmap[arr[i]][arr[i + 1]] = '*';
					}
				}
				break;
			case 6:
			{
				int temparr[5] = { 8,5,2,4,9 };//8,5 5,2 2,4 4,9
				for (ch = 2; ch < 9; ch++) {
					strmap[ch][ch] = '*';
					strmap[ch][10 - ch] = '*';
					if (ch < 6) {
						strmap[temparr[ch - 2]][temparr[ch - 1]] = '*';
					}
				}
				break;
			}
			case 7:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 8:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 9:
				strmap[4][5] = '*';
				strmap[7][5] = '*';
				break;
			case 10:
				for (i = 1; i < 10; i++) {
					for (ch = 1; ch < 10; ch++) {
						'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				for (i = 2; i <= 8; i += 6) {
					for (ch = 4; ch < 7; ch++) {
						strmap[i][ch] = '+';
						strmap[ch][i] = '+';
					}
					for (ch = 2; ch <= 8; ch++) {
						'+' != strmap[i][ch] && (strmap[i][ch] = '-');
						'+' != strmap[ch][i] && (strmap[ch][i] = '-');
					}
				}
				for (i = 2; i <= 8; i++) {
					for (ch = 2; ch <= 8; ch++) {
						'-' == strmap[i][ch] && (strmap[i][ch] = '*');
						'+' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				strmap[5][1] = '*';
				strmap[5][9] = '*';
				break;
			default:
				break;
			}
			memcpy(strmapr, strmap, sizeof strmap);
			strmapr[9][1] = ' ';
			for (ch = 0; vism.front().vmp[ch] != vism.front().vmp.back(); ch++) {
				if ('X' == vism.front().vmp[ch]->getm()) {
					((MX*)vism.front().vmp[ch])->exset(strmap);
				}
			}
			if ('X' == vism.front().vmp[ch]->getm()) {
				((MX*)vism.front().vmp[ch])->exset(strmap);
			}
			for (ch = 0; vism.front().vmp.size() != ch; ch++) {
				*vism.front().vmp[ch]->getcp() = vism.front().vmp[ch]->getm();
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.shootmove(&strmap, 0);//子弹删
		if (vism.size()) {//开始前画“#”以用来告知人们地牢的变化
			for (vector<draw>::iterator it = vmd[5 - vism.size()].begin(); &strmap[9][0] == cp && vmd[5 - vism.size()].back().iwalk + 1; it++) {
				for (char* drawcp = &strmap[it->ix][it->iy]; it->iwalk + 1; drawcp += (1 + 10 * it->brd), it->iwalk--) {
					*drawcp = '#';
				}
			}
		}
		p.printmap(strmap, ba, iunmd);//显示游戏的游玩界面
		ba = 1;
		cin >> ch;
		rewind(stdin);
		'*' != *cp && (*cp = ' ');
		//玩弹怪依次动
		//玩动
		switch (ch) {
		case 'a':
			p.left_move(&cp);
			break;
		case 'd':
			p.right_move(&cp);
			break;
		case 'w':
			p.jump(&cp);
			break;
		case 'z':
			p.shoot(ishoot, &cp);
		default:
			break;
		}
		p.upOrDown(&cp);
		(iunmd || ' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, iunmd = 2, "\a");
		//有怪物使你扣血
		ishoot > 0 && ishoot--;
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (bc ? 2 : rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MUD());
						break;
					case 2:
						mpv.push_back(new MO());
						break;
					case 3:
						mpv.push_back(new MX());
						break;
					default:
						break;
					}
					vism.front().vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					const int arr[8] = { -12, -11, -10, -1, 1, 10, 11, 12 };
					while (!cpa || ' ' != *cpa) {
						int ira = rand() % (cpa = vism.front().vmp.front()->getcp(), 8);
						int imx = (vism.front().vmp.front()->getcp() - &strmap[0][0]) / 11;
						int imy = (vism.front().vmp.front()->getcp() - &strmap[0][0]) % 11;
						bool boolarr[8] = { (imx || imy), !!imx, (imx || 10 != imy), !!imy, 10 != imy, (10 != imx || imy), 10 != imx, (imx || 10 != imy) };
						boolarr[ira] && (cpa += arr[ira]);
					}
					mx = (cpa - &strmap[0][0]) / 11;
					my = (cpa - &strmap[0][0]) % 11;
					switch (bc ? (bc = 0, 2) : ir) {
					case 0:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 2, NULL, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, &em, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 5, NULL, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				'*' != *vism.front().vmp.back()->getcp() && (*vism.front().vmp.back()->getcp() = vism.front().vmp.back()->getm());
				if ('X' == vism.front().vmp.back()->getm()) {
					((MX*)vism.front().vmp.back())->exset(strmapr);
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				'*' != *vism.front().vmp.front()->getcp() && it == vism.front().vmp.end() && (*vism.front().vmp.front()->getcp() = ' ');
				'X' == vism.front().vmp.front()->getm() && (*vism.front().vmp.front()->getcp() = ((MX*)vism.front().vmp.front())->getm(0));
				'*' != *vism.front().vmp.front()->getcp() && (*vism.front().vmp.front()->getcp() = ' ');
				if ('+' == vism.front().vmp.front()->getm()) {
					for_each(vism.front().vmp.begin(), vism.front().vmp.end(), setMempty);
					vism.front().vmp.clear();
					bb = 0;
				} 
				bb && (vism.front().vmp.erase(vism.front().vmp.begin()), 0);//删除怪物
			}
		}
		p.shootmove(&strmap, 1);//子弹动
		if (b && '*' == strmap[9][10]) {//怪物动
			vector<moster*>::iterator vfvp = vism.front().vmp.begin();
			while (!vism.front().vmp.empty() && '+' != (*vfvp)->getm()) {
				if (vism.front().vmp.end() == ++vfvp) {
					break;
				}
			}
			if (1 == vism.size() && bb && (!bosswait || (bosswait--, 0))) {
				char* setcp = &strmap[5][5];
				vo.push_back(new M_o());
				vism.front().vmp.push_back(vo.back());
				vism.front().vmp.back()->set(p.sgetxyhs(), &setcp, 5);
				bosswait = 15;
			}//**会变**
			for (vector<moster*>::iterator it = vism.front().vmp.begin(); vism.front().vmp.end() != it/* || ((*it)->getcp() = tempcp, 0)*/; it++) {
				(*it)->hunt();
				(*it)->mosterdo();
				(*it)->hunt();
			}
			for (vector<trir>::iterator it = p.sgetxyhs()->begin(); p.sgetxyhs()->end() != it; it++) {
				-2 >= it->iy && it->iy++;
			}
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		(iunmd || ' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, iunmd = 2, "\a");
		'*' != *cp && (*cp = 'P');
		//没血使怪物死亡
		system("cls");//清屏
		//如果vism的第0项vmp或者vism为空，那么开门，并头删
		if ((vism.empty() || vism.front().vmp.empty()) && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if (bb && 'P' == strmap[9][10]) {
			b = 0;
			for (vector<trir>::iterator it = p.sgetxyhs()->begin(); p.sgetxyhs()->end() != it; it++) {
				'*' != *it->cp && (*it->cp = ' ');
			}
			p.sgetxyhs()->clear();
			for (i = 0; i < 10; i++) {
				p.printmap(&strmap, ba, i, iunmd);
				!i && (strmap[9][0] = ' ');
				Sleep(100);
				system("cls");
			}
			//下一地牢初始化
			////( <- 分界 )
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			////
			p.printmap(&strmap, ba, 11, iunmd);
			Sleep(100);
			system("cls");
			bool temparrb[8] = { 1, 1, !(rand() % 2), 1, !(rand() % 4), !(rand() % 2), 0, 0};
			if (1 != vism.size()) {//恢复血量
				temparrb[d * 2] && temparra[d] > p.sgetxyhs(HEAL) && (p.sgetxyhs(HEAL)++, ba = 0);
		    }
		    else {
				temparrb[d * 2 + 1] && temparra[d] > p.sgetxyhs(HEAL) && (p.sgetxyhs(HEAL)++, ba = 0);
			}
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
		iunmd && iunmd--;
	}
	char tempstrb[6] = "C2AA7";//胜利
	str[7] = tempstrb[(!bb) * (d + 1)];
	system(str);
	switch ((!bb) * (d + 1)) {//告知你胜利的方式
	case 0:
		cout << "很遗憾，你输了" << endl;
		break;
	case 1:
	case 2:
		cout << "恭喜你，你赢了" << endl;
		break;
	case 3:
		cout << "@------------------@" << endl;
		cout << "|                  |" << endl;
		cout << "|  恭喜你，你赢了  |" << endl;
		cout << "|                  |" << endl;
		cout << "@------------------@" << endl;
		break;
	case 4:
		for (i = 0; i < 15; i++) {
			system("cls");
			win(i);
			Sleep(10);
		}
		for (i = 0; i < 27; i++) {
			strcat(tempstr, tempstra[i % 9]);
			system(tempstr);
			tempstr[7] = 0;
			Sleep(100);
		}
		system("color 0A");
		break;
	default:
		break;
	}
	for_each(mpv.begin(), mpv.end(), del);//释放mpv和vo里new出来的怪物对象
	for_each(vo.begin(), vo.end(), delvo);//释放mpv和vo里new出来的怪物对象
	return 0;
}
*///“删掉无用代码”^
/*
//以前来自MO.cpp，现在无
#include <iostream>
//其他头文件
using namespace std;
//对象的成员函数
void M_o::mosterdo() {//发生bug的成员函数
	int arr[8] = { -12, -11, -10, -1, 1, 10, 11, 12 };
	int ir = 0;
	'*' != **m_cpp && (**m_cpp = ' ');
	'*' != (*m_cpp)[arr[ir = rand() % 8]] && (*m_cpp -= arr[ir]);//看起来没问题，但此乃bug点(重点)：一级指针会“带动”二级指针
}//随便移动，有墙不动
//对象的成员函数
*///“指针的链式带动”^
/*
int main() {
	cout << INT_MAX << endl;
	return 0;
}
*///“climits头文件的使用”^
/*
int main() {
	cout << INT_MIN << endl;
	return 0;
}
*///“INT_MIN”^
/*
int main() {
	cout << CHAR_MAX << endl;
	return 0;
}
*///“CHAR_MAX”^
/*
int main() {
	cout << CHAR_MIN << endl;
	return 0;
}
*///“CHAR_MIN”^
/*
int main() {
	deque<int> d;
	d.push_back(4);
	cout << d.front() << endl;
	d.pop_front();
	d.push_back(4);
	d.push_front(3);
	d.push_back(-2);
	for (deque<int>::iterator it = d.begin(); d.end() != it; it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
*///“deque双端数组”^
/*
int main() {
	stack<int>s;
	int i = 0;
	for (; i < 5; i++) {//放入
		s.push(i);
		cout << i << " ";
	}
	for (cout << endl; i; i--) {//移出
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	return 0;
}
*///“stack栈容器的反转元素顺序功能”^
/*
/*
int main() {
	set<int>s;
	int i = -10;
	for (; i < 10; i++) {
		s.insert(i);
	}
	for (set<int>::const_iterator cit = s.cbegin(); s.cend() != cit; cit++) {
		!*cit && cout << endl;
		cout << *cit << " ";
	}
	cout << endl;
	return 0;
}
*///“set容器的正负分组”^
/*
int main() {
	set<int, greater<int>>s;
	int i = -10;
	for (; i < 10; i++) {
		s.insert(i);
	}
	for (set<int>::const_iterator cit = s.cbegin(); s.cend() != cit; cit++) {
		cout << *cit << " ";
	}
	cout << endl;
	return 0;
}
*///“set容器的排序方式已变为从大到小排”^
/*
int main() {
	vector<int>v = { 1, 1, 4, 5, 1, 4 };
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), [=](int i) {
		cout << i;
	});
	return 0;
}
*///“sort排序函数和for_each遍历函数”^
/*
int main() {
	[=]() {
		cout << "Hello, Lambda!" << endl;
	}();
	return 0;
}
*///“后面有用于函数的调用的括号的匿名函数体”^
/*
//M+.cpp
#include <iostream>
using namespace std;
#include "m+.h"
void Mplus::mosterdo() {
	**m_cpp = '+';//后面根据**m_cpp的内容来执行summon方法
}
char Mplus::getm() {
	return '+';
}
*///“减少导入的头文件”^
/*
//M&.cpp
#include <iostream>
using namespace std;
#include "m&.h"
Mand::Mand() {
	this->set();
}
void Mand::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*, char**, char(*)[11][11], int, int, bool b, bool) {
	m_v = v;
	m_cpp = cpp;
	m_iheal = iheal;
	mblr = b;
}
void Mand::mosterdo() {
	'*' != **m_cpp && (**m_cpp = ' ');//便于移动之后的显示
	if (!mblr && '*' == (*m_cpp)[-1]) {//如果怪物M&往左移动，并且左边有墙
		mblr = 1;//怪物M&就往右移动
	}
	else if (mblr && '*' == (*m_cpp)[1]) {//如果怪物M^往右移动，并且左边有墙
		mblr = 0;//怪物M&就往左动
	}//撞墙换方向
	tempcp = *m_cpp;//防指针的链式带动
	m_cpp = NULL;
	'*' != tempcp[-(1 - 2 * mblr)] && (tempcp -= (1 - 2 * mblr));//左右移
	'*' != tempcp[11] && (tempcp += 11);//下落
	m_cpp = &tempcp;
	//后面main函数中用Mshow函数使见
}//撞墙换方向，会自然下落
char Mand::getm() {
	return '&';
}
//M^.cpp
#include <iostream>
using namespace std;
#include "m^.h"
//构造函数
MUD::MUD() {
	set();
}
//M^的设置函数
void MUD::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*, char**, char(*)[11][11], int, int, bool b, bool ba) {
	m_v = v;
	m_cpp = cpp;
	m_iheal = iheal;
	mblr = b;
	mbud = ba;
}
void MUD::mosterdo() {
	'*' != **m_cpp && (**m_cpp = ' ');//便于移动之后的显示
	if (!mblr && '*' == (*m_cpp)[-1]) {//如果怪物M^往左移动，并且左边有墙
		mblr = 1;//怪物M^就往右移动
	}
	else if(mblr && '*' == (*m_cpp)[1]){//如果怪物M^往右移动，并且右边有墙
		mblr = 0;//怪物M^就往左移动
	}//撞墙换方向
	tempcp = *m_cpp;//防指针的链式带动
	m_cpp = NULL;
	'*' != tempcp[-(1 - 2 * mblr)] && (tempcp -= (1 - 2 * mblr));//左右移
	if (mbud && '*' == tempcp[11]) {//如果怪物M^往下移动，并且下边有墙
		mbud = 0;//怪物M^就往上落
	}
	else if (!mbud && '*' == tempcp[-11]) {//如果怪物M^往上落，并且上边有墙
		mbud = 1;//怪物M^就往下落
	}//碰地会反转
	'*' != tempcp[-(11 * (1 - 2 * mbud))] && (tempcp -= 11 * (1 - 2 * mbud));//上下落
	m_cpp = &tempcp;
	//后面main函数中Mshow函数使见
}//撞墙换方向，碰地会反落
char MUD::getm() {
	if (mbud) {
		return 'v';
	}
	else {
		return '^';
	}
}
//MO.cpp
#include <iostream>
using namespace std;
#include "MO.h"
#define NNEG(A, B) ((A) < (B) ? 1 : (A) > (B) ? -1 : 0)//判断宏
#define MOWAIT 1//怪物等待的回合数
pair<int, int> MO::s_m_pxy = {0, 0};//玩家坐标的初始化
//构造函数
MO::MO() {
	set();
}
//MO的设置函数
void MO::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*m, char**, char(*)[11][11], int ix, int iy, bool, bool) {
	m_v = v;
	m_cpp = cpp;
	m_iheal = iheal;
	m_pxy.first = ix;
	m_pxy.second = iy;
	imove = 0;
	if (m) { 
		m_m = *m;
	}
}
void MO::mosterdo() {
	'*' != **m_cpp && (**m_cpp = ' ');//便于移动之后的显示
	tempcp = *m_cpp;//防指针的链式带动
	m_cpp = NULL;
	if (!m_m.empty()) {//沿路模式
		int arr[4] = { -11, -1, 11, 1 };//怪物MO可能会移动的四个方位
		for (map<char**, WASD>::iterator it = m_m.begin(); m_m.end() != it; it++) {//改变怪物MO的方向
			E != it->second && tempcp == *it->first && (m_wasd = it->second);
		}
		switch (tempcp += (arr[m_wasd]), m_wasd) {//怪物的移动与xy坐标的变化
		case W:
			m_pxy.second--;
			break;
		case A:
			m_pxy.first--;
			break;
		case S:
			m_pxy.second++;
			break;
		case D:
			m_pxy.first++;
			break;
		default:
			break;
		}
	}
	else {//追踪模式
		MOWAIT == imove % (MOWAIT + 1)/*如果MO等待了MOWAIT回合*/ && ('*' != *(tempcp + 11 * NNEG(m_pxy.first, s_m_pxy.first))/*并且垂直移动的方向上没有墙*/ && (tempcp += 11 * NNEG(m_pxy.first, s_m_pxy.first)/*那么怪物MO就往玩家垂直地移动*/, m_pxy.first += NNEG(m_pxy.first, s_m_pxy.first)/*怪物的x坐标也随之变化*/));//根据怪物的xy坐标和玩家的xy坐标来移动
		MOWAIT == imove++ % (MOWAIT + 1) && ('*' != *(tempcp + NNEG(m_pxy.second, s_m_pxy.second)/*并且水平移动的方向上没有墙*/) && (tempcp += NNEG(m_pxy.second, s_m_pxy.second)/*那么怪物MO就往玩家水平地移动*/, m_pxy.second += NNEG(m_pxy.second, s_m_pxy.second)/*怪物的y坐标也随之变化*/));
	}
	m_cpp = &tempcp;
}//遇向则转，看路前行（1），或追玩者（2）
//设置玩家的坐标
void MO::set_s_pxy(int ix, int iy) {
	s_m_pxy = { ix, iy };
}
char MO::getm() {
	return 'O';
}
//MX.cpp
#include <iostream>
using namespace std;
#include <cstring>
#include "mX.h"
//怪物MX的设置函数
void MX::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*, char** pcpp, char(*strmap)[11][11], int, int, bool, bool) {
	m_v = v;
	m_cpp = cpp;
	m_pcpp = pcpp;
	strmap && (m_strmap = strmap);
	m_iheal = iheal;
	setb = 1;
}
//怪物MX的额外设置函数
void MX::exset(char strmapr[11][11]) {
	memcpy(m_strmapr, strmapr, sizeof m_strmapr);
}
//构造函数
MX::MX() {
	set();
}
void MX::mosterdo() {
	vector<trir>::iterator it = m_v->begin();
	if (setb) {
		pxy = { (*m_cpp - &(*m_strmap)[0][0]) / 11, (*m_cpp - &(*m_strmap)[0][0]) % 11 };//设置怪物MX的坐标
		m_cc = m_strmapr[pxy.first][setb = 0, pxy.second];//设置盖住的块
	}
	for (; m_v->end() != it; it++) {
		if (*m_cpp == it->cp || *m_cpp == it->cp - (1 - it->b * 2)) {//如果怪物受伤了就停止这个循环
			break;
		}
	}
	if (m_iheal && (*m_cpp == *m_pcpp || m_v->end() != it)) {//如果刚才的这个循环停止了，并且还有生命且不在玩家的位置上
		tempcp = *m_cpp;//防指针的链式移动
		char* tempcpb = tempcp;
		bool tempb = 1;//防误覆盖空位
		m_cpp = NULL;
		do {
			tempb && m_v->end() != it && (*tempcp = ' ');//便于移动之后的显示
			tempcp = &(*m_strmap)[pxy.first = rand() % 9 + 1][pxy.second = rand() % 9 + 1];//怪物MX的移动

		} while ((tempcp == &(*m_strmap)[9][1] || '@' == (*m_strmap)[pxy.first][pxy.second] || '@' == (*m_strmap)[pxy.first][pxy.second - 1] || '@' == (*m_strmap)[pxy.first][pxy.second + 1] || tempcp == *m_pcpp || '*' == tempcp[-1] || '*' == tempcp[1] || 'X' == (tempcp)[-1] || 'X' == (tempcp)[1]) && (tempb = 0, 1));//如果满足上述的条件，就把误覆盖空位的“开关”启动
		m_cpp = &tempcp;
		*tempcpb = m_cc;
		('@' != m_strmapr[pxy.first][pxy.second] || 'X' != m_strmapr[pxy.first][pxy.second] && 'P' != m_strmapr[pxy.first][pxy.second]) && (m_cc = m_strmapr[pxy.first][pxy.second]);//记录盖住的块，不记录“@”子弹，“P”玩家和“X”怪物MX自己
	}
	//main函数使见
}//被玩家碰到传，受伤传(两旁有砖不传)，并见
char MX::getm() {
	return 'X';
}
char MX::getm(bool) {
	return m_cc;
}
*///“减少注释”^
/*
//mosters.h
#pragma once
#include <iostream>
using namespace std;
#include "moster.h"//怪物们的头文件
#include "M_o.h"
#include "M&.h"
#include "M^.h"
#include "MO.h"
#include "M+.h"
#include "MX.h"
*///“导入的头文件名字已改变”^
/*
//Game.cpp
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>
#include <Windows.h>
#include "draw.h"
enum difficulty {//难度
	EASY,
	NORMAL,
	HARD,
	LIMIT
};
void MShow(moster*& mp) {
	('X' == mp->getm() || '*' != *mp->getcp()) && (*mp->getcp() = mp->getm());//左边条件防出bug
}
void del(moster*& mp) {
	delete mp;
}
void delvo(M_o*& mp) {
	delete mp;
}
void setMempty(moster*& mp) {
	'*' != *mp->getcp() && (*mp->getcp() = ' ');//左边条件也防出bug
}
void start(int ichoose) {//开始时打印大字函数
	switch (ichoose) {
	case 14:
		cout << "      *                  *          *           " << endl;
	case 13:
		cout << "      *                  *          * ********  " << endl;
	case 12:
		cout << "      *  ********        *          *  *     *  " << endl;
	case 11:
		cout << "   ******    *           *        * **  *   *   " << endl;
	case 10:
		cout << "      *      *           *        * * *  * *    " << endl;
	case 9:
		cout << "      * *    *        *  *  *     * *     **    " << endl;
	case 8:
		cout << "     ***     *       **  *   *   *  *   **  *   " << endl;
	case 7:
		cout << "   ** *      *      *    *    *     * **  *  ** " << endl;
	case 6:
		cout << "      *      *     *     *    **    *     *     " << endl;
	case 5:
		cout << "      *      *    *      *     *    *     *     " << endl;
	case 4:
		cout << "      *      *           *          *  *******  " << endl;
	case 3:
		cout << "      *      *           *          *     *     " << endl;
	case 2:
		cout << "      *      *           *          *     *     " << endl;
	case 1:
		cout << "    * *    * *         * *          * ********* " << endl;
	case 0:
		cout << "     *      *           *           *           " << endl;
	default:
		break;
	}
} 
void win(int ichoose) {//胜利后打印函数
	switch (ichoose) {
	case 14:
		cout << "      *   *            *           *  *                       *  *              *                     " << endl;
	case 13:
		cout << "      *   *       ************     *  *                       *  *        ************** *************" << endl;
	case 12:
		cout << "   ************        *           *  *                       *  *         *                        * " << endl;
	case 11:
		cout << "      *   *        **********     *  ********                *  ********   ************            *  " << endl;
	case 10:
		cout << "      *   *                       *  *      *                *  *      *    *       *            **   " << endl;
	case 9:
		cout << "  **************   **********    ** *      *                ** *      *     *********          **     " << endl;
	case 8:
		cout << "      *    *       *        *   * *     *                  * *     *                           *      " << endl;
	case 7:
		cout << "     *  *   *      **********     *     *                    *     *      *** ***** ***        *      " << endl;
	case 6:
		cout << "    *   *    *       *    *       *   * * *                  *   * * *    * * *   * * *        *      " << endl;
	case 5:
		cout << "  **    *     ** **************   *   * *  *      **         *   * *  *   *** *   * * *        *      " << endl;
	case 4:
		cout << "     *  **  *                     *  *  *  **     **         *  *  *  **  * * * * * ***        *      " << endl;
	case 3:
		cout << "    *   * *  *     *********      * *   *   *      *         * *   *   *  *** * * * * *        *      " << endl;
	case 2:
		cout << "   *    * *  *     *       *      *     *         *          *     *      * *   *   * *        *      " << endl;
	case 1:
		cout << "      * *          *********      *   * *        *           *   * *      * *  * * *  **     * *      " << endl;
	case 0:
		cout << "       *           *       *      *    *                     *    *      *  * *   *    *      *       " << endl;
	default:
		break;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	char strmap[11][11] = {//地牢图
		'*','*','*','*','*','*','*','*','*','*','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'P',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*','*','*','*','*','*','*','*','*','*','*',
	};
	bool ba = 1;
	bool bb = 1;
	bool bc = 1;
	char ch = 0;
	int iunmd = 0;
	vector<M_o*>vo;//小BOSS战时需要
	vector<draw>vmd[5] = { {{5,2,6,1}}, {{3,2,4,0}, {7,2,3,1}, {3,5,4,0}, {3,5,3,1}, {3,8,4,0}}, {{3,2,4,0},{3,5,4,0},{3,8,4,0},{7,2,6,1}}, {{3,2,3,1},{3,5,4,0},{7,2,6,1}}, {{5,3,4,1},{3,5,4,0}} };//<-画“#”时所需要的数组
	multimap<int, int>mwasd[4] = { {{9,1},{9,3},{3,3},{5,3},{7,3},{9,3},{8,4},{8,8},{6,8},{4,8}}, {{2,3},{9,9},{3,8},{5,8},{7,8},{9,2}}, {{2,2},{2,7},{1,9}}, {{1,1},{2,4},{4,3},{6,3},{8,3},{8,7}} };//<-画“#”时所需要的数组
	vo.reserve(99999);
	int i = 0;
	int temparr[6] = { 4, 8, 12, 15, 17, 18 };
	int ia = rand() % 10 + 1;// 后：+1 +1 +1 +1 +2 +2 +2 +2 +3 +3 +3 +3 +4 +4 +4 +5 +5 +6
	int tempir = rand() % 22;
	for (i = 0; i < 6; i++) {
		if (tempir < temparr[i]) {
			ia += (i + 1);
			break;
		}
	}
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char**, WASD>m[3];
	map<char**, WASD>em;//追踪map
	char* cparr[45] = { NULL };
	char** cpp = cparr;
	for (WASD w = W; E != w; ++w) {//第5地牢的怪物移动路线
		switch (w) {
		case W:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[10 - i][i];
				m[0].insert({cpp++, W});
			}
			break;
		case A:
			for (i = 6; i < 10; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, A});
			}
			break;
		case S:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][10 - i];
				m[0].insert({cpp++, S});
			}
			break;
		case D:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, D});
			}
			break;
		default:
			break;
		}
		for (multimap<int, int>::iterator it = mwasd[w].begin(); mwasd[w].end() != it; it++) {
			*cpp = &strmap[it->first][it->second];
			m[1].insert({ cpp++, w });
		}
	}
	const int arr[4] = { 6,9,1,5 };
	for (i = 0; i < 4; i++) {
		*cpp = &strmap[arr[i]][i % 2 + 1];
		m[2].insert({ cpp++, (WASD)(i / 2 * 2) });//注意：i / 2 * 2 != i
	}
	char strmapr[11][11];
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	vism.reserve(5000);//防bug出
	char* strcp[47] = { &strmap[9][5], &strmap[9][7], &strmap[9][3], &strmap[1][5], &strmap[1][5], &strmap[6][1], &strmap[4][9], &strmap[6][8], &strmap[3][3], &strmap[4][3], &strmap[5][3], &strmap[6][3], &strmap[7][3], &strmap[8][3], &strmap[9][3], &strmap[4][5], &strmap[5][4], &strmap[5][5], &strmap[5][6], &strmap[6][5], &strmap[1][5], &strmap[1][5], &strmap[9][5], &strmap[9][5], &strmap[1][9], &strmap[1][1], &strmap[8][2], &strmap[2][8], &strmap[8][8], &strmap[2][2], &strmap[5][5], &strmap[1][1], &strmap[2][2], &strmap[3][3], &strmap[4][4], &strmap[8][5], &strmap[5][2], &strmap[2][4], &strmap[4][9], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9], &strmap[3][4], &strmap[5][1], &strmap[5][9], &strmap[5][5]};//生成时要的怪物坐标
	vector<moster*>mpv;//mpv里一共要有的怪物们
	char tempstr[9] = "color 0";//为告知你胜利的文字颜色
	char tempstra[10][2] = { "C", "E", "A", "9", "D", "9", "A", "E", "C" };//大文字动态彩色变化数组(system("color 0" + tempstra[x(0<=x<=9)])
	mpv.reserve(10000);//也防bug出
	//随机设置地牢布置与怪物布置
	for (i = 0; ch < 11; ch++) {
		vism.push_back(ism);
		vism.back().vmp.reserve(500);//还防bug出
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {//编号id对应的地牢怪物生成
		case 0:
			for (itemp = i + 8, vism[ch].str = "O&&^^OXX"; i < itemp; i++) {
				switch (vism[ch].str[8 - (itemp - i)]) {
				case '&':
					mpv.push_back(new Mand());
					break;
				case '^':
					mpv.push_back(new MUD());
					break;
				case 'O':
					mpv.push_back(new MO());
					break;
				case 'X':
					mpv.push_back(new MX());
					break;
				default:
					break;
				}
				vism[ch].vmp.push_back(mpv[i]);
				if (8 == itemp - i) {
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &em, NULL, NULL, 9, 5);
				}
				else {
					switch (vism[ch].str[8 - (itemp - i)]) {
					case '&':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, NULL, NULL, 0, 0, itemp - i - 6);
						break;
					case '^':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 4, NULL, NULL, NULL, 0, 0, itemp - i - 4, true);
						break;
					case 'O':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &m[2], NULL, NULL, 5, 2);
						break;
					case 'X':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, &cp, &strmap);
						break;
					default:
						break;
					}
				}
			}
			break;
		case 1:
			for (itemp = i + 7; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[7 - (itemp - i) + 8], 5, &m[1], NULL, NULL, 0, 0, 10 - (i - itemp), 3);
			}
			break;
		case 2:
			for (itemp = i + 5; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 15], 3, NULL, NULL, NULL, 0, 0, 1, 1);
			}
			break;
		case 3:
			for (itemp = i + 6, vism[ch].str = "&&^^^^"; i < itemp; i++) {
				if ('&' == (vism[ch].str[6 - (itemp - i)])) {
					mpv.push_back(new Mand());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 3, NULL, NULL, NULL, 0, 0, (i - itemp) % 2);
				}
				else {
					mpv.push_back(new MUD());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 4, NULL, NULL, NULL, 0, 0, (6 - (itemp - i) - 2) & 1, (6 - (itemp - i) - 2) & 2);//qezc(键盘)
				}
			}
			break;
		case 4:
			for (itemp = i + 5, vism[ch].str = "XXXXO"; i < itemp; i++) {
				if ('X' == (vism[ch].str[5 - (itemp - i)])) {
					mpv.push_back(new MX());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 3, NULL, &cp, &strmap);
				}
				else {
					mpv.push_back(new MO());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 5, &em, NULL, NULL, 5, 5);
				}

			}
			break;
		case 5:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 31], 5, &m[0], NULL, NULL, itemp - i, itemp - i);
			}
			break;
		case 6:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MX());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 35], 3, NULL, &cp, &strmap);
			}
			break;
		case 7:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 39], 4, NULL, NULL, NULL, 0, 0, (itemp - i) % 2, (itemp - i + 1) % 2);
			}
			break;
		case 8:
			for (itemp = i + 3; i < itemp; i++) {
				mpv.push_back(new Mand());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[3 - (itemp - i) + 43], 3, NULL, NULL, NULL, 0, 0, !((itemp - i) % 2));
			}
			break;
		case 9:
		{
			char* tempcparr[20] = { NULL };
			for (itemp = i + ia; i < itemp; i++) {
				pair<bool, bool>pbb = { rand() % 2, rand() % 2 };
				pair<int, int>pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				while ((7 == pxy.first || 5 == pxy.first) && 4 == pxy.second || 7 <= pxy.first && 3 >= pxy.second) {
					pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				}
				tempcparr[itemp - i] = &strmap[pxy.first][pxy.second];
				switch (rand() % 7) {
				case 0:
				case 1:
					mpv.push_back(new Mand());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 3, NULL, NULL, NULL, 0, 0, pbb.first);
					break;
				case 2:
				case 3:
					mpv.push_back(new MUD());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 2, NULL, NULL, NULL, 0, 0, pbb.first, pbb.second);
					break;
				case 4:
				case 5:
					mpv.push_back(new MX());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 3, NULL, &cp, &strmap);
					break;
				case 6:
					mpv.push_back(new MO());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 5, &em, NULL, NULL, pxy.first, pxy.second);
					break;
				default:
					break;
				}
			}
		}
		break;
		default:
			break;
		}
	}
	random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除本次游戏不需要的地牢
	}
	vism.push_back(ism);//小BOSS的创建
	vism.back().id = 10;
	mpv.push_back(new Mplus());
	vism.back().vmp.push_back(mpv.back());
	vism.back().vmp.back()->set(p.sgetxyhs(), &strcp[46], 10);
	int ishoot = 0;
	int bosswait = 0;
	bool b = 0;
	char str[9] = "color 0";
	difficulty d = EASY;//初始值(EASY)
	//开始界面
	for (i = 0; i < 15; i++) {//大文字缓缓出现
		system("cls");
		start(i);
		Sleep(10);
	}
	Sleep(10);
	for (i = 0; i < 9; i++) {//使大文字变成动态的彩色
		strcat(tempstr, tempstra[i]);
		system(tempstr);
		tempstr[7] = 0;
		Sleep(100);
	}
	system("color 07");
	Sleep(500);
	cout << endl << endl << endl;//游戏的开始界面
	cout << " \033[33m@---------------------------------------------@" << endl;
	cout << " |                                             |" << endl;
	cout << " |   \033[0m1. 游戏规则           \033[32;1m2. 开始游戏(简单)\033[0;33m   |" << endl;
	cout << " |                                             |" << endl;
	cout << " |   3. 开始游戏(普通)     \033[31;1m4. 开始游戏(困难)\033[0;33m   |" << endl;
	cout << " |                                             |" << endl;
	cout << " |   \033[31m5. 开始游戏(极限)\033[1m     0. 退出\033[0;33m             |" << endl;
	cout << " |                                             |" << endl;
	cout << " @---------------------------------------------@\033[0m" << endl;
	cout << endl << endl << endl;
	while ('1' == ch || '0' > ch || ch > '5') {//输入错误或者输入“1”(游戏规则时)重新输入
		cin >> ch;
		if ('1' == ch) {//1.游戏规则(打印游戏规则)
			cout << "游戏规则：" << endl;
			cout << "    “P”是你，“*”是墙，a键左移，d键右移，w键跳，s及其其他键让时间流逝，上面显示你的\033[32;1m生\033[0;33m命\033[31;1m值\033[0m，如果你生命值\033[31m归0\033[0m，那么你就\033[31;1m失败\033[0m，在遇到\033[31;1m怪物\033[0m的时候，你要按下z键用枪射出\033[33m子弹射\033[31;1m死\033[0m各种各样的\033[31;1m怪物\033[0m，\033[31;1m怪物\033[0m是怎么样的你自己看，如果你碰到了\033[31;1m怪物\033[0m，那么你就会被\033[31;1m怪物伤到\033[0m，\033[31;1m血量减1\033[0m，而打败\033[31;1m小BOSS\033[0m“\033[33m+\033[0m”并从\033[31;1m小BOSS\033[0m的房间中\033[32;1m走出去\033[0m即可\033[32;1m胜利\033[0m。而这个游戏有四种可游玩的模式：一种是\033[32;1m简单模式\033[0m，一种是\033[33m普通模式\033[0m，一种是\033[31;1m困难模式\033[0m，一种是\033[31m极限模式\033[0m，其中，\033[32;1m简单模式\033[0m会让你开始时有\033[32;1m8滴血\033[0m，\033[33m普通模式\033[0m会让你开始时有\033[33m5滴血\033[0m，\033[31;1m困难模式\033[0m会让你开始时有\033[31;1m3滴血\033[0m，而\033[31m极限模式\033[0m会让你开始时\033[31;4m只有1滴血\033[0m；同样，\033[4m我们也会根据你选择的\033[31;1m难度\033[0;4m来选择不同的告知你\033[32;1m胜利方式\033[0m：\033[4m如果你选择了\033[31;1m难玩的难度\033[0;4m，那么告知你\033[32;1m胜利方式\033[0;4m也更\033[32;1m新奇\033[0;4m；反之如果你选择了\033[32;1m易玩的难度\033[0;4m，那么告知你\033[32;1m胜利方式\033[0;4m也\033[31;1m更不新奇\033[0m，并且不同的\033[31;1m难度\033[0m也有不同的\033[32;1m战前回血概率\033[0m与\033[31;1m小BOSS\033[32m战前回血概率\033[0m，\033[4m越\033[31;1m难\033[0;4m这个概率就越\033[31;1m小\033[0m。这就是这个打小怪游戏的规则，你听明白了吗?" << endl << endl;
		}
		else if ('0' > ch || ch > '5') {//输入错误
			cout << "\033[31;1m输入错误，请重新输入\033[0m" << endl << endl;
		}
		rewind(stdin);
	}
	if ('0' == ch) {//退出
		cout << endl << "欢迎下次游玩" << endl;
		return 0;
	}
	d = (difficulty)(ch - '2');//难度选择('2'~'5') - '2' = (0~3)
	int temparra[4] = { 8, 5, 3, 1 };
	p.sgetxyhs(HEAL) = temparra[d];//根据玩家选的难度来设置玩家的生命
	system("cls");
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && (&strmap[9][1] == cp || &strmap[8][1] == cp)) {
			b = 1;
			strmap[9][0] = '*';
			for (i = 1; i < 10; i++) {
				for (ch = 1; ch < 10; ch++) {
					'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
				}
			}
			switch (vism.front().id) {//地牢的生成
			case 0:
				for (ch = 3; ch < 8; ch++) {
					for (i = 3; i < 8; i++) {
						strmap[ch][i] = '*';
					}
				}
				{
					int arr[10] = { 1, 2, 5, 2, 7, 1, 1, 8, 6, 7 };
					for (i = 0; i < 10; i += 2) {
						strmap[arr[i]][arr[i + 1]] = (8 != i ? '*' : strmap[7][7] = ' ');
					}
				}
				break;
			case 1:
				strmap[2][8] = '*';
				break;
			case 2:
				strmap[4][6] = '*';
				strmap[7][7] = '*';
				break;
			case 3:
			{
				char* cparr[6] = { &strmap[2][4], &strmap[4][1], &strmap[4][7], &strmap[8][1], &strmap[8][7], &strmap[6][4] };
				for (ch = 0; ch < 3; ch++) {
					for (i = 0; i < 6; i++) {
						*cparr[i]++ = '*';
					}
				}
			}
			break;
			case 4:
				for (i = 2; i < 9; i += 2) {
					for (ch = 2; ch < 9; ch += 2) {
						strmap[i][ch] = '*';
					}
				}
				{
					int arr[12] = { 8, 5, 6, 3, 6, 7, 4, 5, 8, 9, 4, 1 };
					for (i = 0; i < 12; i += 2) {
						strmap[arr[i]][arr[i + 1]] = '*';
					}
				}
				break;
			case 6:
			{
				int temparr[5] = { 8,5,2,4,9 };//8,5 5,2 2,4 4,9
				for (ch = 2; ch < 9; ch++) {
					strmap[ch][ch] = '*';
					strmap[ch][10 - ch] = '*';
					if (ch < 6) {
						strmap[temparr[ch - 2]][temparr[ch - 1]] = '*';
					}
				}
				break;
			}
			case 7:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 8:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 9:
				strmap[4][5] = '*';
				strmap[7][5] = '*';
				break;
			case 10:
				for (i = 1; i < 10; i++) {
					for (ch = 1; ch < 10; ch++) {
						'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				for (i = 2; i <= 8; i += 6) {
					for (ch = 4; ch < 7; ch++) {
						strmap[i][ch] = '+';
						strmap[ch][i] = '+';
					}
					for (ch = 2; ch <= 8; ch++) {
						'+' != strmap[i][ch] && (strmap[i][ch] = '-');
						'+' != strmap[ch][i] && (strmap[ch][i] = '-');
					}
				}
				for (i = 2; i <= 8; i++) {
					for (ch = 2; ch <= 8; ch++) {
						'-' == strmap[i][ch] && (strmap[i][ch] = '*');
						'+' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				strmap[5][1] = '*';
				strmap[5][9] = '*';
				break;
			default:
				break;
			}
			memcpy(strmapr, strmap, sizeof strmap);
			strmapr[9][1] = ' ';
			for (ch = 0; vism.front().vmp[ch] != vism.front().vmp.back(); ch++) {
				if ('X' == vism.front().vmp[ch]->getm()) {
					((MX*)vism.front().vmp[ch])->exset(strmap);
				}
			}
			if ('X' == vism.front().vmp[ch]->getm()) {
				((MX*)vism.front().vmp[ch])->exset(strmap);
			}
			for (ch = 0; vism.front().vmp.size() != ch; ch++) {
				*vism.front().vmp[ch]->getcp() = vism.front().vmp[ch]->getm();
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.shootmove(&strmap, 0);//子弹删
		if (vism.size()) {//开始前画“#”以用来告知人们地牢的变化
			for (vector<draw>::iterator it = vmd[5 - vism.size()].begin(); &strmap[9][0] == cp && vmd[5 - vism.size()].back().iwalk + 1; it++) {
				for (char* drawcp = &strmap[it->ix][it->iy]; it->iwalk + 1; drawcp += (1 + 10 * it->brd), it->iwalk--) {
					*drawcp = '#';
				}
			}
		}
		p.printmap(strmap, ba, iunmd);//显示游戏的游玩界面
		ba = 1;
		cin >> ch;
		rewind(stdin);
		'*' != *cp && (*cp = ' ');
		//玩弹怪依次动
		//玩动
		switch (ch) {
		case 'a':
			p.left_move(&cp);
			break;
		case 'd':
			p.right_move(&cp);
			break;
		case 'w':
			p.jump(&cp);
			break;
		case 'z':
			p.shoot(ishoot, &cp);
		default:
			break;
		}
		p.upOrDown(&cp);
		(iunmd || ' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, iunmd = 2, "\a");
		//有怪物使你扣血
		ishoot > 0 && ishoot--;
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (bc ? 2 : rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MUD());
						break;
					case 2:
						mpv.push_back(new MO());
						break;
					case 3:
						mpv.push_back(new MX());
						break;
					default:
						break;
					}
					vism.front().vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					const int arr[8] = { -12, -11, -10, -1, 1, 10, 11, 12 };
					while (!cpa || ' ' != *cpa) {
						int ira = rand() % (cpa = vism.front().vmp.front()->getcp(), 8);
						int imx = (vism.front().vmp.front()->getcp() - &strmap[0][0]) / 11;
						int imy = (vism.front().vmp.front()->getcp() - &strmap[0][0]) % 11;
						bool boolarr[8] = { (imx || imy), !!imx, (imx || 10 != imy), !!imy, 10 != imy, (10 != imx || imy), 10 != imx, (imx || 10 != imy) };
						boolarr[ira] && (cpa += arr[ira]);
					}
					mx = (cpa - &strmap[0][0]) / 11;
					my = (cpa - &strmap[0][0]) % 11;
					switch (bc ? (bc = 0, 2) : ir) {
					case 0:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 2, NULL, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, &em, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 5, NULL, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				'*' != *vism.front().vmp.back()->getcp() && (*vism.front().vmp.back()->getcp() = vism.front().vmp.back()->getm());
				if ('X' == vism.front().vmp.back()->getm()) {
					((MX*)vism.front().vmp.back())->exset(strmapr);
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				'*' != *vism.front().vmp.front()->getcp() && it == vism.front().vmp.end() && (*vism.front().vmp.front()->getcp() = ' ');
				'X' == vism.front().vmp.front()->getm() && (*vism.front().vmp.front()->getcp() = ((MX*)vism.front().vmp.front())->getm(0));
				'*' != *vism.front().vmp.front()->getcp() && (*vism.front().vmp.front()->getcp() = ' ');
				if ('+' == vism.front().vmp.front()->getm()) {
					for_each(vism.front().vmp.begin(), vism.front().vmp.end(), setMempty);
					vism.front().vmp.clear();
					bb = 0;
				} 
				bb && (vism.front().vmp.erase(vism.front().vmp.begin()), 0);//删除怪物
			}
		}
		p.shootmove(&strmap, 1);//子弹动
		if (b && '*' == strmap[9][10]) {//怪物动
			vector<moster*>::iterator vfvp = vism.front().vmp.begin();
			while (!vism.front().vmp.empty() && '+' != (*vfvp)->getm()) {
				if (vism.front().vmp.end() == ++vfvp) {
					break;
				}
			}
			if (1 == vism.size() && bb && (!bosswait || (bosswait--, 0))) {
				char* setcp = &strmap[5][5];
				vo.push_back(new M_o());
				vism.front().vmp.push_back(vo.back());
				vism.front().vmp.back()->set(p.sgetxyhs(), &setcp, 5);
				bosswait = 15;
			}//**会变**
			for (vector<moster*>::iterator it = vism.front().vmp.begin(); vism.front().vmp.end() != it/* || ((*it)->getcp() = tempcp, 0)*/; it++) {
				(*it)->hunt();
				(*it)->mosterdo();
				(*it)->hunt();
			}
			for (vector<trir>::iterator it = p.sgetxyhs()->begin(); p.sgetxyhs()->end() != it; it++) {
				-2 >= it->iy && it->iy++;
			}
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		(iunmd || ' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, iunmd = 2, "\a");
		'*' != *cp && (*cp = 'P');
		//没血使怪物死亡
		system("cls");//清屏
		//如果vism的第0项vmp或者vism为空，那么开门，并头删
		if ((vism.empty() || vism.front().vmp.empty()) && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if (bb && 'P' == strmap[9][10]) {
			b = 0;
			for (vector<trir>::iterator it = p.sgetxyhs()->begin(); p.sgetxyhs()->end() != it; it++) {
				'*' != *it->cp && (*it->cp = ' ');
			}
			p.sgetxyhs()->clear();
			for (i = 0; i < 10; i++) {
				p.printmap(&strmap, ba, i, iunmd);
				!i && (strmap[9][0] = ' ');
				Sleep(100);
				system("cls");
			}
			//下一地牢初始化
			////( <- 分界 )
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			////
			p.printmap(&strmap, ba, 11, iunmd);
			Sleep(100);
			system("cls");
			bool temparrb[8] = { 1, 1, !(rand() % 2), 1, !(rand() % 4), !(rand() % 2), 0, 0};
			if (1 != vism.size()) {//恢复血量
				temparrb[d * 2] && temparra[d] > p.sgetxyhs(HEAL) && (p.sgetxyhs(HEAL)++, ba = 0);
		    }
		    else {
				temparrb[d * 2 + 1] && temparra[d] > p.sgetxyhs(HEAL) && (p.sgetxyhs(HEAL)++, ba = 0);
			}
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
		iunmd && iunmd--;
	}
	char tempstrb[6] = "C2AA7";//胜利
	str[7] = tempstrb[(!bb) * (d + 1)];
	system(str);
	switch ((!bb) * (d + 1)) {//告知你胜利的方式
	case 0:
		cout << "很遗憾，你输了" << endl;
		break;
	case 1:
	case 2:
		cout << "恭喜你，你赢了" << endl;
		break;
	case 3:
		cout << "@------------------@" << endl;
		cout << "|                  |" << endl;
		cout << "|  恭喜你，你赢了  |" << endl;
		cout << "|                  |" << endl;
		cout << "@------------------@" << endl;
		break;
	case 4:
		for (i = 0; i < 15; i++) {
			system("cls");
			win(i);
			Sleep(10);
		}
		for (i = 0; i < 27; i++) {
			strcat(tempstr, tempstra[i % 9]);
			system(tempstr);
			tempstr[7] = 0;
			Sleep(100);
		}
		system("color 0A");
		break;
	default:
		break;
	}
	for_each(mpv.begin(), mpv.end(), del);//释放mpv和vo里new出来的怪物对象
	for_each(vo.begin(), vo.end(), delvo);//释放mpv和vo里new出来的怪物对象
	return 0;
}
*///“vism与里面的vmp的预留大小已改变”^
/*
enum a {
	b,
	c
};

const int& fun(a aa) {
	if (b == aa) {
		return 45;
	}
}

int main() {
	a aa = b;
	cout << fun(c);
	return 0;
}
*///“会报错”^
/*
enum a {
	b,
	c
};

const int& fun(a aa) {
	if (b == aa) {
		return -0;
	}
}

int main() {
	a aa = b;
	cout << fun(c);
	return 0;
}
*///“更会报错”^
/*
int main() {
	list<int>l;
	l.push_back(1);
	l.push_front(3);
	for (list<int>::const_iterator it = l.cbegin(); l.cend() != it; it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
*///“list链表容器的初步使用”^
/*
int main() {
	list<int>l;
	cout << "初始化时list链表容器l的容量：" << l.size() << " " << endl << endl;
	l.push_back(1);
	cout << "往后面添加元素后list链表容器l的容量：" << l.size() << " " << endl << endl;
	l.push_front(1);
	cout << "往前面添加元素后list链表容器l的容量：" << l.size() << " " << endl;
	return 0;
}
*///“list链表容器的size方法调用”^
/*
int main() {
	list<int>l;
	l.push_front(1);
	l.push_back(2);
	l.push_front(3);
	cout << l.front() << " " << l.back() << " ";
	l.pop_front();
	cout << l.front() << " ";
	l.pop_back();
	cout << l.back() << " " << endl;
	return 0;
}
*///“list容器的pop_front删除前面元素方法和pop_back删除后面元素方法”^
/*
int main() {
	list<int>l;
	for (int i = 0; i < 10; i++) {
		l.push_back(0);
	}
	cout << l.size() << " <- 此时list链表容器的容量" << endl;
	l.clear();
	cout << l.size() << " <- 删除所有元素后list链表容器的容量" << endl;
	return 0;
}
*///“list容器clear方法的调用”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
struct node {
	T t;
	node next;
};
template<class T>
class mylist {
private:
	int capacity;
public:
	T& operator[](int i){
	
	}
	T& at(int i){
	
	}
	int findindex(T t){
	
	}
	int capacity(){
	
	}
	void push_back(T t){
	
	}
	void insert(T t, int i){
	
	}	
	void clear(){
	
	}
	void del_back(){
	
	}
	bool IsEmpty(){
	
	}
};
*///“单向链表容器已创建”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		node(T tc, node* nextc) {
			t = tc;
			next = nextc;
		}
		node() {
			t = NULL;
			next = NULL;
		}
	};
	node head;
public:
	friend class node;
	T& operator[](int i){
		
	}
	T& at(int i){

	}
	int findindex(T t){
	
	}
	int capacity(){
		return ic;
	}
	void push_back(T t){

	}
	void insert(T t, int i){
		
	}	
	void clear(){
		ic = 0;
	}
	void del_back(){
	
	}
	bool IsEmpty(){
		return !ic;
	}
	mylist(){}
	mylist(T* tarr) {
		if (sizeof *tarr) {
			ic = sizeof *tarr / sizeof (*tarr)[0];
			//...
		}
	}
	~mylist() {
		while (head.next) {
			del_back();
		}
	}
};
*///“部分成员函数已完成”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		set(T tf, node* nextf) {
			this->t = tf;
			this->next = nextf;
		}
	};
	node* head;
public:
	T& operator[](int i){
		
	}
	T& at(int i){

	}
	int indexfind(T t){
	
	}
	int capacity(){
		return ic;
	}
	void push_back(T t){
		node* findnode = head;
		node* newnode = new node;
		newnode->set(t, NULL);
		while (findnode->next) {
			findnode = findnode->next;
		}
		findnode->next = newnode;
	}
	void insert(T t, int i){
		if (ic > i && i >= 0) {
			node* findnode = head->next;
			node* newnode = new node;
			newnode->set(t, NULL);
			for (; i; i--) {
				findnode = findnode->next;
			}
			findnode->next = newnode;
		}
	}	
	void clear(){
		//...
		ic = 0;
	}
	void del_back(){
		
	}
	void del_index(int index) {

	}
	bool IsEmpty(){
		return !ic;
	}
	mylist(){}
	mylist(T* tarr) {
		if (sizeof *tarr) {
			ic = sizeof *tarr / sizeof (*tarr)[0];
			//...
		}
	}
	~mylist() {
		while (head.next) {
			del_back();
		}
	}
};
*///“链表元素插入函数已完成”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		set(T tf, node* nextf) {
			this->t = tf;
			this->next = nextf;
		}
	};
	node* head;
public:
	T& operator[](int i) const {
		return at(i);
	}
	T& at(int i) const {
		node* findnode = head->next;
		for (; i; i--) {
			findnode = findnode->next;
		}
		return findnode->t;
	}
	int indexfind(T t){
		
	}
	int capacity() const {
		return ic;
	}
	void push_back(T t){
		node* findnode = head;
		node* newnode = new node;
		newnode->set(t, NULL);
		while (findnode->next) {
			findnode = findnode->next;
		}
		findnode->next = newnode;
	}
	void insert(T t, int i){
		if (ic > i && i >= 0) {
			node* findnode = head->next;
			node* newnode = new node;
			newnode->set(t, NULL);
			for (; i; i--) {
				findnode = findnode->next;
			}
			findnode->next = newnode;
		}
	}	
	void clear(){
		while (ic) {
			del_back();
		}
	}
	void del_back(){
		if (ic) {
			node* prenode = head;
			while (prenode->next->next) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			prenode->next = NULL;
			delete delnode;
			ic--;
		}
	}
	void del_index(int index) {
		if (ic - 1 == index) {
			del_back();
		}
		else if (ic > index && index >= 0) {
			node* prenode = head;
			for (; index > 0; index--) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			node* nextnode = delnode->next;
			prenode->next = nextnode;
			delnode->next = NULL;
			delete delnode;
		}
		ic--;
	}
	bool IsEmpty() const {
		return !ic;
	}
	mylist(){}
	mylist(const T* const tarr) {
		if (sizeof *tarr) {
			ic = sizeof *tarr / sizeof (*tarr)[0];
			T* tp = tarr;
			for (int i = 0; i < ic; i++) {
				push_back(*tp++);
			}
		}
	}
	~mylist() {
		while (head->next) {
			del_back();
		}
	}
};
*///“就差indexfind成员函数没实现”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		set(T tf, node* nextf) {
			this->t = tf;
			this->next = nextf;
		}
	};
	node* head;
public:
	T& operator[](int i) const {
		return at(i);
	}
	T& at(int i) const {
		node* findnode = head->next;
		for (; i; i--) {
			findnode = findnode->next;
		}
		return findnode->t;
	}
	int indexfind(T t){
		node* findnode = head;
		int index = 0;
		while (head->next) {
			findnode = findnode->next;
			if (findnode->t) {
				return index;
			}
			index++;
		}
		return -1;
	}
	int capacity() const {
		return ic;
	}
	void push_back(T t){
		node* findnode = head;
		node* newnode = new node;
		newnode->set(t, NULL);
		while (findnode->next) {
			findnode = findnode->next;
		}
		findnode->next = newnode;
	}
	void insert(T t, int i){
		if (ic > i && i >= 0) {
			node* findnode = head->next;
			node* newnode = new node;
			newnode->set(t, NULL);
			for (; i; i--) {
				findnode = findnode->next;
			}
			findnode->next = newnode;
		}
	}	
	void clear(){
		while (ic) {
			del_back();
		}
	}
	void del_back(){
		if (ic) {
			node* prenode = head;
			while (prenode->next->next) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			prenode->next = NULL;
			delete delnode;
			ic--;
		}
	}
	void del_index(int index) {
		if (ic - 1 == index) {
			del_back();
		}
		else if (ic > index && index >= 0) {
			node* prenode = head;
			for (; index > 0; index--) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			node* nextnode = delnode->next;
			prenode->next = nextnode;
			delnode->next = NULL;
			delete delnode;
		}
		ic--;
	}
	bool IsEmpty() const {
		return !ic;
	}
	mylist(){}
	mylist(const T* const tarr) {
		if (sizeof *tarr) {
			ic = sizeof *tarr / sizeof (*tarr)[0];
			T* tp = tarr;
			for (int i = 0; i < ic; i++) {
				push_back(*tp++);
			}
		}
	}
	~mylist() {
		while (head->next) {
			del_back();
		}
	}
};
*///“mylist单向链表的所有基本的成员方法已完成”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		set(T tf, node* nextf) {
			this->t = tf;
			this->next = nextf;
		}
	};
	node* head;
public:
	mylist() {}
	int indexfind(T t) {
		node* findnode = head;
		int index = 0;
		while (head->next) {
			findnode = findnode->next;
			if (findnode->t) {
				return index;
			}
			index++;
		}
		return -1;
	}
	int capacity() const {
		return ic;
	}
	void push_back(T t) {
		node* findnode = head;
		node* newnode = new node;
		newnode->set(t, NULL);
		while (findnode->next) {
			findnode = findnode->next;
		}
		findnode->next = newnode;
	}
	void operator=(const mylist ml) {
		this->ic = ml.ic;
		int ia = 0;
		clear();
		node* findnode = head->next;
		for (int i = 0; i < this->ic; i++) {
			i && (findnode = findnode->next);
			push_back(findnode->t);
		}
	}
	mylist(const mylist ml) {
		*this = ml;
	}
	mylist(const T* const tarr) {
		if (sizeof * tarr) {
			ic = sizeof * tarr / sizeof(*tarr)[0];
			T* tp = tarr;
			for (int i = 0; i < ic; i++) {
				push_back(*tp++);
			}
		}
	}
	void insert(T t, int i) {
		if (ic > i && i >= 0) {
			node* findnode = head->next;
			node* newnode = new node;
			newnode->set(t, NULL);
			for (; i; i--) {
				findnode = findnode->next;
			}
			findnode->next = newnode;
		}
	}
	void del_back() {
		if (ic) {
			node* prenode = head;
			while (prenode->next->next) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			prenode->next = NULL;
			delete delnode;
			ic--;
		}
	}
	void clear() {
		while (ic) {
			del_back();
		}
	}
	~mylist() {
		clear();
	}
	void del_index(int index) {
		if (ic - 1 == index) {
			del_back();
		}
		else if (ic > index && index >= 0) {
			node* prenode = head;
			for (; index > 0; index--) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			node* nextnode = delnode->next;
			prenode->next = nextnode;
			delnode->next = NULL;
			delete delnode;
		}
		ic--;
	}
	bool IsEmpty() const {
		return !ic;
	}
	T& at(int i) const {
		node* findnode = head->next;
		for (; i; i--) {
			findnode = findnode->next;
		}
		return findnode->t;
	}
	T& operator[](int i) const {
		return at(i);
	}
};
*///“mylist单向链表的拷贝方法已变为深拷贝”^
/*
//Game.cpp
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>
#include <Windows.h>
#include "draw.h"
enum difficulty {//难度
	EASY,
	NORMAL,
	HARD,
	LIMIT
};
void MShow(moster*& mp) {
	('X' == mp->getm() || '*' != *mp->getcp()) && (*mp->getcp() = mp->getm());//左边条件防出bug
}
void del(moster*& mp) {
	delete mp;
}
void delvo(M_o*& mp) {
	delete mp;
}
void setMempty(moster*& mp) {
	'*' != *mp->getcp() && (*mp->getcp() = ' ');//左边条件也防出bug
}
void start(int ichoose) {//开始时打印大字函数
	switch (ichoose) {
	case 14:
		cout << "      *                  *          *           " << endl;
	case 13:
		cout << "      *                  *          * ********  " << endl;
	case 12:
		cout << "      *  ********        *          *  *     *  " << endl;
	case 11:
		cout << "   ******    *           *        * **  *   *   " << endl;
	case 10:
		cout << "      *      *           *        * * *  * *    " << endl;
	case 9:
		cout << "      * *    *        *  *  *     * *     **    " << endl;
	case 8:
		cout << "     ***     *       **  *   *   *  *   **  *   " << endl;
	case 7:
		cout << "   ** *      *      *    *    *     * **  *  ** " << endl;
	case 6:
		cout << "      *      *     *     *    **    *     *     " << endl;
	case 5:
		cout << "      *      *    *      *     *    *     *     " << endl;
	case 4:
		cout << "      *      *           *          *  *******  " << endl;
	case 3:
		cout << "      *      *           *          *     *     " << endl;
	case 2:
		cout << "      *      *           *          *     *     " << endl;
	case 1:
		cout << "    * *    * *         * *          * ********* " << endl;
	case 0:
		cout << "     *      *           *           *           " << endl;
	default:
		break;
	}
} 
void win(int ichoose) {//胜利后打印函数
	switch (ichoose) {
	case 14:
		cout << "      *   *            *           *  *                       *  *              *                     " << endl;
	case 13:
		cout << "      *   *       ************     *  *                       *  *        ************** *************" << endl;
	case 12:
		cout << "   ************        *           *  *                       *  *         *                        * " << endl;
	case 11:
		cout << "      *   *        **********     *  ********                *  ********   ************            *  " << endl;
	case 10:
		cout << "      *   *                       *  *      *                *  *      *    *       *            **   " << endl;
	case 9:
		cout << "  **************   **********    ** *      *                ** *      *     *********          **     " << endl;
	case 8:
		cout << "      *    *       *        *   * *     *                  * *     *                           *      " << endl;
	case 7:
		cout << "     *  *   *      **********     *     *                    *     *      *** ***** ***        *      " << endl;
	case 6:
		cout << "    *   *    *       *    *       *   * * *                  *   * * *    * * *   * * *        *      " << endl;
	case 5:
		cout << "  **    *     ** **************   *   * *  *      **         *   * *  *   *** *   * * *        *      " << endl;
	case 4:
		cout << "     *  **  *                     *  *  *  **     **         *  *  *  **  * * * * * ***        *      " << endl;
	case 3:
		cout << "    *   * *  *     *********      * *   *   *      *         * *   *   *  *** * * * * *        *      " << endl;
	case 2:
		cout << "   *    * *  *     *       *      *     *         *          *     *      * *   *   * *        *      " << endl;
	case 1:
		cout << "      * *          *********      *   * *        *           *   * *      * *  * * *  **     * *      " << endl;
	case 0:
		cout << "       *           *       *      *    *                     *    *      *  * *   *    *      *       " << endl;
	default:
		break;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	char strmap[11][11] = {//地牢图
		'*','*','*','*','*','*','*','*','*','*','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'P',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*','*','*','*','*','*','*','*','*','*','*',
	};
	bool ba = 1;
	bool bb = 1;
	bool bc = 1;
	char ch = 0;
	int iunmd = 0;
	vector<M_o*>vo;//小BOSS战时需要
	vector<draw>vmd[5] = { {{5,2,6,1}}, {{3,2,4,0}, {7,2,3,1}, {3,5,4,0}, {3,5,3,1}, {3,8,4,0}}, {{3,2,4,0},{3,5,4,0},{3,8,4,0},{7,2,6,1}}, {{3,2,3,1},{3,5,4,0},{7,2,6,1}}, {{5,3,4,1},{3,5,4,0}} };//<-画“#”时所需要的数组
	multimap<int, int>mwasd[4] = { {{9,1},{9,3},{3,3},{5,3},{7,3},{9,3},{8,4},{8,8},{6,8},{4,8}}, {{2,3},{9,9},{3,8},{5,8},{7,8},{9,2}}, {{2,2},{2,7},{1,9}}, {{1,1},{2,4},{4,3},{6,3},{8,3},{8,7}} };//<-画“#”时所需要的数组
	vo.reserve(99999);
	int i = 0;
	int temparr[6] = { 4, 8, 12, 15, 17, 18 };
	int ia = rand() % 10 + 1;// 后：+1 +1 +1 +1 +2 +2 +2 +2 +3 +3 +3 +3 +4 +4 +4 +5 +5 +6
	int tempir = rand() % 22;
	for (i = 0; i < 6; i++) {
		if (tempir < temparr[i]) {
			ia += (i + 1);
			break;
		}
	}
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char**, WASD>m[3];
	map<char**, WASD>em;//追踪map
	char* cparr[45] = { NULL };
	char** cpp = cparr;
	for (WASD w = W; E != w; ++w) {//第5地牢的怪物移动路线
		switch (w) {
		case W:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[10 - i][i];
				m[0].insert({cpp++, W});
			}
			break;
		case A:
			for (i = 6; i < 10; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, A});
			}
			break;
		case S:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][10 - i];
				m[0].insert({cpp++, S});
			}
			break;
		case D:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, D});
			}
			break;
		default:
			break;
		}
		for (multimap<int, int>::iterator it = mwasd[w].begin(); mwasd[w].end() != it; it++) {
			*cpp = &strmap[it->first][it->second];
			m[1].insert({ cpp++, w });
		}
	}
	const int arr[4] = { 6,9,1,5 };
	for (i = 0; i < 4; i++) {
		*cpp = &strmap[arr[i]][i % 2 + 1];
		m[2].insert({ cpp++, (WASD)(i / 2 * 2) });//注意：i / 2 * 2 != i
	}
	char strmapr[11][11];
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	vism.reserve(5000);//防bug出
	char* strcp[47] = { &strmap[9][5], &strmap[9][7], &strmap[9][3], &strmap[1][5], &strmap[1][5], &strmap[6][1], &strmap[4][9], &strmap[6][8], &strmap[3][3], &strmap[4][3], &strmap[5][3], &strmap[6][3], &strmap[7][3], &strmap[8][3], &strmap[9][3], &strmap[4][5], &strmap[5][4], &strmap[5][5], &strmap[5][6], &strmap[6][5], &strmap[1][5], &strmap[1][5], &strmap[9][5], &strmap[9][5], &strmap[1][9], &strmap[1][1], &strmap[8][2], &strmap[2][8], &strmap[8][8], &strmap[2][2], &strmap[5][5], &strmap[1][1], &strmap[2][2], &strmap[3][3], &strmap[4][4], &strmap[8][5], &strmap[5][2], &strmap[2][4], &strmap[4][9], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9], &strmap[3][4], &strmap[5][1], &strmap[5][9], &strmap[5][5]};//生成时要的怪物坐标
	vector<moster*>mpv;//mpv里一共要有的怪物们
	char tempstr[9] = "color 0";//为告知你胜利的文字颜色
	char tempstra[10][2] = { "C", "E", "A", "9", "D", "9", "A", "E", "C" };//大文字动态彩色变化数组(system("color 0" + tempstra[x(0<=x<=9)])
	mpv.reserve(10000);//也防bug出
	//随机设置地牢布置与怪物布置
	for (i = 0; ch < 11; ch++) {
		vism.push_back(ism);
		vism.back().vmp.reserve(500);//还防bug出
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {//编号id对应的地牢怪物生成
		case 0:
			for (itemp = i + 8, vism[ch].str = "O&&^^OXX"; i < itemp; i++) {
				switch (vism[ch].str[8 - (itemp - i)]) {
				case '&':
					mpv.push_back(new Mand());
					break;
				case '^':
					mpv.push_back(new MUD());
					break;
				case 'O':
					mpv.push_back(new MO());
					break;
				case 'X':
					mpv.push_back(new MX());
					break;
				default:
					break;
				}
				vism[ch].vmp.push_back(mpv[i]);
				if (8 == itemp - i) {
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &em, NULL, NULL, 9, 5);
				}
				else {
					switch (vism[ch].str[8 - (itemp - i)]) {
					case '&':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, NULL, NULL, 0, 0, itemp - i - 6);
						break;
					case '^':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 4, NULL, NULL, NULL, 0, 0, itemp - i - 4, true);
						break;
					case 'O':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &m[2], NULL, NULL, 5, 2);
						break;
					case 'X':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, &cp, &strmap);
						break;
					default:
						break;
					}
				}
			}
			break;
		case 1:
			for (itemp = i + 7; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[7 - (itemp - i) + 8], 5, &m[1], NULL, NULL, 0, 0, 10 - (i - itemp), 3);
			}
			break;
		case 2:
			for (itemp = i + 5; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 15], 3, NULL, NULL, NULL, 0, 0, 1, 1);
			}
			break;
		case 3:
			for (itemp = i + 6, vism[ch].str = "&&^^^^"; i < itemp; i++) {
				if ('&' == (vism[ch].str[6 - (itemp - i)])) {
					mpv.push_back(new Mand());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 3, NULL, NULL, NULL, 0, 0, (i - itemp) % 2);
				}
				else {
					mpv.push_back(new MUD());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 4, NULL, NULL, NULL, 0, 0, (6 - (itemp - i) - 2) & 1, (6 - (itemp - i) - 2) & 2);//qezc(键盘)
				}
			}
			break;
		case 4:
			for (itemp = i + 5, vism[ch].str = "XXXXO"; i < itemp; i++) {
				if ('X' == (vism[ch].str[5 - (itemp - i)])) {
					mpv.push_back(new MX());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 3, NULL, &cp, &strmap);
				}
				else {
					mpv.push_back(new MO());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 5, &em, NULL, NULL, 5, 5);
				}

			}
			break;
		case 5:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 31], 5, &m[0], NULL, NULL, itemp - i, itemp - i);
			}
			break;
		case 6:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MX());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 35], 3, NULL, &cp, &strmap);
			}
			break;
		case 7:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 39], 4, NULL, NULL, NULL, 0, 0, (itemp - i) % 2, (itemp - i + 1) % 2);
			}
			break;
		case 8:
			for (itemp = i + 3; i < itemp; i++) {
				mpv.push_back(new Mand());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[3 - (itemp - i) + 43], 3, NULL, NULL, NULL, 0, 0, !((itemp - i) % 2));
			}
			break;
		case 9:
		{
			char* tempcparr[20] = { NULL };
			for (itemp = i + ia; i < itemp; i++) {
				pair<bool, bool>pbb = { rand() % 2, rand() % 2 };
				pair<int, int>pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				while ((7 == pxy.first || 5 == pxy.first) && 4 == pxy.second || 7 <= pxy.first && 3 >= pxy.second) {
					pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				}
				tempcparr[itemp - i] = &strmap[pxy.first][pxy.second];
				switch (rand() % 7) {
				case 0:
				case 1:
					mpv.push_back(new Mand());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 3, NULL, NULL, NULL, 0, 0, pbb.first);
					break;
				case 2:
				case 3:
					mpv.push_back(new MUD());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 2, NULL, NULL, NULL, 0, 0, pbb.first, pbb.second);
					break;
				case 4:
				case 5:
					mpv.push_back(new MX());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 3, NULL, &cp, &strmap);
					break;
				case 6:
					mpv.push_back(new MO());
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), tempcparr + itemp - i, 5, &em, NULL, NULL, pxy.first, pxy.second);
					break;
				default:
					break;
				}
			}
		}
		break;
		default:
			break;
		}
	}
	random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除本次游戏不需要的地牢
	}
	vism.push_back(ism);//小BOSS的创建
	vism.back().id = 10;
	mpv.push_back(new Mplus());
	vism.back().vmp.push_back(mpv.back());
	vism.back().vmp.back()->set(p.sgetxyhs(), &strcp[46], 10);
	int ishoot = 0;
	int bosswait = 0;
	bool b = 0;
	char str[9] = "color 0";
	difficulty d = EASY;//初始值(EASY)
	//开始界面
	for (i = 0; i < 15; i++) {//大文字缓缓出现
		system("cls");
		start(i);
		Sleep(10);
	}
	Sleep(10);
	for (i = 0; i < 9; i++) {//使大文字变成动态的彩色
		strcat(tempstr, tempstra[i]);
		system(tempstr);
		tempstr[7] = 0;
		Sleep(100);
	}
	system("color 07");
	Sleep(500);
	cout << endl << endl << endl;//游戏的开始界面
	cout << " \033[33m@---------------------------------------------@" << endl;
	cout << " |                                             |" << endl;
	cout << " |   \033[0m1. 游戏规则           \033[32;1m2. 开始游戏(简单)\033[0;33m   |" << endl;
	cout << " |                                             |" << endl;
	cout << " |   3. 开始游戏(普通)     \033[31;1m4. 开始游戏(困难)\033[0;33m   |" << endl;
	cout << " |                                             |" << endl;
	cout << " |   \033[31m5. 开始游戏(极限)\033[1m     0. 退出\033[0;33m             |" << endl;
	cout << " |                                             |" << endl;
	cout << " @---------------------------------------------@\033[0m" << endl;
	cout << endl << endl << endl;
	while ('1' == ch || '0' > ch || ch > '5') {//输入错误或者输入“1”(游戏规则时)重新输入
		cin >> ch;
		if ('1' == ch) {//1.游戏规则(打印游戏规则)
			cout << "游戏规则：" << endl;
			cout << "    “P”是你，“*”是墙，a键左移，d键右移，w键跳，s及其其他键让时间流逝，上面显示你的\033[32;1m生\033[0;33m命\033[31;1m值\033[0m，如果你生命值\033[31m归0\033[0m，那么你就\033[31;1m失败\033[0m，在遇到\033[31;1m怪物\033[0m的时候，你要按下z键用枪射出\033[33m子弹射\033[31;1m死\033[0m各种各样的\033[31;1m怪物\033[0m，\033[31;1m怪物\033[0m是怎么样的你自己看，如果你碰到了\033[31;1m怪物\033[0m，那么你就会被\033[31;1m怪物伤到\033[0m，\033[31;1m血量减1\033[0m，而打败\033[31;1m小BOSS\033[0m“\033[33m+\033[0m”并从\033[31;1m小BOSS\033[0m的房间中\033[32;1m走出去\033[0m即可\033[32;1m胜利\033[0m。而这个游戏有四种可游玩的模式：一种是\033[32;1m简单模式\033[0m，一种是\033[33m普通模式\033[0m，一种是\033[31;1m困难模式\033[0m，一种是\033[31m极限模式\033[0m，其中，\033[32;1m简单模式\033[0m会让你开始时有\033[32;1m8滴血\033[0m，\033[33m普通模式\033[0m会让你开始时有\033[33m5滴血\033[0m，\033[31;1m困难模式\033[0m会让你开始时有\033[31;1m3滴血\033[0m，而\033[31m极限模式\033[0m会让你开始时\033[31;4m只有1滴血\033[0m；同样，\033[4m我们也会根据你选择的\033[31;1m难度\033[0;4m来选择不同的告知你\033[32;1m胜利方式\033[0m：\033[4m如果你选择了\033[31;1m难玩的难度\033[0;4m，那么告知你\033[32;1m胜利方式\033[0;4m也更\033[32;1m新奇\033[0;4m；反之如果你选择了\033[32;1m易玩的难度\033[0;4m，那么告知你\033[32;1m胜利方式\033[0;4m也\033[31;1m更不新奇\033[0m，并且不同的\033[31;1m难度\033[0m也有不同的\033[32;1m战前回血概率\033[0m与\033[31;1m小BOSS\033[32m战前回血概率\033[0m，\033[4m越\033[31;1m难\033[0;4m这个概率就越\033[31;1m小\033[0m。这就是这个打小怪游戏的规则，你听明白了吗?" << endl << endl;
		}
		else if ('0' > ch || ch > '5') {//输入错误
			cout << "\033[31;1m输入错误，请重新输入\033[0m" << endl << endl;
		}
		rewind(stdin);
	}
	if ('0' == ch) {//退出
		cout << endl << "欢迎下次游玩" << endl;
		return 0;
	}
	d = (difficulty)(ch - '2');//难度选择('2'~'5') - '2' = (0~3)
	int temparra[4] = { 8, 5, 3, 1 };
	p.sgetxyhs(HEAL) = temparra[d];//根据玩家选的难度来设置玩家的生命
	system("cls");
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && (&strmap[9][1] == cp || &strmap[8][1] == cp)) {
			b = 1;
			strmap[9][0] = '*';
			for (i = 1; i < 10; i++) {
				for (ch = 1; ch < 10; ch++) {
					'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
				}
			}
			switch (vism.front().id) {//地牢的生成
			case 0:
				for (ch = 3; ch < 8; ch++) {
					for (i = 3; i < 8; i++) {
						strmap[ch][i] = '*';
					}
				}
				{
					int arr[10] = { 1, 2, 5, 2, 7, 1, 1, 8, 6, 7 };
					for (i = 0; i < 10; i += 2) {
						strmap[arr[i]][arr[i + 1]] = (8 != i ? '*' : strmap[7][7] = ' ');
					}
				}
				break;
			case 1:
				strmap[2][8] = '*';
				break;
			case 2:
				strmap[4][6] = '*';
				strmap[7][7] = '*';
				break;
			case 3:
			{
				char* cparr[6] = { &strmap[2][4], &strmap[4][1], &strmap[4][7], &strmap[8][1], &strmap[8][7], &strmap[6][4] };
				for (ch = 0; ch < 3; ch++) {
					for (i = 0; i < 6; i++) {
						*cparr[i]++ = '*';
					}
				}
			}
			break;
			case 4:
				for (i = 2; i < 9; i += 2) {
					for (ch = 2; ch < 9; ch += 2) {
						strmap[i][ch] = '*';
					}
				}
				{
					int arr[12] = { 8, 5, 6, 3, 6, 7, 4, 5, 8, 9, 4, 1 };
					for (i = 0; i < 12; i += 2) {
						strmap[arr[i]][arr[i + 1]] = '*';
					}
				}
				break;
			case 6:
			{
				int temparr[5] = { 8,5,2,4,9 };//8,5 5,2 2,4 4,9
				for (ch = 2; ch < 9; ch++) {
					strmap[ch][ch] = '*';
					strmap[ch][10 - ch] = '*';
					if (ch < 6) {
						strmap[temparr[ch - 2]][temparr[ch - 1]] = '*';
					}
				}
				break;
			}
			case 7:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 8:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 9:
				strmap[4][5] = '*';
				strmap[7][5] = '*';
				break;
			case 10:
				for (i = 1; i < 10; i++) {
					for (ch = 1; ch < 10; ch++) {
						'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				for (i = 2; i <= 8; i += 6) {
					for (ch = 4; ch < 7; ch++) {
						strmap[i][ch] = '+';
						strmap[ch][i] = '+';
					}
					for (ch = 2; ch <= 8; ch++) {
						'+' != strmap[i][ch] && (strmap[i][ch] = '-');
						'+' != strmap[ch][i] && (strmap[ch][i] = '-');
					}
				}
				for (i = 2; i <= 8; i++) {
					for (ch = 2; ch <= 8; ch++) {
						'-' == strmap[i][ch] && (strmap[i][ch] = '*');
						'+' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				strmap[5][1] = '*';
				strmap[5][9] = '*';
				break;
			default:
				break;
			}
			memcpy(strmapr, strmap, sizeof strmap);
			strmapr[9][1] = ' ';
			for (ch = 0; vism.front().vmp[ch] != vism.front().vmp.back(); ch++) {
				if ('X' == vism.front().vmp[ch]->getm()) {
					((MX*)vism.front().vmp[ch])->exset(strmap);
				}
			}
			if ('X' == vism.front().vmp[ch]->getm()) {
				((MX*)vism.front().vmp[ch])->exset(strmap);
			}
			for (ch = 0; vism.front().vmp.size() != ch; ch++) {
				*vism.front().vmp[ch]->getcp() = vism.front().vmp[ch]->getm();
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.shootmove(&strmap, 0);//子弹删
		if (vism.size()) {//开始前画“#”以用来告知人们地牢的变化
			for (vector<draw>::iterator it = vmd[5 - vism.size()].begin(); &strmap[9][0] == cp && vmd[5 - vism.size()].back().iwalk + 1; it++) {
				for (char* drawcp = &strmap[it->ix][it->iy]; it->iwalk + 1; drawcp += (1 + 10 * it->brd), it->iwalk--) {
					*drawcp = '#';
				}
			}
		}
		p.printmap(strmap, ba, iunmd);//显示游戏的游玩界面
		ba = 1;
		cin >> ch;
		rewind(stdin);
		'*' != *cp && (*cp = ' ');
		//玩弹怪依次动
		//玩动
		switch (ch) {
		case 'a':
			p.left_move(&cp);
			break;
		case 'd':
			p.right_move(&cp);
			break;
		case 'w':
			p.jump(&cp);
			break;
		case 'z':
			p.shoot(ishoot, &cp);
		default:
			break;
		}
		p.upOrDown(&cp);
		(iunmd || ' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, iunmd = 2, "\a");
		//有怪物使你扣血
		ishoot > 0 && ishoot--;
		if (' ' != strmap[9][10]) {//怪物死
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (bc ? 2 : rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MUD());
						break;
					case 2:
						mpv.push_back(new MO());
						break;
					case 3:
						mpv.push_back(new MX());
						break;
					default:
						break;
					}
					vism.front().vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					const int arr[8] = { -12, -11, -10, -1, 1, 10, 11, 12 };
					while (!cpa || ' ' != *cpa) {
						int ira = rand() % (cpa = vism.front().vmp.front()->getcp(), 8);
						int imx = (vism.front().vmp.front()->getcp() - &strmap[0][0]) / 11;
						int imy = (vism.front().vmp.front()->getcp() - &strmap[0][0]) % 11;
						bool boolarr[8] = { (imx || imy), !!imx, (imx || 10 != imy), !!imy, 10 != imy, (10 != imx || imy), 10 != imx, (imx || 10 != imy) };
						boolarr[ira] && (cpa += arr[ira]);
					}
					mx = (cpa - &strmap[0][0]) / 11;
					my = (cpa - &strmap[0][0]) % 11;
					switch (bc ? (bc = 0, 2) : ir) {
					case 0:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 2, NULL, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, &em, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 5, NULL, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				'*' != *vism.front().vmp.back()->getcp() && (*vism.front().vmp.back()->getcp() = vism.front().vmp.back()->getm());
				if ('X' == vism.front().vmp.back()->getm()) {
					((MX*)vism.front().vmp.back())->exset(strmapr);
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				'*' != *vism.front().vmp.front()->getcp() && it == vism.front().vmp.end() && (*vism.front().vmp.front()->getcp() = ' ');
				'X' == vism.front().vmp.front()->getm() && (*vism.front().vmp.front()->getcp() = ((MX*)vism.front().vmp.front())->getm(0));
				'*' != *vism.front().vmp.front()->getcp() && (*vism.front().vmp.front()->getcp() = ' ');
				if ('+' == vism.front().vmp.front()->getm()) {
					for_each(vism.front().vmp.begin(), vism.front().vmp.end(), setMempty);
					vism.front().vmp.clear();
					bb = 0;
				} 
				bb && (vism.front().vmp.erase(vism.front().vmp.begin()), 0);//删除怪物
			}
		}
		p.shootmove(&strmap, 1);//子弹动
		if (b && '*' == strmap[9][10]) {//怪物动
			vector<moster*>::iterator vfvp = vism.front().vmp.begin();
			while (!vism.front().vmp.empty() && '+' != (*vfvp)->getm()) {
				if (vism.front().vmp.end() == ++vfvp) {
					break;
				}
			}
			if (1 == vism.size() && bb && (!bosswait || (bosswait--, 0))) {
				char* setcp = &strmap[5][5];
				vo.push_back(new M_o());
				vism.front().vmp.push_back(vo.back());
				vism.front().vmp.back()->set(p.sgetxyhs(), &setcp, 5);
				bosswait = 15;
			}//**会变**
			for (vector<moster*>::iterator it = vism.front().vmp.begin(); vism.front().vmp.end() != it/* || ((*it)->getcp() = tempcp, 0)*/; it++) {
				(*it)->hunt();
				(*it)->mosterdo();
				(*it)->hunt();
			}
			for (vector<trir>::iterator it = p.sgetxyhs()->begin(); p.sgetxyhs()->end() != it; it++) {
				-2 >= it->iy && it->iy++;
			}
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		(iunmd || ' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, iunmd = 2, "\a");
		'*' != *cp && (*cp = 'P');
		//没血使怪物死亡
		system("cls");//清屏
		//如果vism的第0项vmp或者vism为空，那么开门，并头删
		if ((vism.empty() || vism.front().vmp.empty()) && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if (bb && 'P' == strmap[9][10]) {
			b = 0;
			for (vector<trir>::iterator it = p.sgetxyhs()->begin(); p.sgetxyhs()->end() != it; it++) {
				'*' != *it->cp && (*it->cp = ' ');
			}
			p.sgetxyhs()->clear();
			for (i = 0; i < 10; i++) {
				p.printmap(&strmap, ba, i, iunmd);
				!i && (strmap[9][0] = ' ');
				Sleep(100);
				system("cls");
			}
			//下一地牢初始化
			////( <- 分界 )
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			////
			p.printmap(&strmap, ba, 11, iunmd);
			Sleep(100);
			system("cls");
			bool temparrb[8] = { 1, 1, !(rand() % 2), 1, !(rand() % 4), !(rand() % 2), 0, 0};
			if (1 != vism.size()) {//恢复血量
				temparrb[d * 2] && temparra[d] > p.sgetxyhs(HEAL) && (p.sgetxyhs(HEAL)++, ba = 0);
		    }
		    else {
				temparrb[d * 2 + 1] && temparra[d] > p.sgetxyhs(HEAL) && (p.sgetxyhs(HEAL)++, ba = 0);
			}
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
		iunmd && iunmd--;
	}
	char tempstrb[6] = "C2AA7";//胜利
	str[7] = tempstrb[(!bb) * (d + 1)];
	system(str);
	switch ((!bb) * (d + 1)) {//告知你胜利的方式
	case 0:
		cout << "很遗憾，你输了" << endl;
		break;
	case 1:
	case 2:
		cout << "恭喜你，你赢了" << endl;
		break;
	case 3:
		cout << "@------------------@" << endl;
		cout << "|                  |" << endl;
		cout << "|  恭喜你，你赢了  |" << endl;
		cout << "|                  |" << endl;
		cout << "@------------------@" << endl;
		break;
	case 4:
		for (i = 0; i < 15; i++) {
			system("cls");
			win(i);
			Sleep(10);
		}
		for (i = 0; i < 27; i++) {
			strcat(tempstr, tempstra[i % 9]);
			system(tempstr);
			tempstr[7] = 0;
			Sleep(100);
		}
		system("color 0A");
		break;
	default:
		break;
	}
	for_each(mpv.begin(), mpv.end(), del);//释放mpv和vo里new出来的怪物对象
	for_each(vo.begin(), vo.end(), delvo);//释放mpv和vo里new出来的怪物对象
	return 0;
}
*///“怪物死”注释已添加^
/*
//Player.cpp
#include <iostream>
#include "Player.h"
#include "cmp.h"
#include <algorithm>
#include <Windows.h>
using namespace std;
//构造函数
Player::Player(){
	ijh = 0;
	blr = 1;
}
//打印地牢方法
void Player::printmap(const char strmap[11][11], const bool bwait, const int iunmd) {
	int i = 0;
	int ia = 0;
	cout << "\033[" << (!bwait || 5 < iheal ? "32;1m" : 2 < iheal ? "33m" : "31;1m") << "P * " << iheal << "\033[0m" << endl << endl << endl;//打印玩家的血量
	for (cout << "-----------@" << endl; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : 'v' == strmap[i][ia] ? "36m" : '&' == strmap[i][ia] || '^' == strmap[i][ia] || 'o' == strmap[i][ia] || 'O' == strmap[i][ia] || 'X' == strmap[i][ia] ? "31;1m" : '+' == strmap[i][ia] || '#' == strmap[i][ia] || '@' == strmap[i][ia] ? "33m" : 'P' == strmap[i][ia] && iunmd ? "30;1m" : "0m") << strmap[i][ia] << "\033[0m";///打印地图
		}
		cout << "|" << endl;//竖的外边框
	}
	cout << "-----------@" << endl;//底下的外边框
}
//打印地牢方法(右偏版本)
void Player::printmap(char(*strmap)[11][11], const bool bwait, const int ir, const int iunmd) {
	int i = 0;
	int ia = 0;
	cout << "\033[" << (!bwait || 5 < iheal ? "32;1m" : 2 < iheal ? "33m" : "31;1m") << "P * " << iheal << "\033[0m" << endl << endl << endl;//打印血量
	for (cout << "-----------@" << endl; i < 11; i++) {
		for (ia = ir; 11 > ia - ir; ia++) {
			21 > ia && ia >= 12 && i && 10 != i && ((*strmap)[i][ia % 11] = ' ');//清空左边的墙(除边框)
			cout << "\033[" << ('P' == (*strmap)[i][ia % 11] && iunmd ? "40;1m" : "0m") << (*strmap)[i][ia % 11] << "\033[0m";//打印右偏之后的地图
		}
		cout << "|" << endl;//竖的外边框
	}
	cout << "-----------@" << endl;//底下的外边框
}//跳跃方法
void Player::jump(char** cpp) {
	10 == ix || '*' == (*cpp)[11] && (ijh = JUMPHIGH);
}
//左移方法
void Player::left_move(char** cpp) {
	(iy && '*' != *(*cpp - 1) && ((*cpp)--));
	blr = false;
}
//右移函数
void Player::right_move(char** cpp) {
	10 != iy && '*' != *(*cpp + 1) && ((*cpp)++);
	blr = true;
}
//用于设置或获得玩家的x坐标，y坐标或血量
int& Player::sgetxyhs(XYHS xyhsmode) {
	switch (xyhsmode) {
	case X:
		return ix;
		break;
	case Y:
		return iy;
		break;
	case HEAL:
		return iheal;
		break;
	default:
		break;
	}
}
//设置或获得玩家射出的子弹
vector<trir>* Player::sgetxyhs() {
	return &v;
}
//使玩家上升或下坠
void Player::upOrDown(char** cpp) {
	if (ijh > 0 && ix && '*' != (*cpp)[-11]) {//跳跃后
		ijh--, *cpp -= 11;
	}
	else if ('*' != (*cpp)[11] && (!ix || '*' == (*cpp)[-11])) {//撞墙或跳好后
		ijh = 0, *cpp += 11;
	}
	else if ('*' != (*cpp)[11] && 10 != ix) {//落下时
		*cpp += 11;
	}
	if (ijh > 0 && '*' == (*cpp)[11]) {//防磕头后还能跳
		ijh = 0;
	}
}
//射击方法
void Player::shoot(int& i, char** cpp) {
	if ((!i) && (iy && (!blr) || 10 != iy && blr)) {//检测冷却时间已过并且是否在地牢的边界射过
		v.push_back({ *cpp, iy, blr, 0 });
		i = 3;
	}
}
//子弹的移动方法
void Player::shootmove(const char(*strmap)[11][11], bool bmode) {
	if (bmode) {
		for (vector<trir>::iterator it = v.begin(); v.end() != it; it++) {
			(' ' == *it->cp || '@' == *it->cp) && (*it->cp = ' ');///编译显示之前子弹的移动
			if ('*' == *it->cp || it->bk || (!it->iy && (!it->b)) || (21 == it->iy && it->b)) {
				it->iy = -1;//子弹的销毁
			}
			if (0 <= it->iy) {
				it->cp -= (1 - it->b * 2);//子弹的移动
				it->iy -= (1 - it->b * 2);//子弹y坐标的移动
				(' ' == *it->cp || '@' == *it->cp) && (*it->cp = '@');//显示
			}
		}
	}
	else {
		sort(v.begin(), v.end(), cmp());//按子弹的y坐标进行升序排列
		while ((!v.empty()) && 0 > v.begin()->iy) {
			v.erase(v.begin());//销毁子弹
		}
	}
}
*///注释中多处“函数”已改为“方法”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		set(T tf, node* nextf) {
			this->t = tf;
			this->next = nextf;
		}
	};
	node* head;
public:
	mylist() {}
	int indexfind(T t) {
		node* findnode = head;
		int index = 0;
		while (head->next) {
			findnode = findnode->next;
			if (findnode->t) {
				return index;
			}
			index++;
		}
		return -1;
	}
	int capacity() const {
		return ic;
	}
	void push_back(T t) {
		node* findnode = head;
		node* newnode = new node;
		newnode->set(t, NULL);
		while (findnode->next) {
			findnode = findnode->next;
		}
		findnode->next = newnode;
	}
	void operator=(const mylist ml) {
		this->ic = ml.ic;
		int ia = 0;
		clear();
		node* findnode = head->next;
		for (int i = 0; i < this->ic; i++) {
			i && (findnode = findnode->next);
			push_back(findnode->t);
		}
	}
	mylist(const mylist ml) {
		*this = ml;
	}
	mylist(const T* const tarr) {
		if (sizeof * tarr) {
			ic = sizeof * tarr / sizeof(*tarr)[0];
			T* tp = tarr;
			for (int i = 0; i < ic; i++) {
				push_back(*tp++);
			}
		}
	}
	void insert(T t, int i) {
		if (ic > i && i >= 0) {
			node* findnode = head->next;
			node* newnode = new node;
			newnode->set(t, NULL);
			for (; i; i--) {
				findnode = findnode->next;
			}
			findnode->next = newnode;
		}
	}
	void del_back() {
		if (ic) {
			node* prenode = head;
			while (prenode->next->next) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			prenode->next = NULL;
			delete delnode;
			ic--;
		}
	}
	void clear() const {
		while (ic) {
			del_back();
		}
	}
	~mylist() {
		clear();
	}
	void del_index(int index) {
		if (ic - 1 == index) {
			del_back();
		}
		else if (ic > index && index >= 0) {
			node* prenode = head;
			for (; index > 0; index--) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			node* nextnode = delnode->next;
			prenode->next = nextnode;
			delnode->next = NULL;
			delete delnode;
		}
		ic--;
	}
	bool IsEmpty() const {
		return !ic;
	}
	T& at(int i) {
		node* findnode = head->next;
		for (; i; i--) {
			findnode = findnode->next;
		}
		return findnode->t;
	}
	void myreverse() {
		if (ic >= 2) {
			node* lastnode = head->next;
			node* findnode = head;
			while (lastnode->next) {
				lastnode = lastnode->next;
			}
			while (head->next->next) {
				findnode = head;
				while (findnode->next->next) {
					findnode = findnode->next;
				}
				findnode->next->next = findnode;
				findnode->next = NULL;
			}
			head->next = lastnode;

		}// n 1 2 3
	}
	T& operator[](int i) const {
		return at(i);
	}
};
*///“reverse方法已完成”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		void set(T tf, node* nextf) {
			this->t = tf;
			this->next = nextf;
		}
	};
	node* head;
public:
	mylist() {
		//this->head->t = NULL;
		head->next = nullptr;
	}
	void push_back(T t) {
		node* newnode = new node;
		node** findnode = &head;
		newnode->set(t, nullptr);
		while (nullptr != (*findnode)->next) {
			findnode = &(*findnode)->next;
		}
		(*findnode)->next = newnode;
		ic++;
	}
	int indexfind(T t) {
		node* findnode = head;
		int index = 0;
		while (nullptr != head->next) {
			findnode = findnode->next;
			if (findnode->t) {
				return index;
			}
			index++;
		}
		return -1;
	}
	int capacity() const {
		return ic;
	}
	void operator=(mylist& ml) {
		this->ic = ml.ic;
		int ia = 0;
		clear();
		node* findnode = head->next;
		for (int i = 0; i < this->ic; i++) {
			i && (findnode = findnode->next);
			push_back(findnode->t);
		}
	}
	mylist(mylist& ml) {
		this->head->next = nullptr;
		*this = ml;
	}
	mylist(const T* const tarr) {
		//this->head->t = nullptr;
		this->head->next = nullptr;
		if (sizeof * tarr) {
			ic = sizeof * tarr / sizeof(*tarr)[0];
			T* tp = tarr;
			for (int i = 0; i < ic; i++) {
				push_back(*tp++);
			}
		}
	}
	void insert(T t, int i) {
		if (ic > i && i >= 0) {
			node* findnode = head->next;
			node* newnode = new node;
			newnode->set(t, nullptr);
			for (; i; i--) {
				findnode = findnode->next;
			}
			findnode->next = newnode;
			ic++;
		}
	}
	void del_back() {
		if (ic) {
			node* prenode = head;
			while (nullptr != prenode->next->next) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			prenode->next = nullptr;
			delete delnode;
			ic--;
		}
	}
	void clear() {
		while (ic) {
			del_back();
		}
	}
	~mylist() {
		clear();
	}
	void del_index(int index) {
		if (ic) {
			if (ic - 1 == index) {
				del_back();
			}
			else if (ic > index && index >= 0) {
				node* prenode = head;
				for (; index > 0; index--) {
					prenode = prenode->next;
				}
				node* delnode = prenode->next;
				node* nextnode = delnode->next;
				prenode->next = nextnode;
				delnode->next = nullptr;
				delete delnode;
			}
			ic--;
		}
	}
	bool IsEmpty() const {
		return !ic;
	}
	T& at(int i) {
		node* findnode = head->next;
		for (; i; i--) {
			findnode = findnode->next;
		}
		return findnode->t;
	}
	void myreverse() {
		if (ic >= 2) {
			node* lastnode = head->next;
			node* findnode = head;
			while (nullptr != lastnode->next) {
				lastnode = lastnode->next;
			}
			while (nullptr != head->next->next) {
				findnode = head;
				while (findnode->next->next) {
					findnode = findnode->next;
				}
				findnode->next->next = findnode;
				findnode->next = nullptr;
			}
			head->next = lastnode;

		}// n 1 2 3
	}
	T& operator[](int i) {
		return at(i);
	}
};
*///“mylist单向链表head节点指向位置不可访问bug未修复”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		void set() {
			this->t = NULL;
			this->next = nullptr;
		}
		void set(T tf, node* nextf) {
			this->t = tf;
			this->next = nextf;
		}
	};
	node* head;
public:
	mylist() {
		head = new node;
		head->set();
	}
	void push_back(T t) {
		node* newnode = new node;
		node** findnode = &head;
		newnode->set(t, nullptr);
		while (nullptr != (*findnode)->next) {
			findnode = &(*findnode)->next;
		}
		(*findnode)->next = newnode;
		ic++;
	}
	int indexfind(T t) {
		node* findnode = head;
		int index = 0;
		while (nullptr != head->next) {
			findnode = findnode->next;
			if (findnode->t) {
				return index;
			}
			index++;
		}
		return -1;
	}
	int capacity() const {
		return ic;
	}
	void operator=(mylist& ml) {
		this->ic = ml.ic;
		int ia = 0;
		clear();
		node* findnode = head->next;
		for (int i = 0; i < this->ic; i++) {
			i && (findnode = findnode->next);
			push_back(findnode->t);
		}
	}
	mylist(mylist& ml) {
		this->head->next = nullptr;
		*this = ml;
	}
	mylist(const T* const tarr) {
		//this->head->t = nullptr;
		this->head->next = nullptr;
		if (sizeof * tarr) {
			ic = sizeof * tarr / sizeof(*tarr)[0];
			T* tp = tarr;
			for (int i = 0; i < ic; i++) {
				push_back(*tp++);
			}
		}
	}
	void insert(T t, int i) {
		if (ic > i && i >= 0) {
			node* findnode = head->next;
			node* newnode = new node;
			newnode->set(t, nullptr);
			for (; i; i--) {
				findnode = findnode->next;
			}
			findnode->next = newnode;
			ic++;
		}
	}
	void del_back() {
		if (ic) {
			node* prenode = head;
			while (nullptr != prenode->next->next) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			prenode->next = nullptr;
			delete delnode;
			ic--;
		}
	}
	void clear() {
		while (ic) {
			del_back();
		}
	}
	~mylist() {
		clear();
		//delete head;
	}
	void del_index(int index) {
		if (ic) {
			if (ic - 1 == index) {
				del_back();
			}
			else if (ic > index && index >= 0) {
				node* prenode = head;
				for (; index > 0; index--) {
					prenode = prenode->next;
				}
				node* delnode = prenode->next;
				node* nextnode = delnode->next;
				prenode->next = nextnode;
				delnode->next = nullptr;
				delete delnode;
			}
			ic--;
		}
	}
	bool IsEmpty() const {
		return !ic;
	}
	T& at(int i) {
		node* findnode = head->next;
		for (; i; i--) {
			findnode = findnode->next;
		}
		return findnode->t;
	}
	void myreverse() {
		if (ic >= 2) {
			node* lastnode = head->next;
			node* findnode = head;
			while (nullptr != lastnode->next) {
				lastnode = lastnode->next;
			}
			while (nullptr != head->next->next) {
				findnode = head;
				while (findnode->next->next) {
					findnode = findnode->next;
				}
				findnode->next->next = findnode;
				findnode->next = nullptr;
			}
			head->next = lastnode;

		}// n 1 2 3
	}
	T& operator[](int i) {
		return at(i);
	}
};
*///“mylist单向链表里的节点node类的set重载无参方法已添加”^
/*
//meiri.cpp
#include <iostream>
#include <list>
#include "mylist.hpp"
using namespace std;

int main() {
	list<int>l;
	mylist<int>ml;
	cout << "ml单向链表容器的容量：" << ml.capacity() << " ml单向链表容器的是否为空：" << (ml.IsEmpty() ? "为空" : "不为空") << endl << endl << "添加一个新元素后：" << endl << endl;
	ml.push_back(1);
	cout << "ml单向链表容器的容量：" << ml.capacity() << " ml单向链表容器的是否为空：" << (ml.IsEmpty() ? "为空" : "不为空") << endl;
	return 0;
}
*///“mylist单向链表里的capacity和IsEmpty常方法已测试完毕”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		void set() {
			this->t = NULL;
			this->next = nullptr;
		}
		void set(T tf, node* nextf) {
			this->t = tf;
			this->next = nextf;
		}
	};
	node* head;
public:
	mylist() {
		head = new node;
		head->set();
	}
	void push_back(T t) {
		node* newnode = new node;
		node** findnode = &head;
		newnode->set(t, nullptr);
		while (nullptr != (*findnode)->next) {
			findnode = &(*findnode)->next;
		}
		(*findnode)->next = newnode;
		ic++;
	}
	int indexfind(T t) {
		node* findnode = head;
		int index = 0;
		while (nullptr != head->next) {
			findnode = findnode->next;
			if (findnode->t) {
				return index;
			}
			index++;
		}
		return -1;
	}
	int capacity() const {
		return ic;
	}
	void operator=(mylist& ml) {
		this->ic = ml.ic;
		int ia = 0;
		clear();
		node* findnode = head->next;
		for (int i = 0; i < this->ic; i++) {
			i && (findnode = findnode->next);
			push_back(findnode->t);
		}
	}
	mylist(mylist& ml) {
		this->head->next = nullptr;
		*this = ml;
	}
	mylist(const T* const tarr) {
		//this->head->t = nullptr;
		this->head->next = nullptr;
		if (sizeof * tarr) {
			ic = sizeof * tarr / sizeof(*tarr)[0];
			T* tp = tarr;
			for (int i = 0; i < ic; i++) {
				push_back(*tp++);
			}
		}
	}
	void insert(T t, int i) {
		if (ic > i && i >= 0) {
			node* findnode = head->next;
			node* newnode = new node;
			newnode->set(t, nullptr);
			for (; i; i--) {
				findnode = findnode->next;
			}
			findnode->next = newnode;
			ic++;
		}
	}
	void del_back() {
		if (ic) {
			node* prenode = head;
			while (nullptr != prenode->next->next) {
				prenode = prenode->next;
			}
			node* delnode = prenode->next;
			prenode->next = nullptr;
			delete delnode;
			ic--;
		}
	}
	void clear() {
		while (ic) {
			del_back();
		}
	}
	~mylist() {
		clear();
		delete head;
	}
	void del_index(int index) {
		if (ic) {
			if (ic - 1 == index) {
				del_back();
			}
			else if (ic > index && index >= 0) {
				node* prenode = head;
				for (; index > 0; index--) {
					prenode = prenode->next;
				}
				node* delnode = prenode->next;
				node* nextnode = delnode->next;
				prenode->next = nextnode;
				delnode->next = nullptr;
				delete delnode;
			}
			ic--;
		}
	}
	bool IsEmpty() const {
		return !ic;
	}
	T& at(int i) {
		node* findnode = head->next;
		for (; i; i--) {
			findnode = findnode->next;
		}
		return findnode->t;
	}
	void myreverse() {
		if (ic >= 2) {
			node* lastnode = head->next;
			node* findnode = head;
			while (nullptr != lastnode->next) {
				lastnode = lastnode->next;
			}
			while (nullptr != head->next->next) {
				findnode = head;
				while (findnode->next->next) {
					findnode = findnode->next;
				}
				findnode->next->next = findnode;
				findnode->next = nullptr;
			}
			head->next = lastnode;

		}// n 1 2 3
	}
	T& operator[](int i) {
		if (i >= 0 && i < ic) {
			node* findnode = head->next;
			for (; i; i--) {
				findnode = findnode->next;
			}
			return findnode->t;
		}
		else {
			return head->t;
		}
	}
};
*///“重载中括号运算符的内部代码已更改”^
/*
//meiri.cpp
#include <iostream>
#include <list>
#include "mylist.hpp"
using namespace std;

int main() {
	mylist<int>ml;
	ml.push_back(54);
	ml.push_back(-54);
	ml.push_back(5);
	ml.push_back(540);
	cout << "ml单向链表容器的第2项：" << ml.at(2) << "           ml单向链表容器的第-1项：" << (NULL == ml[-1] ? "NULL" : "NOT NULL") << endl;;
	return 0;
}
*///“ml单向链表容器的at成员方法和重载中括号的安全检测方式已正常运行”^
/*
//mylist.hpp
#pragma once
#include <iostream>
template<class T>
class mylist {
private:
	int ic;
	class node {
	public:
		T t;
		node* next;
		void set() {
			this->t = NULL;
			this->next = nullptr;
		}
		void set(T tf, node* nextf) {
			this->t = tf;
			this->next = nextf;
		}
	};
	node* head;
public:
	mylist() {
		head = new node;
		head->set();
	}
	void push_back(T t) {
		node* newnode = new node;
		node** findnode = &head;
		newnode->set(t, nullptr);
		while (nullptr != (*findnode)->next) {
			findnode = &(*findnode)->next;
		}
		(*findnode)->next = newnode;
		ic++;
	}
	int indexfind(T t) {
		node* findnode = head;
		int index = 0;
		while (nullptr != head->next) {
			findnode = findnode->next;
			if (findnode->t) {
				return index;
			}
			index++;
		}
		return -1;
	}
	int capacity() const {
		return ic;
	}
	void operator=(mylist& ml) {
		this->ic = ml.ic;
		int ia = 0;
		clear();
		node* findnode = head->next;
		for (int i = 0; i < this->ic; i++) {
			i && (findnode = findnode->next);
			push_back(findnode->t);
		}
	}
	mylist(mylist& ml) {
		this->head->next = nullptr;
		*this = ml;
	}
	mylist(const T* const tarr) {
		//this->head->t = nullptr;
		this->head->next = nullptr;
		if (sizeof * tarr) {
			ic = sizeof * tarr / sizeof(*tarr)[0];
			T* tp = tarr;
			for (int i = 0; i < ic; i++) {
				push_back(*tp++);
			}
		}
	}
	void insert(T t, int i) {
		if (ic > i && i >= 0) {
			node* findnode = head->next;
			node* newnode = new node;
			newnode->set(t, nullptr);
			for (; i; i--) {
				findnode = findnode->next;
			}
			findnode->next = newnode;
			ic++;
		}
	}
	void del_back() {
		if (ic) {
			node** prenode = &head;
			while (nullptr != (*prenode)->next->next) {
				prenode = &((*prenode)->next);
			}
			node** delnode = &((*prenode)->next);
			(*prenode)->next = nullptr;
			delete *delnode;
			ic--;
		}
	}
	void clear() {
		while (ic) {
			del_back();
		}
	}
	~mylist() {
		clear();
		delete head;
	}
	void del_index(int index) {
		if (ic) {
			if (ic - 1 == index) {
				del_back();
			}
			else if (ic > index && index >= 0) {
				node* prenode = head;
				for (; index > 0; index--) {
					prenode = prenode->next;
				}
				node* delnode = prenode->next;
				node* nextnode = delnode->next;
				prenode->next = nextnode;
				delnode->next = nullptr;
				delete delnode;
			}
			ic--;
		}
	}
	bool IsEmpty() const {
		return !ic;
	}
	T& at(int i) {
		if (i >= 0 && i < ic) {
			node* findnode = head->next;
			for (; i; i--) {
				findnode = findnode->next;
			}
			return findnode->t;
		}
		else {
			return head->t;
		}
	}
	void myreverse() {
		if (ic >= 2) {
			node* lastnode = head->next;
			node* findnode = head;
			while (nullptr != lastnode->next) {
				lastnode = lastnode->next;
			}
			while (nullptr != head->next->next) {
				findnode = head;
				while (findnode->next->next) {
					findnode = findnode->next;
				}
				findnode->next->next = findnode;
				findnode->next = nullptr;
			}
			head->next = lastnode;

		}// n 1 2 3
	}
	T& operator[](int i) {
		if (i >= 0 && i < ic) {
			node* findnode = head->next;
			for (; i; i--) {
				findnode = findnode->next;
			}
			return findnode->t;
		}
		else {
			return head->t;
		}
	}
};
*///“del_back方法已重新构建”^
/*
//meiri.cpp
#include <iostream>
#include <list>
#include "mylist.hpp"
using namespace std;

int main() {
	mylist<int>ml;
	ml.push_back(54);
	ml.push_back(-54);
	ml.push_back(5);
	ml.push_back(540);
	ml.del_back();
	cout << "ml单向链表容器的容量：" << ml.capacity() << endl;
	return 0;
}
*///新del_back方法已测试好^
/*
//meiri.cpp
#include <iostream>
#include <list>
#include "mylist.hpp"
using namespace std;

int main() {
	mylist<int>ml;
	ml.push_back(54);
	ml.push_back(-54);
	ml.push_back(5);
	ml.push_back(540);
	ml.clear();
	cout << "ml单向链表容器的容量：" << ml.capacity() << endl;
	return 0;
}
*///clear方法已测试好^
/*
//meiri.cpp
#include <iostream>
#include <list>
#include "mylist.hpp"
using namespace std;

int main() {
	mylist<int>ml;
	ml.del_back();
	ml.del_back();
	ml.del_back();
	ml.clear();
	ml.clear();
	ml.del_back();
	cout << "程序已正常运行" << endl;
	return 0;
}
*///mylist单向链表的del_back方法和clear方法的安全检测方式已正常运行^
