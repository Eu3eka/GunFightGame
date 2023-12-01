//物品
//额外属性：种类。
//额外方法：构造；目标对象是否碰撞；
#pragma once

#include "gameObject.h"
#include "constants.h"

class buffItem : public gameObject {
public:
	buffItem(double x, double y, buffItemCategory bufIt);

	//int collide(gameObject* g);
	
	//属性
	buffItemCategory bufIt;
	
};