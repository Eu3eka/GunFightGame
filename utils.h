//����ļ�����һЩ���ߺ���
#pragma once

#include <random>
#include <vector>
#include "groundClass.h"

//����[x,y)֮������������
int randInt(int x, int y);

//����[x,y)֮��ĸ��������
float randN(float x, float y);

//�ж�һ�������Ƿ���ָ���ĵ�����
int isOnGround(ground& gr, gameObject* go);

//�ж�һ�������Ƿ��ڵ�����
int isOnSomeGround(std::vector<ground>& g, gameObject* go);

double minf(double a, double b);

double maxf(double a, double b);

bool equals(double a, double b=0);