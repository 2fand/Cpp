#pragma once
#include <iostream>
using namespace std;
#include <vector>
#define JUMPHIGH 3
#ifndef oncea
#define oncea
enum XYHS {
	X,
	Y,
	HEAL,
};
struct trir {
	char* cp;
	int iy;
	bool b;//0< 1>
	bool bk;//ÊÇ·ñÉ±¹ý¹ÖÎï
};
class Player {
private:
	int ix;
	int iy;
	int ijh;
	int iheal;
	bool blr;
	bool hlwait;
	vector<trir> v;
public:
	Player();
	void printmap(const char strmap[11][11], const bool bwait);
	void printmap(char(*strmap)[11][11], const bool bwait, int ir);
	void jump(char** cpp);
	void left_move(char** cpp);
	void right_move(char** cpp);
	int& sgetxyhs(XYHS xyhsmode);
	vector<trir>* sgetxyhs();
	void upOrDown(char** cpp);
	void shoot(int& i, char** cpp);
	void shootmove(const char(*strmap)[11][11], bool bmode);
};
#endif