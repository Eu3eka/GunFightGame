//这个文件定义游戏对象的基类
#pragma once

#include <iostream>
#include <conio.h>
#include <graphics.h>
#include "EasyXPng.h"
#include "utils.h"
#include <list>
#include <vector>


class gameObject {
public:
	gameObject(double x, double y);

	virtual void draw();

	virtual int collide(const gameObject* other);

	virtual void updateBox();

	virtual void update();

	double x;
	double y;//x y统一定义为对象几何中心位置
	double left;
	double right;
	double top;
	double bottom;//对象的碰撞箱
	double width;
	double height;//对象贴图的宽高
	double vx;
	double vy;
	IMAGE im_this;
};