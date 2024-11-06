#include <iostream>
#include "Cmp.h"
#include "Player.h"
using namespace std;
bool cmp::operator()(trir t, trir ta) {
	return t.iy < ta.iy;
}