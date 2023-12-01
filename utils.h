//这个文件定义一些工具函数
#pragma once

#include <random>
#include <vector>
#include "groundClass.h"

//生成[x,y)之间的整数随机数
int randInt(int x, int y);

//生成[x,y)之间的浮点随机数
float randN(float x, float y);

//判断一个对象是否在指定的地面上
int isOnGround(ground& gr, gameObject* go);

//判断一个对象是否在地面上
int isOnSomeGround(std::vector<ground>& g, gameObject* go);

double minf(double a, double b);

double maxf(double a, double b);

bool equals(double a, double b=0);