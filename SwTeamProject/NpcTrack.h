#pragma once
#include "Common.h"

int getDistance(int, int);
void setNpcPrintPos(NPC*);
void updateNpcPos(player*, NPC*);
void deleteNpc(NPC* npc, int stage[][60]);
void drawNpc(NPC* npc);
int getArea(NPC* n, player* p);
void addNpcCnt(NPC* n);