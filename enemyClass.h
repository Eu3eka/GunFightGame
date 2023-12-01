#pragma once

#include "gameObject.h"
#include "bulletClass.h"
#include "utils.h"
#include "playerClass.h"
#include <vector>

class enemy : public gameObject {
public:
    enemy(double xx, double yy, int category, double vx = enemy_default_vx, double vy = enemy_default_vy,
          int health = enemy_default_health, int dir = -1, int score = 0, int shield = 0, int animId = 0,
          int damageEnhance = 0, double repelAcclEnhance = 0, eStatus enemyStatus = enemyStandRight,
          int strengthInterval = 0, int speedInterval = 0, int shieldInterval = 0, int shootTimes = 3,
          int ammunition = 10, gunCategory gcat = pistol, bulletCategory bcat = pistolBullet);

    bullet shoot(bulletCategory catg);

    void move(std::vector<ground>& g, const player& p);

    void update();


    //���˵�������ͨ��isShooting����

    int category;//�����ֵ���
    int health;
    int dir;    // ����ķ���-1 ����1 ����
    int score;
    int shield; // �Ƿ��л���
    int animId; // ����ѭ���������ŵ� id
    int damageEnhance;
    double repelAcclEnhance;
    int jumpTimes; // ���ǰ������Ծ���Σ�Ĭ��Ϊ 2
    int shootTimes;//�����������
    int strengthInterval;
	int speedInterval;
	int shieldInterval;
    gun gun;      // ��������ǹе
    eStatus enemyStatus; // ��ǰ��״̬

    // ͼƬ
    IMAGE im_standRight; // ����վ��ͼ��
    IMAGE im_standLeft;  // ����վ��ͼ��
    IMAGE im_jumpRight;  // ���ҷ�����Ծͼ��
    IMAGE im_jumpLeft;   // ��������Ծͼ��
    IMAGE im_shootRight; // �������ͼ��
    IMAGE im_shootLeft;  // �������ͼ��
    std::vector<IMAGE> imv_runRight; // ���ұ��ܵ�ͼ������
    std::vector<IMAGE> imv_runLeft;  // �����ܵ�ͼ������
};

