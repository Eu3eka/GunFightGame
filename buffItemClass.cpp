#include "buffItemClass.h"

buffItem::buffItem(double x, double y, buffItemCategory bufIt) :gameObject(x, y) {
	this->bufIt = bufIt;
}

//int buffItem::buffItem(gameObject* g) {
//	
//}