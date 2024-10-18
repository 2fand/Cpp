#include <iostream>// <-- 必备
#include <string>
#include <cstring>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;// <-- 必备
#define PANADD(A,B) ((A) < (B) ? 1 : -1) // <------ “C++两点成一线”中的宏
#define NAME(A) #A // <------ “#”中的宏
#define CAT(A,B) A##B // <------ “##”中的宏
#define NU 45 // <------ “##”中的宏
#define LL // <------ “##”中的宏
#define E ; // <------ “##”中的宏
#define OF using namespace std; // <------ “##”中的宏
/*
int main() {
	cout << endl;
	cout << "a";
	return 0;
}
*///“cout”^
/*
int main() {
	int i = 0;
	cin >> i;
	cout << i << endl;
	return 0;
}
*///“cin”^
/*
int main() {
	cout << __DATE__ << endl;
	return 0;
}
*///“__DATE__”^
/*
int main() {
	string str = "Hello, world!";
	cout << str << endl;
	return 0;
}
*///“string”^
/*
int main() {
	int i = 0;
	int ia = 0;
	int ib = 0;
	cin >> i >> ia >> ib;
	if (i >= ia && i >= ib) {
		cout << i << endl;
	}
	else if (ia >= i && ia >= ib) {
		cout << ia << endl;
	}
	else {
		cout << ib << endl;
	}
	return 0;
}
*///“求三数最大值”(考虑相等的情况)^
/*
int main() {
	int i = 0;
	cin >> i;
	switch (i) {
	case 0:
		cout << "Hello, world!" << endl;
		break;
	case 1:
		cout << "Byebye, world!" << endl;
		break;
	default:
		cout << "NiHao, world!" << endl;
		break;
	}
	return 0;
}
*///“switch语句”^
/*
int main() {
	int i = 0;
	cin >> i;
	cout << (i << 1) << endl;
	cout << (i >> 1) << endl;
	return 0;
}
*///“<<和>>”^
/*
int main() {
	int i = 0;
	int ia = 0;
	cin >> i >> ia;
	cout << (i ^ ia) << endl;
	return 0;
}
*///“按位异或^”^
/*
int main() {
	cout << "\033[36mBLUE" << endl;
	return 0;
}
*///“BLUE”^
/*
int main() {
	cout << "\033[33;4mYELLOW" << endl;
	return 0;
}
*///“YELLOW”^
/*
int main() {
	cout << "\033[32;1;7mGREEN" << endl;
	return 0;
}
*///“GREEN”^
/*
int main() {
	int i = 0;
	cin >> i;
	i > 0 && cout << "+";
	cout << i << endl;
	return 0;
}
*///自动添加正负号^
/*
int main() {
	cout << 1145E4;
	return 0;
}
*///“1145E4”^
/*
int main() {
	cout << 6E8F;
	return 0;
}
*///“6E8F”^
/*
int main() {
	int arr[10] = { 0,1,2,3,4,5,7,6,8,9 };
	int i = 0;
	for (; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
*///“数组”^
/*
int main() {
	string str = "Hello, ";
	cout << str;
	str = "world!\n";
	cout << str;
	return 0;
}
*///“string字符串的特殊之处”^
/*
int main() {
	int i = 0;
	int* ip = &i;
	*ip = 114514;
	cout << "ip = 0x" << ip << endl;
	cout << "*ip = " << *ip << endl;
	cout << "i = " << i << endl;
	return 0;
}
*///“指针”^
/*
struct Box {
	int ix;
	int iy;
};
int main() {
	Box b = { 3,7 };
	Box ba = { 4,5 };
	cout << "箱子b的xy坐标：(" << b.ix << ", " << b.iy << ")" << endl << "箱子ba的xy坐标：(" << ba.ix << ", " << ba.iy << ")" << endl;
	return 0;
}
*///“结构体”^
/*
union test {
	int i;
	char ch;
};
int main() {
	test t = {114514};
	cout << t.i << " " << t.ch << endl;
 	return 0;
}
*///“联合”^
/*
enum RGB {
	R,
	G,
	B,
};
int main() {
	cout << "R = " << R << endl;
	cout << "G = " << G << endl;
	cout << "B = " << B << endl;
	return 0;
}
*///“枚举”^
/*
int main() {
	int* ip = new int(10);
	cout << "*ip = " << *ip << endl;
	cout << "*ip = " << *ip << endl;
	cout << "*ip = " << *ip << endl;
	delete ip;
	//cout << "*ip = " << *ip << endl; <-- ERROR
	return 0;
}
*///“new和delete”^
/*
int main() {
	int i = 114514;
	int& ia = i;
	cout << "i = " << i << "    ia = " << ia << endl;
	ia = 666;
	cout << "i = " << i << "    ia = " << ia << endl;
	i = 1314520;
	cout << "i = " << i << "    ia = " << ia << endl;
	return 0;
}
*///“引用&”^
/*
void printmaze(char strmaze[5][5][5]) {
	cout << "-----@" << endl;
	int i = 0;
	int ia = 0;
	int ib = 0;
	for (; i < 5; i++) {
		for (ia = 0; ia < 5; ia++) {
			for (ib = 0; ib < 5; ib++) {
				cout << "\033[" << ('G' == strmaze[i][ia][ib] ? "32;1" : "0") << "m" << strmaze[i][ia][ib] << "\033[0m";
			}
			cout << "|" << endl;
		}
		cout << "-----@" << endl;
	}
}
int main() {
	char strmaze[5][5][5] = {
		'P','*',' ','*','*',
		'*',' ',' ',' ','*',
		' ',' ','*',' ',' ',
		' ','*','*','*',' ',
		' ',' ','*',' ',' ',

		' ',' ','*',' ',' ',
		' ','*',' ','*',' ',
		'*','*','*','*','*',
		' ',' ','*',' ',' ',
		' ',' ','*',' ',' ',

		'*',' ',' ','*',' ',
		'*',' ','*',' ',' ',
		' ','*',' ','*','*',
		' ',' ','*',' ',' ',
		' ',' ','*',' ',' ',

		'*','*',' ',' ',' ',
		' ',' ','*','*',' ',
		' ',' ','*',' ','*',
		' ',' ','*',' ',' ',
		' ',' ','*','*',' ',

		'*','*',' ',' ',' ',
		'*',' ',' ',' ',' ',
		' ','*','*',' ','*',
		' ',' ','*','*','*',
		' ','*',' ',' ','G',
	};
	char* cp = &strmaze[0][0][0];
	char ch = 0;
	cout << "欢迎你来玩这个3D迷宫，在这个迷宫中，“P”是你，“*”是墙，空格是你可以走的地方，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这就能让你胜利了，并且，按“w”能使你往上移，按“a”能使你往左移，按“s”能使你往下移，按“d”能使你往右移，按“q”能使你上一层，按“e”能使你下一层。这就是这迷宫的规则，你听明白了吗?" << endl << endl;
	system("pause");
	system("cls");
	while ('G' == strmaze[4][4][4]) {
		int ix = (cp - &strmaze[0][0][0]) / 25;
		int iy = (cp - &strmaze[0][0][0]) / 5 % 5;
		int iz = (cp - &strmaze[0][0][0]) % 5;
		printmaze(strmaze);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
		switch (ch) {
		case 'w':
			iy && '*' != *(cp - 5) && (cp -= 5);
			break;
		case 'a':
			iz && '*' != *(cp - 1) && (cp--);
			break;
		case 's':
			4 != iy && '*' != *(cp + 5) && (cp += 5);
			break;
		case 'd':
			4 != iz && '*' != *(cp + 1) && (cp++);
			break;
		case 'q':
			ix && '*' != *(cp - 25) && (cp -= 25);
			break;
		case 'e':
			4 != ix && '*' != *(cp + 25) && (cp += 25);
			break;
		default:
			break;
		}
		*cp = 'P';
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，你赢了" << endl;
	return 0;
}
*///“C++3D迷宫”(选自我的CSDN博客)^
/*
void fun() {
	cout << -1 << endl;
}
void fun(int i) {
	cout << 1 << " " << i << endl;
}
int main() {
	fun();
	fun(7);
	fun(114514);
	return 0;
}
*///“函数重载”^
/*
enum RBYG {
	R = 1,
	B = 2,
	Y = 4,
	G = 7,
};
struct heal {
	int ix;
	int iy;
	enum RBYG rbyg;
	int HOrD;
};
void printmaze(const char strmaze[11][11], const int ihea, heal healarr[54]) {
	int i = 0;
	int ia = 0;
	int ib = 0;
	string str = "0";
	for (; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			for (ib = 0; ib < 54; ib++) {
				if (healarr[ib].ix == i && healarr[ib].iy == ia) {
					if (2 == healarr[ib].HOrD || -2 == healarr[ib].HOrD) {
						str = "35;1";
					}
					else {
						switch (healarr[ib].rbyg) {
						case R:
							str = "31;1";
							break;
						case B:
							str = "36";
							break;
						case Y:
							str = "33";
							break;
						case G:
							str = "32;1";
							break;
						default:
							break;
						}
					}
					break;
				}
			}
			cout << "\033[" << ('P' != strmaze[i][ia] ? 'G' == strmaze[i][ia] ? "32;1" : str : "0") << "m" << strmaze[i][ia] << "\033[0m";
			str = "0";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl << "\033[3" << (ihea > 6 ? "2;1" : ihea > 3 ? "3" : "1") << "m你现在的生命值为：" << ihea << endl << "\033[0m";
}
int main() {
	char str[9] = "color 0";
	char strmaze[11][11] = {
		'P','X','O',' ',' ',' ',' ','X','X','O','O',
		'*','*','*','*',' ','X',' ',' ','X','O','O',
		'O','X','X','X',' ',' ','X',' ',' ','*','*',
		'*','*','*','*','O',' ','*','*','X','O','O',
		' ','X',' ','*','*','*','*',' ',' ','X','O',
		' ','X','X','*','X','O','*',' ',' ',' ','X',
		'X','*',' ','O',' ','X','*',' ',' ','X','O',
		' ','*','X',' ','X',' ',' ','*',' ',' ','X',
		'O','*','X','*',' ',' ',' ','*',' ','X','X',
		'X','O','X','*','X',' ',' ',' ','X','X','X',
		'O','X','O','*','O','X',' ','X','X','X','G',
	};
	char strmazer[11][11] = { 0 };
	char* cp = &strmaze[0][0];
	char ch = 0;
	int ihea = 10;
	int i = 0;
	heal healarr[54] = { {0,1,R,-1},{0,2,R,1},{0,7,R,-1},{0,8,B,-1},{0,9,R,1},{0,10,R,1},{1,5,G,-1},{1,8,Y,-1},{1,9,R,1},{1,10,B,1},{2,0,G,1},{2,1,R,-1},{2,2,R,-1},{2,3,R,-1},{2,6,B,-1},{3,4,Y,1},{3,8,Y,-1},{3,9,R,1},{3,10,R,1},{4,1,B,-1},{4,9,B,-1},{4,10,Y,1},{5,1,R,-1},{5,2,R,-1},{5,4,R,1},{5,5,R,-1},{5,10,B,-1},{6,0,Y,-1},{6,3,G,1},{6,5,Y,-1},{6,9,Y,-1},{6,10,Y,2},{7,2,R,-1},{7,4,G,-1},{7,10,B,-1},{8,0,Y,1},{8,2,B,-1},{8,9,R,-1},{8,10,G,-1},{9,0,R,-1},{9,1,G,1},{9,2,Y,-1},{9,4,B,1},{9,8,R,-1},{9,9,G,-2},{9,10,G,-2},{10,0,Y,1},{10,1,B,-1},{10,2,G,1},{10,4,B,1},{10,5,R,-1},{10,7,B,-1},{10,8,G,-1},{10,9,G,-2} };
	heal healarrR[54] = { 0 };
	memcpy(healarrR, healarr, sizeof healarr);
	memcpy(strmazer, strmaze, sizeof strmaze);
	cout << "欢迎你来玩这个\033[31m掉血迷宫\033[0m，在这个迷宫中，“P”是你，“*”是墙，空格是你可以走的地方，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这能让你\033[32;1m胜利\033[0m，并且，按“w”使你上移，按“a”使你左移，按“s”使你下移，按“d”使你右移，按“r”重置这个迷宫，\033[31;1m“X”\033[0m是\033[31;1m陷阱\033[0m，你如果踩了他，就会根据它的\033[31;1m颜\033[0;36m色\033[31m扣掉相应的血\033[0m，其中，\033[31;1m红色扣1血\033[0m，\033[36m蓝色扣2血\033[0m，\033[33m黄色扣4血\033[0m，\033[32;1m绿色扣7血\033[0m，而\033[35;1m紫色扣14血\033[0m，\033[4m并且会\033[31m永远出现在这个迷宫中\033[0m，而\033[32;1m“O”\033[0m是\033[32;1m血瓶\033[0m。到这就会使你用\033[32;1m血瓶加血\033[0m，\033[4m但\033[32;1;4m血瓶\033[0;4m用完之后就不能再使用了\033[0m，其中，\033[31;1m红色加1血\033[0m，\033[36m蓝色加2血\033[0m，\033[33m黄色加4血\033[0m，\033[32;1m绿色加7血\033[0m，\033[35;1m紫色加14血\033[0m。这就是这迷宫的规则，你听明白了吗?" << endl << endl;
	system("pause");
	system("cls");
	while ('G' == strmaze[10][10] && ihea >= 1) {
		int ix = (cp - &strmaze[0][0]) / 11;
		int iy = (cp - &strmaze[0][0]) % 11;
		for (i = 0; i < 54; i++) {
			healarr[i].HOrD < 0 && ('P' == strmaze[healarr[i].ix][healarr[i].iy] && (ihea += healarr[i].rbyg * healarr[i].HOrD), ' ' == strmaze[healarr[i].ix][healarr[i].iy] && (strmaze[healarr[i].ix][healarr[i].iy] = 'X'));
			healarr[i].HOrD > 0 && ('P' == strmaze[healarr[i].ix][healarr[i].iy] && (ihea += healarr[i].rbyg * healarr[i].HOrD), 'O' != strmaze[healarr[i].ix][healarr[i].iy] && (healarr[i].HOrD = 0));
		}
		printmaze(strmaze, ihea, healarr);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
		switch (ch) {
		case 'w':
			ix && '*' != *(cp - 11) && (cp -= 11);
			break;
		case 'a':
			iy && '*' != *(cp - 1) && (cp--);
			break;
		case 's':
			10 != ix && '*' != *(cp + 11) && (cp += 11);
			break;
		case 'd':
			10 != iy && '*' != *(cp + 1) && (cp++);
			break;
		case 'r':
			memcpy(healarr, healarrR, sizeof healarr);
			memcpy(strmaze, strmazer, sizeof strmaze);
			ihea = 10;
			cp = &strmaze[0][0];
			break; 
		default:
			break;
		}
		*cp = 'P';
		system("cls");
	}
	ihea >= 1 && (str[7] = 'A'), ihea >= 1 || (str[7] = '4');
	system(str);
	cout << (ihea >= 1 ? "恭喜你，你赢了" : "很遗憾，你输了") << endl;
	return 0;
}
*///“C++掉血迷宫”(选自我的CSDN博客)^
/*
class One {
public:
	int i;
	int fun() {
		return 1;
	}
};
int main() {
	One o = { 0 };
	One oa = { 2 };
	cout << o.i << " " << oa.i << endl;
	cout << o.fun() << " " << oa.fun() << endl;
	return 0;
}
*///“类(对象)的使用”^
/*
class Test {
public:
	Test() {
		cout << "Hello, world!" << endl;
	}
};
int main() {
	Test t;
	return 0;
}
*///“构造函数”^
/*
class Test {
public:
	~Test() {
		cout << "Hello, world!" << endl;
	}
};
int main() {
	Test t;
	return 0;
}
*///“析构函数”^
/*
int main() {
	auto i = 123;
	cout << i << endl;
	return 0;
}
*///“auto”^
/*
int main() {
	static int i = 123;
	cout << i << endl;
	return 0;
}
*///“static”^
/*
int main() {
	register int i = 123;
	cout << i << endl;
	return 0;
}
*///“register”^
/*
class Test {
public:
	int i;
private:
	int ia;
};
int main() {
	Test t;
	t.i = 123;
	//t.ia = 123;//ERR
	cout << t.i << endl;
	//cout << t.ia << endl;//ERR
	return 0;
}
*///“private”^
/*
void printmaze(const char strmaze[11][11]) {
	int i = 0;
	int ia = 0;
	for (; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('0' == strmaze[i][ia] ? "33" : 'G' == strmaze[i][ia] ? "32;1" : "0") << "m" << strmaze[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl;
}
int main() {
	char strmaze[11][11] = {
		'P','0','*','0','*','0','0',' ','0',' ',' ',
		' ',' ','*',' ','*',' ',' ','0',' ',' ',' ',
		'*','*','*',' ','*',' ','*',' ','*',' ',' ',
		'0',' ','*',' ','*','0','*',' ',' ',' ',' ',
		' ',' ','*',' ',' ',' ','0','*','*','*',' ',
		' ','0','*',' ','0','0',' ','*',' ','*','*',
		' ',' ','*','*',' ',' ','0','*','*','*','0',
		' ',' ','*','0','*',' ',' ','*',' ',' ',' ',
		'0',' ','*',' ','*',' ','*',' ',' ','*','0',
		' ',' ','*',' ','*','*','*','0',' ','*',' ',
		' ',' ','*',' ',' ','0',' ',' ',' ','*','G',
	};
	char* cp = &strmaze[0][0];
	char ch = 0;
	int i = 0;
	bool bpw = 0;
	int doorarr[36] = {0,1,3,0,5,1,0,8,8,0,0,3,3,5,4,6,1,7,0,5,0,6,6,6,5,5,9,7,6,10,8,10,5,4,7,3};
	cout << "欢迎你来玩这个\033[33m门\033[0m迷宫，在这个迷宫中，“P”是你，“*”是墙，你不能走到这，空格是你可以走的地方，“w”使你上移，“a”使你左移，“s”使你下移，“d”使你右移，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这能让你\033[32;1m胜利\033[0m，并且，\033[33m“0”\033[0m是\033[33m门\033[0m，按“\033[33mz\033[0m”键进入就可以走到\033[33m另外一扇门\033[0m的前面。这就是这迷宫的规则，你听明白了吗?" << endl << endl;
	system("pause");
	system("cls");
	while ('G' == strmaze[10][10]) {
		int ix = (cp - &strmaze[0][0]) / 11;
		int iy = (cp - &strmaze[0][0]) % 11;
		printmaze(strmaze);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
		switch (ch) {
		case 'w':
			ix && '*' != *(cp - 11) && '0' != *(cp - 11) && (cp -= 11);
			bpw = 1;
			break;
		case 'a':
			iy && '*' != *(cp - 1) && '0' != *(cp - 1) && (cp--);
			bpw = 0;
			break;
		case 's':
			10 != ix && '*' != *(cp + 11) && '0' != *(cp + 11) && (cp += 11);
			bpw = 0;
			break;
		case 'd':
			10 != iy && '*' != *(cp + 1) && '0' != *(cp + 1) && (cp++);
			bpw = 0;
			break;
		case 'z':
			if (bpw) {
				for (i = 0; i < 36; i += 2) {
					if (ix - 1 == doorarr[i] && iy == doorarr[i + 1]) {
						if (i / 2 % 2) {
							cp = &strmaze[doorarr[i - 2] + 1][doorarr[i - 1]];
						}
						else {
							cp = &strmaze[doorarr[i + 2] + 1][doorarr[i + 3]];
						}
					}
				}
			}
			break;
		default:
			break;
		}
		*cp = 'P';
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，你赢了" << endl;
	return 0;
}
*///“C++门迷宫”(选自我的CSDN博客)^
/*
class Test {
public:
	int i;
protected:
	int ia;
};
int main() {
	Test t;
	t.i = 123;
	//t.ia = 123;//ERR
	cout << t.i << endl;
	//cout << t.ia << endl;//ERR
	return 0;
}
*///“protected”^
/*
void printmap(const char strmap[11][11]) {
	int i = 0;
	int ia = 0;
	for (; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('@' == strmap[i][ia] ? "33" : '+' == strmap[i][ia] || '-' == strmap[i][ia] || '|' == strmap[i][ia] ? "33;1" : "0") << "m" << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------*" << endl;
}
int main() {
	char strmap[11][11] = {0};
	int dotarr[4] = { -1, -1, -1, -1 };
	int i = 1;
	memset(strmap, ' ', sizeof strmap);
	for (; i < 3; i++) {
		printmap(strmap);
		cout << "请输入第" << i << "个点的xy坐标(x y)(0<=x<=10, 0<=y<=10)" << (2 == i ? "\033[4m(不可重叠)\033[0m" : "") << " -> ";
		cin >> dotarr[(i - 1) * 2] >> dotarr[(i - 1) * 2 + 1];
		while (dotarr[(i - 1) * 2] < 0 || dotarr[(i - 1) * 2] > 10 || dotarr[(i - 1) * 2 + 1] < 0 || dotarr[(i - 1) * 2 + 1] > 10 || dotarr[0] == dotarr[2] && dotarr[1] == dotarr[3]) {
			cout << "\033[31;1m输入错误\033[0m，请重新输入(0<=x<=10, 0<=y<=10) -> ";
			cin >> dotarr[(i - 1) * 2] >> dotarr[(i - 1) * 2 + 1];
		}
		strmap[dotarr[(i - 1) * 2]][dotarr[(i - 1) * 2 + 1]] = '@';
		system("cls");
	}
	for (char* cp = &strmap[dotarr[0]][dotarr[1]]; !(dotarr[0] == dotarr[2] && dotarr[1] == dotarr[3]); Sleep(100)) {
		system("cls");
		printmap(strmap);
		if (dotarr[1] != dotarr[3]) {
			(cp += PANADD(dotarr[1], dotarr[3]));
			(dotarr[1] += PANADD(dotarr[1], dotarr[3])) == dotarr[3] && (*cp = '+'), dotarr[1] == dotarr[3] || (*cp = '-');
			continue;
		}
		dotarr[0] != dotarr[2] && (cp += 11 * PANADD(dotarr[0], dotarr[2]), (*cp = '|'), (dotarr[0] += PANADD(dotarr[0], dotarr[2])));
	}
	return 0;
}
*///“C++两点成一线”(选自我的CSDN博客)^
/*
int main() {
	int i = 0;
	int ia = 56;
	string str = "48+989+";
	cout << NAME(i) << " = " << i << endl;
	cout << NAME(ia) << " = " << ia << endl;
	cout << NAME(str) << " = " << str << endl;
	return 0;
}
*///“#”^
/*
int main() {
	cout << __FILE__ << endl;
	return 0;
}
*///“__FILE__”^
/*
int main() {
	cout << __LINE__ << endl;
	return 0;
}
*///“__LINE__”^
/*
int main() {
	cout << __FUNCTION__ << endl;
	return 0;
}
*///“__FUNCTION__”^
/*
void fun(int i = 10){
	cout << i << endl;
}
int main() {
	fun();
	fun(114154);
	return 0;
}
*///“函数的默认参数”^
/*
enum ABC {
	en,
	dl
};
int main() {
	cout << CAT(114, 514) << endl;
	cout << CAT(en, dl);
	cout << CAT(NU, LL) << " " << CAT(E, OF) << endl;
	return 0;
}
*///“##”^
/*
void fun(int) {
	//cout << int << endl;//ERR
	cout << "!@#$%^&*()" << endl;
}
int main() {
	//fun();//ERR
	fun(-78904367);
	fun(')');
	return 0;
}
*///“函数的占位参数”^
/*
void fun(int = 123) {
	//cout << int << endl;//ERR
	cout << "!@#$%asdfghjkl^&*()" << endl;
}
int main() {
	fun();//OK
	fun(-78904367);
	fun(')');
	return 0;
}
*///“函数的默认占位参数”^
/*
class m_int {
public:
	m_int(int inum) {
		i = inum;
	}
	int operator+(m_int mi){
		return i + mi.i;
	}
	int i;
};
int main() {
	m_int mi = 10;
	m_int mia = 666;
	cout << mi + mia << endl;
	return 0;
}
*///“重载加号运算符”^
/*
class m_int {
public:
	m_int(int inum) {
		i = inum;
	}
	int operator-(m_int mi){
		return i - mi.i;
	}
	int i;
};
int main() {
	m_int mi = 10;
	m_int mia = 666;
	cout << mi - mia << endl;
	return 0;
}
*///“重载减号运算符”^
/*
class m_int {
public:
	m_int(int inum) {
		i = inum;
	}
	int operator*(m_int mi){
		return i * mi.i;
	}
	int i;
};
int main() {
	m_int mi = 10;
	m_int mia = 666;
	cout << mi * mia << endl;
	return 0;
}
*///“重载乘号运算符”^
/*
struct near {
	int i;
	int ia;
	int ix;
	int iy;
	int iwalk;
};
void printnear(const char* const cp, char ca, near* n) {
	int i = 0;
	int arr[9] = { -33,-32,-31,-1,0,1,31,32,33 };
	for (; i < 9; i++) {
		cout << "\033[" << ('G' == cp[arr[i]] ? "32;1m" : 4 == i && '0' == ca && (n->i == n->ix || n->ia == n->iy) ? "32m" : "0m") << cp[arr[i]] << "\033[0m" << (i % 3 - 2 ? "" : "#\n");
	}
	cout << "####" << endl << "你走了\033[" << ('0' == ca ? "32;1m" : "31;1m") << n->iwalk << "\033[0m步" << endl;
}
int main() {
	srand((unsigned int)time(NULL));
	near n = { rand() % 30 + 1, rand() % 30 + 1 };
	char strmaze[32][32] = {
		'@','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','@',
		'|',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ','|',
		'|','*',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*','*',' ','*','*',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ',' ',' ','|',
		'|',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ','*',' ','*',' ',' ','*',' ','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ','|',
		'|',' ','*',' ','*','*',' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*','*',' ',' ','*',' ','*',' ','*',' ','*',' ',' ','|',
		'|',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ','*','*',' ','*',' ',' ','*',' ',' ','*','|',
		'|',' ','*',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','|',
		'|','*','*','*',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ','|',
		'|',' ','*',' ',' ','*',' ',' ',' ',' ','*',' ','*',' ','*','*',' ','*',' ','*',' ','*',' ',' ','*','*',' ','*',' ',' ','*','|',
		'|',' ','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','|',
		'|',' ',' ','*',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ','|',
		'|','*',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*','*',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ','|',
		'|',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','|',
		'|',' ','*',' ',' ','*',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ','|',
		'|',' ',' ','*',' ','*',' ',' ','*',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*','*','*',' ','*',' ','*',' ',' ','*','|',
		'|','*',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*',' ',' ','|',
		'|',' ',' ','*',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ','|',
		'|',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*','|',
		'|',' ',' ','*','*',' ','*','*',' ','*',' ',' ',' ',' ','*',' ','*',' ',' ','*','*','*','*','*',' ','*','*','*','*',' ',' ','|',
		'|',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ','*','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ','*','*',' ','|',
		'|',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ','|',
		'|',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',' ',' ',' ','|',
		'|','*',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ',' ','*','|',
		'|',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','|',
		'|',' ',' ','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','|',
		'|','*',' ',' ',' ',' ',' ','*',' ','*','*',' ',' ','*',' ',' ','*','*',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ','|',
		'|',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ','|',
		'|',' ','*',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ',' ','|',
		'|',' ','*','*',' ',' ',' ',' ','*',' ','*',' ',' ','*',' ',' ',' ','*','*','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','|',
		'|',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',' ',' ','|',
		'|','*',' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','|',
		'@','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','@',
	};
	char ca = 0;
	strmaze[n.i][n.ia] = 'P';
	char* cp = &strmaze[n.i][n.ia];
	while ('P' == strmaze[n.i = rand() % 30 + 1][n.ia = rand() % 30 + 1]) {
		;
	}
	strmaze[n.i][n.ia] = 'G';
	char ch = 0;
	cout << "欢迎你来玩这个\033[7m黑暗\033[0m迷宫，在这个迷宫中，“P”是你，“*”是墙，你不能走到这，空格是你可以走的地方，“w”上移，“a”左移，“s”下移，“d”右移，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这能让你\033[32;1m胜利\033[0m，并且，\033[4m在这个迷宫中你的出生点与\033[32;1m“G”终点\033[0;4m是随机指定的\033[0m，\033[4m而你的可视范围是以你为中心点的3*3的方块\033[0m。其中，这迷宫游戏有\033[32;1m两个\033[31m模式\033[0m，\033[32;1m一个模式是简单模式\033[0m，以\033[32;1m这个模式开始游戏就会给你提供一些\033[4m增益\033[0m：如果\033[32;1m终点“G”\033[0m的X坐标与你的X坐标相等，或者\033[32;1m终点“G”\033[0m的Y坐标与你的Y坐标相等，那么你就会变\033[32m绿\033[0m，\033[31m另一个模式是困难模式，\033[4m没有任何的增益，全靠找。\033[0m这就是这迷宫的规则，你听明白了吗?" << endl << endl << "**************" << endl << "* \033[32;1m0.简单模式\033[0m *" << endl << "* \033[31m1.困难模式\033[0m *" << endl << "**************" << endl;
	cin >> ca;
	while ('0' != ca && '1' != ca) {
		cout << "\033[31;1m输入错误，请重新输入 ->\033[0m";
		rewind(stdin);
		cin >> ca;
	}
	system("cls");
	while ('G' == strmaze[n.i][n.ia]) {
		n.ix = (cp - &strmaze[0][0]) / 32;
		n.iy = (cp - &strmaze[0][0]) % 32;
		printnear(cp, ca, &n);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
		switch (ch) {
		case 'w':
			1 != n.ix && '*' != *(cp - 32) && (cp -= 32, n.iwalk++);
			break;
		case 'a':
			1 != n.iy && '*' != *(cp - 1) && (cp--, n.iwalk++);
			break;
		case 's':
			30 != n.ix && '*' != *(cp + 32) && (cp += 32, n.iwalk++);
			break;
		case 'd':
			30 != n.iy && '*' != *(cp + 1) && (cp++, n.iwalk++);
			break;
		default:
			break;
		}
		*cp = 'P';
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，走了\033[3" << ('0' == ca ? "2m" : "3;1m") << n.iwalk << "\033[0;32;1m步就赢了" << endl;
	return 0;
}
*///“C++黑暗迷宫”(选自我的CSDN博客)^
/*
class m_int {
public:
	m_int(int inum) {
		i = inum;
	}
	int operator/(m_int mi) {
		return i / mi.i;
	}
	int i;
};
int main() {
	m_int mi = 114514;
	m_int mia = 666;
	cout << mi / mia << endl;
	return 0;
}
*///“重载除号运算符”^
/*
class m_int {
public:
	m_int(int inum) {
		i = inum;
	}
	int operator+(m_int mi) {
		return i + mi.i;
	}
	int i;
};
ostream& operator<<(ostream& cout, const m_int m_i) {
	return cout << m_i.i;
}
int main() {
	m_int mi = 114514;
	m_int mia = 666;
	cout << mi + mia << endl;
	return 0;
}
*///“重载左移运算符”^
/*
class m_int {
public:
	m_int(int inum) {
		i = inum;
	}
	int operator<(m_int mi) {
		return i < mi.i;
	}
	int i;
};
int main() {
	m_int mi = 0;
	m_int mia = 8;
	cout << (mi < mia) << endl;
	return 0;
}
*///“重载小于号运算符”^
/*
enum XY {
	X,
	Y
};
class Player{
private:
	int ix;
	int iy;
	int ij;
public:
	void left_move(char* cp, int iy) {

	}
	void right_move(char* cp, int iy) {

	}
	void jump() {

	}
	int& sgetxy(XY xymode) {
		return xymode ? iy : ix;
	}
	void upOrDown() {

	}
};
void printmap(const char strmap[11][11]) {
	int i = 0;
	int ia = 0;
	for (; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl;
}
int main() {
	char strmap[11][11] = {
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ','G',' ',' ',' ',' ',' ','*','*','*',' ',
		' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ','*','*','*',' ',' ','*','*','*',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ','*','*','*',' ',' ',' ','*','*','*',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
	};
	char* cp = &strmap[10][0];
	Player p;
	char ch = 0;
	int i = 0;
	//cout << "欢迎你来玩这个\033[33m门\033[0m迷宫，在这个迷宫中，“P”是你，“*”是墙，你不能走到这，空格是你可以走的地方，“w”使你上移，“a”使你左移，“s”使你下移，“d”使你右移，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这能让你\033[32;1m胜利\033[0m，并且，\033[33m“0”\033[0m是\033[33m门\033[0m，按“\033[33mz\033[0m”键进入就可以走到\033[33m另外一扇门\033[0m的前面。这就是这迷宫的规则，你听明白了吗?" << endl << endl;
	//system("pause");
	system("cls");
	while ('G' == strmap[1][1]) {
		p.sgetxy(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 11;
		printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
		switch (ch) {
		case 'a':
			p.sgetxy(Y) && '*' != *(cp - 1)&& (cp--);
			break;
		case 'd':
			10 != p.sgetxy(Y) && '*' != *(cp + 1) && (cp++);
			break;
		case 'w':

		default:
			break;
		}
		*cp = 'P';
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，你赢了" << endl;
	return 0;
}
*///“C++平台跳跃游戏测试版Alpha1.0”^
/*
enum XY {
	X,
	Y,
};
class Player{
private:
	int ix;
	int iy;
	int ij;
public:
	void jump(char* cp) {
		10 == ix || '*' == cp[11] && (ij = 3);
	}
	void left_move(char** cpp) {
		iy && '*' != *(*cpp-1) && ((*cpp)--);
	}
	void right_move(char** cpp) {
		10 != iy && '*' != *(*cpp+1) && ((*cpp)++);
	}
	int& sgetxy(XY xymode) {
		return xymode ? iy : ix;
	}
	void upOrDown(char** cp) {
		if (ij > 0 && ix && '*' != cp[0][-11]) {
			ij--, *cp -= 11;
		}
		else if (!ix || '*' == cp[0][-11]) {
			ij = 0, *cp += 11;
		}
		else if('*' != cp[0][11] || 10 != ix) {
			*cp += 11;
		}
	}
};
void printmap(const char strmap[11][11]) {
	int i = 0;
	int ia = 0;
	for (; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl;
}
int main() {
	char strmap[11][11] = {
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ','G',' ',' ',' ',' ',' ','*','*','*',' ',
		' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ','*','*','*',' ',' ','*','*','*',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ','*','*','*',' ',' ',' ','*','*','*',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
	};
	char* cp = &strmap[10][0];
	Player p;
	char ch = 0;
	int i = 0;
	//cout << "欢迎你来玩这个\033[33m门\033[0m迷宫，在这个迷宫中，“P”是你，“*”是墙，你不能走到这，空格是你可以走的地方，“w”使你上移，“a”使你左移，“s”使你下移，“d”使你右移，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这能让你\033[32;1m胜利\033[0m，并且，\033[33m“0”\033[0m是\033[33m门\033[0m，按“\033[33mz\033[0m”键进入就可以走到\033[33m另外一扇门\033[0m的前面。这就是这迷宫的规则，你听明白了吗?" << endl << endl;
	//system("pause");
	system("cls");
	while ('G' == strmap[1][1]) {
		p.sgetxy(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 11;
		printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
		switch (ch) {
		case 'a':
			p.left_move(&cp);
			break;
		case 'd':
			p.right_move(&cp);
			break;
		case 'w':
			p.jump(cp);
			break;
		default:
			break;
		}
		*cp = (p.upOrDown(&cp),'P');
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，你赢了" << endl;
	return 0;
}
*///“C++平台跳跃游戏Bug1.0”^
/*
enum XY {
	X,
	Y,
};
class Player{
private:
	int ix;
	int iy;
	int ij;
public:
	Player() {
		ij = 0;
	}//防止ij未定义
	void jump(char** cpp) {
		(10 == ix || '*' == (*cpp)[11]) && (ij = 3);
	}
	void left_move(char** cpp) {
		iy && '*' != *(*cpp-1) && ((*cpp)--);
	}
	void right_move(char** cpp) {
		10 != iy && '*' != *(*cpp+1) && ((*cpp)++);
	}
	int& sgetxy(XY xymode) {
		return xymode ? iy : ix;
	}
	void upOrDown(char** cpp) {
		if (ij > 0 && ix && '*' != (*cpp)[-11]) {
			ij--, *cpp -= 11;
		}
		else if (!ix || '*' == (*cpp)[-11]) {
			ij = 0, *cpp += 11;
		}
		else if('*' != (*cpp)[11] && 10 != ix) {
			*cpp += 11;
		}
	}
};
void printmap(const char strmap[11][11]) {
	int i = 0;
	int ia = 0;
	for (; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl;
}
int main() {
	char strmap[11][11] = {
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ','G',' ',' ',' ',' ',' ','*','*','*',' ',
		' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ','*','*','*',' ',' ','*','*','*',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ','*','*','*',' ',' ',' ','*','*','*',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
	};
	char* cp = &strmap[10][0];
	Player p;
	char ch = 0;
	int i = 0;
	//cout << "欢迎你来玩这个\033[33m门\033[0m迷宫，在这个迷宫中，“P”是你，“*”是墙，你不能走到这，空格是你可以走的地方，“w”使你上移，“a”使你左移，“s”使你下移，“d”使你右移，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这能让你\033[32;1m胜利\033[0m，并且，\033[33m“0”\033[0m是\033[33m门\033[0m，按“\033[33mz\033[0m”键进入就可以走到\033[33m另外一扇门\033[0m的前面。这就是这迷宫的规则，你听明白了吗?" << endl << endl;
	//system("pause");
	system("cls");
	while ('G' == strmap[1][1]) {
		p.sgetxy(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 11;
		printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		default:
			break;
		}
		p.upOrDown(&cp);
		*cp = 'P';
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，你赢了" << endl;
	return 0;
}
*///“C++平台跳跃游戏Beta1.0”^
/*
enum XY {
	X,
	Y,
};
class Player{
private:
	int ix;
	int iy;
	int ij;
public:
	Player() {
		ij = 0;
	}//初始化
	void jump(char** cpp) {
		(10 == ix || '*' == (*cpp)[11]) && (ij = 3);
	}
	void left_move(char** cpp) {
		iy && '*' != *(*cpp-1) && ((*cpp)--);
	}
	void right_move(char** cpp) {
		10 != iy && '*' != *(*cpp+1) && ((*cpp)++);
	}
	int& sgetxy(XY xymode) {
		return xymode ? iy : ix;
	}
	void upOrDown(char** cpp) {
		if (ij > 0 && ix && '*' != (*cpp)[-11]) {
			ij--, *cpp -= 11;
		}
		else if ('*' != (*cpp)[11] && (!ix || '*' == (*cpp)[-11])) {
			ij = 0, *cpp += 11;
		}
		else if('*' != (*cpp)[11] && 10 != ix) {
			*cpp += 11;
		}
	}
};
void printmap(const char strmap[11][11]) {
	int i = 0;
	int ia = 0;
	for (; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl;
}
int main() {
	char strmap[11][11] = {
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ','G',' ',' ',' ',' ',' ','*','*','*',' ',
		' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ','*','*','*',' ',' ','*','*','*',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ','*','*','*',' ',' ',' ','*','*','*',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		'P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
	};
	char* cp = &strmap[10][0];
	Player p;
	char ch = 0;
	int i = 0;
	//cout << "欢迎你来玩这个\033[33m门\033[0m迷宫，在这个迷宫中，“P”是你，“*”是墙，你不能走到这，空格是你可以走的地方，“w”使你上移，“a”使你左移，“s”使你下移，“d”使你右移，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这能让你\033[32;1m胜利\033[0m，并且，\033[33m“0”\033[0m是\033[33m门\033[0m，按“\033[33mz\033[0m”键进入就可以走到\033[33m另外一扇门\033[0m的前面。这就是这迷宫的规则，你听明白了吗?" << endl << endl;
	//system("pause");
	system("cls");
	while ('G' == strmap[1][1]) {
		p.sgetxy(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 11;
		printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		default:
			break;
		}
		p.upOrDown(&cp);
		*cp = 'P';
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，你赢了" << endl;
	return 0;
}
*///“C++平台跳跃游戏临正1.0”^
/*
//cppMeiRi.cpp
#include <iostream>
#include "Player.h"
using namespace std;
void printmap(const char strmap[11][11], const int icoin) {
	int i = 0;
	int ia = 0;
	for (; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : '$' == strmap[i][ia] ? "33m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl << "\033[33" << (20 == icoin ? ";1" : "") << "m$ * " << icoin << "\033[0m" << endl;
}
int main() {
	char str[9] = "color 0";
	char strmap[11][11] = {
		' ',' ',' ',' ',' ',' ',' ',' ','$','$',' ',
		' ','G',' ',' ',' ','$',' ','*','*','*',' ',
		' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',
		'$',' ',' ',' ','$',' ','$',' ',' ','$',' ',
		' ',' ','$',' ','*','*','*',' ','$',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ','*','*','*',' ',' ','*','*','*',' ',' ',
		' ',' ','$',' ','$',' ',' ',' ','$',' ',' ',
		' ',' ','*','*','*',' ','$',' ','*','*','*',
		' ',' ',' ',' ',' ',' ',' ',' ',' ','$','$',
		'P',' ','$','$','$',' ',' ',' ',' ','$','$'
	};
	char* cp = &strmap[10][0];
	Player p;
	char ch = 0;
	int icoin = 0;
	int coinarr[40] = { 0,8,0,9,1,5,3,0,3,4,3,6,3,9,4,2,4,8,7,2,7,4,7,8,8,6,9,9,9,10,10,2,10,3,10,4,10,9,10,10 };
	cout << "欢迎你来玩这个平台跳跃游戏，在这个游戏中，“P”是你，“*”是平台，你不能走到这，空格是\033[30;1m空气\033[0m，“w”使你跳，就像\033[31;1m马里奥\033[0m一样，“a”使你左移，“d”使你右移，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这能让你\033[32;1m胜利\033[0m，并且，\033[33m“$”\033[0m是\033[33m金币\033[0m，得到\033[33m它\033[0m就会使你\033[33m获得\033[0m一个\033[33m金币\033[0m。这就是这游戏的规则，你听明白了吗?" << endl << endl;
	system("pause");
	system("cls");
	while ('G' == strmap[1][1]) {
		p.sgetxy(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 11;
		for (ch = 0; ch < 40; ch += 2) {
			p.sgetxy(X) == coinarr[ch] && p.sgetxy(Y) == coinarr[ch + 1] && (coinarr[ch] = -1, icoin++);
		}
		printmap(strmap, icoin);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		default:
			break;
		}
		p.upOrDown(&cp);
		*cp = 'P';
		system("cls");
	}
	20 == icoin && (str[7] = 'E'), 20 == icoin || (str[7] = '6');
	system(str);
	cout << "恭喜你，你赢了，获得了金币" << icoin << "枚" << endl;
	return 0;
}
//Player.h
#pragma once
#include <iostream>
using namespace std;
#define JUMPHIGH 3
enum XY {
	X,
	Y,
};
class Player {
private:
	int ix;
	int iy;
	int ij;
public:
	Player();
	void jump(char** cpp);
	void left_move(char** cpp);
	void right_move(char** cpp);
	int& sgetxy(XY xymode);
	void upOrDown(char** cpp);
};
//Player.cpp
#include <iostream>
#include "Player.h"
using namespace std;
Player::Player(){
	ij = 0;
}
void Player::jump(char** cpp) {
	(10 == ix || '*' == (*cpp)[11]) && (ij = JUMPHIGH);
}
void Player::left_move(char** cpp) {
	iy && '*' != *(*cpp - 1) && ((*cpp)--);
}
void Player::right_move(char** cpp) {
	10 != iy && '*' != *(*cpp + 1) && ((*cpp)++);
}
int& Player::sgetxy(XY xymode) {
	return xymode ? iy : ix;
}
void Player::upOrDown(char** cpp) {
	if (ij > 0 && ix && '*' != (*cpp)[-11]) {
		ij--, * cpp -= 11;
	}
	else if ('*' != (*cpp)[11] && (!ix || '*' == (*cpp)[-11])) {
		ij = 0, * cpp += 11;
	}
	else if ('*' != (*cpp)[11] && 10 != ix) {
		*cpp += 11;
	}
}
*///“C++平台跳跃游戏”(选自我的CSDN博客)^
/*
int main() {
	std::cout << "Hello, world! - ::" << std::endl;
	return 0;
}
*///“::”^
/*
//trigger.h
#pragma once
#include <iostream>
using namespace std;
class trigger {
private:
	int MISX;
	int MISY;
	int MIEX;
	int MIEY;
	int Mtrig;
	bool MBt;
	static bool MSB;
	static bool MSBa;
	static bool MSBb;
public:
	trigger(int istartx, int istarty, int iendx, int iendy, int trig) :MISY(istarty), MIEX(iendx), MIEY(iendy), MISX(istartx), Mtrig(trig), MBt(false) {
		MSB = false;
		MSBa = false;
		MSBb = false;
	}
	void check(int ix, int iy, char strmap[11][11], char* cp = NULL);
};
//trigger.cpp
#include <iostream>
#include "trigger.h"
using namespace std;
void trigger::check(int ix, int iy, char strmap[11][11], char* cp = NULL) {
	if (MISX <= ix && ix <= MIEX && MISY <= iy && iy <= MIEY && Mtrig - 4 ? (!MBt) : 1) {
		switch (MBt = true, Mtrig) {
		case 0:
			break;
		default:
			break;
		}
	}
}
*///“触发器类1”^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
#include "trigger.h"
using namespace std;
void printmap(const char strmap[22][22]) {
	int i = 0;
	int ia = 0;
	for (; i < 22; i++) {
		for (ia = 0; ia < 22; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : 'X' == strmap[i][ia] ? "31;1m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "-----------@" << endl;
}
int main() {
	char str[9] = "color 0";
	char strmap[22][22] = {
		'G',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',
		' ','t','t','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ','#',
		' ','*','*','*',' ','t',' ',' ',' ','t',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','*','X','*',' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','t','*','*','*','t',' ',' ',' ',' ',' ',' ','t',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','t','t','t',' ',' ','t',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','t',' ','t',' ',' ','t','t','t',' ',' ','t',' ',' ',' ','S',' ',
		'X','X','X','X','X','X','X','X','X','X','X','*','*','*','X','X','X','X','X','X','*',' ',
		' ','t',' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','S',
		'*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ','t','t','*',' ',' ','*',
		' ','t','X',' ',' ',' ',' ','t','t','*','X','*',' ',' ',' ','t',' ','*',' ',' ',' ',' ',
		'G','t',' ',' ',' ','X',' ','t','t',' ',' ','t','*',' ','t',' ',' ','*',' ',' ',' ',' ',
		'*','*','*','*','*','*','*','t','t',' ',' ','t',' ',' ','t',' ',' ','*','t','t',' ',' ',
		' ',' ',' ',' ',' ','t',' ','*',' ',' ','X','t',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','t',' ',' ','*','*','*','*','*','t',' ','t','t','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','*',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ',' ','*',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','t',' ',' ','*','*','*','*',' ',' ',' ',
		' ',' ',' ','t',' ',' ',' ',' ',' ','X',' ',' ','t','X',' ','*',' ',' ',' ',' ',' ',' ',
		'P','X','X','*','X','X','X',' ','X','X','X',' ','X','X','X','*','X','X','X','X','X','X',
	};
	char* cp = &strmap[21][0];
	Player p;
	char ch = 0;
	trigger t[22] = { trigger(20,3,20,3,0), trigger(16,5,16,6,1),trigger(19,12,20,12,2),trigger(17,13,17,13,3),trigger(17,15,17,16,3),trigger(14,14,14,15,3),trigger(13,16,13,17,3),trigger(15,18,15,19,3),trigger(11,20,11,21,4),trigger(3,21,3,21,5),trigger(0,16,9,16,6),trigger(8,11,10,12,7),trigger(4,5,7,9,8),trigger(9,6,9,8,9),trigger(3,1,3,3,10),trigger(11,1,11,1,11),trigger(11,3,11,3,12),trigger(13,1,14,1,13),trigger(13,7,15,8,14),trigger(15,11,17,11,15),trigger(15,11,17,11,16),trigger(21,13,21,13,17)};
	//cout << "欢迎你来玩这个平台跳跃游戏，在这个游戏中，“P”是你，“*”是平台，你不能走到这，空格是\033[30;1m空气\033[0m，“w”使你跳，就像\033[31;1m马里奥\033[0m一样，“a”使你左移，“d”使你右移，而\033[32;1m“G”\033[0m是\033[32;1m终点\033[0m，走到这能让你\033[32;1m胜利\033[0m，并且，\033[33m“$”\033[0m是\033[33m金币\033[0m，得到\033[33m它\033[0m就会使你\033[33m获得\033[0m一个\033[33m金币\033[0m。这就是这游戏的规则，你听明白了吗?" << endl << endl;
	//system("pause");
	system("cls");
	while ('G' == strmap[0][0]) {
		p.sgetxy(X) = (cp - &strmap[0][0]) / 22;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 22;
		printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
			break;
		case 'r':
			break;
		default:
			break;
		}
		p.upOrDown(&cp);
		*cp = 'P';
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，你赢了" << endl;
	return 0;
}
//trigger.h
#pragma once
#include <iostream>
using namespace std;
class trigger {
private:
	int MISX;
	int MISY;
	int MIEX;
	int MIEY;
	int Mtrig;
	bool MBt;
	static bool MSB;
	static bool MSBa;
	static bool MSBb;
public:
	trigger(int istartx, int istarty, int iendx, int iendy, int trig) :MISY(istarty), MIEX(iendx), MIEY(iendy), MISX(istartx), Mtrig(trig), MBt(false) {
		MSB = false;
		MSBa = false;
		MSBb = false;
	}
	void check(int ix, int iy, char(*strmap)[11][11], char* cp = NULL);
};
//trigger.cpp
#include <iostream>
#include "trigger.h"
using namespace std;
void trigger::check(int ix, int iy, char (*strmap)[11][11], char* cp = NULL) {
	int i = 0;
	if (MISX <= ix && ix <= MIEX && MISY <= iy && iy <= MIEY && Mtrig - 4 ? (!MBt) : 1) {
		switch (MBt = true, Mtrig) {
		case 0:
			(*strmap)[21][3] = 'X';
			break;
		case 1:
			for (i = 16; i < 21; i++) {
				(*strmap)[i][6] = 'X';
			}
			break;
		case 2:
			for (i = 18; i < 22; i++) {
				if ('X' == (*strmap)[i][13]) {
					(*strmap)[i][13] = ' ';
				}
				else {
					(*strmap)[i][13] = 'X';
				}
			}
			break;
		case 3:
			for (i = MISX; i <= MIEX; i++) {
				for (int ia = MISY; ia <= MIEY; ia++) {
					(*strmap)[i][ia] = 'X';
				}
			}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			break;
		case 17:
			(*strmap)[21][13] = 'X';
			break;
		default:
			break;
		}
	}
}
*///“触发器类2”^
/*
//Player.cpp
#include <iostream>
#include <algorithm>
#include "trigger.h"
#include "Player.h"
using namespace std;
Player::Player(){
	ij = 2;
	ijh = 0;
	blr = 1;
}
bool trigger::MSB = false;
void Player::printmap(const char strmap[22][22]) {
	int i = 0;
	int ia = 0;
	for (; i < 22; i++) {
		for (ia = 0; ia < 22; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : 'X' == strmap[i][ia] ? "31;1m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "----------------------@" << endl;
}
void Player::Djump(char** cpp) {
	switch (ij) {
	case 2:
		((21 == ix || '*' == (*cpp)[22] || '#' == (*cpp)[22]) && (ij = 1, ijh = JUMPHIGH), (21 != ix && '*' != (*cpp)[22] && '#' != (*cpp)[22]) && (ij = 0, ijh = JUMPHIGH));
		break;
	case 1:
		((21 == ix || '*' == (*cpp)[22] || '#' == (*cpp)[22]) && (ij = 2), (21 != ix && '*' != (*cpp)[22] && '#' != (*cpp)[22]) && (ij = 0, ijh = JUMPHIGH));
		break;
	default:
		rejump(cpp);
		((21 == ix || '*' == (*cpp)[22] || '#' == (*cpp)[22]) && (ij = 1, ijh = JUMPHIGH), (21 != ix && '*' != (*cpp)[22] && '#' != (*cpp)[22]) && (ij = 0, ijh = JUMPHIGH));
		break;
	}
}
void Player::left_move(char** cpp) {
	(iy && '*' != *(*cpp - 1) && '#' != *(*cpp - 1) && ((*cpp)--));
	blr = false;
}
void Player::right_move(char** cpp) {
	21 != iy && '*' != *(*cpp + 1) && '#' != *(*cpp + 1) && ((*cpp)++);
	blr = true;
}
int& Player::sgetxy(XY xymode) {
	return xymode ? iy : ix;
}
void Player::upOrDown(char** cpp) {
	if (ijh > 0 && ix && '*' != (*cpp)[-22] && '#' != (*cpp)[-22]) {
		ijh--, *cpp -= 22;
	}
	else if ('*' != (*cpp)[22] && '#' != (*cpp)[22] && (!ix || '*' == (*cpp)[-22] || '#' == (*cpp)[-22])) {
		ijh = 0, *cpp += 22;
	}
	else if ('*' != (*cpp)[22] && '#' != (*cpp)[22] && 21 != ix) {
		*cpp += 22;
	}
}
void Player::gameover(char** cpp,const char strmap[22][22]) {
	char ch = 0;
	system("cls");
	printmap(strmap); 
	cout << "\033[31;1m游戏结束 请按r键重新开始\033[0m" << endl;
	while (ch - 'r') {
		cin >> ch;
		rewind(stdin);
		system("cls");
		if (ch - 'r') {
			printmap(strmap);
			cout << "\033[31;1m游戏结束 请按r键重新开始\033[0m" << endl;
		}
	}
	reset(cpp);
}
void Player::reset(char** cpp) {

}
void Player::rejump(char** cpp) {
	(21 == ix || '*' == (*cpp)[22]) && (ij = 2);
}
void Player::shoot(int& i, char** cpp) {
	if ((!i) && (iy && blr || 21 != iy && (!blr))) {
		v.push_back({*cpp, blr, iy});
		i = 3;
	}
}
void Player::shootmove() {
	vector<trir>::iterator ite = v.end();
	for (vector<trir>::iterator it = v.begin();ite!=it;it++) {
		(' ' == *it->cp || '@' == *it->cp) && (*it->cp = ' ');
		'#' == *it->cp && (MSB = true);
		if ('*' == *it->cp || '#' == *it->cp || (!it->iy && (!it->b)) || (21 == it->iy && it->b)) {
			vector<trir>::iterator ita = it++;
			ite--;
			v.erase(ita);
		}
		if (!v.size() || ite <= it) {
			break;
		}
		it->cp -= 1 - it->b * 2;
		it->iy -= 1 - it->b * 2;
		(' ' == *it->cp || '@' == *it->cp) && (*it->cp = '@');
	}
}
*///射弹^
/*
//Player.cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include "trigger.h"
#include "Player.h"
using namespace std;
Player::Player(){
	ij = 2;
	ijh = 0;
	blr = 1;
}
bool MSB = false;
bool MSBa = false;
bool MSBb = false;
bool MSBc = false;
bool trigger::MSv = false;
void Player::printmap(const char strmap[22][22]) {
	int i = 0;
	int ia = 0;
	for (; i < 22; i++) {
		for (ia = 0; ia < 22; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : 'X' == strmap[i][ia] ? "31;1m" : '#' == strmap[i][ia] ? trigger::MSB ? "32;1m" : "31;1m" : 'S' == strmap[i][ia] ? ((!trigger::MSv) || 21 == ia) ? "33m" : "33;1m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "----------------------@" << endl;
}
void Player::Djump(char** cpp) {
	switch (ij) {
	case 2:
		((21 == ix || '*' == (*cpp)[22] || '#' == (*cpp)[22]) && (ij = 1, ijh = JUMPHIGH), (21 != ix && '*' != (*cpp)[22] && '#' != (*cpp)[22]) && (ij = 0, ijh = JUMPHIGH));
		break;
	case 1:
		((21 == ix || '*' == (*cpp)[22] || '#' == (*cpp)[22]) && (ij = 2), (21 != ix && '*' != (*cpp)[22] && '#' != (*cpp)[22]) && (ij = 0, ijh = JUMPHIGH));
		break;
	default:
		rejump(cpp);
		((21 == ix || '*' == (*cpp)[22] || '#' == (*cpp)[22]) && (ij = 1, ijh = JUMPHIGH), (21 != ix && '*' != (*cpp)[22] && '#' != (*cpp)[22]) && (ij = 0));
		break;
	}
}
void Player::left_move(char** cpp) {
	(iy && '*' != *(*cpp - 1) && '#' != *(*cpp - 1) && ((*cpp)--));
	blr = false;
}
void Player::right_move(char** cpp) {
	21 != iy && '*' != *(*cpp + 1) && '#' != *(*cpp + 1) && ((*cpp)++);
	blr = true;
}
int& Player::sgetxy(XY xymode) {
	return xymode ? iy : ix;
}
void Player::upOrDown(char** cpp) {
	if (ijh > 0 && ix && '*' != (*cpp)[-22] && '#' != (*cpp)[-22]) {
		ijh--, *cpp -= 22;
	}
	else if ('*' != (*cpp)[22] && '#' != (*cpp)[22] && (!ix || '*' == (*cpp)[-22] || '#' == (*cpp)[-22])) {
		ijh = 0, *cpp += 22;
	}
	else if ('*' != (*cpp)[22] && '#' != (*cpp)[22] && 21 != ix) {
		*cpp += 22;
	}
}
void Player::gameover(char** cpp, char (*strmap)[22][22], const char (*strmapr)[22][22], trigger(*tarr)[23]) {
	char ch = 0;
	system("cls");
	printmap(*strmap); 
	cout << "\033[31;1m游戏结束 请按r键重新开始\033[0m" << endl;
	while (ch - 'r') {
		cin >> ch;
		rewind(stdin);
		system("cls");
		if (ch - 'r') {
			printmap(*strmap);
			cout << "\033[31;1m游戏结束 请按r键重新开始\033[0m" << endl;
		}
	}
	reset(cpp, strmap, strmapr, tarr);
}
void Player::reset(char** cpp, char(*strmap)[22][22], const char(*strmapr)[22][22], trigger(*tarr)[23]) {
	trigger::MSv && (*cpp = &((*strmap)[9][20]), ix = 9, iy = 20), trigger::MSv || (*cpp = &((*strmap)[21][0]), ix = 21, iy = 0);
	MSB = false;
	MSBa = false;
	MSBb = false;
	MSBc = false;
	int i = 0;
	memcpy(*strmap, *strmapr, sizeof(*strmapr));
	for (; i < 23; i++) {
		(*tarr)[i].MBt = false;
	}
	rejump(cpp);
}
void Player::rejump(char** cpp) {
	(21 == ix || '*' == (*cpp)[22]) && (ij = 2);
}
void Player::shoot(int& i, char** cpp) {
	if ((!i) && (iy && blr || 21 != iy && (!blr))) {
		v.push_back({*cpp, blr, iy});
		i = 3;
	}
}
void Player::shootmove(const char(*strmap)[22][22]) {
	vector<trir>::iterator ite = v.end();
	for (vector<trir>::iterator it = v.begin();ite!=it;it++) {
		(' ' == *it->cp || '@' == *it->cp) && (*it->cp = ' ');
		'#' == *it->cp && (trigger::MSB = true);
		&((*strmap)[9][20]) == it->cp && (trigger::MSv = true);
		if ('*' == *it->cp || '#' == *it->cp || (!it->iy && (!it->b)) || (21 == it->iy && it->b)) {
			vector<trir>::iterator ita = it++;
			ite--;
			v.erase(ita);
		}
		if (!v.size() || ite <= it) {
			break;
		}
		it->cp -= 1 - it->b * 2;
		it->iy -= 1 - it->b * 2;
		(' ' == *it->cp || '@' == *it->cp) && (*it->cp = '@');
	}
}
*///存档^
/*
//Game.cpp
#include <iostream>
#include <cstring>
#include <fstream>
#include "Player.h"
#include "trigger.h"
using namespace std;
void deadset(int (*deadarr)[3], fstream& fs) {
	int i = 0;
	for (; i < 3; i++) {
		fs >> (*deadarr)[i];
		fs.flush();
	}
}
void printstart() {
	cout << "*****    * * *   ***   *   *  *   *   ***      ***    ***     *****   ***     *****  *   *  *****   \033[32;1m* *  ***    * *\033[0m" << endl;
	cout << "  *      * * *  *   *  **  *  **  *  *   *    *      *   *      *    *   *      *    *   *  *     \033[32;1m * *  *      * *\033[0m " << endl;
	cout << "  *      * * *  *****  * * *  * * *  *****    *  **  *   *      *    *   *      *    *****  *****       \033[32;1m* ***\033[0m      " << endl;
	cout << "  *       * *   *   *  *  **  *  **  *   *    *   *  *   *      *    *   *      *    *   *  *           \033[32;1m*   *\033[0m      " << endl;
	cout << "*****     * *   *   *  *   *  *   *  *   *     ***    ***       *     ***       *    *   *  *****        \033[32;1m***\033[0m       " << endl;
}
int main() {
	char strmap[22][22] = {
		'G',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','*','X','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','S',' ',
		'X','X','X','X','X','X','X','X','X','X','X','*','*','*','X','X','X','X','X','X','*',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','S',
		'*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',
		' ',' ','X',' ',' ',' ',' ',' ',' ','*','X','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		'G',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',
		'*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ','*',' ',' ','X',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','*','*','*','*',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X',' ','*',' ',' ',' ',' ',' ',' ',
		' ','X','X','*','X','X','X',' ','X','X','X',' ','X','X','X','*','X','X','X','X','X','X',
	};
	char strmapr[22][22] = { 0 };
	memcpy(strmapr, strmap, sizeof strmap);
	Player p;
	char ch = 0;
	int itrap = -1;
	int ishoot = 0;
	int ibsv = 0;
	fstream fs("s.txt", ios::in);
	fs.flush();
	if ((!fs.is_open()) || fs.eof()) {
		fs.close();
		fs.open("s.txt", ios::out);
		fs << "0 0 0 0";
		fs.close();
		fs.open("s.txt", ios::in);
	}
	bool barr[3] = { 0 };
	fs >> ibsv;
	for (ch = 0; ch < 3; ch++) {
		barr[ch] = (ibsv & (1 << ch));
	}
	trigger t[23] = { trigger(20,3,20,3,0), trigger(16,5,16,6,1),trigger(19,12,20,12,2),trigger(17,13,17,13,3),trigger(17,15,17,16,3),trigger(14,14,14,15,3),trigger(13,16,13,17,3),trigger(15,18,15,19,3),trigger(11,20,11,21,4),trigger(3,21,3,21,5),trigger(0,16,9,16,6),trigger(8,11,9,13,7),trigger(4,5,7,9,8),trigger(9,6,9,8,9),trigger(3,1,3,3,10),trigger(11,1,11,1,11),trigger(11,3,11,3,12),trigger(13,1,14,1,13),trigger(13,7,15,8,14),trigger(15,11,17,11,15),trigger(16,12,17,12,16),trigger(21,13,21,13,17),trigger(11,8,11,8,18) };
	printstart();
	cout << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\t  ";
	system("pause");
	system("cls");
	printstart();
	cout << endl << "              \033[31;1m********\033[0m                          \033[33m********\033[0m                              \033[32;1m********\033[0m" << endl;
	cout << "             \033[31;1m* SAVE 1 *\033[0m                        \033[33m* SAVE 2 *\033[0m                            \033[32;1m* SAVE 3 *\033[0m" << endl;
	cout << "              \033[31;1m********\033[0m                          \033[33m********\033[0m                              \033[32;1m********\033[0m" << endl << endl;
	cout << "a左走    d右走    w二段跳，空中一段    z\033[33m存档\033[0m/射弹    r重开    \033[31;1m“X”死\033[0m   “*”墙    \033[31;1m“#”按钮\033[0m，\033[32;1m射就触发机关\033[0m    \033[33m“S”存档\033[0m    \033[32;1m“G”终点\033[0m    1~3选择要玩的存档    d删存档" << endl << endl << endl;
	cin >> ch;
	while (rewind(stdin), /*'d' != ch &&*/ (ch < '1' || ch > '3')) {
		cout << "\033[31;1m输入错误，请重新输入\033[0m" << endl << endl;
		cin >> ch;
	}
	int barri = (--ch -= '0');
	system("cls");
	char* cp = (t[0].saveset(barr[barri]) ? &strmap[9][20] : &strmap[21][0]);
	int deadarr[3] = { 0 };
	deadset(&deadarr, fs);
	*cp = 'P';
	fs << (char)(ibsv + '0');
	fs.flush();
	while ('G' == strmap[0][0]) {
		' ' == strmap[9][20] && (strmap[9][20] = 'S');
		' ' == strmap[11][21] && (strmap[11][21] = 'S');
		p.sgetxy(X) = (cp - &strmap[0][0]) / 22;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 22;
		p.printmap(strmap, deadarr[barri]);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
		switch (ch) {
		case 'a':
			p.left_move(&cp);
			break;
		case 'd':
			p.right_move(&cp);
			break;
		case 'w':
			p.Djump(&cp);
			break;
		case 'z':
			p.shoot(ishoot, &cp);
			break;
		case 'r':
			p.reset(&cp, &strmap, &strmapr, &t, deadarr[barri]);
			break;
		default:
			break;
		}
		for (int i = 0; i < 23; i++) {
			t[i].check(p.sgetxy(X), p.sgetxy(Y), &strmap, &strmapr, p, itrap, &cp, ch, &t, deadarr[barri]);
		}
		itrap > 0 && itrap--, !itrap && (strmap[14][5] = ' ', strmap[15][5] = 'X');
		p.upOrDown(&cp);
		p.shootmove(&strmap, barri, ibsv, fs, &deadarr);
		p.rejump(&cp);
		if ('X' == *cp) {
			p.gameover(&cp, &strmap, &strmapr, &t, deadarr[barri]);
		}
		*cp = 'P';
		ishoot > 0 && ishoot--;
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，你赢了，似了" << deadarr[barri] << "次" << endl;
	fs.close();
	return 0;
}
*///“似亡”^
/*
//Game.cpp
#include <iostream>
#include <cstring>
#include <fstream>
#include "Player.h"
#include "trigger.h"
using namespace std;
void deadset(int (*deadarr)[3], fstream& fs) {
	int i = 0;
	for (; i < 3; i++) {
		fs >> (*deadarr)[i];
		fs.flush();
	}
}
void printstart() {
	cout << "*****    * * *   ***   *   *  *   *   ***      ***    ***     *****   ***     *****  *   *  *****   \033[32;1m* *  ***    * *\033[0m" << endl;
	cout << "  *      * * *  *   *  **  *  **  *  *   *    *      *   *      *    *   *      *    *   *  *     \033[32;1m * *  *      * *\033[0m " << endl;
	cout << "  *      * * *  *****  * * *  * * *  *****    *  **  *   *      *    *   *      *    *****  *****       \033[32;1m* ***\033[0m      " << endl;
	cout << "  *       * *   *   *  *  **  *  **  *   *    *   *  *   *      *    *   *      *    *   *  *           \033[32;1m*   *\033[0m      " << endl;
	cout << "*****     * *   *   *  *   *  *   *  *   *     ***    ***       *     ***       *    *   *  *****        \033[32;1m***\033[0m       " << endl;
}
int main() {
	char strmap[22][22] = {
		'G',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','*','X','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','S',' ',
		'X','X','X','X','X','X','X','X','X','X','X','*','*','*','X','X','X','X','X','X','*',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','S',
		'*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',
		' ',' ','X',' ',' ',' ',' ',' ',' ','*','X','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		'G',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',
		'*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ','*',' ',' ','X',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','*','*','*','*',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X',' ','*',' ',' ',' ',' ',' ',' ',
		' ','X','X','*','X','X','X',' ','X','X','X',' ','X','X','X','*','X','X','X','X','X','X',
	};
	char strmapr[22][22] = { 0 };
	memcpy(strmapr, strmap, sizeof strmap);
	Player p;
	char ch = 0;
	int itrap = -1;
	int ishoot = 0;
	int ibsv = 0;
	fstream fs("s.txt", ios::in);
	fs.flush();
	if ((!fs.is_open()) || fs.eof()) {
		fs.close();
		fs.open("s.txt", ios::out);
		fs << "0 0 0 0";
		fs.close();
		fs.open("s.txt", ios::in);
	}
	bool barr[3] = { 0 };
	fs >> ibsv;
	for (ch = 0; ch < 3; ch++) {
		barr[ch] = (ibsv & (1 << ch));
	}
	trigger t[23] = { trigger(20,3,20,3,0), trigger(16,5,16,6,1),trigger(19,12,20,12,2),trigger(17,13,17,13,3),trigger(17,15,17,16,3),trigger(14,14,14,15,3),trigger(13,16,13,17,3),trigger(15,18,15,19,3),trigger(11,20,11,21,4),trigger(3,21,3,21,5),trigger(0,16,9,16,6),trigger(8,11,9,13,7),trigger(4,5,7,9,8),trigger(9,6,9,8,9),trigger(3,1,3,3,10),trigger(11,1,11,1,11),trigger(11,3,11,3,12),trigger(13,1,14,1,13),trigger(13,7,15,8,14),trigger(15,11,17,11,15),trigger(16,12,17,12,16),trigger(21,13,21,13,17),trigger(11,8,11,8,18) };
	printstart();
	cout << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\t  ";
	system("pause");
	system("cls");
	printstart();
	cout << endl << "              \033[31;1m********\033[0m                          \033[33m********\033[0m                              \033[32;1m********\033[0m" << endl;
	cout << "             \033[31;1m* SAVE 1 *\033[0m                        \033[33m* SAVE 2 *\033[0m                            \033[32;1m* SAVE 3 *\033[0m" << endl;
	cout << "              \033[31;1m********\033[0m                          \033[33m********\033[0m                              \033[32;1m********\033[0m" << endl << endl;
	cout << "游戏内：a左走    d右走    w二段跳，空中一段    z\033[33m存档\033[0m/射弹    r重开    \033[31;1m“X”死\033[0m   “*”墙    \033[31;1m“#”按钮\033[0m，\033[32;1m射就触发机关\033[0m    \033[33m“S”存档\033[0m    \033[32;1m“G”终点\033[0m" << endl <<  "开始界面：1~3选择要玩的存档    d删存档" << endl << endl << endl;
	cin >> ch;
	int deadarr[3] = { 0 };
	deadset(&deadarr, fs);
	while (ch < '1' || ch > '3') {
		while (rewind(stdin), 'd' != ch && (ch < '1' || ch > '3')) {
			cout << "\033[31;1m输入错误，请重新输入\033[0m" << endl << endl;
			cin >> ch;
		}
		cout << "\033[31;1m请输入要删除的存档编号(输入错误就不删除存档)\033[0m" << endl << endl;
		cin >> ch;
		if (rewind(stdin), ch < '1' || ch > '3') {
			cout << "\033[31;1m输入错误，不删除存档\033[0m" << endl << endl;
			cin >> ch;
			continue;
		}
		int index = ch - 1 - '0';
		(ibsv & (1 << index)) && (ibsv -= (1 << index));
		fs.close();
		fs.open("s.txt", ios::trunc | ios::out);
		deadarr[index] = 0;
		fs << ibsv;
		for (int i = 0; i < 3; i++) {
			fs << " " << deadarr[i];
		}
		cout << "\033[32m删除成功!\033[0m" << endl << endl;
		cin >> ch;
	}
	int barri = (--ch -= '0');
	system("cls");
	char* cp = (t[0].saveset(barr[barri]) ? &strmap[9][20] : &strmap[21][0]);
	*cp = 'P';
	fs << (char)(ibsv + '0');
	fs.flush();
	while ('G' == strmap[0][0]) {
		' ' == strmap[9][20] && (strmap[9][20] = 'S');
		' ' == strmap[11][21] && (strmap[11][21] = 'S');
		p.sgetxy(X) = (cp - &strmap[0][0]) / 22;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 22;
		p.printmap(strmap, deadarr[barri]);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
		switch (ch) {
		case 'a':
			p.left_move(&cp);
			break;
		case 'd':
			p.right_move(&cp);
			break;
		case 'w':
			p.Djump(&cp);
			break;
		case 'z':
			p.shoot(ishoot, &cp);
			break;
		case 'r':
			p.reset(&cp, &strmap, &strmapr, &t, deadarr[barri]);
			break;
		default:
			break;
		}
		for (int i = 0; i < 23; i++) {
			t[i].check(p.sgetxy(X), p.sgetxy(Y), &strmap, &strmapr, p, itrap, &cp, ch, &t, deadarr[barri]);
		}
		itrap > 0 && itrap--, !itrap && (strmap[14][5] = ' ', strmap[15][5] = 'X');
		p.upOrDown(&cp);
		p.shootmove(&strmap, barri, ibsv);
		p.rejump(&cp);
		if ('X' == *cp) {
			p.gameover(&cp, &strmap, &strmapr, &t, deadarr[barri]);
		}
		*cp = 'P';
		ishoot > 0 && ishoot--;
		system("cls");
		fs.open("s.txt", ios::trunc | ios::out);
		fs << (char)(ibsv + '0');
		for (int i = 0; i < 3; i++) {
			fs << " " << deadarr[i];
		}
		fs.close();
	}
	system("color 0A");
	cout << "恭喜你，你赢了，似了" << deadarr[barri] << "次" << endl;
	fs.close();
	return 0;
}
*///“删档”^
/*
//Cmp.h
#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;
class cmp {
public:
	bool operator()(trir t, trir ta);
};
//Cmp.cpp
#include <iostream>
#include <vector>
#include "Cmp.h"
#include "Player.h"
using namespace std;
bool cmp::operator()(trir t, trir ta) {
	return t.iy < ta.iy;
}
*///“函数对象”
/*
//Game.cpp
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include "Player.h"
#include "trigger.h"
using namespace std;
void deadset(int (*deadarr)[3], fstream& fs) {
	int i = 0;
	for (; i < 3; i++) {
		fs >> (*deadarr)[i];
		fs.flush();
	}
}
void printstart() {
	cout << "*****    * * *   ***   *   *  *   *   ***      ***    ***     *****   ***     *****  *   *  *****   \033[32;1m* *  ***    * *\033[0m" << endl;
	cout << "  *      * * *  *   *  **  *  **  *  *   *    *      *   *      *    *   *      *    *   *  *     \033[32;1m * *  *      * *\033[0m " << endl;
	cout << "  *      * * *  *****  * * *  * * *  *****    *  **  *   *      *    *   *      *    *****  *****       \033[32;1m* ***\033[0m      " << endl;
	cout << "  *       * *   *   *  *  **  *  **  *   *    *   *  *   *      *    *   *      *    *   *  *           \033[32;1m*   *\033[0m      " << endl;
	cout << "*****     * *   *   *  *   *  *   *  *   *     ***    ***       *     ***       *    *   *  *****        \033[32;1m***\033[0m       " << endl;
}
int main() {
	system("title I WANNA GO TO THE \"G\"");
	char strmap[22][22] = {
		'G',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','*','X','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','S',' ',
		'X','X','X','X','X','X','X','X','X','X','X','*','*','*','X','X','X','X','X','X','*',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','S',
		'*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',
		' ',' ','X',' ',' ',' ',' ',' ',' ','*','X','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		'G',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',
		'*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ','*',' ',' ','X',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','*','*','*','*',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X',' ','*',' ',' ',' ',' ',' ',' ',
		' ','X','X','*','X','X','X',' ','X','X','X',' ','X','X','X','*','X','X','X','X','X','X',
	};
	char strmapr[22][22] = { 0 };
	memcpy(strmapr, strmap, sizeof strmap);
	Player p;
	char ch = 0;
	int itrap = -1;
	int ishoot = 0;
	int ibsv = 0;
	fstream fs("s.txt", ios::in);
	fs.flush();
	if ((!fs.is_open()) || fs.eof()) {
		fs.close();
		fs.open("s.txt", ios::out);
		fs << "0 0 0 0";
		fs.close();
		fs.open("s.txt", ios::in);
	}
	bool barr[3] = { 0 };
	fs >> ibsv;
	for (ch = 0; ch < 3; ch++) {
		barr[ch] = (ibsv & (1 << ch));
	}
	trigger t[23] = { trigger(20,3,20,3,0), trigger(16,5,16,6,1),trigger(19,12,20,12,2),trigger(17,13,17,13,3),trigger(17,15,17,16,3),trigger(14,14,14,15,3),trigger(13,16,13,17,3),trigger(15,18,15,19,3),trigger(11,20,11,21,4),trigger(3,21,3,21,5),trigger(0,16,9,16,6),trigger(8,11,9,13,7),trigger(4,5,7,9,8),trigger(9,6,9,8,9),trigger(3,1,3,3,10),trigger(11,1,11,1,11),trigger(11,3,11,3,12),trigger(13,1,14,1,13),trigger(13,7,15,8,14),trigger(15,11,17,11,15),trigger(16,12,17,12,16),trigger(21,13,21,13,17),trigger(11,8,11,8,18) };
	printstart();
	cout << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\t  ";
	system("pause");
	system("cls");
	printstart();
	cout << endl << "              \033[31;1m********\033[0m                          \033[33m********\033[0m                              \033[32;1m********\033[0m" << endl;
	cout << "             \033[31;1m* SAVE 1 *\033[0m                        \033[33m* SAVE 2 *\033[0m                            \033[32;1m* SAVE 3 *\033[0m" << endl;
	cout << "              \033[31;1m********\033[0m                          \033[33m********\033[0m                              \033[32;1m********\033[0m" << endl << endl;
	cout << "游戏内：a左走    d右走    w二段跳，空中一段    z\033[33m存档\033[0m/射弹    r重开    \033[31;1m“X”死\033[0m   “*”墙    \033[31;1m“#”按钮\033[0m，\033[32;1m射就触发机关\033[0m    \033[33m“S”存档\033[0m    \033[32;1m“G”终点\033[0m" << endl <<  "开始界面：1~3选择要玩的存档    d删存档" << endl << endl << endl;
	cin >> ch;
	int deadarr[3] = { 0 };
	deadset(&deadarr, fs);
	while (ch < '1' || ch > '3') {
		while (rewind(stdin), (ch < '1' || ch > '3') && 'd' != ch) {
			cout << "\033[31;1m输入错误，请重新输入\033[0m" << endl << endl;
			cin >> ch;
			if (ch >= '1' && ch <= '3') {
				goto g;
			}
		}
		cout << "\033[31;1m请输入要删除的存档编号(输入错误就不删除存档)\033[0m" << endl << endl;
		cin >> ch;
		if (rewind(stdin), ch < '1' || ch > '3') {
			cout << "\033[31;1m输入错误，不删除存档\033[0m" << endl << endl;
			cin >> ch;
			continue;
		}
		int index = ch - 1 - '0';
		(ibsv & (1 << index)) && (ibsv -= (1 << index));
		fs.close();
		fs.open("s.txt", ios::trunc | ios::out);
		deadarr[index] = 0;
		fs << ibsv;
		for (int i = 0; i < 3; i++) {
			fs << " " << deadarr[i];
		}
		fs.flush();
		cout << "\033[32m删除成功!\033[0m" << endl << endl;
		cin >> ch;
	}
	g:
	int barri = (--ch -= '0');
	system("cls");
	char* cp = (t[0].saveset(barr[barri]) ? &strmap[9][20] : &strmap[21][0]);
	*cp = 'P';
	fs << (char)(ibsv + '0');
	fs.close();
	while ('G' == strmap[0][0]) {
		char str[100] = "title I WANNA GO TO THE \"G\" : 似亡 * ";
		char stra[100] = "";
		sprintf(stra, "%d", deadarr[barri]);
		strcat(str, stra);
		system(str);
		' ' == strmap[9][20] && (strmap[9][20] = 'S');
		' ' == strmap[11][21] && (strmap[11][21] = 'S');
		p.sgetxy(X) = (cp - &strmap[0][0]) / 22;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 22;
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
		switch (ch) {
		case 'a':
			p.left_move(&cp);
			break;
		case 'd':
			p.right_move(&cp);
			break;
		case 'w':
			p.Djump(&cp);
			break;
		case 'z':
			p.shoot(ishoot, &cp);
			break;
		case 'r':
			p.reset(&cp, &strmap, &strmapr, &t, deadarr[barri]);
			break;
		default:
			break;
		}
		for (int i = 0; i < 23; i++) {
			t[i].check(p.sgetxy(X), p.sgetxy(Y), &strmap, &strmapr, p, itrap, &cp, ch, &t, deadarr[barri]);
		}
		itrap > 0 && itrap--, !itrap && (strmap[14][5] = ' ', strmap[15][5] = 'X');
		p.upOrDown(&cp);
		p.shootmove(&strmap, barri, ibsv);
		p.rejump(&cp);
		if ('X' == *cp) {
			p.gameover(&cp, &strmap, &strmapr, &t, deadarr[barri]);
		}
		*cp = 'P';
		ishoot > 0 && ishoot--;
		system("cls");
		fs.open("s.txt", ios::trunc | ios::out);
		fs << (char)(ibsv + '0');
		for (int i = 0; i < 3; i++) {
			sprintf(str, "%d", deadarr[i]);
			fs << " " << str;
		}
		fs.close();
	}
	system("color 0A");
	cout << "恭喜你，你赢了，似了" << deadarr[barri] << "次" << endl;
	fs.close();
	return 0;
}
//Cmp.h
#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;
class cmp {
public:
	bool operator()(trir t, trir ta);
};
//Cmp.cpp
#include <iostream>
#include <vector>
#include "Cmp.h"
#include "Player.h"
using namespace std;
bool cmp::operator()(trir t, trir ta) {
	return t.iy < ta.iy;
}
//Player.h
#pragma once
#include <iostream>
#include <vector>
#include "trigger.h"
using namespace std;
#define JUMPHIGH 3
enum XY {
	X,
	Y,
};
struct trir {
	char* cp;
	bool b;
	int iy;
};
class Player {
private:
	int ix;
	int iy;
	int ijh;
	int ij;
	bool blr;
	vector<trir> v;
public:
	friend class trigger;
	Player();
	void printmap(const char strmap[22][22]);
	void Djump(char** cpp);
	void left_move(char** cpp);
	void right_move(char** cpp);
	int& sgetxy(XY xymode);
	void upOrDown(char** cpp);
	void gameover(char** cpp, char(*strmap)[22][22], const char(*strmapr)[22][22], trigger(*tarr)[23], int& idead);
	void reset(char** cpp, char(*strmap)[22][22], const char(*strmapr)[22][22], trigger(*tarr)[23], int& idead);
	void rejump(char** cp);
	void shoot(int& i, char** cpp);
	void shootmove(const char (*strmap)[22][22], int barri, int& ibsv);
};
//Player.cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include "trigger.h"
#include "Player.h"
#include "Cmp.h"
using namespace std;
Player::Player(){
	ij = 2;
	ijh = 0;
	blr = 1;
}
bool MSB = false;
bool MSBa = false;
bool MSBb = false;
bool MSBc = false;
bool MSv = false;
void Player::printmap(const char strmap[22][22]) {
	int i = 0;
	int ia = 0;
	for (; i < 22; i++) {
		for (ia = 0; ia < 22; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : 'X' == strmap[i][ia] ? "31;1m" : '#' == strmap[i][ia] ? trigger::MSB ? "32;1m" : "31;1m" : 'S' == strmap[i][ia] ? ((!trigger::MSv) || 21 == ia) ? "33m" : "33;1m" : '@' == strmap[i][ia] ? "33m" : "0m") << strmap[i][ia] << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << "----------------------@" << endl;
}
void Player::Djump(char** cpp) {
	switch (ij) {
	case 2:
		((21 == ix || '*' == (*cpp)[22] || '#' == (*cpp)[22]) && (ij = 1, ijh = JUMPHIGH), (21 != ix && '*' != (*cpp)[22] && '#' != (*cpp)[22]) && (ij = 0, ijh = JUMPHIGH));
		break;
	case 1:
		((21 == ix || '*' == (*cpp)[22] || '#' == (*cpp)[22]) && (ij = 2), (21 != ix && '*' != (*cpp)[22] && '#' != (*cpp)[22]) && (ij = 0, ijh = JUMPHIGH));
		break;
	default:
		rejump(cpp);
		((21 == ix || '*' == (*cpp)[22] || '#' == (*cpp)[22]) && (ij = 1, ijh = JUMPHIGH), (21 != ix && '*' != (*cpp)[22] && '#' != (*cpp)[22]) && (ij = 0));
		break;
	}
}
void Player::left_move(char** cpp) {
	(iy && '*' != *(*cpp - 1) && '#' != *(*cpp - 1) && ((*cpp)--));
	blr = false;
}
void Player::right_move(char** cpp) {
	21 != iy && '*' != *(*cpp + 1) && '#' != *(*cpp + 1) && ((*cpp)++);
	blr = true;
}
int& Player::sgetxy(XY xymode) {
	return xymode ? iy : ix;
}
void Player::upOrDown(char** cpp) {
	if (ijh > 0 && ix && '*' != (*cpp)[-22] && '#' != (*cpp)[-22]) {
		ijh--, *cpp -= 22;
	}
	else if ('*' != (*cpp)[22] && '#' != (*cpp)[22] && (!ix || '*' == (*cpp)[-22] || '#' == (*cpp)[-22])) {
		ijh = 0, *cpp += 22;
	}
	else if ('*' != (*cpp)[22] && '#' != (*cpp)[22] && 21 != ix) {
		*cpp += 22;
	}
}
void Player::gameover(char** cpp, char (*strmap)[22][22], const char (*strmapr)[22][22], trigger(*tarr)[23], int& idead) {
	char ch = 0;
	system("cls");
	' ' == (*strmap)[9][20] && ((*strmap)[9][20] = 'S');
	printmap(*strmap);
	cout << "\033[31;1m游戏结束 请按r键重新开始\033[0m" << endl;
	while (ch - 'r') {
		cin >> ch;
		rewind(stdin);
		system("cls");
		if (ch - 'r') {
			printmap(*strmap);
			cout << "\033[31;1m游戏结束 请按r键重新开始\033[0m" << endl;
		}
	}
	reset(cpp, strmap, strmapr, tarr, idead);
}
void Player::reset(char** cpp, char(*strmap)[22][22], const char(*strmapr)[22][22], trigger(*tarr)[23], int& idead) {
	idead++;
	trigger::MSv && (*cpp = &((*strmap)[9][20]), ix = 9, iy = 20), trigger::MSv || (*cpp = &((*strmap)[21][0]), ix = 21, iy = 0);
	trigger::MSB = false;
	MSBa = false;
	MSBb = false;
	MSBc = false;
	blr = true;
	int i = 0;
	memcpy(*strmap, *strmapr, sizeof(*strmapr));
	for (; i < 23; i++) {
		(*tarr)[i].MBt = false;
	}
	v.clear();
	rejump(cpp);
}
void Player::rejump(char** cpp) {
	(21 == ix || '*' == (*cpp)[22]) && (ij = 2);
}
void Player::shoot(int& i, char** cpp) {
	if ((!i) && (iy && blr || 21 != iy && (!blr))) {
		v.push_back({*cpp, blr, iy});
		i = 3;
	}
}
void Player::shootmove(const char(*strmap)[22][22], int barri, int& ibsv) {
	for (vector<trir>::iterator it = v.begin();v.end()!=it;it++) {
		(' ' == *it->cp || '@' == *it->cp) && (*it->cp = ' ');
		'#' == *it->cp && (trigger::MSB = true);
		if (&((*strmap)[9][20]) == it->cp) {
			trigger::MSv = true;
			(!(ibsv & (1 << barri))) && (ibsv += (1 << barri));
		}
		if ('*' == *it->cp || '#' == *it->cp || (!it->iy && (!it->b)) || (21 == it->iy && it->b)) {
			it->iy = -1;
		}
		if (0 <= it->iy) {
			it->cp -= (1 - it->b * 2);
			it->iy -= (1 - it->b * 2);
			(' ' == *it->cp || '@' == *it->cp) && (*it->cp = '@');
		}
	}
	sort(v.begin(), v.end(), cmp());
	while ((!v.empty()) && 0 > v.begin()->iy) {
		v.erase(v.begin());
	}
}
//trigger.h
#pragma once
#include <iostream>
#include "Player.h"
using namespace std;
class trigger {
private:
	int MISX;
	int MISY;
	int MIEX;
	int MIEY;
	int Mtrig;
	bool MBt;
	static bool MSB;
	static bool MSBa;
	static bool MSBb;
	static bool MSBc;
	static bool MSv;
public:
	friend class Player;
	trigger(int istartx, int istarty, int iendx, int iendy, int trig) :MISY(istarty), MIEX(iendx), MIEY(iendy), MISX(istartx), Mtrig(trig), MBt(false) {}
	void check(int ix, int iy, char(*strmap)[22][22], const char(*strmapr)[22][22], Player& p, int& ii, char** cpp, char ch, trigger(*tarr)[23], int& idead);
	bool saveset(bool b);
};
//trigger.cpp
#include <iostream>
#include "trigger.h"
#include <string>
#include "Player.h"
using namespace std;
bool trigger::MSB = false;
bool trigger::MSBa = false;
bool trigger::MSBb = false;
bool trigger::MSBc = false;
bool trigger::MSv = false;
void trigger::check(int ix, int iy, char (*strmap)[22][22], const char (*strmapr)[22][22],Player& p, int& ii, char** cpp, char ch, trigger(*tarr)[23], int& idead) {
	int i = 0;
	if (MISX <= ix && ix <= MIEX && MISY <= iy && iy <= MIEY && (Mtrig - 4 && Mtrig - 8 && Mtrig - 16 && Mtrig - 18 ? (!MBt) : 1)) {
		switch (MBt = true, Mtrig) {
		case 0:
			(*strmap)[21][3] = 'X';
			p.gameover(cpp, strmap, strmapr, tarr, idead);
			break;
		case 1:
			for (i = 16; i < 21; i++) {
				(*strmap)[i][6] = 'X';
			}
			break;
		case 2:
			for (i = 18; i < 22; i++) {
				if ('X' == (*strmap)[i][13]) {
					(*strmap)[i][13] = ' ';
				}
				else {
					(*strmap)[i][13] = 'X';
				}
			}
			break;
		case 3:
			for (i = MISX; i <= MIEX; i++) {
				for (int ia = MISY; ia <= MIEY; ia++) {
					(*strmap)[i][ia] = 'X';
				}
			}
			p.gameover(cpp, strmap, strmapr, tarr, idead);
			break;
		case 4:
			if ('z' == ch) { 
				(*strmap)[13][19] = 'L';
				(*strmap)[13][20] = 'O';
				(*strmap)[13][21] = 'L';
				p.gameover(cpp, strmap, strmapr, tarr, idead);
			}
			break;
		case 5:
			break;
		case 6:
			if (!MSB) {
				for (i = 0; i < 10; i++) {
					(*strmap)[i][15] = 'X';
				}
			}
			break;
		case 7:
			for (i = 8; i < 10; i++) {
				(*strmap)[i][10] = '*';
				(*strmap)[i][14] = '*';
			}
			for (; i < 15; i++) {
				(*strmap)[7][i] = '*';
			}
			break;
		case 8:
			((!MSBa) && '*' == (*cpp)[22]) && ((*cpp)[22] = 'X');
			break;
		case 9:
			MSBa = true;
			for (i = 6; i < 9; i++) {
				(*strmap)[10][i] = '*';
			}
			break;
		case 10:
			for (i = 1; i < 4; i++) {
				(*strmap)[4][i] = '*';
			}
			break;
		case 11:
		{ 
			string str = "LOL LOL"; 
			char* cpa = &((*strmap)[11][2]);
			char* cpb = &(str[0]);
			for (i = 0; i < 7; i++, cpa++, cpb++) {
				*cpa = *cpb;
			}
			MSBb = true;
		}
		break;
		case 12:
			(*strmap)[11][0] = 'G';
			(*strmap)[14][0] = ' ';
			break;
		case 13:
			(*strmap)[11][0] = 'G';
			(*strmap)[13][0] = ' ';
			(*strmap)[13][5] = 'X';
			(*strmap)[13][2] = ' ';
			(*strmap)[15][5] = '*';
			for (i = 16; i < 21; i++) {
				(*strmap)[i][0] = 'L';
				(*strmap)[i][1] = 'O';
				(*strmap)[i][2] = 'L';
			}
			break;
		case 14:
			ii = 10;
			break;
		case 15:
			MSBc = true;
			for (i = 10; i < 13; i++) {
				(*strmap)[14][i] = 'X';
			}
			(*strmap)[13][10] = '*';
			for (i = 0; i < 11; i++) {
				(*strmap)[10][i] = '*';
			}
			if (*cpp == &((*strmap)[14][12])) {
				p.gameover(cpp, strmap, strmapr, tarr, idead);
			}
			break;
		case 16:
			if (MSBc) {
				(*strmap)[14][10] = ' ';
				(*strmap)[14][11] = ' ';
				'*' == (*cpp)[11] && ((*cpp)[11] = 'X');
			}
			break;
		case 17:
			(*strmap)[21][13] = 'X';
			break;
		case 18:
			if (MSBb) {
				*cpp = &((*strmap)[11][7]);
				(*strmap)[11][8] = '*';
				MSBb = false;
			}
			break;
		default:
			break;
		}
	}
}
bool trigger::saveset(bool b) {
	MSv = b;
	return MSv;
}
*///“C++版iwanna完成”
/*
int main() {
	char str[100] = "123";
	cout << atoi(str)+1 << endl;
	return 0;
}
*///“atoi函数”^
/*
int main() {
	char str[100] = "123999999";
	cout << atol(str)+1 << endl;
	return 0;
}
*///“atol函数”^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
using namespace std;
int main() {
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
	Player p;
	char ch = 0;
	//system("pause");
	//system("cls");
	char* cp = &strmap[9][0];
	*cp = 'P';
	while (1 || 'G' == strmap[0][0]) {
		p.sgetxy(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxy(Y) = (cp - &strmap[0][0]) % 11;
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
			p.shoot();
		default:
			break;
		}
		p.upOrDown(&cp);
		*cp = 'P';
		system("cls");
	}
	system("color 0A");
	cout << "恭喜你，你赢了" << endl;
	return 0;
}
//Player.h
#pragma once
#include <iostream>
#include <vector>
#include "trigger.h"
using namespace std;
#define JUMPHIGH 3
enum XYH {
	X,
	Y,
	HEAL
};
struct trir {
	char* cp;
	bool b;
	int iy;
};
class Player {
private:
	int ix;
	int iy;
	int ijh;
	int iheal;
	bool blr;
	vector<trir> v;
public:
	Player();
	void printmap(const char strmap[11][11]);
	void jump(char** cpp);
	void left_move(char** cpp);
	void right_move(char** cpp);
	int& sgetxyh(XYH xyhmode);
	void upOrDown(char** cpp);
	void gameover();
	void reset();
	void shoot();
	void shootmove();
};
//Player.cpp
#include <iostream>
#include "Player.h"
using namespace std;
Player::Player(){
	ijh = 0;
	blr = 1;
}
void Player::printmap(const char strmap[11][11]) {
	int i = 0;
	int ia = 0;
	for (; i < 11; i++) {
		for (ia = 0; ia < 11; ia++) {
			cout << "\033[" << ('G' == strmap[i][ia] ? "32;1m" : 'v' == strmap[i][ia] ? "36m" : '&' == strmap[i][ia] || 'o' == strmap[i][ia] || 'O' == strmap[i][ia] || 'X' == strmap[i][ia] ? "31;1m" : '+' == strmap[i][ia] ? "33m" : "0m") << strmap[i][ia] << "\033[0m";
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
int& Player::sgetxyh(XYH xyhmode) {
	switch (xyhmode) {
	case X:
		return ix;
	case Y:
		return iy;
	default:
		return iheal;
	}
}
void Player::upOrDown(char** cpp) {
	if (ijh > 0 && ix && '*' != (*cpp)[-11]) {
		ijh--, *cpp -= 11;
	}
	else if ('*' != (*cpp)[11] && !ix || '*' == (*cpp)[-11]) {
		ijh = 0, *cpp += 11;
	}
	else if ('*' != (*cpp)[11] && 10 != ix) {
		*cpp += 11;
	}
}
void Player::gameover() {

}
void Player::reset() {

}
void Player::shoot() {

}
void Player::shootmove() {

}
*///“C++打小怪游戏始版”
/*
//moster.h
#pragma once
#include <iostream>
using namespace std;
class moster {
protected:
	char* mcp;
	int m_iheal;
public:
	virtual void mosterdo() = 0;
};
*///“纯虚函数”^
/*
//M^.h
#pragma once
#include <iostream>
#include "moster.h"
using namespace std;
class MUD : public moster {
private:
	bool mblr;
	bool mbud;
public:
	MUD(bool b, bool ba);
	void mosterdo();
};
//M^.cpp
#include <iostream>
using namespace std;
#include "m^.h"
MUD::MUD(bool b, bool ba) {
	mblr = b;
	mbud = ba;
}
void MUD::mosterdo() {
	' ' == **m_cpp && (mbud && (**m_cpp = 'v'), mbud && (**m_cpp = '^'));//使见
	'*' == (*m_cpp)[-1] && (mblr = 1), '*' == (*m_cpp)[1] && (mblr = 0);//撞墙换方向
	m_cpp -= (1 - 2 * mblr);//左右移
	'*' == (*m_cpp)[11] && (mbud = 0), '*' == (*m_cpp)[-11] && (mbud = 1);//碰地会反转
	m_cpp -= 11 * (1 - 2 * mbud);//上下落
}//撞墙换方向，碰地会反落
*///“M^”完成^
/*
//MO.cpp
#include <iostream>
#include "MO.h"
using namespace std;
MO::MO(WASD wasd, map<char*, WASD>m) {
	m_wasd = wasd;
	m_m = m;
}
void MO::mosterdo() {
	if (!m_m.empty()) {
		int arr[4] = { -11,-1,11,1 };
		for (map<char*, WASD>::iterator it = m_m.begin(); m_m.end() != it; it++) {
			*m_cpp == it->first && (m_wasd = it->second);
		}
		*m_cpp += (arr[m_wasd]);
	}
	else {
		if ()
	}
}//遇向则转，看路前行（1），或追玩者（2）
//MO.h
#pragma once
#include <iostream>
#include <map>
#include "moster.h"
using namespace std;
enum WASD {
	W,
	A,
	S,
	D
};
class MO : public moster {
private:
	WASD m_wasd;
	map<char*, WASD>m_m;//[strmap point, wasd]...
public:
	MO(WASD wasd, map<char*, WASD>m);
	void mosterdo();
};
*///“MO”第一部分完成^
/*
//MO.cpp
#include <iostream>
#include "MO.h"
#define NNEG(A, B) ((A) < (B) ? 1 : (A) > (B) ? -1 : 0)
using namespace std;
pair<int, int> s_m_pxy;
void MO::exset(pair<int, int>& pxy, int ix, int iy) {
	pxy.first = ix;
	pxy.second = iy;
}
void MO::mosterdo() {
	if (!m_m.empty()) {
		int arr[8] = { -11,-1,11,1 };
		for (map<char*, WASD>::iterator it = m_m.begin(); m_m.end() != it; it++) {
			*m_cpp == it->first && (m_wasd = it->second);
		}
		switch (*m_cpp += (arr[m_wasd]), m_wasd) {
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
	else {
		*m_cpp += NNEG(m_pxy.first, s_m_pxy.first);
		*m_cpp += 11 * NNEG(m_pxy.second, s_m_pxy.second);
		m_pxy.first += NNEG(m_pxy.first, s_m_pxy.first);
		m_pxy.second -= NNEG(m_pxy.second, s_m_pxy.second);
	}
}//遇向则转，看路前行（1），或追玩者（2）
void MO::set_s_pxy(int ix, int iy) {
	s_m_pxy = { ix, iy };
}
*///“MO”第二部分完成^
/*
//moster.cpp#include <iostream>
#include "moster.h"
using namespace std;
void moster::set(vector<trir> v) {
	m_v = v;
}
void moster::hude() {
	for (vector<trir>::iterator it; m_v.end() != it; it++) {
		*m_cpp == it->cp && m_iheal--;
	}//检测扣血
	m_iheal || 1;//检测死亡(1 = 未做)
}
*///“怪物扣血”^
/*
//mosters.h
#pragma once
#include <iostream>
using namespace std;
#include "moster.h"
#include "m_o.h"
#include "m&.h"
#include "m^.h"
#include "mO.h"
#include "m+.h"
#include "mX.h"
*///“头文件包含”^
/*
//M_o.cpp
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "M_o.h"
using namespace std;
void M_o::near() {
	int arr[8] = { -12, -11, -10, -1, 1, -10, -11, -12 };
	int i = 0;
	for (; i < 8; i++) {
		if ('*' == (*m_cpp)[arr[i]]) {
			m_iheal = -1;
		}
	}
}
void M_o::mosterdo() {
	switch (rand() % 8) {//随便移动
	case 0:
		'*' != *m_cpp[-12] && ((*m_cpp) -= 12);
		break;
	case 1:
		'*' != *m_cpp[-11] && ((*m_cpp) -= 11);
		break;
	case 2:
		'*' != *m_cpp[-10] && ((*m_cpp) -= 10);
		break;
	case 3:
		'*' != *m_cpp[-1] && ((*m_cpp)--);
		break;
	case 4:
		'*' != *m_cpp[1] && ((*m_cpp)++);
		break;
	case 5:
		'*' != *m_cpp[11] && ((*m_cpp) += 11);
		break;
	case 6:
		'*' != *m_cpp[12] && ((*m_cpp) += 12);
		break;
	case 7:
		'*' != *m_cpp[13] && ((*m_cpp) += 13);
		break;
	default:
		break;
	}
}//随便移动，有墙不动
*///“M_o”完成构造^
/*
//M+.cpp
#include <iostream>
using namespace std;
#include "m+.h"
#include "M_o.h"
void Mplus::mosterdo() {
	**m_cpp = '+';
}
void summon(vector<pair<int, vector<moster*>>>& vpm, int i) {
	M_o o;
	vpm[i].second.push_back(&o);
}
//M+.h
#pragma once
#include <iostream>
#include "moster.h"
#include <vector>
using namespace std;
class Mplus : public moster {
public:
	void summon(vector<pair<int, vector<moster*>>>& vpm, int i);//生成
	void mosterdo();
};
*///“M+”完成构造^
#include "M_o.h"
void Mplus::mosterdo() {
	**m_cpp = '+';
}
void summon(vector<pair<int, vector<moster*>>>& vpm, int i) {
	M_o o;
	vpm[i].second.push_back(&o);
}
//M+.h
#pragma once
#include <iostream>
#include "moster.h"
#include <vector>
using namespace std;
class Mplus : public moster {
public:
	void summon(vector<pair<int, vector<moster*>>>& vpm, int i);//生成
	void mosterdo();
};
*///“M+”完成构造^
/*
//MX.cpp
#include <iostream>
using namespace std;
#include "mX.h"
void MX::mosterdo() {
	vector<trir>::iterator it = m_v->begin();
	for (; m_v->end() != it; it++) {
		if (*m_cpp == it->cp) {
			break;
		}
	}
	if (*m_cpp == m_cp || m_v->end() != it) {
		do {
			**m_cpp = chs;//还原
			*m_cpp = &((*m_strmap)[rand() % 9 + 1][rand() % 9 + 1]);
			chs = **m_cpp;//记砖
		} while ('*' == (*m_cpp)[-1] && '*' == (*m_cpp)[1]);
	}
	**m_cpp = 'X';//使见
}//被玩家碰到传，受伤传(两旁有砖不传)，并见
//MX.h
#pragma once
#include <iostream>
#include "moster.h"
using namespace std;
class MX : public moster {
private:
	char*& m_cp;//玩家的地点，不用xy坐标
	char(*m_strmap)[11][11];
	char chs;
public:
	MX(char*& cp, char(*strmap)[11][11]) : m_cp(cp), m_strmap(strmap), chs(**m_cpp) {};
	void mosterdo();
};
*///所有怪物已完成构造^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
void MDoAndHunt(moster* mp) {
	mp->hunt();
	mp->mosterdo();
}
void del(moster* mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	Player p;
	char* cp = &strmap[9][0];
	map<char*, WASD>m;
	vector<moster*>mpv = { new Mand(), new Mand(), new Mand(), new M_o(), new MUD(), new MO(), new MX(), new Mplus()};//mpv里一共要有的怪物们
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[3] = { &strmap[5][1], &strmap[5][9], &strmap[3][4]};
	//随机设置地牢布置与怪物布置
	for (; ch < 10; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		switch (ch) {
		case 0:
			for (vism[ch].str = "&&&"; i < 3; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp[i]->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			//未完成

			break;
		case 2:
			//未完成

			break;
		case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		default:
			break;
		}
	}
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
	p.sgetxyhs(HEAL) = 3;//设置默认生命值
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && bb && 'P' != strmap[9][10]) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
			{
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
			}
				break;
			case 1:
				//未完成

				break;
			case 2:
				//未完成

				break;
			case 3:
				//未完成

				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcpp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		p.shootmove(&strmap);
		ishoot > 0 && ishoot--;
		//怪物做
		if (b) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
		}
		//有怪物使你扣血
		' ' == *cp || p.sgetxyhs(HEAL)--, ' ' == *cp && (*cp = 'P');
		//没血使怪物死亡
		sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
		while (vism.front().vmp.front()->getheal() < 1) {
			if (-1 == vism.front().vmp.front()->getheal()) {
				int ir = 0;
				//转换成其他怪物
				switch (ir = rand() % 4) {
				case 0:
					mpv.push_back(new Mand());
					break;
				case 1:
					mpv.push_back(new MO());
					break;
				case 2:
					mpv.push_back(new MX());
					break;
				case 3:
					mpv.push_back(new MUD());
					break;
				default:
					break;
				}
				vism[ch].vmp.push_back(mpv.back());
				char* cpa = NULL;
				int mx = 0;
				int my = 0;
				while (' ' == *cpa) {
					cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
				}
				switch (ir) {
				case 0:
					vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
					break;
				case 1:
					vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
					break;
				case 2:
					vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
					break;
				case 3:
					vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
					break;
				default:
					break;
				}
			}
			vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
		}
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty()) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“地牢与怪物的布置”^
/*
//M&.cpp
#include <iostream>
using namespace std;
#include "m&.h"
Mand::Mand() {
	this->set();
}
//vector<trir>* = NULL, char** = NULL, char** = NULL, pair<int, int>* = NULL, int = 0, int = 0, int = 3, bool = 0, bool = 0
void Mand::set(vector<trir>* v, char** cpp, int iheal, char**, char(*)[11][11], int, int, bool b, bool) {
	m_v = v;
	m_cpp = cpp;
	m_iheal = iheal;
	mblr = b;
}
void Mand::mosterdo() {
	**m_cpp = ' ';
	if (!mblr && '*' == (*m_cpp)[-1]) {
		mblr = 1;
	}
	else if (mblr && '*' == (*m_cpp)[1]) {
		mblr = 0;
	}//撞墙换方向
	(*m_cpp) -= (1 - 2 * mblr);//左右移
	'*' != (*m_cpp)[11] && ((*m_cpp) += 11);//下落
	**m_cpp = '&';//使见
}//撞墙换方向，会自然下落
*///“‘M&’正式死亡”^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
//#define DEBUG
void MDoAndHunt(moster* mp) {
	mp->hunt();
	mp->mosterdo();
}
void del(moster* mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	Player p;
	char* cp = &strmap[9][0];
	map<char*, WASD>m;
	vector<moster*>mpv = { new Mand(), new Mand(), new Mand(), new M_o(), new MUD(), new MO(), new MX(), new Mplus()};//mpv里一共要有的怪物们
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[3] = { &strmap[5][1], &strmap[5][9], &strmap[3][4]};
	//随机设置地牢布置与怪物布置
	for (; ch < 10; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		switch (ch) {
		case 0:
			for (vism[ch].str = "&&&"; i < 3; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp[i]->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			//未完成

			break;
		case 2:
			//未完成

			break;
		case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		default:
			break;
		}
	}
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && bb && 'P' != strmap[9][10]) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
			{
				for (ch = 2; ch < 5; ch++) {
#ifndef DEBUG
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
#else
					strmap[7][ch] = '*';
					strmap[7][ch + 3] = '*';
					strmap[7][ch + 6] = '*';
					strmap[4][ch + 1] = '*';
#endif
				}
			}
				break;
			case 1:
				//未完成

				break;
			case 2:
				//未完成

				break;
			case 3:
				//未完成

				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcpp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		ishoot > 0 && ishoot--;
		p.shootmove(&strmap, 1);//子弹删
		//怪物动
		if (b && ' ' != strmap[9][10]) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
		}
		//有怪物使你扣血
		' ' == *cp || cout << (p.sgetxyhs(HEAL)--, "\a"), ' ' == *cp && (*cp = 'P');
		//没血使怪物死亡
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MO());
						break;
					case 2:
						mpv.push_back(new MX());
						break;
					case 3:
						mpv.push_back(new MUD());
						break;
					default:
						break;
					}
					vism[ch].vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					while (' ' == *cpa) {
						cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
					}
					switch (ir) {
					case 0:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				//如果该地只有一个空格，那么设怪物所在的位置为空格
				vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
			}
		}
		p.shootmove(&strmap, 0);
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“启用DEBUG功能”^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
#define DEBUG
void MDoAndHunt(moster* mp) {
	mp->hunt();
	mp->mosterdo();
}
void del(moster* mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char*, WASD>m;
	vector<moster*>mpv = { new Mand(), new Mand(), new Mand(), new M_o(), new MUD(), new MO(), new MX(), new Mplus()};//mpv里一共要有的怪物们
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[3] = { &strmap[5][1], &strmap[5][9], &strmap[3][4]};
	//随机设置地牢布置与怪物布置
	for (; ch < 10; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		switch (ch) {
		case 0:
			for (vism[ch].str = "&&&"; i < 3; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp[i]->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			//未完成

			break;
		case 2:
			//未完成

			break;
		case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		default:
			break;
		}
	}
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 1:
				//未完成

				break;
			case 2:
				//未完成

				break;
			case 3:
				//未完成

				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		ishoot > 0 && ishoot--;
		p.shootmove(&strmap, 1);//子弹删
		//有怪物使你扣血
		' ' == *cp || cout << (p.sgetxyhs(HEAL)--, "\a"), ' ' == *cp && (*cp = 'P');
		//没血使怪物死亡
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MO());
						break;
					case 2:
						mpv.push_back(new MX());
						break;
					case 3:
						mpv.push_back(new MUD());
						break;
					default:
						break;
					}
					vism[ch].vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					while (' ' == *cpa) {
						cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
					}
					switch (ir) {
					case 0:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				if (it == vism.front().vmp.end()) {
					*vism.front().vmp.front()->getcp() = ' ';
				}
				vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
			}
		}
		//怪物动
		if (b && ' ' != strmap[9][10]) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
		}
		p.shootmove(&strmap, 0);
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//下一地牢初始化
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“地牢部分已完善”^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
#define DEBUG
void MDoAndHunt(moster* mp) {
	mp->hunt();
	mp->mosterdo();
}
void del(moster* mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char*, WASD>m;
	vector<moster*>mpv = {new Mand(), new Mand(), new Mand(), new MUD(), new MUD(), new MUD(), new MUD(), };//mpv里一共要有的怪物们
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[7] = { &strmap[5][1], &strmap[5][9], &strmap[3][4], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9], };//请注意先后顺序，否则会出bug
	//随机设置地牢布置与怪物布置
	for (; ch < 10; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {
		case 0:
			for (itemp = i + 3, vism[ch].str = "&&&"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp[3 - (itemp - i)]->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			for (itemp = i + 4, vism[ch].str = "^v^v"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp[4 - (itemp - i)]->set(p.sgetxyhs(), &strcp[i], 2, NULL, NULL, 0, 0, i % 2, (i + 1) % 2);
			}
			break;
		case 2:
			//未完成

			break;
		case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		default:
			break;
		}
	}
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 1:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 2:
				//未完成

				break;
			case 3:
				//未完成

				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		ishoot > 0 && ishoot--;
		p.shootmove(&strmap, 1);//子弹删
		//有怪物使你扣血
		' ' == *cp || cout << (p.sgetxyhs(HEAL)--, "\a"), ' ' == *cp && (*cp = 'P');
		//没血使怪物死亡
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MO());
						break;
					case 2:
						mpv.push_back(new MX());
						break;
					case 3:
						mpv.push_back(new MUD());
						break;
					default:
						break;
					}
					vism[ch].vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					while (' ' == *cpa) {
						cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
					}
					switch (ir) {
					case 0:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				if (it == vism.front().vmp.end()) {
					*vism.front().vmp.front()->getcp() = ' ';
				}
				vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
			}
		}
		//怪物动
		if (b && '*' == strmap[9][10]) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
		}
		p.shootmove(&strmap, 0);
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//下一地牢初始化
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“M^”测试^
/*
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
#define DEBUG
void MDoAndHunt(moster* mp) {
	mp->hunt();
	mp->mosterdo();
}
void del(moster* mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char*, WASD>m;
	vector<moster*>mpv = {new Mand(), new Mand(), new Mand(), new MUD(), new MUD(), new MUD(), new MUD(), };//mpv里一共要有的怪物们
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[7] = { &strmap[5][1], &strmap[5][9], &strmap[3][4], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9], };//请注意先后顺序，否则会出bug
	//随机设置地牢布置与怪物布置
	for (; ch < 10; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {
		case 0:
			for (itemp = i + 3, vism[ch].str = "&&&"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp[3 - (itemp - i)]->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			for (itemp = i + 4, vism[ch].str = "^v^v"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp[4 - (itemp - i)]->set(p.sgetxyhs(), &strcp[i], 2, NULL, NULL, 0, 0, i % 2, (i + 1) % 2);
			}
			break;
		case 2:
			//未完成

			break;
		case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		default:
			break;
		}
	}
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 1:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 2:
				//未完成

				break;
			case 3:
				//未完成

				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		ishoot > 0 && ishoot--;
		p.shootmove(&strmap, 1);//子弹删
		//有怪物使你扣血
		' ' == *cp || cout << (p.sgetxyhs(HEAL)--, "\a"), ' ' == *cp && (*cp = 'P');
		//没血使怪物死亡
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MO());
						break;
					case 2:
						mpv.push_back(new MX());
						break;
					case 3:
						mpv.push_back(new MUD());
						break;
					default:
						break;
					}
					vism[ch].vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					while (' ' == *cpa) {
						cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
					}
					switch (ir) {
					case 0:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				if (it == vism.front().vmp.end()) {
					*vism.front().vmp.front()->getcp() = ' ';
				}
				vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
			}
		}
		//怪物动
		if (b && '*' == strmap[9][10]) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
		}
		p.shootmove(&strmap, 0);
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//下一地牢初始化
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“M^”测试已完成^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
#define DEBUG
void MDoAndHunt(moster* mp) {
	mp->hunt();
	mp->mosterdo();
}
void MShow(moster* mp) {
	*mp->getcp() = mp->getm();
}
void del(moster* mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char*, WASD>m;
	vector<moster*>mpv = {new Mand(), new Mand(), new Mand(), new MUD(), new MUD(), new MUD(), new MUD(), };//mpv里一共要有的怪物们
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[7] = { &strmap[5][1], &strmap[5][9], &strmap[3][4], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9], };//请注意先后顺序，否则会出bug
	//随机设置地牢布置与怪物布置
	for (; ch < 10; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {
		case 0:
			for (itemp = i + 3, vism[ch].str = "&&&"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp[3 - (itemp - i)]->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			for (itemp = i + 4, vism[ch].str = "^v^v"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp[4 - (itemp - i)]->set(p.sgetxyhs(), &strcp[i], 2, NULL, NULL, 0, 0, i % 2, (i + 1) % 2);
			}
			break;
		case 2:
			//未完成

			break;
		case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		default:
			break;
		}
	}
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 1:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 2:
				//未完成

				break;
			case 3:
				//未完成

				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		ishoot > 0 && ishoot--;
		p.shootmove(&strmap, 1);//子弹删
		//有怪物使你扣血
		' ' == *cp || cout << (p.sgetxyhs(HEAL)--, "\a"), ' ' == *cp && (*cp = 'P');
		//没血使怪物死亡
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MO());
						break;
					case 2:
						mpv.push_back(new MX());
						break;
					case 3:
						mpv.push_back(new MUD());
						break;
					default:
						break;
					}
					vism[ch].vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					while (' ' == *cpa) {
						cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
					}
					switch (ir) {
					case 0:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				if (it == vism.front().vmp.end()) {
					*vism.front().vmp.front()->getcp() = ' ';
				}
				vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
			}
		}
		//怪物动
		if (b && '*' == strmap[9][10]) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		p.shootmove(&strmap, 0);
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//下一地牢初始化
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“已解决显示不完全bug”^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
#define DEBUG
void MDoAndHunt(moster* mp) {
	mp->hunt();
	mp->mosterdo();
}
void MShow(moster* mp) {
	*mp->getcp() = mp->getm();
}
void del(moster* mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char*, WASD>m;
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[7] = { &strmap[5][1], &strmap[5][9], &strmap[3][4], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9], };//请注意先后顺序，否则会出bug
	vector<moster*>mpv = { new Mand(), new Mand(), new Mand(), new MUD(), new MUD(), new MUD(), new MUD(), };//mpv里一共要有的怪物们
	//随机设置地牢布置与怪物布置
	for (; ch < 11; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		int itemp = 0;
		int ia = rand() % 10;
		ia += ia / 2;
		switch (ch) {
		case 0:
			for (itemp = i + 3, vism[ch].str = "&&&"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			for (itemp = i + 4, vism[ch].str = "^v^v"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 2, NULL, NULL, 0, 0, i % 2, (i + 1) % 2);
			}
			break;
		case 10:
			//未完成

			break;
		case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		case 2:
			for (itemp = i + ia; i < itemp; i++) {
				pair<bool, bool>pbb = {rand() % 2, rand() % 2};
				pair<int, int>pxy = {rand() % 9 + 1, rand() % 9 + 1};
				while ((7 == pxy.first || 5 == pxy.first) && 4 == pxy.second) {
					pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				}
				strcp[i] = &strmap[pxy.first][pxy.second];
				switch (rand() % 2) {
				case 0:
					mpv.push_back(new Mand());
					vism[ch].str += '&';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, pbb.first);
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
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 2, NULL, NULL, 0, 0, pbb.first, pbb.second);
					break;
				//case 2:

					//break;
				//case 3:

					//break;
				default:

					break;
				}
			}
			break;
		default:
			break;
		}
	}
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 1:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			//case 2:
				//未完成

				break;
			case 3:
				//未完成

				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

			case 2:
				strmap[4][5] = '*';
				strmap[7][5] = '*';
				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		ishoot > 0 && ishoot--;
		p.shootmove(&strmap, 1);//子弹删
		//有怪物使你扣血
		' ' == *cp || cout << (p.sgetxyhs(HEAL)--, "\a"), ' ' == *cp && (*cp = 'P');
		//没血使怪物死亡
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MO());
						break;
					case 2:
						mpv.push_back(new MX());
						break;
					case 3:
						mpv.push_back(new MUD());
						break;
					default:
						break;
					}
					vism[ch].vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					while (' ' == *cpa) {
						cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
					}
					switch (ir) {
					case 0:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				if (it == vism.front().vmp.end()) {
					*vism.front().vmp.front()->getcp() = ' ';
				}
				vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
			}
		}
		//怪物动
		if (b && '*' == strmap[9][10]) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		p.shootmove(&strmap, 0);
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//下一地牢初始化
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“随机怪地牢已完成”^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
#define DEBUG
void MDoAndHunt(moster* mp) {
	mp->hunt();
	mp->mosterdo();
}
void MShow(moster* mp) {
	*mp->getcp() = mp->getm();
}
void del(moster* mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char*, WASD>m;
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[11] = { &strmap[5][1], &strmap[5][9], &strmap[3][4], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9],&strmap[8][5],&strmap[5][2],&strmap[2][4],&strmap[4][7]};//请注意先后顺序，否则会出bug
	vector<moster*>mpv = { new Mand(), new Mand(), new Mand(), new MUD(), new MUD(), new MUD(), new MUD(), new MX(), new MX(), new MX(), new MX(), };//mpv里一共要有的怪物们
	//随机设置地牢布置与怪物布置
	for (; ch < 11; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {
		case 0:
			for (itemp = i + 3, vism[ch].str = "&&&"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			for (itemp = i + 4, vism[ch].str = "^v^v"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 4, NULL, NULL, 0, 0, i % 2, (i + 1) % 2);
			}
			break;
		case 2:
			for (itemp = i + 4, vism[ch].str = "XXXX"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, &cp, &strmap);
			}
			break;
		//case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		case 3:
		{
			int ia = rand() % 10;
			ia += ia / 2;
			for (itemp = i + ia; i < itemp; i++) {
				pair<bool, bool>pbb = { rand() % 2, rand() % 2 };
				pair<int, int>pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				while ((7 == pxy.first || 5 == pxy.first) && 4 == pxy.second) {
					pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				}
				strcp[i] = &strmap[pxy.first][pxy.second];
				switch (rand() % 3) {
				case 0:
					mpv.push_back(new Mand());
					vism[ch].str += '&';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, pbb.first);
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
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 2, NULL, NULL, 0, 0, pbb.first, pbb.second);
					break;
				case 2:
					mpv.push_back(new MX());
					vism[ch].str += 'X';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, &cp, &strmap);
					break;
				//case 3:

				//break;
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
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 1:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 2:
			{
				int temparr[5] = { 8,5,2,4,7 };//8,5 5,2 2,4 4,7
				for (ch = 2; ch < 9; ch++) {
					strmap[ch][ch] = '*';
					strmap[ch][10 - ch] = '*';
					if (ch < 6) {
						strmap[temparr[ch - 2]][temparr[ch - 1]] = '*';
					}
				}
			}
				break;
			case 3:
				strmap[4][5] = '*';
				strmap[7][5] = '*';
				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

			case 10:
				
				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		ishoot > 0 && ishoot--;
		p.shootmove(&strmap, 1);//子弹删
		//有怪物使你扣血
		' ' == *cp || cout << (p.sgetxyhs(HEAL)--, "\a"), ' ' == *cp && (*cp = 'P');
		//没血使怪物死亡
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MO());
						break;
					case 2:
						mpv.push_back(new MX());
						break;
					case 3:
						mpv.push_back(new MUD());
						break;
					default:
						break;
					}
					vism[ch].vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					while (' ' == *cpa) {
						cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
					}
					switch (ir) {
					case 0:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				if (it == vism.front().vmp.end()) {
					*vism.front().vmp.front()->getcp() = ' ';
				}
				vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
			}
		}
		//怪物动
		if (b && '*' == strmap[9][10]) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		p.shootmove(&strmap, 0);
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//下一地牢初始化
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“MX”房已构造完成^
/*
//Game.cpp
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
#define DEBUG
void MDoAndHunt(moster*& mp) {
	mp->hunt();
	mp->mosterdo();
}
void MShow(moster*& mp) {
	*mp->getcp() = mp->getm();
}
void del(moster*& mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char*, WASD>m;
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	vector<char*>strcp = { &strmap[5][1], &strmap[5][9], &strmap[3][4], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9],&strmap[8][5],&strmap[5][2],&strmap[2][4],&strmap[4][7]};//请注意先后顺序，否则会出bug
	vector<moster*>mpv = { new Mand(), new Mand(), new Mand(), new MUD(), new MUD(), new MUD(), new MUD(), new MX(), new MX(), new MX(), new MX(), };//mpv里一共要有的怪物们
	//随机设置地牢布置与怪物布置
	for (; ch < 11; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {
		case 0:
			for (itemp = i + 3, vism[ch].str = "&&&"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			for (itemp = i + 4, vism[ch].str = "^v^v"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 4, NULL, NULL, 0, 0, i % 2, (i + 1) % 2);
			}
			break;
		case 2:
			for (itemp = i + 4, vism[ch].str = "XXXX"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, &cp, &strmap);
			}
			break;
		//case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		case 3:
		{
			int ia = rand() % 10;
			ia += ia / 2;
			for (itemp = i + ia; i < itemp; i++) {
				pair<bool, bool>pbb = { rand() % 2, rand() % 2 };
				pair<int, int>pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				while ((7 == pxy.first || 5 == pxy.first) && 4 == pxy.second) {
					pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				}
				strcp.push_back(&strmap[pxy.first][pxy.second]);
				switch (rand() % 3) {
				case 0:
					mpv.push_back(new Mand());
					vism[ch].str += '&';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, pbb.first);
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
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 2, NULL, NULL, 0, 0, pbb.first, pbb.second);
					break;
				case 2:
					mpv.push_back(new MX());
					vism[ch].str += 'X';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, &cp, &strmap);
					break;
				//case 3:

				//break;
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
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 1:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 2:
			{
				int temparr[5] = { 8,5,2,4,7 };//8,5 5,2 2,4 4,7
				for (ch = 2; ch < 9; ch++) {
					strmap[ch][ch] = '*';
					strmap[ch][10 - ch] = '*';
					if (ch < 6) {
						strmap[temparr[ch - 2]][temparr[ch - 1]] = '*';
					}
				}
			}
				break;
			case 3:
				strmap[4][5] = '*';
				strmap[7][5] = '*';
				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

			case 10:
				
				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		ishoot > 0 && ishoot--;
		p.shootmove(&strmap, 1);//子弹删
		//有怪物使你扣血
		' ' == *cp || cout << (p.sgetxyhs(HEAL)--, "\a"), ' ' == *cp && (*cp = 'P');
		//没血使怪物死亡
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MO());
						break;
					case 2:
						mpv.push_back(new MX());
						break;
					case 3:
						mpv.push_back(new MUD());
						break;
					default:
						break;
					}
					vism[ch].vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					while (' ' == *cpa) {
						cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
					}
					switch (ir) {
					case 0:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				if (it == vism.front().vmp.end()) {
					*vism.front().vmp.front()->getcp() = ' ';
				}
				vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
			}
		}
		//怪物动
		if (b && '*' == strmap[9][10]) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		p.shootmove(&strmap, 0);
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//下一地牢初始化
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“有BUG，勿扰”^
/*
#include <iostream>
#include "Player.h"
#include "mosters.h"
#include "cmpm.h"
#include "isvp.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
#define DEBUG
void MDoAndHunt(moster*& mp) {
	mp->hunt();
	mp->mosterdo();
}
void MShow(moster*& mp) {
	*mp->getcp() = mp->getm();
}
void del(moster*& mp) {
	delete mp;
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
	bool bb = 1;
	char ch = 0;
	int i = 0;
	int ia = rand() % 11;
	ia += ia / 2;
	Player p;
	char* cp = &strmap[9][0];
	vector<map<int, int>>vm;
	map<char*, WASD>m;
	isv ism;//用来布置怪物
	vector<isv> vism;//地牢布置与怪物布置，无时即BOSS战(+)(int为编号)
	char* strcp[26] = { &strmap[5][1], &strmap[5][9], &strmap[3][4], &strmap[1][8], &strmap[9][2], &strmap[1][1], &strmap[9][9],&strmap[8][5],&strmap[5][2],&strmap[2][4],&strmap[4][7] };//请注意先后顺序，否则会出bug
	vector<moster*>mpv = { new Mand(), new Mand(), new Mand(), new MUD(), new MUD(), new MUD(), new MUD(), new MX(), new MX(), new MX(), new MX(), };//mpv里一共要有的怪物们
	//随机设置地牢布置与怪物布置
	for (; ch < 11; ch++) {
		vism.push_back(ism);
		vism[ch].id = ch;
		int itemp = 0;
		switch (ch) {
		case 0:
			for (itemp = i + 3, vism[ch].str = "&&&"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, i % 2);
			}
			break;
		case 1:
			for (itemp = i + 4, vism[ch].str = "^v^v"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 4, NULL, NULL, 0, 0, i % 2, (i + 1) % 2);
			}
			break;
		case 2:
			for (itemp = i + 4, vism[ch].str = "XXXX"; i < itemp; i++) {
				vism[ch].vmp.push_back(mpv[i]);
				vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, &cp, &strmap);
			}
			break;
		//case 3:
			//未完成

			break;
		case 4:
			//未完成

			break;
		case 5:
			//未完成

			break;
		case 6:
			//未完成

			break;
		case 7:
			//未完成

			break;
		case 8:
			//未完成

			break;
		case 9:
			//未完成

			break;
		case 3:
		{
			for (itemp = i + ia; i < itemp; i++) {
				pair<bool, bool>pbb = { rand() % 2, rand() % 2 };
				pair<int, int>pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				while ((7 == pxy.first || 5 == pxy.first) && 4 == pxy.second) {
					pxy = { rand() % 9 + 1, rand() % 9 + 1 };
				}
				strcp[i] = (&strmap[pxy.first][pxy.second]);
				switch (rand() % 3) {
				case 0:
					mpv.push_back(new Mand());
					vism[ch].str += '&';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, NULL, NULL, 0, 0, pbb.first);
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
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 2, NULL, NULL, 0, 0, pbb.first, pbb.second);
					break;
				case 2:
					mpv.push_back(new MX());
					vism[ch].str += 'X';
					vism[ch].vmp.push_back(mpv.back());
					vism[ch].vmp.back()->set(p.sgetxyhs(), &strcp[i], 3, &cp, &strmap);
					break;
				//case 3:

				//break;
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
	//random_shuffle(vism.begin(), vism.end());//使地牢随机化
	while (4 != vism.size()) {
		vism.pop_back();//删除不重要的东西
	}
#ifdef DEBUG
	p.sgetxyhs(HEAL) = 999;//设置默认生命值
#else 
	p.sgetxyhs(HEAL) = 3;
#endif
	int ishoot = 0;
	bool b = 0;
	//system("pause");
	//system("cls");
	char str[9] = "color 0";
	while (p.sgetxyhs(HEAL) && (bb || 'P' != strmap[9][10])) {
		MO mo;
		//如果玩家踏进新的地牢(具体位置：&strmap[9][1])(!b)，b设为真，并重置怪物生成和地牢生成(vism无时BOSS战(+))
		if (!b && &strmap[9][1] == cp) {
			b = 1;
			strmap[9][0] = '*';
			vism.front().cp = &(vism.front().str[0]);
			switch (vism.front().id) {
			case 0:
				for (ch = 2; ch < 5; ch++) {
					strmap[7][ch] = '*';
					strmap[7][ch + 4] = '*';
					strmap[4][ch + 1] = '*';
				}
				break;
			case 1:
				for (ch = 1; ch < 4; ch++) {
					strmap[2][ch] = '*';
					strmap[5][ch + 3] = '*';
					strmap[8][ch + 6] = '*';
				}
				break;
			case 2:
			{
				int temparr[5] = { 8,5,2,4,7 };//8,5 5,2 2,4 4,7
				for (ch = 2; ch < 9; ch++) {
					strmap[ch][ch] = '*';
					strmap[ch][10 - ch] = '*';
					if (ch < 6) {
						strmap[temparr[ch - 2]][temparr[ch - 1]] = '*';
					}
				}
			}
				break;
			case 3:
				strmap[4][5] = '*';
				strmap[7][5] = '*';
				break;
			case 4:
				//未完成

				break;
			case 5:
				//未完成

				break;
			case 6:
				//未完成

				break;
			case 7:
				//未完成

				break;
			case 8:
				//未完成

				break;
			case 9:
				//未完成

			case 10:
				
				break;
			default:
				break;
			}
			for (ch = 0; *(vism.front().cp); ch++, vism.front().cp++) {
				*vism.front().vmp[ch]->getcp() = *vism.front().cp;
			}
		}
		p.sgetxyhs(X) = (cp - &strmap[0][0]) / 11;
		p.sgetxyhs(Y) = (cp - &strmap[0][0]) % 11;
		mo.set_s_pxy(p.sgetxyhs(X), p.sgetxyhs(Y));
		p.printmap(strmap);
		cin >> ch;
		rewind(stdin);
		*cp = ' ';
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
		//有怪物使你扣血
		ishoot > 0 && ishoot--;
		p.shootmove(&strmap, 1);//子弹删
		//没血使怪物死亡
		if (' ' != strmap[9][10]) {
			sort(vism.front().vmp.begin(), vism.front().vmp.end(), cmpm());//对怪物血量进行升序排序
			while (!vism.front().vmp.empty() && vism.front().vmp.front()->getheal() < 1) {
				if (-1 == vism.front().vmp.front()->getheal()) {
					int ir = 0;
					//把怪物“o”转换成其他怪物
					switch (ir = rand() % 4) {
					case 0:
						mpv.push_back(new Mand());
						break;
					case 1:
						mpv.push_back(new MO());
						break;
					case 2:
						mpv.push_back(new MX());
						break;
					case 3:
						mpv.push_back(new MUD());
						break;
					default:
						break;
					}
					vism[ch].vmp.push_back(mpv.back());
					char* cpa = NULL;
					int mx = 0;
					int my = 0;
					while (' ' == *cpa) {
						cpa = &strmap[mx = rand() % 9 + 1][my = rand() % 9 + 1];
					}
					switch (ir) {
					case 0:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2);//怪物“&”
						break;
					case 1:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, 0, 0, rand() % 2, rand() % 2);//怪物“^”
						break;
					case 2:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, NULL, NULL, mx, my);//怪物“O”
						break;
					case 3:
						vism[ch].vmp.front()->set(p.sgetxyhs(), &cpa, 3, &cp, &strmap);//怪物“X”
						break;
					default:
						break;
					}
				}
				//如果该地只有一个怪物，那么设怪物所在的位置为空格
				vector<moster*>::iterator it = vism.front().vmp.begin() + 1;
				for (; it != vism.front().vmp.end(); it++) {
					if (vism.front().vmp.front()->getcp() == (*it)->getcp()) {
						break;
					}
				}
				if (it == vism.front().vmp.end()) {
					*vism.front().vmp.front()->getcp() = ' ';
				}
				vism.front().vmp.erase(vism.front().vmp.begin());//删除怪物
			}
		}
		//怪物动
		if (b && '*' == strmap[9][10]) {
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MDoAndHunt);
			for_each(vism.front().vmp.begin(), vism.front().vmp.end(), MShow);
		}
		p.shootmove(&strmap, 0);
		' ' == *cp || cout << (p.sgetxyhs(HEAL)--, "\a"), ' ' == *cp && (*cp = 'P');
		system("cls");//清屏
		//如果vism的第0项vmp为空，那么开门，并头删
		if (vism.front().vmp.empty() && '*' == strmap[9][10]) {
			strmap[9][10] = ' ';
			vism.erase(vism.begin());
		}
		//如果进门，那么重置地图('*'  -->  ' ')，并把b设为假
		if ('P' == strmap[9][10]) {
			for (b = 0, ch = 1; ch < 10; ch++) {
				for (i = 1; i < 10; i++) {
					strmap[ch][i] = ' ';
				}
			}
			//下一地牢初始化
			strmap[9][10] = '*';
			strmap[9][0] = 'P';
			//并把cp设为&strmap[9][0]
			cp = &strmap[9][0];
		}
	}
	bb && (str[7] = 'C'), bb || (str[7] = 'A');
	system(str);
	cout << (bb ? "很遗憾，你输了" : "恭喜你，你赢了") << endl;
	for_each(mpv.begin(), mpv.end(), del);
	return 0;
}
*///“已无明显BUG”^
