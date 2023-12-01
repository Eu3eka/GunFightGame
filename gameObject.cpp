#include "gameObject.h"

gameObject::gameObject(double x, double y) {
	this->x = x;
	this->y = y;
	left = x - width / 2;
	right = x + width / 2;
	top = y - height / 2;
	bottom = y + height / 2;
}

void gameObject::draw() {
	putimagePng(left, top, &im_this);
}

void gameObject::updateBox() {
	this->width = im_this.getwidth();
    this->height = im_this.getheight();
    left = x - width / 2;
	right = x + width / 2;
	top = y - height / 2;
	bottom = y + height / 2;
}

int gameObject::collide(const gameObject* other) {
    double distanceX = std::abs(x - other->x);
    double distanceY = std::abs(y - other->y);

    double sumHalfWidth = (width + other->width) / 2.0;
    double sumHalfHeight = (height + other->height) / 2.0;

    bool collisionX = distanceX < sumHalfWidth;
    bool collisionY = distanceY < sumHalfHeight;

    if (collisionX && collisionY) {
        double offsetX = sumHalfWidth - distanceX;
        double offsetY = sumHalfHeight - distanceY;
        //碰撞都以当前这个对象为中心
        if (offsetX < offsetY) {
            //1从左边撞，3从右边
            return x < other->x ? 1 : 3;
        }
        else {
            //2从上面撞，4从下面撞
            return y < other->y ? 2 : 4;
        }
    }
    return 0;
}

void gameObject::update() {
    updateBox();
}