#include <iostream>
#include "cmpM.h"
#include "moster.h"
using namespace std;
bool cmpm::operator()(moster* mp, moster* mpa) {
	return mp->getheal() < mpa->getheal();
}