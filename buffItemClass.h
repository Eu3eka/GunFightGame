//��Ʒ
//�������ԣ����ࡣ
//���ⷽ�������죻Ŀ������Ƿ���ײ��
#pragma once

#include "gameObject.h"
#include "constants.h"

class buffItem : public gameObject {
public:
	buffItem(double x, double y, buffItemCategory bufIt);

	//int collide(gameObject* g);
	
	//����
	buffItemCategory bufIt;
	
};