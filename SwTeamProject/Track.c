#include "Track.h"




int getDistance(int x, int y) {
	return x * x + y * y;
}
void updateNpcPos(player *p, NPC *npc) {
	int tempX = 0, tempY = 0;
	tempX = p->x - npc->x;
	tempY = p->y - npc->y;

	if (tempX > 0)
		npc->x += 1;
	else if (tempX < 0)
		npc->x -= 1;
	if (tempY > 0)
		npc->y++;
	else if (tempY < 0)
		npc->y--;
}
void addNpcCnt(NPC *npc) {
	npc->cnt++;
}
