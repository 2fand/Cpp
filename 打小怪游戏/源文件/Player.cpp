#include <iostream>
#include "Player.h"
#include "cmp.h"
#include <algorithm>
#include <Windows.h>
using namespace std;
Player::Player(){
	ijh = 0;
	blr = 1;
	hlwait = 1;
}
void Player::printmap(const char strmap[11][11], const bool bwait, const int iunmd) {
	int i = 0;
	int ia = 0;
	cout << "\033[" << (!bwait || 5 < iheal ? "32;1m" : 2 < iheal ? "33m" : "31;1m") << "P * " << iheal << "\033[0m" << endl << endl << endl;
	for (cout << "-----------@" << endl; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : 'v' == strmap[i][ia] ? "36m" : '&' == strmap[i][ia] || '^' == strmap[i][ia] || 'o' == strmap[i][ia] || 'O' == strmap[i][ia] || 'X' == strmap[i][ia] ? "31;1m" : '+' == strmap[i][ia] || '#' == strmap[i][ia] ? "33m" : '@' == strmap[i][ia] ? "33m" : 'P' == strmap[i][ia] && iunmd ? "30;1m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl;
}
void Player::printmap(char(*strmap)[11][11], const bool bwait, const int ir, const int iunmd) {
	int i = 0;
	int ia = 0;
	cout << "\033[" << (!bwait || 5 < iheal ? "32;1m" : 2 < iheal ? "33m" : "31;1m") << "P * " << iheal << "\033[0m" << endl << endl << endl;
	for (cout << "-----------@" << endl; i < 11; i++) {
		for (ia = ir; 11 > ia - ir; ia++) {
			21 > ia && ia >= 12 && i && 10 != i && ((*strmap)[i][ia % 11] = ' ');
			cout << "\033[" << ('P' == (*strmap)[i][ia % 11] && iunmd ? "40;1m" : "0m") << (*strmap)[i][ia % 11] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl;
}
void Player::jump(char** cpp) {
	10 == ix || '*' == (*cpp)[11] && (ijh = JUMPHIGH);
}
void Player::left_move(char** cpp) {
	(iy && '*' != *(*cpp - 1) && ((*cpp)--));
	blr = false;
}
void Player::right_move(char** cpp) {
	10 != iy && '*' != *(*cpp + 1) && ((*cpp)++);
	blr = true;
}
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
vector<trir>* Player::sgetxyhs() {
	return &v;
}
void Player::upOrDown(char** cpp) {
	if (ijh > 0 && ix && '*' != (*cpp)[-11]) {
		ijh--, *cpp -= 11;
	}
	else if ('*' != (*cpp)[11] && (!ix || '*' == (*cpp)[-11])) {
		ijh = 0, *cpp += 11;
	}
	else if ('*' != (*cpp)[11] && 10 != ix) {
		*cpp += 11;
	}
	if (ijh > 0 && '*' == (*cpp)[11]) {
		ijh = 0;
	}
}
void Player::shoot(int& i, char** cpp) {
	if ((!i) && (iy && blr || 21 != iy && (!blr))) {
		v.push_back({ *cpp, iy, blr, 0 });
		i = 3;
	}
}
void Player::shootmove(const char(*strmap)[11][11], bool bmode) {
	if (bmode) {
		for (vector<trir>::iterator it = v.begin(); v.end() != it; it++) {
			(' ' == *it->cp || '@' == *it->cp) && (*it->cp = ' ');
			if ('*' == *it->cp || it->bk || (!it->iy && (!it->b)) || (21 == it->iy && it->b)) {
				it->iy = -1;//子弹的销毁
			}
			if (0 <= it->iy) {
				it->cp -= (1 - it->b * 2);
				it->iy -= (1 - it->b * 2);
				(' ' == *it->cp || '@' == *it->cp) && (*it->cp = '@');
			}
		}
	}
	else {
		sort(v.begin(), v.end(), cmp());
		while ((!v.empty()) && 0 > v.begin()->iy) {
			v.erase(v.begin());
		}
	}
}
