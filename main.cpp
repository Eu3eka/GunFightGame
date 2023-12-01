#include "playerClass.h"
#include "buffItemClass.h"
#include "bulletClass.h"
#include "enemyClass.h"
#include "groundClass.h"
#include "utils.h"
using namespace std;

void startUp() {
	initgraph(WIDTH, HEIGHT);
}


int main() {
	startUp();
	_getch();
	return 0;
}