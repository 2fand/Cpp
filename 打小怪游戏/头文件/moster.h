#pragma once
#include <iostream>
using namespace std;
#include "Player.h"
#include "WASD.h"
#include <map>
class moster {
protected:
	char** m_cpp;
	int m_iheal;
	vector<trir>* m_v;
	char* tempcp;
public:
	moster();
	virtual void set(vector<trir>* v = NULL, char** cpp = NULL, int iheal = 3, map<char**, WASD>* = NULL, char** = NULL, char(*)[11][11] = NULL, int = 0, int = 0, bool = 0, bool = 0);
	void hunt();
	int getheal();
	virtual void mosterdo() = 0;
	virtual char getm() = 0;
	char*& getcp();
};