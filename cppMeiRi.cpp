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