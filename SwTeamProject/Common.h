#pragma once
#include <stdio.h>
#include <Windows.h>
#include "Characters.h"
#include "DragonBall.h"
#include "Cloud.h"

#define stage1Y 40
#define stage1X 60
#define OriginX 5
#define OriginY 5
#define GameX 7
#define GameY 7
#define LEFT 75
#define RIGHT 77
#define JUMPHEIGHT -7
//초기 화면 설정
void initCmd();
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);
void RemoveCursor(void);
//맵 테두리 그려주기
void printStage();
//맵 내부 그리기
void printCloud(int stage[40][60], DragonBall dgb[]);
int isGameOver(player* p);
void respawnPlayer(player* p, int stage[][60]);
void UpdateRecord(player* p);
void initPlayer(player* p);
void initNPC(NPC* npc, int posX, int posY);
void drawPlayer(player* p);
void deletePlayer(player* p, int stage[][60]);
void moveLeft(player* p, int stage[][60]);
void moveRight(player* p, int stage[][60]);
void processKeyInput(player* p, int stage[][60]);
int detectColl(int x, int y, int stage[][60]);
int jumpColl(int x, int y, int stage[][60]);
int JumpVector(int y);
int playerJump(player* p, int* jump, int stage[][60]);