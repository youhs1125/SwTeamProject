#pragma once
#include <stdio.h>
#include <Windows.h>
#include "Characters.h"
#include "DragonBall.h"
#include "Cloud.h"
#include "NextStage.h"


#define stage1Y 40
#define stage1X 60
#define OriginX 5
#define OriginY 5
#define GameX 7
#define GameY 7
#define LEFT 75
#define RIGHT 77
#define JUMPHEIGHT -6
#define safeX 15
#define safeY 10

typedef struct zone {
	int x[3];
	int y[3];
}zone;


//�ʱ� ȭ�� ����
void initCmd();
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);
void RemoveCursor(void);
//�� �׵θ� �׷��ֱ�
void printStage();
//�� ���� �׸���

int isGameOver(player* p);
void respawnPlayer(player* p, int stage[][60]);
void UpdateRecord(player* p);
void initPlayer(player* p);
void drawPlayer(player* p);
void deletePlayer(player* p, int stage[][60]);
void moveLeft(player* p, int stage[][60]);
void moveRight(player* p, int stage[][60]);
void processKeyInput(player* p, int stage[][60]);
int detectColl(int x, int y, int stage[][60]);
int jumpColl(int x, int y, int stage[][60]);
int JumpVector(int y);
int playerJump(player* p, int* jump, int stage[][60]);
//printCloud �����ϸ� ���� ����...
void InitZone(zone* z);
void printSafe();
void safeZone(zone* z, int stageNum, int stage[][60]);
void printZone(zone* z, int stageNum);