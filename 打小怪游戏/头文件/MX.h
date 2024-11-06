#pragma once
#include <iostream>
using namespace std;
#include "moster.h"
class MX : public moster {
private:
	char** m_pcpp;//玩家的地点，不用xy坐标
	char(*m_strmap)[11][11];
	char m_strmapr[11][11];
	char m_cc;
	pair<int, int>pxy;
	bool setb;
public:
	MX();
	void set(vector<trir>* v = NULL, char** cpp = NULL, int iheal = 3, map<char**, WASD>* = NULL, char** pcpp = NULL, char(*strmap)[11][11] = NULL, int = 0, int = 0, bool = 0, bool = 0);
	void mosterdo();
	void exset(char strmapr[11][11]);
	char getm();
	char getm(bool);
};