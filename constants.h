#pragma once

#include <graphics.h>

//常量定义
//系统

#define IM_BG1 "background1.png"
extern const double x_air_accl;//空气中固定减速度
extern const double x_ground_accl;//地面上的
extern const double y_accl;//竖直方向固定减速度
extern const int WIDTH;
extern const int HEIGHT;
extern IMAGE bg;


//玩家
#define IM_PLAYER_STANDRIGHT "player_standRight.png"
#define IM_PLAYER_STANDLEFT "player_standLeft.png"
#define IM_PLAYER_JUMPRIGHT "player_jumpRight.png"
#define IM_PLAYER_JUMPLEFT "player_jumpLeft.png"
#define IM_PLAYER_SHOOTLEFT "player_shootLeft.png"
#define IM_PLAYER_SHOOTRIGHT "player_shootRight.png"
#define IM_PLAYER_RUNLEFT "player_runLeft%d.png"
#define IM_PLAYER_RUNRIGHT "player_runRight%d.png"

enum playerStatus {
	standRight, standLeft, runLeft, runRight, jumpLeft, jumpRight,
	shootLeft, shootRight,
};


extern double player_key_accl;//玩家输入提供的加速度
extern double player_max_speed;//玩家最大速度
extern const double player_default_vx;//玩家默认水平速度
extern const double player_default_vy;//玩家默认竖直速度
extern const int player_default_health;
extern const int player_default_jumpTimes;
extern const double player_default_max_jumpSpeed;


//敌人
#define IM_ENEMY_STANDRIGHT(x) "enemy_standRight" #x ".png"
#define IM_ENEMY_STANDLEFT(x) "enemy_standLeft" #x ".png"
#define IM_ENEMY_JUMPRIGHT(x) "enemy_jumpRight" #x ".png"
#define IM_ENEMY_JUMPLEFT(x) "enemy_jumpLeft" #x ".png"
#define IM_ENEMY_SHOOTLEFT(x) "enemy_shootLeft" #x ".png"
#define IM_ENEMY_SHOOTRIGHT(x) "enemy_shootRight" #x ".png"
#define IM_ENEMY_RUNLEFT(x) "enemy_runLeft" #x "%d.png"
#define IM_ENEMY_RUNRIGHT(x) "enemy_runRight" #x "%d.png"



extern double enemy_key_accl;
extern double enemy_max_speed;//敌人最大速度
extern const double enemy_default_vx;    // 敌人默认水平速度
extern const double enemy_default_vy;    // 敌人默认竖直速度
extern const int enemy_default_health;    // 敌人默认生命值
extern const int enemy_default_jumpTimes;    // 敌人默认跳跃次数
extern const double enemy_default_max_jumpSpeed;    // 敌人默认最大跳跃速度
extern const double alertHeight; //敌人警戒高度差
extern const double alertWidth; //敌人警戒宽度差
extern const int shootPause;//敌人停顿时间

enum eStatus {
	enemyStandRight, enemyStandLeft, enemyRunLeft, enemyRunRight, enemyJumpLeft, enemyJumpRight,
	enemyShootLeft, enemyShootRight,
};

//子弹
#define IM_BULLET_PISTOL "bullet_pistol.png"
#define IM_BULLET_RIFLE "bullet_rifle.png"
#define IM_BULLET_SHOTGUN "bullet_shotgun.png"
#define IM_BULLET_SNIPER "bullet_sniper.png"

enum bulletCategory {
	pistolBullet, rifleBullet, shotgunBullet, sniperBullet
};

//各类子弹速度
extern const double pistolBullet_vx;
extern const double rifleBullet_vx;
extern const double shotgunBullet_vx;
extern const double sniperBullet_vx;
//子弹最远射程
extern const double pistolBullet_maxDis;
extern const double rifleBullet_maxDis;
extern const double shotgunBullet_maxDis;
extern const double sniperBullet_maxDis;
//子弹击退时施加给目标的加速度
extern const double pistolBullet_repelAccl;
extern const double rifleBullet_repelAccl;
extern const double shotgunBullet_repelAccl;
extern const double sniperBullet_repelAccl;
//子弹伤害
extern const int pistolBullet_damage;
extern const int rifleBullet_damage;
extern const int shotgunBullet_damage;
extern const int sniperBullet_damage;


//枪械
#define IM_PISTOL "gun_pistol.png"
#define IM_RIFLE "gun_rifle.png"
#define IM_SHOTGUN "gun_shotgun.png"
#define IM_SNIPER "gun_sniper.png"



//射击间隔
extern const int pistol_shootInterval;
extern const int rifle_shootInterval;
extern const int shotgun_shootInterval;
extern const int sniper_shootInterval;
//枪械换弹用时
extern const int pistol_refillInterval;
extern const int rifle_refillInterval;
extern const int shotgun_refillInterval;
extern const int sniper_refillInterval;

enum gunCategory {
	pistol, rifle, shotgun, sniper
};

typedef struct gun {
	IMAGE im_gun;
	int ammunition;
	int refillInterval;
	int shootInterval;
	gunCategory gcat;
	bulletCategory bcat;
}gun;




//物品
//加速buff通过修改玩家的键盘输入加速度和最大速度实现。
#define IM_BUFFITEM_HEALING "buffitem_healing.png"
#define IM_BUFFITEM_STRENGTH "buffitem_strength.png"
#define IM_BUFFITEM_SHIELD "buffitem_shield.png"
#define IM_BUFFITEM_SPEED "buffitem_speed.png"
#define IM_BUFFITEM_NEWGUN "buffitem_newGun.png"

extern const int shieldTime;
extern const int strengthTime;
extern const int speedTime;

enum buffItemCategory {
	healing, strength, shield, speed, newGun,
};

