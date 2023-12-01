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


    //敌人的射击间隔通过isShooting控制

    int category;//若干种敌人
    int health;
    int dir;    // 面向的方向，-1 向左，1 向右
    int score;
    int shield; // 是否有护盾
    int animId; // 用于循环动画播放的 id
    int damageEnhance;
    double repelAcclEnhance;
    int jumpTimes; // 落地前可以跳跃几次，默认为 2
    int shootTimes;//连续射击次数
    int strengthInterval;
	int speedInterval;
	int shieldInterval;
    gun gun;      // 敌人所持枪械
    eStatus enemyStatus; // 当前的状态

    // 图片
    IMAGE im_standRight; // 向右站立图像
    IMAGE im_standLeft;  // 向左站立图像
    IMAGE im_jumpRight;  // 向右方向跳跃图像
    IMAGE im_jumpLeft;   // 向左方向跳跃图像
    IMAGE im_shootRight; // 向右射击图像
    IMAGE im_shootLeft;  // 向左射击图像
    std::vector<IMAGE> imv_runRight; // 向右奔跑的图像序列
    std::vector<IMAGE> imv_runLeft;  // 向左奔跑的图像序列
};

