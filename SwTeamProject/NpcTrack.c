#include "NpcTrack.h"


int getDistance(int x, int y) {
	return x * x + y * y;
}
void updateNpcPos(player* p, NPC* npc) {

	if (getArea(npc, p) > npc->detectArea) return; //특정 영역안에 존재할 떄 추적 시작

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
		npc->x += npc->dx;
		npc->y += npc->dy;
	}
}
void addNpcCnt(NPC *npc) {
	npc->cnt++;
}
void deleteNpc(NPC* npc, int stage[][60]) {
	int posX = OriginX + (npc->x * 2);
	int posY = OriginY + npc->y;
	SetCurrentCursorPos(posX, posY);
	recoverCloud(npc->x, npc->y, stage);
}

void drawNpc(NPC* npc) {
	int posX = OriginX + (npc->x * 2);
	int posY = OriginY + npc->y;
	SetCurrentCursorPos(posX, posY);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);	//보라색
	printf("●");  //임시 npc
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// 흰색}
}

int getArea(NPC* npc, player* p) {
	int x  = npc->x - p->x;
	int y = npc->y - p->y;
	return x * y < 0 ? x * y * (-1) : x * y;
}