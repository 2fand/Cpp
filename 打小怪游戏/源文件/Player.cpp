#include <iostream>
#include "Player.h"
#include "cmp.h"
#include <algorithm>
#include <Windows.h>
using namespace std;
//构造函数
Player::Player(){
	ijh = 0;
	blr = 1;
}
//打印地牢函数
void Player::printmap(const char strmap[11][11], const bool bwait, const int iunmd) {
	int i = 0;
	int ia = 0;
	cout << "\033[" << (!bwait || 5 < iheal ? "32;1m" : 2 < iheal ? "33m" : "31;1m") << "P * " << iheal << "\033[0m" << endl << endl << endl;//打印玩家的血量
	for (cout << "-----------@" << endl; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : 'v' == strmap[i][ia] ? "36m" : '&' == strmap[i][ia] || '^' == strmap[i][ia] || 'o' == strmap[i][ia] || 'O' == strmap[i][ia] || 'X' == strmap[i][ia] ? "31;1m" : '+' == strmap[i][ia] || '#' == strmap[i][ia] || '@' == strmap[i][ia] ? "33m" : 'P' == strmap[i][ia] && iunmd ? "30;1m" : "0m") << strmap[i][ia] << "\033[0m";///打印地图
		}
		cout << "|" << endl;//竖的外边框
	}
	cout << "-----------@" << endl;//底下的的外边框
}
//打印地牢函数(右偏版本)
void Player::printmap(char(*strmap)[11][11], const bool bwait, const int ir, const int iunmd) {
	int i = 0;
	int ia = 0;
	cout << "\033[" << (!bwait || 5 < iheal ? "32;1m" : 2 < iheal ? "33m" : "31;1m") << "P * " << iheal << "\033[0m" << endl << endl << endl;//打印血量
	for (cout << "-----------@" << endl; i < 11; i++) {
		for (ia = ir; 11 > ia - ir; ia++) {
			21 > ia && ia >= 12 && i && 10 != i && ((*strmap)[i][ia % 11] = ' ');//清空左边的墙(除边框)
			cout << "\033[" << ('P' == (*strmap)[i][ia % 11] && iunmd ? "40;1m" : "0m") << (*strmap)[i][ia % 11] << "\033[0m";//打印右偏之后的地图
		}
		cout << "|" << endl;//竖的外边框
	}
	cout << "-----------@" << endl;//底下的的外边框
}//跳跃函数
void Player::jump(char** cpp) {
	10 == ix || '*' == (*cpp)[11] && (ijh = JUMPHIGH);
}
//左移函数
void Player::left_move(char** cpp) {
	(iy && '*' != *(*cpp - 1) && ((*cpp)--));
	blr = false;
}
//右移函数
void Player::right_move(char** cpp) {
	10 != iy && '*' != *(*cpp + 1) && ((*cpp)++);
	blr = true;
}
//用于设置或获得玩家的x坐标，y坐标或血量
int& Player::sgetxyhs(XYHS xyhsmode) {
	switch (xyhsmode) {
	case X:
		return ix;
		break;
	case Y:
		return iy;
		break;
	case HEAL:
		return iheal;
		break;
	default:
		break;
	}
}
//设置或获得玩家射出的子弹
vector<trir>* Player::sgetxyhs() {
	return &v;
}
//使玩家上升或下坠
void Player::upOrDown(char** cpp) {
	if (ijh > 0 && ix && '*' != (*cpp)[-11]) {//跳跃后
		ijh--, *cpp -= 11;
	}
	else if ('*' != (*cpp)[11] && (!ix || '*' == (*cpp)[-11])) {//撞墙或跳好后
		ijh = 0, *cpp += 11;
	}
	else if ('*' != (*cpp)[11] && 10 != ix) {//落下时
		*cpp += 11;
	}
	if (ijh > 0 && '*' == (*cpp)[11]) {//防磕头后还能跳
		ijh = 0;
	}
}
//射击函数
void Player::shoot(int& i, char** cpp) {
	if ((!i) && (iy && (!blr) || 10 != iy && blr)) {//检测冷却时间已过并且是否在地牢的边界射过
		v.push_back({ *cpp, iy, blr, 0 });
		i = 3;
	}
}
//子弹的移动函数
void Player::shootmove(const char(*strmap)[11][11], bool bmode) {
	if (bmode) {
		for (vector<trir>::iterator it = v.begin(); v.end() != it; it++) {
			(' ' == *it->cp || '@' == *it->cp) && (*it->cp = ' ');///编译显示之前子弹的移动
			if ('*' == *it->cp || it->bk || (!it->iy && (!it->b)) || (21 == it->iy && it->b)) {
				it->iy = -1;//子弹的销毁
			}
			if (0 <= it->iy) {
				it->cp -= (1 - it->b * 2);//子弹的移动
				it->iy -= (1 - it->b * 2);//子弹y坐标的移动
				(' ' == *it->cp || '@' == *it->cp) && (*it->cp = '@');//显示
			}
		}
	}
	else {
		sort(v.begin(), v.end(), cmp());//按子弹的y坐标进行升序排列
		while ((!v.empty()) && 0 > v.begin()->iy) {
			v.erase(v.begin());//销毁子弹
		}
	}
}
