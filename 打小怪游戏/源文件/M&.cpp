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
