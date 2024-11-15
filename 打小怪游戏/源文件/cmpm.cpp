#include <iostream>
#include "cmpM.h"
#include "moster.h"
using namespace std;
bool cmpm::operator()(moster* mp, moster* mpa) {
	return mp->getheal() < mpa->getheal();//比较两个怪物的生命值
}
