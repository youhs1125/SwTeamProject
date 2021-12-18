#include "NpcTrack.h"
#include "Item.h"

int getDistance(int x, int y) {
	return x * x + y * y;
}

int getSafety(zone* z, player* p, int x, int y)
{
	//int posX = OriginX + (x + z->x[p->stageNum])* 2;
	//int posY = OriginY + y + z->y[p->stageNum];
	//npc 멀어지는 범위 여기에 넣어주기.
	if (x >= z->x[p->stageNum] && x <= z->x[p->stageNum] + safeX && y >= z->y[p->stageNum] && y <= z->y[p->stageNum] + safeY)
		return -1;
	else return 1;



	//if (posX <= (OriginX + stage1X * 2) / 4 && posY <= (OriginY + stage1Y) / 4)
	//	return -1;
	//else return 1;
}

void updateNpcPos(zone* z, player* p, NPC* npc) {
	if (npc->isMoving == 0)
	{
		npc->npcSpeed = 4;
		npc->detectArea = 40;
	}
	if (getArea(npc, p) > npc->detectArea)
	{
		npc->isMoving = 0;
		return; //특정 영역안에 존재할 ?? 추적 시작
	}

	int check = getSafety(z, p, p->x, p->y);
	int tempCheck = getSafety(z, p, npc->x, npc->y);
	//printf("%d ", check);
	npc->isMoving = 1;
	if (npc->moveStyle == 0) { //지그 재그 움직임
		npc->directionCnt++;
		if (npc->directionCnt % 4 == 0) { //
			int tempX = 0, tempY = 0;
			tempX = p->x - npc->x;
			tempY = p->y - npc->y;
			if (tempX > 0)
				npc->dx = 1;
			else
				npc->dx = -1;


			if (tempY > 0)
				npc->dy = 1;
			else
				npc->dy = -1;

			if (npc->directionFlag == 0) {
				npc->directionFlag = 1;
				npc->dx = 0;
			}
			else {
				npc->directionFlag = 0;
				npc->dy = 0;
			}
		}
		else {
			npc->x += npc->dx * check * tempCheck;
			npc->y += npc->dy * check * tempCheck;
			if (npc->x >= stage1X - 1)
				npc->x--;
			if (npc->y <= 1)
				npc->y++;
		}
	}
	else if (npc->moveStyle == 1) {//직선 움직임

		if (npc->x < p->x) npc->dx = 1;
		else if (npc->x > p->x) npc->dx = -1;

		if (npc->y < p->y) npc->dy = 1;
		else if (npc->y > p->y) npc->dy = -1;

		npc->x += npc->dx * check * tempCheck;
		npc->y += npc->dy * check * tempCheck;
	}
}
void addNpcCnt(NPC* npc) {
	npc->cnt++;
}
void deleteNpc(NPC* npc, int stage[][60]) {
	int posX = OriginX + (npc->x * 2);
	int posY = OriginY + npc->y;
	SetCurrentCursorPos(posX, posY);
	recoverCloud(npc->x, npc->y, stage);
	SetCurrentCursorPos(posX, posY + 1);
	recoverCloud(npc->x, npc->y + 1, stage);
}

void drawNpc(NPC* npc) {
	int posX = OriginX + (npc->x * 2);
	int posY = OriginY + npc->y;
	SetCurrentCursorPos(posX, posY);

	if (npc->isMoving)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);	//보라색
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	SetCurrentCursorPos(posX, posY);
	printf("●");  //임시 npc
	SetCurrentCursorPos(posX, posY + 1);
	printf("▼");  //임시 npc
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// 흰색}
}

int getArea(NPC* npc, player* p) {
	int x = npc->x - p->x;
	int y = npc->y - p->y;
	return x * y < 0 ? x * y * (-1) : x * y;
}

void initNPC(NPC* npcArr, int diff, int stageNum, int* npcNum)
//npc 난이도 조절을 위해 난이도와 스테이지 넘버 매개변수로 받아오기 
//npcNum -> 맵에서 돌아다니는 npc 개수
{
	//
	if (diff == E) {
		if (stageNum == 0) {
			*npcNum = 1;
			npcArr = (NPC*)realloc(npcArr, sizeof(NPC) * (*npcNum));
			npcArr[0].homeX = 10; npcArr[0].homeY = 13;
			//npcArr[1].homeX = 50; npcArr[1].homeY = 20;

			npcArr[0].moveStyle = 0;
			npcArr[0].npcSpeed = 3;
		}
		else if (stageNum == 1) {
			*npcNum = 2;
			npcArr = (NPC*)realloc(npcArr, sizeof(NPC) * (*npcNum));
			npcArr[0].homeX = 10; npcArr[0].homeY = 10;
			npcArr[1].homeX = 50; npcArr[1].homeY = 20;

			npcArr[0].moveStyle = 0;
			npcArr[0].npcSpeed = 2;
			npcArr[1].moveStyle = 0;
			npcArr[1].npcSpeed = 2;
		}
		else {
			*npcNum = 2;
			npcArr = (NPC*)realloc(npcArr, sizeof(NPC) * (*npcNum));
			npcArr[0].homeX = 10; npcArr[0].homeY = 10;
			npcArr[1].homeX = 45; npcArr[1].homeY = 5;

			npcArr[0].moveStyle = 1;
			npcArr[0].npcSpeed = 2;
			npcArr[1].moveStyle = 1;
			npcArr[1].npcSpeed = 2;
		}
	}

	if (diff == H) {
		if (stageNum == 0) {
			*npcNum = 2;
			npcArr = (NPC*)realloc(npcArr, sizeof(NPC) * (*npcNum));
			npcArr[0].homeX = 10; npcArr[0].homeY = 13;
			npcArr[1].homeX = 50; npcArr[1].homeY = 20;

			npcArr[0].moveStyle = 0;
			npcArr[0].npcSpeed = 2;
			npcArr[1].moveStyle = 0;
			npcArr[1].npcSpeed = 2;
		}
		else if (stageNum == 1) {
			*npcNum = 2;
			npcArr = (NPC*)realloc(npcArr, sizeof(NPC) * (*npcNum));
			npcArr[0].homeX = 10; npcArr[0].homeY = 10;
			npcArr[1].homeX = 50; npcArr[1].homeY = 20;

			npcArr[0].moveStyle = 0;
			npcArr[0].npcSpeed = 2;
			npcArr[1].moveStyle = 1;
			npcArr[1].npcSpeed = 2;
		}
		else {
			*npcNum = 3;
			npcArr = (NPC*)realloc(npcArr, sizeof(NPC) * (*npcNum));
			npcArr[0].homeX = 10; npcArr[0].homeY = 10;
			npcArr[1].homeX = 50; npcArr[1].homeY = 20;
			npcArr[2].homeX = 40; npcArr[2].homeY = 35;

			npcArr[0].moveStyle = 1;
			npcArr[0].npcSpeed = 2;
			npcArr[1].moveStyle = 1;
			npcArr[1].npcSpeed = 2;
			npcArr[2].moveStyle = 1;
			npcArr[2].npcSpeed = 2;
		}
	}

	for (int i = 0; i < *npcNum; i++) {
		npcArr[i].x = npcArr[i].homeX;
		npcArr[i].y = npcArr[i].homeY;
		npcArr[i].haveBall = 1;

		//npcArr[i].moveStyle = 0;
		npcArr[i].cnt = 0; //npc 움직임 주기 카운트용 변수
		//npcArr[i].npcSpeed = 4; //npc 움직임 주기

		npcArr[i].dx = 1;
		npcArr[i].dy = 0;
		npcArr[i].directionCnt = 0;
		npcArr[i].directionFlag = 0;

		npcArr[i].detectArea = 50;
		npcArr[i].isMoving = 0;
	}

	//임시로 보여주기 위한 설정
	/*npcArr[0].moveStyle = 1;
	npcArr[0].npcSpeed = 6;*/
}

void addNpcData(NPC* npc, int x, int y, int npcNum)
{
	npc[npcNum - 1].x = x;
	npc[npcNum - 1].y = y;
	npc[npcNum - 1].moveStyle = 0;
	npc[npcNum - 1].npcSpeed = 2;
	npc[npcNum - 1].cnt = 0;
	npc[npcNum - 1].dx = 1;
	npc[npcNum - 1].dy = 0;
	npc[npcNum - 1].directionCnt = 0;
	npc[npcNum - 1].directionFlag = 0;

	npc[npcNum - 1].detectArea = 50;
	npc[npcNum - 1].isMoving = 0;
}