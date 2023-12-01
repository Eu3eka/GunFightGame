#include "playerClass.h"



player::player(double xx, double yy) : gameObject(xx, yy) {
	this->vx = player_default_vx;
	this->vy = player_default_vy;
	this->health = player_default_health;
	this->dir = 1;
	this->score = 0;
	this->shield = 0;
	this->animId = 0;
	this->shootInterval = pistol_shootInterval;
	this->tmpInterval = shootInterval;
	this->strengthInterval = 0;
	this->speedInterval = 0;
	this->shieldInterval = 0;
	this->damageEnhance = 0;
	this->repelAcclEnhance = 0;
	this->playerStatus = standRight;

	this->gun.ammunition = 10;
	this->gun.refillInterval = 0;
	this->gun.gcat = pistol;
	this->gun.bcat = pistolBullet;

	loadimage(&this->gun.im_gun, _T(IM_PISTOL));
	loadimage(&im_standLeft, _T(IM_PLAYER_STANDLEFT));
	loadimage(&im_standRight, _T(IM_PLAYER_STANDRIGHT));
	loadimage(&im_jumpRight, _T(IM_PLAYER_JUMPRIGHT));
	loadimage(&im_jumpLeft, _T(IM_PLAYER_JUMPLEFT));
	loadimage(&im_shootRight, _T(IM_PLAYER_SHOOTRIGHT));
	loadimage(&im_shootLeft, _T(IM_PLAYER_SHOOTLEFT));
	for (int i = 0; i < 6; i++) {
		IMAGE img;
		TCHAR imgName[50];
		_stprintf(imgName, _T(IM_PLAYER_RUNLEFT), i);
		loadimage(&img, imgName);
		imv_runLeft.push_back(img);
	}
	for (int i = 0; i < 6; i++) {
		IMAGE img;
		TCHAR imgName[50];
		_stprintf(imgName, _T(IM_PLAYER_RUNRIGHT), i);
		loadimage(&img, imgName);
		imv_runRight.push_back(img);
	}
	
	im_this = im_standRight;
}


bullet player::shoot(bulletCategory	bulId) {
	//射击间隔结束才能射击
	if(tmpInterval > 0) return;
	//不允许玩家在运动时射击
	if (dir == -1) {
		playerStatus == shootLeft;
		im_this = im_shootLeft;
	}
	else if (dir == 1) {
		playerStatus = shootRight;
		im_this = im_shootRight;
	}
	bullet* b = new bullet(this->left + dir * 10, this->y + 5, 
		this->dir, bulId, 0, damageEnhance, repelAcclEnhance);
	return *b;
}

void player::move(std::vector<ground>& g, int moveDir) {
	//可以传VK_LEFT等方向宏定义。控制玩家的移动，包括加减速、手动移动、跳跃。
	//玩家按键只为角色增加加速度，不直接影响位置。
	//更新水平速度.水平速度为矢量，向左为负向右为正，更新玩家位置时x始终加上vx.
	//玩家向左走时使vx减，向右时加。
	//玩家速度为正,面向右边，为负,面向左边,为0默认面向右边
	//更新水平速度
	//玩家键盘提供加速度{
	if (moveDir == -1) {
		if (dir == -1) {
			vx -= player_key_accl;
		}
		else if (dir == 1) {
			if (vx - player_key_accl < 0) dir = -1;
			vx = vx - player_key_accl;
		}
	}
	if (moveDir == 1) {
		if (dir == -1) {
			if (vx + player_key_accl >= 0) dir = 1;
			vx = vx + player_key_accl;
		}
		else if (dir == 1) vx += player_key_accl;
	}
	double tmp_vx = vx;
	//固定减速度
	if (isOnSomeGround(g, this)) {
		if (vx < 0) vx = minf(0.0, (vx + x_ground_accl));  // 使用min确保不会超过0
		else if (vx > 0) vx = maxf(0.0, (vx - x_ground_accl));
	}
	else {
		if (vx < 0) vx = minf(0.0, (vx + x_air_accl));  // 使用min确保不会超过0
		else if (vx > 0) vx = maxf(0.0, (vx - x_air_accl));
	}
	
	vx = dir * maxf(abs(vx), player_max_speed);

	if (fabs(vx - 0) <= 1e-6) {
		if (tmp_vx < 0) {
			dir = -1;
			playerStatus = standLeft;
		}
		else {
			dir = 1;
			playerStatus = standRight;
		}
	}

	//更新竖直速度和位置,正方向为向上;只在跳跃过程中需要更新
	if (playerStatus == jumpLeft || playerStatus == jumpRight) {
		vy += y_accl;
		for (int i = 0; i < g.size(); i++) {
			if (isOnGround(g[i], this)) {
				vy = 0;
				jumpTimes = player_default_jumpTimes;
				bottom = g[i].top;
				// 向左跳，落地后切换到向左站立方向
				if (playerStatus == jumpLeft) playerStatus = standLeft;
				// 向右跳，落地后切换到向右站立方向
				if (playerStatus == jumpRight) playerStatus = standRight;
				break;
			}
		}
		y = bottom - this->height / 2;
	}
	else y += vy;
	x += vx;

	//更新图片
	if (dir == 1 && vx > 0) {
		//移动后掉下去了
		if (!isOnSomeGround(g, this)) {
			im_this = im_jumpRight;
			playerStatus = jumpRight;
		}
		//没掉下去的右移
		else {
			if (playerStatus != runRight && (playerStatus)) {
				playerStatus = runRight;
				animId = 0;
			}
			else {
				animId++;
				if (animId >= this->imv_runRight.size()) animId = 0;
			}
		}
		im_this = imv_runRight[animId];
	}
	else if (dir == -1 && vx < 0) {
		if (!isOnSomeGround(g, this)) {
			im_this = im_jumpLeft;
			playerStatus = jumpLeft;
		}
		else {
			if (playerStatus != runLeft) {
				playerStatus = runLeft;
				animId = 0;
			}
			else {
				animId++;
				if (animId >= this->imv_runLeft.size()) animId = 0;
			}
		}
		im_this = imv_runLeft[animId];
	}
	
}


void player::jump() {
	if (playerStatus != jumpLeft && playerStatus != jumpRight) {
		if (playerStatus == runLeft || playerStatus == standLeft) {
			playerStatus = jumpLeft;
			im_this = im_jumpLeft;
		}
		else if (playerStatus == runRight || playerStatus == standRight) {
			playerStatus = jumpRight;
			im_this = im_jumpRight;
		}
	}
	vy = player_default_max_jumpSpeed;
}

void player::update(std::list<bullet>& bullet, std::list<buffItem>& buff){
	//更新玩家状态
	//被子弹打中
	for(auto& p:bullet){
		if(p.collide(this)){
			if(this->shield == 1){
				this->vx += dir * p.repelAccl;
			}
			p.collided = 1;
		}
	}
	//碰到道具
	for(auto& p:buff){
		if(p.collide(this)){
			switch(p.bufIt){
			case healing:
				this->health++;
				break;
			case strength:
				this->repelAcclEnhance = this->gun.
			}
		}
	}
	//更新道具状态

	this->updateBox();
	if(tmpInterval >= 0) tmpInterval--;
}