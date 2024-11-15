#include <iostream>
using namespace std;
#include "moster.h"
moster::moster(){
	vector<trir>v;
	m_v = &v;
}
//vector<trir>* v = NULL, char** cpp = NULL, char** = NULL, pair<int, int>* = NULL, char(*)[11][11] = NULL, int = 0, int = 0, int iheal = 3, bool b = 0, bool ba = 0
void moster::set(vector<trir>* v, char** cpp, int iheal, map<char**, WASD>*, char**, char(*)[11][11], int, int, bool, bool) {
	m_v = v;
	m_cpp = cpp;
	m_iheal = iheal;
}
void moster::hunt() {
	for (vector<trir>::iterator it = m_v->begin(); m_v->end() != it; it++) {
		(!it->bk && (*m_cpp == it->cp || *m_cpp == (it->cp - (1 - 2 * it->b)))) && (m_iheal--, it->bk = 1);
	}//检测扣血(如果子弹没杀过怪物并且子弹在怪物正中或者前面就扣怪物的血)
	//Game.cpp的main函数中检测怪物的死亡
}
int moster::getheal() {
	return m_iheal;
}
char*& moster::getcp() {
	return *m_cpp;
}
