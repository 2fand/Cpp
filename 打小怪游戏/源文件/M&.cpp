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
	'*' != **m_cpp && (**m_cpp = ' ');
	if (!mblr && '*' == (*m_cpp)[-1]) {
		mblr = 1;
	}
	else if (mblr && '*' == (*m_cpp)[1]) {
		mblr = 0;
	}//ײǽ������
	tempcp = *m_cpp;
	m_cpp = NULL;
	'*' != tempcp[-(1 - 2 * mblr)] && (tempcp -= (1 - 2 * mblr));//������
	'*' != tempcp[11] && (tempcp += 11);//����
	m_cpp = &tempcp;
	//����Mshowʹ��
}//ײǽ�����򣬻���Ȼ����
char Mand::getm() {
	return '&';
}