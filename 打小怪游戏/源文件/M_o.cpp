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
	tempcp = (near(), *m_cpp);//��ʱһ��ָ�룬�޿��ö���ָ��
	m_cpp = NULL;//��ָ�����ʽ�ƶ�
	'*' != tempcp[arr[ir = rand() % 8]] && (tempcp -= arr[ir]);//����bug�㣺һ��ָ��ᡰ����������ָ��
	m_cpp = &tempcp;//�ƶ�
}//����ƶ�����ǽ����
char M_o::getm() {
	return 'o';
}