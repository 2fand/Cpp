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
