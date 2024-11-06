#include <iostream>
using namespace std;
#include "m^.h"
MUD::MUD() {
	this->set();
}
void MUD::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*, char**, char(*)[11][11], int, int, bool b, bool ba) {
	m_v = v;//vector<trir>* = NULL, char** = NULL, char** = NULL, pair<int, int>* = NULL, int = 0, int = 0, int = 3, bool = 0, bool = 0
	m_cpp = cpp;
	m_iheal = iheal;
	mblr = b;
	mbud = ba;
}
void MUD::mosterdo() {
	'*' != **m_cpp && (**m_cpp = ' ');
	if (!mblr && '*' == (*m_cpp)[-1]) {
		mblr = 1;
	}
	else if(mblr && '*' == (*m_cpp)[1]){
		mblr = 0;
	}//撞墙换方向
	tempcp = *m_cpp;
	m_cpp = NULL;
	'*' != tempcp[-(1 - 2 * mblr)] && (tempcp -= (1 - 2 * mblr));//左右移
	if (mbud && '*' == tempcp[11]) {
		mbud = 0;
	}
	else if (!mbud && '*' == tempcp[-11]) {
		mbud = 1;
	}//碰地会反转
	'*' != tempcp[-(11 * (1 - 2 * mbud))] && (tempcp -= 11 * (1 - 2 * mbud));//上下落
	m_cpp = &tempcp;
	//后面Mshow函数使见
}//撞墙换方向，碰地会反落
char MUD::getm() {
	if (mbud) {
		return 'v';
	}
	else {
		return '^';
	}
}