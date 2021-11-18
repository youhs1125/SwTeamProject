#pragma once
#include <Windows.h>
#include <stdio.h>
#include "characters.h"
#include "cursor.h"
#define OriginX 5
#define OriginY 10
#define JUMPHEIGHT -7

typedef struct SPECIALCLOUD
{
	int movement;				//구름 움직임
	int cloudType;				//3 => 점프구름, 5 => 약한 구름, 7 = 깜박 구름, 11 => 지뢰구름
	int size;					//구름 크기
	int x, y;
	int vis;
}cloud;


int jumpHigh(int height);

void blink(int* cloudVis);

void vanishCloud(int* cloudVis);

int cloudColl(int x, int y, int size, int stage[][60]);

void printJumpCloud();

void printWeakCloud();

void printBlinkCloud();

void printNormalCloud();

void printTrapCloud();

void recoverCloud(int x, int y, int stage[][60]);


void drawSpecialCloud(cloud* cloud, int stage[][60]);


void deleteSpecialCloud(cloud* cloud, int stage[][60]);


void initSpecialCloud(cloud* cloudArray, int size);


int collSpecialCloud(cloud* cloudArr, player* p, int stage[][60]);


void moveCloud(cloud* cloudArr, int stage[][60]);

