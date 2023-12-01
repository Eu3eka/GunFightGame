#pragma once

#include "gameObject.h"


class ground: public gameObject {
public:
	ground(double x, double y);

	int category;
	//可以有不同的地面？加速、减速的地面
};