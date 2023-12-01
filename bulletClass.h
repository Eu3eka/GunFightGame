//子弹类
#pragma once

#include "gameObject.h"
#include "constants.h"

class bullet : public gameObject {
public:
	bullet(double x, double y, int dir, bulletCategory bulId,
		int shooter, int damageEnhance=0, double repelAcclEnhanc=0.0, int collided=0);
	
	void update();

	int dir;//子弹飞行方向，涉及不同贴图,-1往左1往右
	bulletCategory bulCat;
	double speed;//子弹飞行速度
	double maxDis;//子弹最大飞行距离
	int damage;//伤害
	double repelAccl;//子弹可产生的击退加速度
	int shooter;//0表示玩家，1表示敌人
	int collided;//是否命中,命中了就把他从列表中删除
};