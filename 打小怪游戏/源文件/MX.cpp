#include <iostream>
using namespace std;
#include <cstring>
#include "mX.h"
void MX::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*, char** pcpp, char(*strmap)[11][11], int, int, bool, bool) {
	m_v = v;//vector<trir>* = NULL, char** = NULL, char** = NULL, pair<int, int>* = NULL, char(*)[11][11] = NULL,int = 0, int = 0, int = 3, bool = 0, bool = 0
	m_cpp = cpp;
	m_pcpp = pcpp;
	strmap && (m_strmap = strmap);
	m_iheal = iheal;
	setb = 1;
}
void MX::exset(char strmapr[11][11]) {
	memcpy(m_strmapr, strmapr, sizeof m_strmapr);
}
MX::MX() {
	set();
}
void MX::mosterdo() {
	vector<trir>::iterator it = m_v->begin();
	if (setb) {
		pxy = { (*m_cpp - &(*m_strmap)[0][0]) / 11, (*m_cpp - &(*m_strmap)[0][0]) % 11 };
		m_cc = m_strmapr[pxy.first][setb = 0, pxy.second];//盖住的块
	}
	for (; m_v->end() != it; it++) {
		if (*m_cpp == it->cp || *m_cpp == it->cp - (1 - it->b * 2)) {
			break;
		}
	}
	if (m_iheal && (*m_cpp == *m_pcpp || m_v->end() != it)) {
		tempcp = *m_cpp;
		char* tempcpb = tempcp;
		bool tempb = 1;
		m_cpp = NULL;
		do {
			tempb && m_v->end() != it && (*tempcp = ' ');
			tempcp = &(*m_strmap)[pxy.first = rand() % 9 + 1][pxy.second = rand() % 9 + 1];

		} while ((tempcp == &(*m_strmap)[9][1] || '@' == (*m_strmap)[pxy.first][pxy.second] || '@' == (*m_strmap)[pxy.first][pxy.second - 1] || '@' == (*m_strmap)[pxy.first][pxy.second + 1] || tempcp == *m_pcpp || ('*' == (tempcp)[-1] && '*' == (tempcp)[1]) || 'X' == (tempcp)[-1] || 'X' == (tempcp)[1]) && (tempb = 0, 1));
		m_cpp = &tempcp;
		*tempcpb = m_cc;
		('@' != m_strmapr[pxy.first][pxy.second] || 'X' != m_strmapr[pxy.first][pxy.second] && 'P' != m_strmapr[pxy.first][pxy.second]) && (m_cc = m_strmapr[pxy.first][pxy.second]);//记录盖住的块
	}
	//**m_cpp = 'X';//使见
}//被玩家碰到传，受伤传(两旁有砖不传)，并见
char MX::getm() {
	return 'X';
}
char MX::getm(bool) {
	return m_cc;
}