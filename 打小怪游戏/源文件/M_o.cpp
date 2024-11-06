#include <iostream>
#include <ctime>
#include "M_o.h"
using namespace std;
void M_o::near() {
	int arr[8] = { -12, -11, -10, -1, 1, 10, 11, 12 };
	int i = 0;
	for (; i < 8; i++) {
		if ('*' == (*m_cpp)[arr[i]]) {
			m_iheal = -1;
			break;
		}
	}
}
void M_o::mosterdo() {
	int arr[8] = { -12, -11, -10, -1, 1, 10, 11, 12 };
	int ir = 0;
	'*' != **m_cpp && (**m_cpp = ' ');
	tempcp = (near(), *m_cpp);//临时一级指针，无可用二级指针
	m_cpp = NULL;//防指针的链式移动
	'*' != tempcp[arr[ir = rand() % 8]] && (tempcp -= arr[ir]);//曾有bug点：一级指针会“带动”二级指针
	m_cpp = &tempcp;//移动
}//随便移动，有墙不动
char M_o::getm() {
	return 'o';
}