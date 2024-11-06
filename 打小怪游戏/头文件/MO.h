#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "Player.h"
#include "moster.h"
class MO : public moster {
private:
	WASD m_wasd;
	map<char**, WASD>m_m;//[strmap point, wasd]...
	pair<int, int> m_pxy;//MOSTER xy×ø±ê
	static pair<int, int> s_m_pxy;//PLAYER xy×ø±ê
	int imove;
public:
	void set(vector<trir>* v = NULL, char** cpp = NULL, int iheal = 3, map<char**, WASD>* m = NULL, char** = NULL, char(*)[11][11] = NULL, int ix = 0, int iy = 0, bool = 0, bool = 0);
	MO();
	void set_s_pxy(int ix, int iy);
	void mosterdo();
	char getm();
};