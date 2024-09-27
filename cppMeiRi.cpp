#include <iostream>// <-- 必备
#include <string>
#include <cstring>
#include <Windows.h>
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
