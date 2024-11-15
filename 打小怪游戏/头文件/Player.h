#pragma once
#include <iostream>
using namespace std;
#include <vector>
#define JUMPHIGH 3
#ifndef oncea
#define oncea
enum XYHS {
	X,//x坐标
	Y,//y坐标
	HEAL,//玩家的血量
};
struct trir {//子弹
	char* cp;//子弹的位置
	int iy;//子弹的y坐标
	bool b;//子弹的朝向(0< 1>)
	bool bk;//是否杀过怪物
};
class Player {
private:
	int ix;//x坐标
	int iy;//y坐标
	int ijh;//跳跃高度
	int iheal;//生命值
	bool blr;//朝向
	vector<trir> v;//玩家射出的子弹
public:
	Player();//构造函数
	void printmap(const char strmap[11][11], const bool bwait, const int iunmd);//打印地牢
	void printmap(char(*strmap)[11][11], const bool bwait, const int ir, const int iunmd);//打印地牢(右偏版本)
	void jump(char** cpp);//跳跃
	void left_move(char** cpp);//左移
	void right_move(char** cpp);//右移
	int& sgetxyhs(XYHS xyhsmode);//设置或获得玩家的x坐标，y坐标或血量
	vector<trir>* sgetxyhs();//设置或获得玩家射出的子弹
	void upOrDown(char** cpp);//上升或下坠
	void shoot(int& i, char** cpp);//射击
	void shootmove(const char(*strmap)[11][11], bool bmode);//子弹移动
};
#endif
