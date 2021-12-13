#pragma once
#include "Common.h"
#include "StartScreen.h"


int getDistance(int, int);
void setNpcPrintPos(NPC*);

void deleteNpc(NPC* npc, int stage[][60]);
void drawNpc(NPC* npc);
int getArea(NPC* n, player* p);
void addNpcCnt(NPC* n);
void initNPC(NPC* npc, int diff, int stageNum, int* npcNum);
