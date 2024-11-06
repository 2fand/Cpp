#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>
#include <Windows.h>
#include "draw.h"
#define DEBUG
void MShow(moster*& mp) {
	('X' == mp->getm() || '*' != *mp->getcp()) && (*mp->getcp() = mp->getm());
}
void del(moster*& mp) {
	delete mp;
}
void delvo(M_o*& mp) {
	delete mp;
}
void setMempty(moster*& mp) {
	'*' != *mp->getcp() && (*mp->getcp() = ' ');
}
void start(int ichoose) {
	switch (ichoose) {
	case 14:
		cout << "      *                  *          *           " << endl;
	case 13:
		cout << "      *                  *          * ********  " << endl;
	case 12:
		cout << "      *  ********        *          *  *     *  " << endl;
	case 11:
		cout << "   ******    *           *        * **  *   *   " << endl;
	case 10:
		cout << "      *      *           *        * * *  * *    " << endl;
	case 9:
		cout << "      * *    *        *  *  *     * *     **    " << endl;
	case 8:
		cout << "     ***     *       **  *   *   *  *   **  *   " << endl;
	case 7:
		cout << "   ** *      *      *    *    *     * **  *  ** " << endl;
	case 6:
		cout << "      *      *     *     *    **    *     *     " << endl;
	case 5:
		cout << "      *      *    *      *     *    *     *     " << endl;
	case 4:
		cout << "      *      *           *          *  *******  " << endl;
	case 3:
		cout << "      *      *           *          *     *     " << endl;
	case 2:
		cout << "      *      *           *          *     *     " << endl;
	case 1:
		cout << "    * *    * *         * *          * ********* " << endl;
	case 0:
		cout << "     *      *           *           *           " << endl;
	default:
		break;
	}
} 
int main() {
	srand((unsigned int)time(NULL));
	char strmap[11][11] = {
		'*','*','*','*','*','*','*','*','*','*','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'P',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
		'*','*','*','*','*','*','*','*','*','*','*',
	};
	bool ba = 1;
	bool bb = 1;
	char ch = 0;
	vector<M_o*>vo;
	vector<draw>vmd[5] = { {{5,2,6,1}}, {{3,2,4,0}, {7,2,3,1}, {3,5,4,0}, {3,5,3,1}, {3,8,4,0}}, {{3,2,4,0},{3,5,4,0},{3,8,4,0},{7,2,6,1}}, {{3,2,3,1},{3,5,4,0},{7,2,6,1}}, {{5,3,4,1},{3,5,4,0}} };
	multimap<int, int>mwasd[4] = { {{9,1},{9,3},{3,3},{5,3},{7,3},{9,3},{8,4},{8,8},{6,8},{4,8}}, {{2,3},{9,9},{3,8},{5,8},{7,8},{9,2}}, {{2,2},{2,7},{1,9}}, {{1,1},{2,4},{4,3},{6,3},{8,3},{8,7}} };
	vo.reserve(99999);
	int i = 0;
	int temparr[6] = { 4, 8, 12, 15, 17, 18 };
	int ia = rand() % 10 + 1;// 后：+1 +1 +1 +1 +2 +2 +2 +2 +3 +3 +3 +3 +4 +4 +4 +5 +5 +6
	int tempir = rand() % 22;
	for (i = 0; i < 6; i++) {
		if (tempir < temparr[i]) {
			ia += (i + 1);
			break;
		}
	}
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char**, WASD>m[3];
	map<char**, WASD>em;//追踪map
	char* cparr[45] = { NULL };
	char** cpp = cparr;
	for (WASD w = W; E != w; ++w) {
		switch (w) {
		case W:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[10 - i][i];
				m[0].insert({cpp++, W});
			}
			break;
		case A:
			for (i = 6; i < 10; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, A});
			}
			break;
		case S:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][10 - i];
				m[0].insert({cpp++, S});
			}
			break;
		case D:
			for (i = 1; i < 5; i++) {
				*cpp = &strmap[i][i];
				m[0].insert({cpp++, D});
			}
			break;
		default:
			break;
		}
		for (multimap<int, int>::iterator it = mwasd[w].begin(); mwasd[w].end() != it; it++) {
			*cpp = &strmap[it->first][it->second];
			m[1].insert({ cpp++, w });
		}
	}
	const int arr[4] = { 6,9,1,5 };
	for (i = 0; i < 4; i++) {
		*cpp = &strmap[arr[i]][i % 2 + 1];
		m[2].insert({ cpp++, (WASD)(i / 2 * 2) });//注意：i / 2 * 2 != i
	}
	char strmapr[11][11];
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[47] = { &strmap[9][5], &strmap[9][7], &strmap[9][3], &strmap[1][5], &strmap[1][5], &strmap[6][1], &strmap[4][9], &strmap[6][8], &strmap[3][3], &strmap[4][3], &strmap[5][3], &strmap[6][3], &strmap[7][3], &strmap[8][3], &strmap[9][3], &strmap[4][5], &strmap[5][4], &strmap[5][5], &strmap[5][6], &strmap[6][5], &strmap[1][5], &strmap[1][5], &strmap[9][5], &strmap[9][5], &strmap[1][9], &strmap[1][1], &strmap[8][2], &strmap[2][8], &strmap[8][8], &strmap[2][2], &strmap[5][5], &strmap[1][1], &strmap[2][2], &strmap[3][3], &strmap[4][4], &strmap[8][5], &strmap[5][2], &strmap[2][4], &strmap[4][9], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9], &strmap[3][4], &strmap[5][1], &strmap[5][9], &strmap[5][5]};
	vector<moster*>mpv;//mpv里一共要有的怪物们
	mpv.reserve(10000);
	//随机设置地牢布置与怪物布置
	for (i = 0; ch < 11; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {//建议每个case都封装成一个函数
		case 0:
			for (itemp = i + 8, vism[ch].str = "O&&^^OXX"; i < itemp; i++) {
				switch (vism[ch].str[8 - (itemp - i)]) {
				case '&':
					mpv.push_back(new Mand());
					break;
				case '^':
					mpv.push_back(new MUD());
					break;
				case 'O':
					mpv.push_back(new MO());
					break;
				case 'X':
					mpv.push_back(new MX());
					break;
				default:
					break;
				}
				vism[ch].vmp.push_back(mpv[i]);
				if (8 == itemp - i) {
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &em, NULL, NULL, 9, 5);
				}
				else {
					switch (vism[ch].str[8 - (itemp - i)]) {
					case '&':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, NULL, NULL, 0, 0, itemp - i - 6);
						break;
					case '^':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 4, NULL, NULL, NULL, 0, 0, itemp - i - 4, true);
						break;
					case 'O':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 5, &m[2], NULL, NULL, 5, 2);
						break;
					case 'X':
						vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[8 - (itemp - i)], 3, NULL, &cp, &strmap);
						break;
					default:
						break;
					}
				}
			}
			break;
		case 1:
			for (itemp = i + 7; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[7 - (itemp - i) + 8], 5, &m[1], NULL, NULL, 0, 0, 10 - (i - itemp), 3);
			}
			break;
		case 2:
			for (itemp = i + 5; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 15], 3, NULL, NULL, NULL, 0, 0, 1, 1);
			}
			break;
		case 3:
			for (itemp = i + 6, vism[ch].str = "&&^^^^"; i < itemp; i++) {
				if ('&' == (vism[ch].str[6 - (itemp - i)])) {
					mpv.push_back(new Mand());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 3, NULL, NULL, NULL, 0, 0, (i - itemp) % 2);
				}
				else {
					mpv.push_back(new MUD());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[6 - (itemp - i) + 20], 4, NULL, NULL, NULL, 0, 0, (6 - (itemp - i) - 2) & 1, (6 - (itemp - i) - 2) & 2);//qezc(键盘)
				}
			}
			break;
		case 4:
			for (itemp = i + 5, vism[ch].str = "XXXXO"; i < itemp; i++) {
				if ('X' == (vism[ch].str[5 - (itemp - i)])) {
					mpv.push_back(new MX());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 3, NULL, &cp, &strmap);
				}
				else {
					mpv.push_back(new MO());
					vism[ch].vmp.push_back(mpv[i]);
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[5 - (itemp - i) + 26], 5, &em, NULL, NULL, 5, 5);
				}

			}
			break;
		case 5:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MO());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 31], 5, &m[0], NULL, NULL, itemp - i, itemp - i);
			}
			break;
		case 6:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MX());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 35], 3, NULL, &cp, &strmap);
			}
			break;
		case 7:
			for (itemp = i + 4; i < itemp; i++) {
				mpv.push_back(new MUD());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[4 - (itemp - i) + 39], 4, NULL, NULL, NULL, 0, 0, (itemp - i) % 2, (itemp - i + 1) % 2);
			}
			break;
		case 8:
			for (itemp = i + 3; i < itemp; i++) {
				mpv.push_back(new Mand());
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[3 - (itemp - i) + 43], 3, NULL, NULL, NULL, 0, 0, !((itemp - i) % 2));
			}
			break;
		case 9:
		{
			for (itemp = i + ia; i < itemp; i++) {
				pair<bool, bool>pbb = { rand() % 2, rand() % 2 };
				pair<int, int>pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				while ((7 == pxy.first || 5 == pxy.first) && 4 == pxy.second) {
					pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				}
				char* tempcp = &strmap[pxy.first][pxy.second];
				switch (rand() % 3) {
				case 0:
					mpv.push_back(new Mand());
					vism[ch].str += '&';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &tempcp, 3, NULL, NULL, NULL, 0, 0, pbb.first);
					break;
				case 1:
					mpv.push_back(new MUD());
					if (pbb.second) {
						vism[ch].str += 'v';
					}
					else {
						vism[ch].str += '^';
					}
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &tempcp, 2, NULL, NULL, NULL, 0, 0, pbb.first, pbb.second);
					break;
				case 2:
					mpv.push_back(new MX());
					vism[ch].str += 'X';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &tempcp, 3, NULL, &cp, &strmap);
					break;
				case 3:
					mpv.push_back(new MO());
					vism[ch].str += 'O';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &tempcp, 5, &em, NULL, NULL, pxy.first, pxy.second);
					break;
				default:
					break;
				}
			}
		}
		break;
		default:
			break;
		}
	}
	random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除本次游戏不需要的地牢
	}
	vism.push_back(ism);
	vism.back().id = 10;
	mpv.push_back(new Mplus());
	vism.back().vmp.push_back(mpv.back());
	vism.back().vmp.back()->set(p.sgetxyhs(), &strcp[45], 10);
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	int bosswait = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	//开始界面
	for (i = 0; i < 15; i++) {
		system("cls");
		start(i);
		Sleep(10);
	}
	Sleep(10);
	for (i = 0; i < 10; i++) {
		char tempstr[9] = "color 0";
		char tempstra[10][2] = {"C", "E", "A", "9", "D", "9", "A", "E", "C", "7"};
		strcat(tempstr, tempstra[i]);
		system(tempstr);
		Sleep(100);
	}
	Sleep(500);
	cout << endl << endl << endl;
	cout << "           \033[33m@---------------------------@" << endl;
	cout << "           |     \033[32;1m1. 开始    \033[0;31;1m0. 退出    \033[0;33m|" << endl;
	cout << "           @---------------------------@\033[0m" << endl;
	cout << endl << endl << endl;
	while (ch < '0' || ch > '1') {
		cin >> ch;
		ch < '0' || ch > '1' && cout << "\033[31;1m输入错误，请重新输入\033[0m" << endl << endl;
	}
	if ('0' == ch) {
		cout << endl << "欢迎下次游玩" << endl;
		return 0;
	}
	system("cls");
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && (&strmap[9][1] == cp || &strmap[8][1] == cp)) {
			b = 1;
			strmap[9][0] = '*';
			for (i = 1; i < 10; i++) {
				for (ch = 1; ch < 10; ch++) {
					'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
				}
			}
			switch (vism.front().id) {
			case 0:
				for (ch = 3; ch < 8; ch++) {
					for (i = 3; i < 8; i++) {
						strmap[ch][i] = '*';
					}
				}
				{
					int arr[10] = { 1, 2, 5, 2, 7, 1, 1, 8, 6, 7 };
					for (i = 0; i < 10; i += 2) {
						strmap[arr[i]][arr[i + 1]] = (8 != i ? '*' : strmap[7][7] = ' ');
					}
				}
				break;
			case 1:
				strmap[2][8] = '*';
				break;
			case 2:
				strmap[4][6] = '*';
				strmap[7][7] = '*';
				break;
			case 3:
			{
				char* cparr[6] = { &strmap[2][4], &strmap[4][1], &strmap[4][7], &strmap[8][1], &strmap[8][7], &strmap[6][4] };
				for (ch = 0; ch < 3; ch++) {
					for (i = 0; i < 6; i++) {
						*cparr[i]++ = '*';
					}
				}
			}
			break;
			case 4:
				for (i = 2; i < 9; i += 2) {
					for (ch = 2; ch < 9; ch += 2) {
						strmap[i][ch] = '*';
					}
				}
				strmap[8][5] = '*';
				strmap[6][3] = '*';
				strmap[6][7] = '*';
				strmap[4][5] = '*';
				break;
			case 6:
			{
				int temparr[5] = { 8,5,2,4,9 };//8,5 5,2 2,4 4,9
				for (ch = 2; ch < 9; ch++) {
					strmap[ch][ch] = '*';
					strmap[ch][10 - ch] = '*';
					if (ch < 6) {
						strmap[temparr[ch - 2]][temparr[ch - 1]] = '*';
					}
				}
				break;
			}
			case 7:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 8:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 9:
				strmap[4][5] = '*';
				strmap[7][5] = '*';
				break;
			case 10:
				for (i = 1; i < 10; i++) {
					for (ch = 1; ch < 10; ch++) {
						'#' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				for (i = 2; i <= 8; i += 6) {
					for (ch = 4; ch < 7; ch++) {
						strmap[i][ch] = '+';
						strmap[ch][i] = '+';
					}
					for (ch = 2; ch <= 8; ch++) {
						'+' != strmap[i][ch] && (strmap[i][ch] = '-');
						'+' != strmap[ch][i] && (strmap[ch][i] = '-');
					}
				}
				for (i = 2; i <= 8; i++) {
					for (ch = 2; ch <= 8; ch++) {
						'-' == strmap[i][ch] && (strmap[i][ch] = '*');
						'+' == strmap[i][ch] && (strmap[i][ch] = ' ');
					}
				}
				strmap[5][1] = '*';
				strmap[5][9] = '*';
				break;
			default:
				break;
			}
			memcpy(strmapr, strmap, sizeof strmap);
			strmapr[9][1] = ' ';
			for (ch = 0; vism.front().vmp[ch] != vism.front().vmp.back(); ch++) {
				if ('X' == vism.front().vmp[ch]->getm()) {
					((MX*)vism.front().vmp[ch])->exset(strmap);
				}
			}
			if ('X' == vism.front().vmp[ch]->getm()) {
				((MX*)vism.front().vmp[ch])->exset(strmap);
			}
			for (ch = 0; vism.front().vmp.size() != ch; ch++) {
				*vism.front().vmp[ch]->getcp() = vism.front().vmp[ch]->getm();
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.shootmove(&strmap, 0);//子弹删
		for (vector<draw>::iterator it = vmd[5 - vism.size()].begin(); &strmap[9][0] == cp && vmd[5 - vism.size()].back().iwalk + 1; it++) {
			for (char* drawcp = &strmap[it->ix][it->iy]; it->iwalk + 1; drawcp += (1 + 10 * it->brd), it->iwalk--) {
				*drawcp = '#';
			}
		}
		p.printmap(strmap, ba);
		ba = 1;
		cin >> ch;
		rewind(stdin);
		'*' != *cp && (*cp = ' ');
		//玩弹怪依次动
		//玩动
		switch (ch) {
		case 'a':
			p.left_move(&cp);
			break;
		case 'd':
			p.right_move(&cp);
			break;
		case 'w':
			p.jump(&cp);
			break;
		case 'z':
			p.shoot(ishoot, &cp);
		default:
			break;
		}
		p.upOrDown(&cp);
		(' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, "\a");
		//有怪物使你扣血
		ishoot > 0 && ishoot--;
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = (ba ? ba = !ba, 2 : rand() % 4)) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MUD());
						break;
					case 2:
						mpv.push_back(new MO());
						break;
					case 3:
						mpv.push_back(new MX());
						break;
					default:
						break;
					}
					vism.front()/* <- 会改 */.vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					const int arr[8] = { -12,-11,-10,-1,1,10,11,12 };
					while (!cpa || ' ' != *cpa) {
						int ira = rand() % (cpa = vism.front().vmp.front()->getcp(), 8);
						int imx = (vism.front().vmp.front()->getcp() - &strmap[0][0]) / 11;
						int imy = (vism.front().vmp.front()->getcp() - &strmap[0][0]) % 11;
						bool boolarr[8] = { (imx || imy), !!imx, (imx || 10 != imy), !!imy, 10 != imy, (10 != imx || imy), 10 != imx, (imx || 10 != imy) };
						boolarr[ira] && (cpa += arr[ira]);
					}
					mx = (cpa - &strmap[0][0]) / 11;
					my = (cpa - &strmap[0][0]) % 11;
					switch (ir) {
					case 0:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 2, NULL, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 3, &em, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism.front().vmp.back()->set(p.sgetxyhs(), &cpa, 5, NULL, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				'*' != *vism.front().vmp.back()->getcp() && (*vism.front().vmp.back()->getcp() = vism.front().vmp.back()->getm());
				if ('X' == vism.front().vmp.back()->getm()) {
					((MX*)vism.front().vmp.back())->exset(strmapr);
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				'*' != *vism.front().vmp.front()->getcp() && it == vism.front().vmp.end() && (*vism.front().vmp.front()->getcp() = ' ');
				'X' == vism.front().vmp.front()->getm() && (*vism.front().vmp.front()->getcp() = ((MX*)vism.front().vmp.front())->getm(0));
				'*' != *vism.front().vmp.front()->getcp() && (*vism.front().vmp.front()->getcp() = ' ');
				if ('+' == vism.front().vmp.front()->getm()) {
					for_each(vism.front().vmp.begin(), vism.front().vmp.end(), setMempty);
					vism.front().vmp.clear();
					bb = 0;
				} 
				bb && (vism.front().vmp.erase(vism.front().vmp.begin()), 0);//删除怪物
			}
		}
		p.shootmove(&strmap, 1);//子弹动
		if (b && '*' == strmap[9][10]) {//怪物动
			vector<moster*>::iterator vfvp = vism.front/* <- 会改(back) */().vmp.begin();
			while (/*完善后有判断*/!vism.front/* <- 会改(back) */().vmp.empty() && '+' != (*vfvp)->getm()) {
				if (vism.front/* <- 会改(back) */().vmp.end() == ++vfvp) {
					break;
				}
			}
			if (1 == vism.size() && bb && (!bosswait || (bosswait--, 0))) {
				char* setcp = &strmap[5][5];
				vo.push_back(new M_o());
				vism.front().vmp.push_back(vo.back());
				vism.front().vmp.back()->set(p.sgetxyhs(), &setcp, 5);
				bosswait = 15;
			}//**会变**
			for (vector<moster*>::iterator it = vism.front().vmp.begin(); vism.front().vmp.end() != it/* || ((*it)->getcp() = tempcp, 0)*/; it++) {
				(*it)->hunt();
				(*it)->mosterdo();
				(*it)->hunt();
			}
			for (vector<trir>::iterator it = p.sgetxyhs()->begin(); p.sgetxyhs()->end() != it; it++) {
				-2 >= it->iy && it->iy++;
			}
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		(' ' == *cp || '@' == *cp) || cout << (p.sgetxyhs(HEAL)--, "\a"), (' ' == *cp || '@' == *cp) && (*cp = 'P');
		//没血使怪物死亡
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if (bb && 'P' == strmap[9][10]) {
			strmap[9][0] = ' ';
			b = 0;
			for (i = 0; i < 10; i++) {
				p.printmap(&strmap, ba, i);
				Sleep(100);
				system("cls");
			}
			//下一地牢初始化
			////( <- 分界 )
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			////
			p.printmap(&strmap, ba, 11);
			Sleep(100);
			system("cls");
			1 != vism.size() && (!(rand() % 4) && (3 > p.sgetxyhs(HEAL) && p.sgetxyhs(HEAL)++, ba = 0) || (!(rand() % 2)) && (3 > p.sgetxyhs(HEAL) && p.sgetxyhs(HEAL)++, ba = 0));//恢复血量
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C') || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	for_each(vo.begin(), vo.end(), delvo);
	return 0;
}