#include <iostream>// <-- 必备
using namespace std;// <-- 必备
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
