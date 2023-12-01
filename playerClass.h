//���������
#pragma once

#include "gameObject.h"
#include "bulletClass.h"
#include "utils.h"
#include "buffItemClass.h"



class player : public gameObject{
public:
	player(double xx, double yy);

	bullet shoot(bulletCategory catg);

	void move(std::vector<ground>& g, int moveDir);

	void jump();

	void update(std::list<bullet>& b);

	

	int health;
	int dir;//����ķ���,-1����1����
	int score;
	int shield;//�Ƿ��л���
	int animId;  // ����ѭ���������ŵ�id
	int damageEnhance;
	double repelAcclEnhance;
	int shootInterval;
	int tmpInterval;
	int strengthInterval;
	int speedInterval;
	int shieldInterval;
	int jumpTimes;//���ǰ������Ծ���Σ�Ĭ��Ϊ2
	gun gun;//�������ǹе
	playerStatus playerStatus; // ��ǰ��״̬


	//im_thisΪ��ǰ��ʾͼ��
	IMAGE im_standRight; // ����վ��ͼ��
	IMAGE im_standLeft; // ����վ��ͼ��
	IMAGE im_jumpRight; // ���ҷ�����Ծͼ��
	IMAGE im_jumpLeft; // ��������Ծͼ��
	IMAGE im_shootLeft; //�������ͼ��
	IMAGE im_shootRight; //�������ͼ��
	std::vector <IMAGE> imv_runRight; // ���ұ��ܵ�ͼ������
	std::vector <IMAGE> imv_runLeft; // �����ܵ�ͼ������
	
};

