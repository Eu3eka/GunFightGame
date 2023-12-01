//�ӵ���
#pragma once

#include "gameObject.h"
#include "constants.h"

class bullet : public gameObject {
public:
	bullet(double x, double y, int dir, bulletCategory bulId,
		int shooter, int damageEnhance=0, double repelAcclEnhanc=0.0, int collided=0);
	
	void update();

	int dir;//�ӵ����з����漰��ͬ��ͼ,-1����1����
	bulletCategory bulCat;
	double speed;//�ӵ������ٶ�
	double maxDis;//�ӵ������о���
	int damage;//�˺�
	double repelAccl;//�ӵ��ɲ����Ļ��˼��ٶ�
	int shooter;//0��ʾ��ң�1��ʾ����
	int collided;//�Ƿ�����,�����˾Ͱ������б���ɾ��
};