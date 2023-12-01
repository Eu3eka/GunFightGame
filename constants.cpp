#include "constants.h"

//系统
const double x_air_accl = 1;//水平方向空中固定减速度
const double x_gournd_accl = 1.5;//水平方向地面加速度
const double y_accl = 3;//竖直方向固定减速度
const int WIDTH = 1068;
const int HEIGHT = 600;
IMAGE bg;



//玩家
double player_key_accl = 2;//玩家输入提供的速度
double player_max_speed = 10;//玩家最大速度
const double player_default_vx = 0;//玩家默认水平速度
const double player_default_vy = 0;//玩家默认竖直速度
const int player_default_health = 20;
const int player_default_jumpTimes = 2;
const double player_default_max_jumpSpeed = -30;

//敌人
double enemy_key_accl = 2;
double enemy_max_speed = 6;//敌人最大速度
const double enemy_default_vx = 0;    // 敌人默认水平速度
const double enemy_default_vy = 0;    // 敌人默认竖直速度
const int enemy_default_health = 20;    // 敌人默认生命值
const int enemy_default_jumpTimes = 2;    // 敌人默认跳跃次数
const double enemy_default_max_jumpSpeed = -30;
const double alertHeight = 50.0;//敌人警戒高度差
const double alertWidth = 30.0; //敌人警戒宽度差
const int shootPause = 100;//停顿帧数


//各类子弹速度
const double pistolBullet_vx = 7;
const double rifleBullet_vx = 10;
const double shotgunBullet_vx = 15;
const double sniperBullet_vx = 5;
//子弹最远射程
const double pistolBullet_maxDis = 200;
const double rifleBullet_maxDis = 500;
const double shotgunBullet_maxDis = 100;
const double sniperBullet_maxDis = WIDTH;
//子弹击退加速度
const double pistolBullet_repelAccl = 5;
const double rifleBullet_repelAccl = 7.5;
const double shotgunBullet_repelAccl = 20;
const double sniperBullet_repelAccl = 15;
//子弹伤害
const int pistolBullet_damage = 1;
const int rifleBullet_damage = 1;
const int shotgunBullet_damage = 5;
const int sniperBullet_damage = 3;

//枪械射击间隔帧数
const int pistol_shootInterval = 50;
const int rifle_shootInterval = 60;
const int shotgun_shootInterval = 65;
const int sniper_shootInterval = 100;
//枪械换弹帧数
const int pistol_refillInterval = 200;
const int rifle_refillInterval = 100;
const int shotgun_refillInterval = 90;
const int sniper_refillInterval = 120;

//物品
extern const int shieldTime = 200;
extern const int strengthTime = 400;
extern const int speedTime = 500;