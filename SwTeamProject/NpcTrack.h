#pragma once
#include "characters.h"
#include "Common.h"
#include "cloud.h"

int getDistance(int, int);
void setNpcPrintPos(NPC*);
void updateNpcPos(player*, NPC*);
void deleteNpc(NPC* npc, int stage[][60]);
void drawNpc(NPC* npc);