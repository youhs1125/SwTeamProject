#include "NextStage.h"

void setStageDoor(StageDoor* std) {
	std[0].x = 46; std[0].y = 4;
	std[1].x = 32; std[1].y = 6;
	std[2].x = 46; std[2].y = 4;
}

void printStageDoor(StageDoor* std, int stage[][60], int stageNum) {		//출구 = 97
	int posX = std[stageNum].x * 2 + OriginX;
	int posY = std[stageNum].y + OriginY;
	stage[std[stageNum].y][std[stageNum].x] *= 97;
	SetCurrentCursorPos(posX, posY);
	printPortal();
}

int checkStageDoor(player* p, StageDoor* std, int stageNum) {
	if (p->balls == p->targetBall[p->stageNum] && p->x == std[stageNum].x && p->y + 2 == std[stageNum].y)
		return 1;
	else
		return 0;
}

void gotoNextStage(player* p, DragonBall dgball[][3], StageDoor* std, int stage[][60]) {
	printStage();
	printCloud(stage, dgball[p->stageNum]);

	p->life++; //respawnPlayer에서 life를 한칸 깍으므로 미리 추가해두기
	respawnPlayer(p, stage); //deletePlayer 함수 에서 문을 삭제시키므로 가장 마지막에 printStageDoor 출력해야함
	printStageDoor(std, stage, p->stageNum);

	p->balls = 0;
	UpdateRecord(p);
}

void printPortal() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);		//노랑색
	printf("★");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);		//흰색
}

void nextStageEffect()
{
	int i,j;
	SetCurrentCursorPos(0, 0);
	for (j = 0; j < 45; j++)
	{
		for (i = 0; i < 80; i++)
			printf("■");
		Sleep(10);
		printf("\n");
	}
	system("cls");
	return;
}