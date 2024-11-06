#include <iostream>
using namespace std;
#include "MO.h"
#define NNEG(A, B) ((A) < (B) ? 1 : (A) > (B) ? -1 : 0)
#define M_oWAIT 1
pair<int, int> MO::s_m_pxy = {0, 0};
MO::MO() {
	this->set();
}
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
	'*' != **m_cpp && (**m_cpp = ' ');
	tempcp = *m_cpp;
	m_cpp = NULL;
	if (!m_m.empty()) {
		int arr[4] = { -11, -1, 11, 1 };
		for (map<char**, WASD>::iterator it = m_m.begin(); m_m.end() != it; it++) {
			E != it->second && tempcp == *it->first && (m_wasd = it->second);
		}
		//int* iparr[2] = { &m_pxy.first, &m_pxy.second };
		switch (tempcp += (arr[m_wasd]), m_wasd) {
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
	else {
		M_oWAIT == imove % (M_oWAIT + 1) && ('*' != *(tempcp + 11 * NNEG(m_pxy.first, s_m_pxy.first)) && (tempcp += 11 * NNEG(m_pxy.first, s_m_pxy.first), m_pxy.first += NNEG(m_pxy.first, s_m_pxy.first)));//根据怪物的xy坐标和玩家的xy坐标来移动
		M_oWAIT == imove++ % (M_oWAIT + 1) && ('*' != *(tempcp + NNEG(m_pxy.second, s_m_pxy.second)) && (tempcp += NNEG(m_pxy.second, s_m_pxy.second), m_pxy.second += NNEG(m_pxy.second, s_m_pxy.second)));
	}
	m_cpp = &tempcp;
}//遇向则转，看路前行（1），或追玩者（2）
void MO::set_s_pxy(int ix, int iy) {
	s_m_pxy = { ix, iy };
}
char MO::getm() {
	return 'O';
}