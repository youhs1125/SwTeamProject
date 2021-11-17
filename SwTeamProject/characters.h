#pragma once

typedef struct Player
{
	int x, y;
	int life;
	int totalBalls;
	int balls;
	int stageNum;
}player;

typedef struct NPC
{
	int x, y;
	int homeX, homeY;
	int haveBall;
	int distance[8];   //8가지 방향
	int minDistance;  //캐릭터와의 최소거리
}NPC;