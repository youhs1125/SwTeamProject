#include "Common.h"
//초기 화면 설정
void initCmd()
{
	RemoveCursor();
	system("mode con cols=200 lines=50");
}
void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
COORD GetCurrentCursorPos(void)
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}
void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

int isGameOver(player* p)
{
	if (p->life <= 0)
		return 1;
	return 0;
}
//맵 테두리 그려주기
void printStage()
{
	int i;

	//윗,아래 - 58
	for (i = 1; i < stage1X - 1; i++)
	{
		SetCurrentCursorPos(OriginX + (i * 2), OriginY);
		printf("─");
		SetCurrentCursorPos(OriginX + (i * 2), stage1Y + OriginY - 1);
		printf("─");
	}

	//옆
	for (i = 0; i < stage1Y; i++)
	{
		if (i == 0)
		{
			SetCurrentCursorPos(OriginX, i + OriginY);
			printf("┌");
			SetCurrentCursorPos(OriginX + (stage1X - 1) * 2, i + OriginY);
			printf("┐");
		}
		else if (i == stage1Y - 1)
		{
			SetCurrentCursorPos(OriginX, i + OriginY);
			printf("└");
			SetCurrentCursorPos(OriginX + (stage1X - 1) * 2, i + OriginY);
			printf("┘");
		}
		else
		{
			SetCurrentCursorPos(OriginX, i + OriginY);
			printf("│");
			SetCurrentCursorPos(OriginX + (stage1X - 1) * 2, i + OriginY);
			printf("│");
		}
	}
}

void printCloud(int stage[40][60], DragonBall dgb[])
{
	//맵 그리기 전에 내부 한번 초기화 시켜주기
	//다음 스테이지 이동시 필요
	int i, j;
	int curX, curY;
	for (i = 1; i < stage1Y - 1; i++)
	{
		for (j = 1; j < stage1X - 1; j++)
		{
			curX = j * 2 + OriginX;
			curY = i + OriginY;
			SetCurrentCursorPos(curX, curY);
			printf("  ");
		}
	}

	//구름 그려주기
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

	//드래곤볼 그려주기
	for (int i = 0; i < 3; i++) {				//드래곤볼 => 89
		
		if (dgb[i].x > 100)
			return;

		stage[dgb[i].y][dgb[i].x] *= 89;
		curX = dgb[i].x * 2 + OriginX;
		curY = dgb[i].y + OriginY;
		SetCurrentCursorPos(curX, curY);
		printDragonBall();
	}
}

void UpdateRecord(player* p)
{
	int curX = 135;
	int curY = 20;
	static int maxLife;
	int i;
	SetCurrentCursorPos(curX, curY++);
	printf("현재 스테이지: %d", p->stageNum);
	SetCurrentCursorPos(curX, curY++);
	printf("남은 목숨: ");

	maxLife = max(maxLife, p->life);

	for (i = 0; i < p->life; i++)
		printf("♥");
	for (i = 0; i < maxLife - p->life; i++)
		printf("  ");
	SetCurrentCursorPos(curX, curY++);
	printf("모은 드래곤 볼 총 개수: %d", p->totalBalls);
	SetCurrentCursorPos(curX, curY++);
	printf("이번 스테이지에서 모은 볼 개수: %d", p->balls);
	SetCurrentCursorPos(curX, curY++);
	printf("좌우 이동 <- -> 방향키");
}

void respawnPlayer(player* p, int stage[][60])
{
	deletePlayer(p, stage);
	p->x = 56;
	p->y = 32;
	p->life--;
}

void initPlayer(player* p)
{
	p->x = 56;
	p->y = 32;
	p->life = 3;
	p->totalBalls = 0;
	p->balls = 0;
	p->stageNum = 0;
	p->targetBall[0] = 2;
	p->targetBall[1] = 2;
	p->targetBall[2] = 3;
}

void initNPC(NPC* npc, int posX, int posY)
{
	npc->homeX = posX;
	npc->homeY = posY;
	npc->x = npc->homeX;
	npc->y = npc->homeY;
	npc->haveBall = 1;

	npc->cnt = 0; //npc 움직임 주기 카운트용 변수
	npc->npcSpeed = 4; //npc 움직임 주기

	npc->dx = 1;
	npc->dy = 0;
	npc->directionCnt = 0;
	npc->directionFlag = 0;
	npc->detectArea = 40;
}

void drawPlayer(player* p)
{
	/*if (p->y < 0)
		p->y = 0;*/
	int posX = OriginX + (p->x * 2);
	int posY = OriginY + p->y;
	SetCurrentCursorPos(posX, posY++);
	printf("●");
	SetCurrentCursorPos(posX, posY++);
	printf("■");
	SetCurrentCursorPos(posX, posY);
	printf("△");
}

void deletePlayer(player* p, int stage[][60])
{
	int posX = OriginX + (p->x * 2);
	int posY = OriginY + p->y;
	SetCurrentCursorPos(posX, posY++);								//해당 부분 다시 맵과 비교해서 복구
	recoverCloud(p->x, p->y, stage);
	SetCurrentCursorPos(posX, posY++);
	recoverCloud(p->x, p->y + 1, stage);
	SetCurrentCursorPos(posX, posY);
	recoverCloud(p->x, p->y + 2, stage);
}

void moveLeft(player* p, int stage[][60])
{
	if (detectColl(p->x - 1, p->y, stage) != 2)
	{
		deletePlayer(p, stage);
		p->x -= 1;
		drawPlayer(p);
	}
}

void moveRight(player* p, int stage[][60])
{
	if (detectColl(p->x + 1, p->y, stage) != 2)
	{
		deletePlayer(p, stage);
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

int detectColl(int x, int y, int stage[][60])
{
	if (y < 0) y = 0;

	if (stage[y][x] != 0 && (stage[y][x] % 11 == 0 || stage[y + 1][x] % 11 == 0 || stage[y + 2][x] % 11 == 0)) //바닥에 추락 or 함정구름과 충돌
		return -1;
	else if (stage[y][x] == 0 || stage[y + 1][x] == 0 || stage[y + 2][x] == 0) //벽면 충돌
		return 2;
	else if (stage[y][x] == 1 && stage[y + 1][x] == 1 && stage[y + 2][x] == 1) //방해물 x
		return 0;
	//else if (stage[y][x] == 2 || stage[y + 1][x] == 2 || stage[y + 2][x] == 2) //구름과 겹쳐진 상태
	//	return 1;
	else if (stage[y][x] % 89 == 0 || stage[y + 1][x] % 89 == 0 || stage[y + 2][x] % 89 == 0) //드래곤볼 충돌 예외
		return 0;
	else
		return 1;
}

int jumpColl(int x, int y, int stage[][60])
{
	if (stage[y][x] != 1) //발이 구름
		return 3;
	if (stage[y + 1][x] != 1) //몸이 구름
		return 2;
	if (stage[y + 2][x] != 1) //머리가 구름
		return 1;
	return 0;
}

int JumpVector(int y)
{
	//위쪽으로 갈수록 y좌표가 작아지니, 올라가는 상황의 벡터는 음수
	float temp = -(2.0 / 5.0);
	return temp * y;
}

int playerJump(player* p, int* jump, int stage[][60])
{
	//캐릭터가 끼인 상태일 때 내려갈 수 있게 해주는 변수
	static int flag = 0;

	int moveY = JumpVector(*jump);
	(*jump)++;
	if (moveY > 2)
		moveY = 2;
	else if (moveY < -2)
		moveY = -2;

	int coll = detectColl(p->x, p->y - moveY, stage);

	//천장에 부딪히는 겨우
	if (coll == 2)
	{
		*jump = -(*jump);
		moveY = -moveY;
		coll = detectColl(p->x, p->y - moveY, stage);
	}

	Sleep(50);  //각 동작에 대한 지연
	if (moveY < 0 && coll == 1 && flag <= 0)		// 구름 위에 서 있는 상태 -> col == 1인 이유는 구름 밑으로 몸이 떨어지면 낑겨있는 상황이기 떄문
	{
		moveY = -1;
		int temp = detectColl(p->x, p->y - moveY, stage); //한칸 위로 이동했을 경우에서 detectColl 실행
		if (temp == 0) //구름 위에 서 있는 상태라면
		{
			//캐릭터 올려주기
			deletePlayer(p, stage);
			p->y -= moveY;
			drawPlayer(p);
		}
		return 1;
	}
	else if ((coll == 0 || (coll != 2 && moveY >= 0) || flag > 0) && coll != -1)	//일반적인 점프 or 구름에 껴 있는 경우
	{
		deletePlayer(p, stage);
		p->y -= moveY;
		drawPlayer(p);

		flag--; //flag 값이 0이하가 될 때까지 이 조건에 갇힌다. -> flag값이 양수인 것은 구름에 낑겨있는 상태. 

		if (coll != 0 && moveY == 0) //구름에 껴 있는 상황
			flag = jumpColl(p->x, p->y, stage);

		return 0;
	}
	else if (coll == -1)
		return -1;
	else
		return 1;
}