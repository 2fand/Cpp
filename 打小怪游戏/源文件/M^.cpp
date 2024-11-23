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
