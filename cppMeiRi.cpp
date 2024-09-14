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
