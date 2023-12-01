#pragma once

#include <graphics.h>

//��������
//ϵͳ

#define IM_BG1 "background1.png"
extern const double x_air_accl;//�����й̶����ٶ�
extern const double x_ground_accl;//�����ϵ�
extern const double y_accl;//��ֱ����̶����ٶ�
extern const int WIDTH;
extern const int HEIGHT;
extern IMAGE bg;


//���
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


extern double player_key_accl;//��������ṩ�ļ��ٶ�
extern double player_max_speed;//�������ٶ�
extern const double player_default_vx;//���Ĭ��ˮƽ�ٶ�
extern const double player_default_vy;//���Ĭ����ֱ�ٶ�
extern const int player_default_health;
extern const int player_default_jumpTimes;
extern const double player_default_max_jumpSpeed;


//����
#define IM_ENEMY_STANDRIGHT(x) "enemy_standRight" #x ".png"
#define IM_ENEMY_STANDLEFT(x) "enemy_standLeft" #x ".png"
#define IM_ENEMY_JUMPRIGHT(x) "enemy_jumpRight" #x ".png"
#define IM_ENEMY_JUMPLEFT(x) "enemy_jumpLeft" #x ".png"
#define IM_ENEMY_SHOOTLEFT(x) "enemy_shootLeft" #x ".png"
#define IM_ENEMY_SHOOTRIGHT(x) "enemy_shootRight" #x ".png"
#define IM_ENEMY_RUNLEFT(x) "enemy_runLeft" #x "%d.png"
#define IM_ENEMY_RUNRIGHT(x) "enemy_runRight" #x "%d.png"



extern double enemy_key_accl;
extern double enemy_max_speed;//��������ٶ�
extern const double enemy_default_vx;    // ����Ĭ��ˮƽ�ٶ�
extern const double enemy_default_vy;    // ����Ĭ����ֱ�ٶ�
extern const int enemy_default_health;    // ����Ĭ������ֵ
extern const int enemy_default_jumpTimes;    // ����Ĭ����Ծ����
extern const double enemy_default_max_jumpSpeed;    // ����Ĭ�������Ծ�ٶ�
extern const double alertHeight; //���˾���߶Ȳ�
extern const double alertWidth; //���˾����Ȳ�
extern const int shootPause;//����ͣ��ʱ��

enum eStatus {
	enemyStandRight, enemyStandLeft, enemyRunLeft, enemyRunRight, enemyJumpLeft, enemyJumpRight,
	enemyShootLeft, enemyShootRight,
};

//�ӵ�
#define IM_BULLET_PISTOL "bullet_pistol.png"
#define IM_BULLET_RIFLE "bullet_rifle.png"
#define IM_BULLET_SHOTGUN "bullet_shotgun.png"
#define IM_BULLET_SNIPER "bullet_sniper.png"

enum bulletCategory {
	pistolBullet, rifleBullet, shotgunBullet, sniperBullet
};

//�����ӵ��ٶ�
extern const double pistolBullet_vx;
extern const double rifleBullet_vx;
extern const double shotgunBullet_vx;
extern const double sniperBullet_vx;
//�ӵ���Զ���
extern const double pistolBullet_maxDis;
extern const double rifleBullet_maxDis;
extern const double shotgunBullet_maxDis;
extern const double sniperBullet_maxDis;
//�ӵ�����ʱʩ�Ӹ�Ŀ��ļ��ٶ�
extern const double pistolBullet_repelAccl;
extern const double rifleBullet_repelAccl;
extern const double shotgunBullet_repelAccl;
extern const double sniperBullet_repelAccl;
//�ӵ��˺�
extern const int pistolBullet_damage;
extern const int rifleBullet_damage;
extern const int shotgunBullet_damage;
extern const int sniperBullet_damage;


//ǹе
#define IM_PISTOL "gun_pistol.png"
#define IM_RIFLE "gun_rifle.png"
#define IM_SHOTGUN "gun_shotgun.png"
#define IM_SNIPER "gun_sniper.png"



//������
extern const int pistol_shootInterval;
extern const int rifle_shootInterval;
extern const int shotgun_shootInterval;
extern const int sniper_shootInterval;
//ǹе������ʱ
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




//��Ʒ
//����buffͨ���޸���ҵļ���������ٶȺ�����ٶ�ʵ�֡�
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

