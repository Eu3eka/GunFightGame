#include "utils.h"


int randInt(int x, int y) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(x, y);
	return dis(gen);
}

float randN(float x, float y) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(x, y);
	return dis(gen);
}

double minf(double a, double b){
	return a > b?b:a;
}

double maxf(double a, double b){
	return a > b?a:b;
}

int isOnGround(ground& gr, gameObject* go) {
	if (gr.left - go->left <= go->width * 0.6 && go->right - gr.right <= go->width * 0.6
		&& fabs(go->bottom - gr.top) <= 5 + go->vy) {
		return 1;
	}
	else return 0;
}

int isOnSomeGround(std::vector<ground>& g, gameObject* go) {
	for (auto& p : g) {
		if (!isOnGround(p, go)) return 0;
	}
	return 1;
}

bool equals(double a, double b=0){
	return fabs(a-b)<1e-5;
}