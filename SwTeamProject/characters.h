#pragma once

typedef struct Player
{
	int x, y; //y는 player의 머리 좌표
	int life;
	int totalBalls;
	int balls;
	int stageNum;
	int targetBall[3];

	int spawnPos[3][2]; //3스테이지 (x,y)좌표 - > 3*2 배열
}player;

typedef struct NPC
{
	int x, y;
	int dx, dy;
	int homeX, homeY;
	int haveBall;

	int distance[8];   //8가지 방향
	int minDistance;  //캐릭터와의 최소거리
	int cnt; //npc while문 안에서 움직이는 주기
	int directionCnt; //npc 방향 바꾸는 주기
	int directionFlag;
	int npcSpeed;
	int detectArea;
}NPC;

