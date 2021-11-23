#pragma once
#include "characters.h"
#include "Common.h"
#include "cloud.h"
#include <math.h>

int getDistance(int, int);
void setNpcPrintPos(NPC*);
void updateNpcPos(player*, NPC*);
void deleteNpc(NPC* npc, int stage[][60]);
void drawNpc(NPC* npc);
int getArea(NPC* n, player* p);