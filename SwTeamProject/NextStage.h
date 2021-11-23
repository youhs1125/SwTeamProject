#pragma once
#include "Common.h"

typedef struct StageDoor {
	int x, y;
}StageDoor;

//extern void respawnPlayer(player* p, int stage[][60]);
//extern void UpdateRecord(player* p);

void setStageDoor(StageDoor* std);
void printStageDoor(StageDoor* std, int stage[][60], int stageNum);
int checkStageDoor(player* p, StageDoor* std, int stageNum);
//gotoNextStage 선언하면 오류 생김 -> 이유는 모름


void printPortal(void);