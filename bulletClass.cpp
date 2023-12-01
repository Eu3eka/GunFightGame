#include "bulletClass.h"

bullet::bullet(double x, double y, int dir, bulletCategory bulCat, int shooter,
	/*是否有对子弹的强化*/int damageEnhance, double repelAcclEnhance, int collided) : gameObject(x, y) {
	this->bulCat = bulCat;
	this->shooter = shooter;
	this->dir = dir;
	switch (bulCat) {
	case pistolBullet:
		speed = pistolBullet_vx;
		maxDis = pistolBullet_maxDis;
		damage = pistolBullet_damage;
		repelAccl = pistolBullet_repelAccl;
		loadimage(&im_this, _T(IM_BULLET_PISTOL));
		break;
	case rifleBullet:
		speed = rifleBullet_vx;
		maxDis = rifleBullet_maxDis;
		damage = rifleBullet_damage;
		repelAccl = rifleBullet_repelAccl;
		loadimage(&im_this, _T(IM_BULLET_RIFLE));
		break;
	case shotgunBullet:
		speed = shotgunBullet_vx;
		maxDis = shotgunBullet_maxDis;
		damage = shotgunBullet_damage;
		repelAccl = shotgunBullet_repelAccl;
		loadimage(&im_this, _T(IM_BULLET_SHOTGUN));
		break;
	case sniperBullet:
		speed = sniperBullet_vx;
		maxDis = sniperBullet_maxDis;
		damage = sniperBullet_damage;
		repelAccl = sniperBullet_repelAccl;
		loadimage(&im_this, _T(IM_BULLET_SNIPER));
		break;
	};
	speed *= dir;
	damage += damageEnhance;
	repelAccl += repelAcclEnhance;
}

void bullet::update() {
	x += speed;
	this->updateBox();
}

