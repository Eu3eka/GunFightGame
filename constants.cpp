#include "constants.h"

//ϵͳ
const double x_air_accl = 1;//ˮƽ������й̶����ٶ�
const double x_gournd_accl = 1.5;//ˮƽ���������ٶ�
const double y_accl = 3;//��ֱ����̶����ٶ�
const int WIDTH = 1068;
const int HEIGHT = 600;
IMAGE bg;



//���
double player_key_accl = 2;//��������ṩ���ٶ�
double player_max_speed = 10;//�������ٶ�
const double player_default_vx = 0;//���Ĭ��ˮƽ�ٶ�
const double player_default_vy = 0;//���Ĭ����ֱ�ٶ�
const int player_default_health = 20;
const int player_default_jumpTimes = 2;
const double player_default_max_jumpSpeed = -30;

//����
double enemy_key_accl = 2;
double enemy_max_speed = 6;//��������ٶ�
const double enemy_default_vx = 0;    // ����Ĭ��ˮƽ�ٶ�
const double enemy_default_vy = 0;    // ����Ĭ����ֱ�ٶ�
const int enemy_default_health = 20;    // ����Ĭ������ֵ
const int enemy_default_jumpTimes = 2;    // ����Ĭ����Ծ����
const double enemy_default_max_jumpSpeed = -30;
const double alertHeight = 50.0;//���˾���߶Ȳ�
const double alertWidth = 30.0; //���˾����Ȳ�
const int shootPause = 100;//ͣ��֡��


//�����ӵ��ٶ�
const double pistolBullet_vx = 7;
const double rifleBullet_vx = 10;
const double shotgunBullet_vx = 15;
const double sniperBullet_vx = 5;
//�ӵ���Զ���
const double pistolBullet_maxDis = 200;
const double rifleBullet_maxDis = 500;
const double shotgunBullet_maxDis = 100;
const double sniperBullet_maxDis = WIDTH;
//�ӵ����˼��ٶ�
const double pistolBullet_repelAccl = 5;
const double rifleBullet_repelAccl = 7.5;
const double shotgunBullet_repelAccl = 20;
const double sniperBullet_repelAccl = 15;
//�ӵ��˺�
const int pistolBullet_damage = 1;
const int rifleBullet_damage = 1;
const int shotgunBullet_damage = 5;
const int sniperBullet_damage = 3;

//ǹе������֡��
const int pistol_shootInterval = 50;
const int rifle_shootInterval = 60;
const int shotgun_shootInterval = 65;
const int sniper_shootInterval = 100;
//ǹе����֡��
const int pistol_refillInterval = 200;
const int rifle_refillInterval = 100;
const int shotgun_refillInterval = 90;
const int sniper_refillInterval = 120;

//��Ʒ
extern const int shieldTime = 200;
extern const int strengthTime = 400;
extern const int speedTime = 500;