//����ļ�������Ϸ����Ļ���
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
	double y;//x yͳһ����Ϊ���󼸺�����λ��
	double left;
	double right;
	double top;
	double bottom;//�������ײ��
	double width;
	double height;//������ͼ�Ŀ��
	double vx;
	double vy;
	IMAGE im_this;
};