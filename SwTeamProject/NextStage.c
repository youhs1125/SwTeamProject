#include "NextStage.h"

void setStageDoor(StageDoor* std) {
	std[0].x = 46; std[0].y = 4;
	std[1].x = 32; std[1].y = 6;
	std[2].x = 46; std[2].y = 4;
}

void printStageDoor(StageDoor* std, int stage[][60], int stageNum) {		//免备 = 97
	int posX = std[stageNum].x * 2 + OriginX;
	int posY = std[stageNum].y + OriginY;
	stage[std[stageNum].y][std[stageNum].x] *= 97;
	SetCurrentCursorPos(posX, posY);
	printPortal();
}

int checkStageDoor(player* p, StageDoor* std, int stageNum) {
	if (p->balls == p->targetBall[p->stageNum] && p->x == std[stageNum].x && (p->y + 2 == std[stageNum].y || p->y + 1 == std[stageNum].y || p->y == std[stageNum].y))
		return 1;
	else
		return 0;
}

void gotoNextStage(player* p, DragonBall dgball[][3], StageDoor* std, int stage[][60]) {
	printStage();
	printCloud(stage, dgball[p->stageNum]);

	p->life++; //respawnPlayer俊辑 life甫 茄沫 憋栏骨肺 固府 眠啊秦滴扁
	respawnPlayer(p, stage); //deletePlayer 窃荐 俊辑 巩阑 昏力矫虐骨肺 啊厘 付瘤阜俊 printStageDoor 免仿秦具窃
	printStageDoor(std, stage, p->stageNum);

	p->balls = 0;
	UpdateRecord(p);
}

void printPortal() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);		//畴尔祸
	printf("≮");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);		//闰祸
}

void nextStageEffect(int stageNum)
{
    stageNum = stageNum % 3;
	/*system("cls");
	for (int j = 0; j < 45; j++) {
		if(j%2 == 0)
			for (int i = 0; i < 100; i++) {
				for (int k = j; k < j + 9; k++) {
					SetCurrentCursorPos(2 * i, k);
					printf("∴");
				}
				Sleep(1);
			}
		else 
			for (int i = 99; i >= 0; i--) {
				for (int k = j; k < j + 9; k++) {
					SetCurrentCursorPos(2 * i, k);
					printf("♂");
				}
				Sleep(1);
			}
		j += 8;
	}
	system("cls");
	return;*/

    SetCurrentCursorPos(0, 0);
    for (int i = 1; i <= 49; i++) {
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        Sleep(10);
    }
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
    SetCurrentCursorPos(0, 0);
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    if (stageNum == 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("　　　　　　　　　　　　　　　　　　　　　　　　♂♂♂♂　　　♂♂♂♂♂　　　　♂♂♂　　　　　♂♂♂　　　　♂♂♂♂♂　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　♂　　　　　♂　　　♂　　　♂　　　♂　　　♂　　　　　　　　　　　　　　　　　♂♂　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　♂　　　　　♂　　　♂　　　♂　　　　　　　♂　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　♂　　　　　♂　　　♂　　　♂　　　　　　　♂　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　♂♂♂　　　　　　♂　　　　　♂♂♂♂♂　　　♂　　　　　　　♂♂♂♂♂　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　♂　　　　　♂　　　♂　　　♂　　♂♂　　　♂　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　♂　　　　　♂　　　♂　　　♂　　　♂　　　♂　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　♂　　　　　♂　　　♂　　　♂　　　♂　　　♂　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂♂♂♂　　　　　　♂　　　　　♂　　　♂　　　　♂♂♂　　　　♂♂♂♂♂　　　　　　　　　　　　　♂♂♂　　　　　　　　　　　　　　　　　　　　　　　　\n");
    }
    if(stageNum == 1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf("　　　　　　　　　　　　　　　　　　　　　　　　♂♂♂♂　　　♂♂♂♂♂　　　　♂♂♂　　　　　♂♂♂　　　　♂♂♂♂♂　　　　　　　　　　　　♂♂♂♂♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　♂　　　　　♂　　　♂　　　♂　　　♂　　　♂　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　♂　　　　　♂　　　♂　　　♂　　　　　　　♂　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　♂　　　　　♂　　　♂　　　♂　　　　　　　♂　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　♂♂♂　　　　　　♂　　　　　♂♂♂♂♂　　　♂　　　　　　　♂♂♂♂♂　　　　　　　　　　　　♂♂♂♂♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　♂　　　　　♂　　　♂　　　♂　　♂♂　　　♂　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　♂　　　　　♂　　　♂　　　♂　　　♂　　　♂　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　♂　　　　　♂　　　♂　　　♂　　　♂　　　♂　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂♂♂♂　　　　　　♂　　　　　♂　　　♂　　　　♂♂♂　　　　♂♂♂♂♂　　　　　　　　　　　　♂♂♂♂♂　　　　　　　　　　　　　　　　　　　　　　　\n");
    }
    if (stageNum == 2) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        printf("　　　　　　　　　　　　　　　　　　　　　　　　♂♂♂♂　　　♂♂♂♂♂　　　　♂♂♂　　　　　♂♂♂　　　　♂♂♂♂♂　　　　　　　　　　　　♂♂♂♂　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　♂　　　　　♂　　　♂　　　♂　　　♂　　　♂　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　♂　　　　　♂　　　♂　　　♂　　　　　　　♂　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　♂　　　　　♂　　　♂　　　♂　　　　　　　♂　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　♂♂♂　　　　　　♂　　　　　♂♂♂♂♂　　　♂　　　　　　　♂♂♂♂♂　　　　　　　　　　　　♂♂♂♂　　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　♂　　　　　♂　　　♂　　　♂　　♂♂　　　♂　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　♂　　　　　♂　　　♂　　　♂　　　♂　　　♂　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　♂　　　　　♂　　　　　♂　　　♂　　　♂　　　♂　　　♂　　　　　　　　　　　　　　　　　　　　♂　　　　　　　　　　　　　　　　　　　　　　　\n");
        printf("　　　　　　　　　　　　　　　　　　　　　　　♂♂♂♂　　　　　　♂　　　　　♂　　　♂　　　　♂♂♂　　　　♂♂♂♂♂　　　　　　　　　　　　♂♂♂♂　　　　　　　　　　　　　　　　　　　　　　　　\n");
    }
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
    printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
    Sleep(1500);
    SetCurrentCursorPos(0, 0);


    for (int j = 0; j < 45; j++) {
        if (j % 2 == 0)
            for (int i = 0; i < 100; i++) {
                for (int k = j; k < j + 9; k++) {
                    SetCurrentCursorPos(2 * i, k);
                    printf("∴");
                }
            }
        else
            for (int i = 99; i >= 0; i--) {
                for (int k = j; k < j + 9; k++) {
                    SetCurrentCursorPos(2 * i, k);
                    printf("♂");
                }
            }
        j += 8;
    }
    system("cls");
    
}