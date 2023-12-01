//定义玩家类
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
	int dir;//面向的方向,-1向左，1向右
	int score;
	int shield;//是否有护盾
	int animId;  // 用于循环动画播放的id
	int damageEnhance;
	double repelAcclEnhance;
	int shootInterval;
	int tmpInterval;
	int strengthInterval;
	int speedInterval;
	int shieldInterval;
	int jumpTimes;//落地前可以跳跃几次，默认为2
	gun gun;//玩家所持枪械
	playerStatus playerStatus; // 当前的状态


	//im_this为当前显示图像
	IMAGE im_standRight; // 向右站立图像
	IMAGE im_standLeft; // 向左站立图像
	IMAGE im_jumpRight; // 向右方向跳跃图像
	IMAGE im_jumpLeft; // 向左方向跳跃图像
	IMAGE im_shootLeft; //向左射击图像
	IMAGE im_shootRight; //向右射击图像
	std::vector <IMAGE> imv_runRight; // 向右奔跑的图像序列
	std::vector <IMAGE> imv_runLeft; // 向左奔跑的图像序列
	
};

