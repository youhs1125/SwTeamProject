#pragma once

typedef struct Player
{
	int x, y; //y는 player의 머리 좌표
	int life;
	int totalBalls;
	int balls;
	int stageNum;
	int targetBall[3];
}player;

typedef struct NPC
{
	int x, y;
	int homeX, homeY;
	int haveBall;
	int distance[8];   //8가지 방향
	int minDistance;  //캐릭터와의 최소거리
	int cnt;
	int npcSpeed;
}NPC;

