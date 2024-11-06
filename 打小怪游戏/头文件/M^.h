#pragma once
#include <iostream>
using namespace std;
#include "moster.h"
class MUD : public moster {
private:
	bool mblr;
	bool mbud;
public:
	MUD();
	void set(vector<trir>* v = NULL, char** cpp = NULL, int iheal = 3, map<char**, WASD>* = NULL, char** = NULL, char(*)[11][11] = NULL, int = 0, int = 0, bool b = 0, bool ba = 0);
	void mosterdo();
	char getm();
};