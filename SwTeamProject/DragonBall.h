#pragma once
#include "characters.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
//스테이지 상에서 넘버 5로 표시
typedef struct DragonBall {
	//드래곤볼의 위치 좌표
	int x, y;
	//플레이어의 드래곤볼 보유 여부
	int get;
}DragonBall;

void setDragonBallPos(DragonBall *dgb);
int dragonBallGet(player* p, DragonBall* dgb);
/*void checkDragonBall(void);
void stageCheck(void);
void gotoNextStage(void)*/;