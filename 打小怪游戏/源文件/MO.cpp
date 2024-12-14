#include <iostream>
using namespace std;
#include "MO.h"
#define NNEG(A, B) ((A) < (B) ? 1 : (A) > (B) ? -1 : 0)//判断宏
#define MOWAIT 1//怪物MO等待的回合数
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
	if (nullptr != m) { 
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
