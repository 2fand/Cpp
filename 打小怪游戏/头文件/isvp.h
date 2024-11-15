#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "moster.h"
struct isv {//地牢怪物
	string str;//判断怪物的生成
	vector<moster*> vmp;//生成的怪物
	int id;//地牢怪物所代表的id
};
