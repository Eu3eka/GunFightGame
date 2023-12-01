#include "enemyClass.h"

enemy::enemy(double xx, double yy, int category, double vx, double vy,
             int health, int dir, int score, int shield,
             int animId, int damageEnhance, double repelAcclEnhance, eStatus enemyStatus,
             int strengthInterval, int speedInterval, int shieldInterval, int shootTimes,
             int ammunition, gunCategory gcat, bulletCategory bcat) : gameObject(xx, yy){

    this->category = category;
    this->vx = enemy_default_vx;
    this->vy = enemy_default_vy;
    this->health = health;
    this->dir = dir;
    this->shield = shield;
    this->animId = 0;
    this->damageEnhance = damageEnhance;
    this->repelAcclEnhance = repelAcclEnhance;
    this->enemyStatus = enemyStatus;

    this->gun.ammunition = ammunition;
    this->gun.refillInterval = 0;
    this->gun.gcat = gcat;
    this->gun.bcat = bcat;

    // if(gcat == pistol) {
    //     loadimage(&this->gun.im_gun, _T(IM_PISTOL));
    //     this->shootInterval = pistol_shootInterval;
    // };
    // if(gcat == rifle) {
    //     loadimage(&this->gun.im_gun, _T(IM_RIFLE));
    //     this->shootInterval = rifle_shootInterval;
    // };
    // if(gcat == shotgun) {
    //     loadimage(&this->gun.im_gun, _T(IM_SHOTGUN));
    //     this->shootInterval = shotgun_shootInterval;
    // };
    // if(gcat == sniper) {
    //     loadimage(&this->gun.im_gun, _T(IM_SNIPER));
    //     this->shootInterval = sniper_shootInterval;
    // };
    // this->tmpInterval = shootInterval;

    loadimage(&im_standLeft,_T(IM_ENEMY_STANDLEFT(category)));
    loadimage(&im_standRight, _T(IM_ENEMY_STANDRIGHT(category)));
    loadimage(&im_jumpRight, _T(IM_ENEMY_JUMPRIGHT(category)));
    loadimage(&im_jumpLeft, _T(IM_ENEMY_JUMPLEFT(category))); 
    loadimage(&im_shootRight, _T(IM_ENEMY_SHOOTRIGHT(category)));
    loadimage(&im_shootLeft, _T(IM_ENEMY_SHOOTLEFT(category)));

    for (int i = 0; i < 6; i++) {
        IMAGE img;
        TCHAR imgName[50];
        _stprintf(imgName, _T(IM_ENEMY_RUNLEFT(i)), i);
        loadimage(&img, imgName);
        imv_runLeft.push_back(img);
    }
    for (int i = 0; i < 6; i++) {
        IMAGE img;
        TCHAR imgName[50];
        _stprintf(imgName, _T(IM_ENEMY_RUNRIGHT(i)), i);
        loadimage(&img, imgName);
        imv_runRight.push_back(img);
    }
    im_this = im_standRight;
}

bullet enemy::shoot(bulletCategory bulId) {
    // if(tmpInterval > 0) return;
    if (dir == -1) {
        enemyStatus = enemyShootLeft;
        im_this = im_shootLeft;
    }
    else if (dir == 1) {
        enemyStatus = enemyShootRight;
        im_this = im_shootRight;
    }
    bullet* b = new bullet((dir == -1?this->left:this->right) + dir * 10, this->y + 5,
        this->dir, bulId, 1, damageEnhance, repelAcclEnhance);
    return *b;
}

void enemy::move(std::vector<ground>& g, const player& p) {
    // bool onLand = false;
    if(isOnSomeGround(g, this)){
        // onLand = true;
        if(category == 1){
            //进行走动
            if(dir == 1){
                gameObject *go = new gameObject(this->x + this->width/2, this->y);
                if(!isOnSomeGround(g, go)) {
                    dir = -1;
                    animId = 0;
                    enemyStatus = enemyRunLeft;
                } else{
                    animId++;
                    if(animId > imv_runLeft.size()) animId = 0;
                }
                delete go;
            } else if(dir == -1){
                gameObject *go = new gameObject(this->x - this->width/2, this->y);
                if(!isOnSomeGround(g,go)) {
                    dir = 1;
                    animId = 0;
                    enemyStatus = enemyRunRight;
                } else{
                    animId++;
                    if(animId > imv_runRight.size()) animId = 0;
                }
                delete go;
            }
            //进行射击
            if (abs(this->y - p.y) < this->height / 2){
                if(p.x < this->x){
                    dir = -1;
                    enemyStatus = enemyShootLeft;
                    im_this = im_shootLeft;
                } else {
                    dir = 1;
                    enemyStatus = enemyShootRight;
                    im_this = im_shootRight;
                }
                this->shoot(gun.bcat);
            } else {
                x += vx;//由于移动时不允许射击，将移动放到是否射击之后来判断
                vx = dir * (abs(vx) > enemy_max_speed ? enemy_max_speed : abs(vx) + enemy_key_accl);
                im_this = dir == -1 ? imv_runLeft[animId] : imv_runRight[animId];
            }
        } else if(category == 2){

        } else if(category == 3){

        } else if(category == 4){

        }
    } else {
      this->enemyStatus = (dir == 1?enemyJumpRight:enemyJumpLeft);
      im_this = dir == 1 ? im_jumpLeft : im_jumpRight;
    }
}

void enemy::update(){
    //要进行：碰撞箱修改、外界对该对象的作用
    //包括:(玩家独有：与道具碰撞)、被子弹打中
    this->updateBox();
}