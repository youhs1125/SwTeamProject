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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	SetCurrentCursorPos(curX + 13, curY - 2);
	printf("< ＳＴＡＧＥ　%d >", p->stageNum + 1);

	for (int i = 0; i < 9; i++) {
		SetCurrentCursorPos(curX - 2, curY - 1 + i);
		if (i == 0) printf("┏");
		else if (i == 4) printf("┣");
		else if (i == 8) printf("┗");
		else printf("┃");
	}
	for (int i = 0; i < 9; i++) {
		SetCurrentCursorPos(curX + 45, curY - 1 + i);
		if (i == 0) printf("┓");
		else if (i == 4) printf("┫");
		else if (i == 8) printf("┛");
		else printf("┃");
	}
	for (i = 0; i < 3; i++) {
		SetCurrentCursorPos(curX + 10, curY + i);
		printf("┃");
		SetCurrentCursorPos(curX + 10, curY + 4 + i);
		printf("┃");
	}
	for (int i = 0; i < 23; i++) {
		SetCurrentCursorPos(curX + i * 2, curY - 1);
		if (i == 5) printf("┳");
		else printf("━");
	}
	for (int i = 0; i < 23; i++) {
		SetCurrentCursorPos(curX + i * 2, curY + 3);
		if (i == 5) printf("╋");
		else printf("━");
	}
	for (int i = 0; i < 23; i++) {
		SetCurrentCursorPos(curX + i * 2, curY + 7);
		if (i == 5) printf("┻");
		else printf("━");
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	curY += 1;
	SetCurrentCursorPos(curX, curY);
	printf(" 남은체력 ");

	maxLife = max(maxLife, p->life);
	curX += 13;
	SetCurrentCursorPos(curX, curY);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	for (i = 0; i < p->life; i++)
		printf("♥ ");
	for (i = 0; i < maxLife - p->life; i++)
		printf("  　");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	curY += 4;
	curX -= 13;
	SetCurrentCursorPos(curX, curY);
	printf(" 드래곤볼");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	curX += 14;
	SetCurrentCursorPos(curX, curY);
	for (i = 0; i < p->totalBalls; i++) {
		printf("● ");
		if (i == 1 || i == 3) printf(" /  ");
	}
	for (i = p->totalBalls; i < 7; i++) {
		printf("○ ");
		if (i == 1 || i == 3) printf(" /  ");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void respawnPlayer(player* p, int stage[][60], int difficulty, NPC** npc, int* npcNum)
{
	if (difficulty == 104)
	{
		(*npcNum)++;
		*npc = (NPC*)realloc(*npc, sizeof(NPC) * (*npcNum));
		if (p->y >= stage1Y - 1)
			p->y = stage1Y - 3;
		addNpcData(*npc, p->x, p->y, *npcNum);
	}


	deletePlayer(p, stage);
	p->x = p->spawnPos[p->stageNum][0];
	p->y = p->spawnPos[p->stageNum][1];
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

	p->spawnPos[0][0] = 56; //x좌표
	p->spawnPos[0][1] = 32; //y좌표

	p->spawnPos[1][0] = 6;
	p->spawnPos[1][1] = 30;

	p->spawnPos[2][0] = 56;
	p->spawnPos[2][1] = 32;
}

void drawPlayer(player* p)
{
	/*if (p->y < 0)
		p->y = 0;*/
	int posX = OriginX + (p->x * 2);
	int posY = OriginY + p->y;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //3 옥색

	SetCurrentCursorPos(posX, posY++);
	printf("●");
	SetCurrentCursorPos(posX, posY++);
	printf("■");
	SetCurrentCursorPos(posX, posY);
	printf("▲");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //3 옥색
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
	
	if (y < 0) 
		y = 0;
	if (stage[y][x] != 0 && (stage[y][x] % 11 == 0 || stage[y + 1][x] % 11 == 0 || stage[y + 2][x] % 11 == 0)) //바닥에 추락 or 함정구름과 충돌
	{
		if (stage[y + 1][x] % 11 == 0 && stage[y][x] != 1 && stage[y][x] % 11 != 0)
			return 1;
		else if (stage[y + 2][x] % 11 == 0 && stage[y + 1][x] != 1 && stage[y + 1][x] % 11 != 0)
			return 1;
		return -1;
	}
	else if (stage[y][x] == 0 || stage[y + 1][x] == 0 || stage[y + 2][x] == 0) //벽면 충돌
		return 2;
	else if (stage[y][x] == 1 && stage[y + 1][x] == 1 && stage[y + 2][x] == 1) //방해물 x
		return 0;
	else if (stage[y][x] % 89 == 0 || stage[y + 1][x] % 89 == 0 || stage[y + 2][x] % 89 == 0) //드래곤볼 충돌 예외
		return 0;
	else if (stage[y][x] % 97 == 0 || stage[y + 1][x] % 97 == 0 || stage[y + 2][x] % 97 == 0) //다음 스테이지 이동시켜주는 포탈 충돌 예외
		return 0;
	else if (stage[y][x] % 37 == 0 || stage[y + 1][x] % 37 == 0 || stage[y + 2][x] % 37 == 0)
	{
		if (stage[y + 1][x] % 37 == 0 && stage[y][x] != 1 && stage[y][x] % 37 != 0)
			return 1;
		else if (stage[y + 2][x] % 37 == 0 && stage[y + 1][x] != 1 && stage[y + 1][x] % 37 != 0)
			return 1;
		else if (stage[y][x] / 37 >= 2 || stage[y + 1][x] / 37 >= 2 || stage[y + 1][x] / 37 >= 2)
			return 1;
		if (stage[y + 1][x] % 37 == 0 && stage[y + 2][x] != 1 && stage[y + 2][x] % 37 != 0)
			return 1;
		else if (stage[y][x] % 37 == 0 && stage[y + 1][x] != 1 && stage[y + 1][x] % 37 != 0)
			return 1;
		return 0;
	}
	else 
		return 1;
}

int jumpColl(int x, int y, int stage[][60])
{
	if (stage[y][x] != 1) //발이 구름
		return 2;
	if (stage[y + 1][x] != 1) //몸이 구름
		return 1;
	if (stage[y + 2][x] != 1) //머리가 구름
		return 0;
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
	if (moveY < 0 && coll == 1 && flag <= 0)		// 구름 위에 서 있는 상태 -> col == 1인 이유는 구름 밑으로 몸이 떨어지면 낑겨있는 상황이기 문
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
	else if (coll == -1)
		return -1;
	else if (coll == 0 || (coll != 2 && moveY >= 0) || flag > 0)	//일반적인 점프 or 구름에 껴 있는 경우
	{
		deletePlayer(p, stage);
		p->y -= moveY;
		drawPlayer(p);

		flag--; //flag 값이 0이하가 될 때까지 이 조건에 갇힌다. -> flag값이 양수인 것은 구름에 낑겨있는 상태. 

		if (coll != 0 && moveY == 0) //구름에 껴 있는 상황
			flag = jumpColl(p->x, p->y, stage);

		return 0;
	}
	else
		return 1;
}

void InitZone(zone* z)
{
	z->x[0] = 2;
	z->y[0] = 1;
	z->x[1] = 31;
	z->y[1] = 23;
	z->x[2] = 16;
	z->y[2] = 18;
}

void printSafe()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("◇");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void safeZone(zone* z, int stageNum, int stage[][60])
{
	int i;
	for (int i = 1; i < safeX - 1; i++)
	{
		stage[z->y[stageNum]][z->x[stageNum] + i] *= 37;
		stage[z->y[stageNum] + safeY - 1][z->x[stageNum] + i] *= 37;
	}
	for (int i = 0; i < safeY; i++)
	{
		stage[z->y[stageNum] + i][z->x[stageNum]] *= 37;
		stage[z->y[stageNum] + i][z->x[stageNum] + safeX - 1] *= 37;
	}
}

void printZone(zone* z, int stageNum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	int i;

	/*for (int y = 0; y < safeY; y++) {
		for (int x = 1; x < safeX; x++) {

		}
	}*/

	for (int i = 1; i < safeX - 1; i++)
	{
		int posX = OriginX + (z->x[stageNum] + i) * 2;
		int posY = z->y[stageNum] + OriginY;
		SetCurrentCursorPos(posX, posY);
		printf("◇");
		posY += safeY - 1;
		SetCurrentCursorPos(posX, posY);
		printf("◇");
	}
	for (int i = 0; i < safeY; i++)
	{
		int posX = OriginX + (z->x[stageNum]) * 2;
		int posY = z->y[stageNum] + OriginY + i;
		SetCurrentCursorPos(posX, posY);
		printf("◇");
		posX = OriginX + (z->x[stageNum] + safeX - 1) * 2;
		SetCurrentCursorPos(posX, posY);
		printf("◇");
	}
}