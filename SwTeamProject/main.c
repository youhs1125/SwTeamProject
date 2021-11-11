#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "characters.h"
#include "cursor.h"
#include "stage1.h"



#define LEFT 75
#define RIGHT 77
#define JUMPHEIGHT -7

void initCmd()
{
	RemoveCursor();
	system("mode con cols=200 lines=50");
}


void initPlayer(player* p)
{
	p->x = 56;
	p->y = 32;
	p->life = 3;
	p->totalBalls = 0;
	p->balls = 0;
	p->stageNum = 1;
}

void initNPC(NPC* npc, int posX, int posY)
{
	npc->homeX = posX;
	npc->homeY = posY;
	npc->x = npc->homeX;
	npc->y = npc->homeY;
	npc->haveBall = 1;
}

void printStage()
{
	int i;

	for (i = 1; i < stage1X - 1; i++)
	{
		SetCurrentCursorPos(OriginX + (i * 2), OriginY);
		printf("─");
		SetCurrentCursorPos(OriginX + (i * 2), stage1Y + OriginY - 1);
		printf("─");
	}

	for (i = 0; i < stage1Y; i++)
	{
		if (i == 0)
		{
			SetCurrentCursorPos(OriginX, i + OriginY);
			printf("┌");
			SetCurrentCursorPos(OriginY + (stage1X - 1) * 2, i + OriginY);
			printf("┐");
		}
		else if (i == stage1Y - 1)
		{
			SetCurrentCursorPos(OriginX, i + OriginY);
			printf("└");
			SetCurrentCursorPos(OriginY + (stage1X - 1) * 2, i + OriginY);
			printf("┘");
		}
		else
		{
			SetCurrentCursorPos(OriginX, i + OriginY);
			printf("│");
			SetCurrentCursorPos(OriginY + (stage1X - 1) * 2, i + OriginY);
			printf("│");
		}
	}

}

void printCloud(int stage[40][60])
{
	int i, j;
	int curX, curY;
	for (i = 1; i < stage1Y - 1; i++)
	{
		for (j = 1; j < stage1X - 1; j++)
		{
			curX = j * 2 + OriginX;
			curY = i + OriginY;
			SetCurrentCursorPos(curX, curY);
			if (stage[i][j] == 2)
				printf("◎");
		}
	}
}

void drawPlayer(player* p)
{
	int posX = OriginX + (p->x * 2);
	int posY = OriginY + p->y;
	SetCurrentCursorPos(posX, posY++);
	printf("●");
	SetCurrentCursorPos(posX, posY++);
	printf("■");
	SetCurrentCursorPos(posX, posY);
	printf("△");
}

void deletePlayer(player* p)
{
	int posX = OriginX + (p->x * 2);
	int posY = OriginY + p->y;
	SetCurrentCursorPos(posX, posY++);
	printf("  ");
	SetCurrentCursorPos(posX, posY++);
	printf("  ");
	SetCurrentCursorPos(posX, posY);
	printf("  ");
}

void drawNPC(NPC* npc)
{
	int posX = OriginX + (npc->x * 2);
	int posY = OriginY + npc->y - 1;
	SetCurrentCursorPos(posX, posY++);
	printf("○");
	SetCurrentCursorPos(posX, posY++);
	printf("◇");
	SetCurrentCursorPos(posX, posY);
	printf("▲");
}

void UpdateRecord(player* p)
{
	int curX = 135;
	int curY = 20;
	int i;
	SetCurrentCursorPos(curX, curY++);
	printf("현재 스테이지: %d", p->stageNum);
	SetCurrentCursorPos(curX, curY++);
	printf("남은 목숨: ");
	for (i = 0; i < p->life; i++)
		printf("♥");
	for (i = 0; i < 3 - p->life; i++)
		printf("  ");
	SetCurrentCursorPos(curX, curY++);
	printf("모은 드래곤 볼 총 개수: %d", p->totalBalls);
	SetCurrentCursorPos(curX, curY++);
	printf("이번 스테이지에서 모은 볼 개수: %d", p->balls);
	SetCurrentCursorPos(curX, curY++);
	printf("좌우 이동 <- -> 방향키");

}

void recoverCloud(player* p, int stage[][60])
{
	int i, j;
	int curX, curY;
	int startX = p->x - 8 < 0 ? 0 : p->x - 8;
	int startY = p->y - 8 < 0 ? 0 : p->y - 8;
	int limitY = p->y + 2 >= stage1Y ? stage1Y - 1 : p->y + 2;
	int limitX = p->x + 8 >= stage1X ? stage1X - 1 : p->x + 8;

	for (i = startY; i < limitY; i++)
	{
		for (j = startX; j < limitX; j++)
		{
			curX = j * 2 + OriginX;
			curY = i + OriginY;
			SetCurrentCursorPos(curX, curY);
			if (stage[i][j] == 2)
				printf("◎");
		}
	}
}

int detectColl(int x, int y, int stage[][60])
{
	if (stage[y][x] == 0 && stage[y + 1][x] == 0 && stage[y + 2][x] == 0)
		return 0;
	else if (stage[y][x] == -1 || stage[y + 1][x] == -1 || stage[y + 2][x] == -1)
		return -1;
	else if (stage[y][x] == 2 || stage[y + 1][x] == 2 || stage[y + 2][x] == 2)
		return 1;
	else if (stage[y][x] == 1 || stage[y + 1][x] == 1 || stage[y + 2][x] == 1)
		return 2;
}

int jumpColl(int x, int y, int stage[][60])
{
	if (stage[y][x] != 0)
		return 3;
	if (stage[y + 1][x] != 0)
		return 2;
	if (stage[y + 2][x] != 0)
		return 1;
	return 0;
}

int JumpVector(int y)
{
	float temp = -(2.0 / 5.0);
	return temp * y;
}

int playerJump(player* p, int* jump, int stage[][60])
{
	static int flag = 0;
	static int cloudFlag = 0;
	int moveY = JumpVector(*jump);
	(*jump)++;
	if (moveY > 2)
		moveY = 2;
	else if (moveY < -2)
		moveY = -2;
	int coll = detectColl(p->x, p->y - moveY, stage);

	if (coll == 2)
	{
		*jump = -(*jump);
		moveY = -moveY;
		coll = detectColl(p->x, p->y - moveY, stage);
	}

	if (moveY < 0 && coll == 1 && flag <= 0)		// 바닥에 붕 뜨게 되었을 때
	{
		moveY = -1;
		int temp = detectColl(p->x, p->y - moveY, stage);

		if (temp == 0)
		{
			Sleep(50);
			deletePlayer(p);
			p->y -= moveY;
			drawPlayer(p);
		}
	}
	else if (coll == 0 || (coll != 2 && moveY >= 0) || flag > 0)	//일반적인 점프
	{
		Sleep(50);
		deletePlayer(p);
		p->y -= moveY;
		drawPlayer(p);

		flag--;

		if (coll != 0 && moveY == 0)
			flag = jumpColl(p->x, p->y, stage);

		return 0;
	}
	else if (coll == -1)
		return -1;
	else
		return 1;
}

void moveLeft(player* p, int stage[][60])
{
	if (detectColl(p->x - 1, p->y, stage) != 2)
	{
		deletePlayer(p);
		p->x -= 1;
		drawPlayer(p);
	}
}

void moveRight(player* p, int stage[][60])
{
	if (detectColl(p->x + 1, p->y, stage) != 2)
	{
		deletePlayer(p);
		p->x += 1;
		drawPlayer(p);
	}
}


void processKeyInput(player* p, int stage[][60])
{
	int i, key;

	for (i = 0; i < 5; i++)
	{
		if (_kbhit() != 0)
		{
			key = _getch();
			switch (key)
			{
			case LEFT:
				moveLeft(p, stage);
				break;
			case RIGHT:
				moveRight(p, stage);
				break;
			}
		}
	}
}

void respawnPlayer(player* p)
{
	deletePlayer(p);
	p->x = 56;
	p->y = 32;
	p->life--;
}

int isGameOver(player* p)
{
	if (p->life <= 0)
		return 1;
	return 0;
}

int main()
{
	player p;
	NPC npc;
	int jump = JUMPHEIGHT;
	int gameFlag = 1;
	int jumpFlag = 0;

	initCmd();
	printStage();
	initPlayer(&p);

	initNPC(&npc, 8, 13);

	printCloud(stage1);
	drawPlayer(&p);
	drawNPC(&npc);
	UpdateRecord(&p);


	while (1)
	{
		if (isGameOver(&p))
			break;

		jumpFlag = playerJump(&p, &jump, stage1);

		recoverCloud(&p, stage1);

		if (jumpFlag == 1)
			jump = JUMPHEIGHT;
		else if (jumpFlag == -1)
		{
			respawnPlayer(&p);
			UpdateRecord(&p);
		}

		processKeyInput(&p, stage1);
	}

	SetCurrentCursorPos(0, 0);
	printf("GameOver");


	getchar();

	return 0;
}