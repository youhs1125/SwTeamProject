#pragma once
#include "Common.h"
#include "StartScreen.h"
#define E 101
#define H 104
#define Q 113
#define UP 72
#define DOWN 80
#define ENTER 13


int printStartScreen() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	int menu = 0;
	SetCurrentCursorPos(30, 5);
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 6);
	puts("□□□□□□□□■■■□□□□□□□□□□□□□□□□□□■■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 7);
	puts("□□□□□□□■□□□■□□□□□□■■■■■■■□□□□□□□□□□□□■□□□□□□□□□□□□□□■■■■□□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 8);
	puts("□□□□□□■□□□□□■□□□□■□□□□□□□■□□□□□□□■□□□■□□□□□□□□□□□□■■□□□□■■□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 9);
	puts("□□□□□■□□□■□□□■□□□■□□□□□□□■□□□□□□□■□□□□□□□□□□□□□□■■□□□□□□□□■□□□□□□□□□□□");
	SetCurrentCursorPos(30, 10);
	puts("□□□□□□□□□■□□□□□□□□■■■■■■■□□□■■■■■■■■■■■□□□□□□□■■□□□□□□□□□□■□□□□□□□□□□□");
	SetCurrentCursorPos(30, 11);
	puts("□□□□■■■■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□□□■□□□□□■□□□□□□□□□□□");
	SetCurrentCursorPos(30, 12);
	puts("□□□□□□□□□□□□□□□□□□□□□■□□□□□□□□□■■■■■□□□□□□□□■□□□□□□□■□□□□■□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 13);
	puts("□□□□□■□□□□□□□□□□□□□□□■□□□□□□□□■□□□□□■□□□□□□■□□□□□□□□□■■■■□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 14);
	puts("□□□□□■□□□□□□□□□□■■■■■■■■■■■□□□■□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 15);
	puts("□□□□□■■■■■■■■■□□□□□□□□□□□□□□□□□■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 16);
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■■□□□■□□■■■■■■■■■□□□□□□");
	SetCurrentCursorPos(30, 17);
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□□□■□□□□■□□□■□□□□□□□□");
	SetCurrentCursorPos(30, 18);
	puts("□□□□□□□□□□□□□□□□■■■■■□□□□□□□□□□■□□□□□□□□□□□□■□■□□■■■■□□□□■□□□■□□□□□□□□");
	SetCurrentCursorPos(30, 19);
	puts("□□□□□□□□□□□□□□□■□□□□□■□□□□□□□□■□□□□□□□□□□□□■□□□■□□□□■□□□□■□□□■□□□□□□□□");
	SetCurrentCursorPos(30, 20);
	puts("□□□□□□□□□□□□□□■□□□□□□□■□□□□□□■□□□□□□□□□□□□■□□□□□■□□□■□□□□■□□□■□□□□□□□□");
	SetCurrentCursorPos(30, 21);
	puts("□□□□□□□□□□□□□□■□□□□□□■□□□□□■■□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■■■■□□□□□□");
	SetCurrentCursorPos(30, 22);
	puts("□□□□□□□□□□□□□□■□□□□□□□□□□■■□□□□□□□□□□□□□□□□□■■■■■■■■■□□□□□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 23);
	puts("□□□□□□□□□□□□□□□■□□□□□□■■■□□□□□□□□□□□□□□□□□□□■□□□□□□□■□□□□□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 24);
	puts("□□□□□□□□□□□□□□□□■■■■■■□□□□□□□□□□□□□□□□□□□□□□■□□□□□□□■□□□□□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 25);
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■■■■□■■■■■■■■■■■□□□□□");
	SetCurrentCursorPos(30, 26);
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	SetCurrentCursorPos(30, 27);
	puts("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	SetCurrentCursorPos(30, 28);
	puts("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　SW 기초설계 7팀 : 유희석, 이재혁, 조현수, 정준엽");
	SetCurrentCursorPos(90, 35);
	printf("▶ Play Easy Mode ◀");
	SetCurrentCursorPos(90, 37);
	printf("　 Play Hard Mode 　");
	SetCurrentCursorPos(89, 39);
	printf("　 Game Explanation 　");
	SetCurrentCursorPos(90, 41);
	printf("　 Quit The Game 　");
	while (1) {
		for (int i = 0; i < 50; i++) {
			if (_kbhit() != 0) {
				int key;
				key = _getch();
				switch (key) {
				case UP:
					if (menu == 0) break;
					else if (menu == 1) {
						SetCurrentCursorPos(90, 35);
						printf("▶ Play Easy Mode ◀");
						SetCurrentCursorPos(90, 37);
						printf("　 Play Hard Mode 　");
						menu = 0;
					}
					else if (menu == 2) {
						SetCurrentCursorPos(90, 37);
						printf("▶ Play Hard Mode ◀");
						SetCurrentCursorPos(89, 39);
						printf("　 Game Explanation 　");
						menu = 1;
					}
					else {
						SetCurrentCursorPos(89, 39);
						printf("▶ Game Explanation ◀");
						SetCurrentCursorPos(90, 41);
						printf("　 Quit The Game 　");
						menu = 2;
					}
					break;
				case DOWN:
					if (menu == 0) {
						SetCurrentCursorPos(90, 35);
						printf("　 Play Easy Mode 　");
						SetCurrentCursorPos(90, 37);
						printf("▶ Play Hard Mode ◀");
						menu = 1;
					}
					else if (menu == 1) {
						SetCurrentCursorPos(90, 37);
						printf("　 Play Hard Mode 　");
						SetCurrentCursorPos(89, 39);
						printf("▶ Game Explanation ◀");
						menu = 2;
					}
					else if (menu == 2) {
						SetCurrentCursorPos(89, 39);
						printf("　 Game Explanation 　");
						SetCurrentCursorPos(90, 41);
						printf("▶ Quit The Game ◀");
						menu = 3;
					}
					else break;
					break;
				case ENTER:
					system("cls");
					if (menu == 0) return E;
					else if (menu == 1) return H;
					else if (menu == 2) return 2;
					else exit(-1);
				}
			}
			if (i >= 25) {
				Sleep(10);
				SetCurrentCursorPos(30, 5);
				puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 6);
				puts("■■■■■■■■□□□■■■■■■■■■■■■■■■■■■□□□□□□□□□■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 7);
				puts("■■■■■■■□■■■□■■■■■■□□□□□□□■■■■■■■■■■■■□■■■■■■■■■■■■■■□□□□■■■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 8);
				puts("■■■■■■□■■■■■□■■■■□■■■■■■■□■■■■■■■□■■■□■■■■■■■■■■■■□□■■■■□□■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 9);
				puts("■■■■■□■■■□■■■□■■■□■■■■■■■□■■■■■■■□■■■■■■■■■■■■■■□□■■■■■■■■□■■■■■■■■■■■");
				SetCurrentCursorPos(30, 10);
				puts("■■■■■■■■■□■■■■■■■■□□□□□□□■■■□□□□□□□□□□□■■■■■■■□■■■■■■■■■■■□■■■■■■■■■■■");
				SetCurrentCursorPos(30, 11);
				puts("■■■■□□□□□□□□□□□■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□■■■■■■□■■■■■□■■■■■■■■■■■");
				SetCurrentCursorPos(30, 12);
				puts("■■■■■■■■■■■■■■■■■■■■■□■■■■■■■■■□□□□□■■■■■■■■□■■■■■■■□■■■■□■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 13);
				puts("■■■■■□■■■■■■■■■■■■■■■□■■■■■■■■□■■■■■□■■■■■■□■■■■■■■■■□□□□■■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 14);
				puts("■■■■■□■■■■■■■■■■□□□□□□□□□□□■■■□■■■■■□■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 15);
				puts("■■■■■□□□□□□□□□■■■■■■■■■■■■■■■■■□□□□□■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 16);
				puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□□□□□□□■■■□■■□□□□□□□□□■■■■■■");
				SetCurrentCursorPos(30, 17);
				puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□■■■■■■□■■■■□■■■□■■■■■■■■");
				SetCurrentCursorPos(30, 18);
				puts("■■■■■■■■■■■■■■■■□□□□□■■■■■■■■■■□■■■■■■■■■■■■□■□■■□□□□■■■■□■■■□■■■■■■■■");
				SetCurrentCursorPos(30, 19);
				puts("■■■■■■■■■■■■■■■□■■■■■□■■■■■■■■□■■■■■■■■■■■■□■■■□■■■■□■■■■□■■■□■■■■■■■■");
				SetCurrentCursorPos(30, 20);
				puts("■■■■■■■■■■■■■■□■■■■■■■□■■■■■■□■■■■■■■■■■■■□■■■■■□■■■□■■■■□■■■□■■■■■■■■");
				SetCurrentCursorPos(30, 21);
				puts("■■■■■■■■■■■■■■□■■■■■■□■■■■■□□■■■■■■■■■■■■■■■■■■■■■■■■■■□□□□□□□□□■■■■■■");
				SetCurrentCursorPos(30, 22);
				puts("■■■■■■■■■■■■■■□■■■■■■■■■■□□■■■■■■■■■■■■■■■■■□□□□□□□□□■■■■■■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 23);
				puts("■■■■■■■■■■■■■■■□■■■■■■□□□■■■■■■■■■■■■■■■■■■■□■■■■■■■□■■■■■■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 24);
				puts("■■■■■■■■■■■■■■■■□□□□□□■■■■■■■■■■■■■■■■■■■■■■□■■■■■■■□■■■■■■■■■■■■■■■■■");
				SetCurrentCursorPos(30, 25);
				puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□□□□□□□□□■□□□□□□□□□□□■■■■■");
				SetCurrentCursorPos(30, 26);
				puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			}
			else {
				Sleep(10);
				SetCurrentCursorPos(30, 5);
				puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 6);
				puts("□□□□□□□□■■■□□□□□□□□□□□□□□□□□□■■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 7);
				puts("□□□□□□□■□□□■□□□□□□■■■■■■■□□□□□□□□□□□□■□□□□□□□□□□□□□□■■■■□□□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 8);
				puts("□□□□□□■□□□□□■□□□□■□□□□□□□■□□□□□□□■□□□■□□□□□□□□□□□□■■□□□□■■□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 9);
				puts("□□□□□■□□□■□□□■□□□■□□□□□□□■□□□□□□□■□□□□□□□□□□□□□□■■□□□□□□□□■□□□□□□□□□□□");
				SetCurrentCursorPos(30, 10);
				puts("□□□□□□□□□■□□□□□□□□■■■■■■■□□□■■■■■■■■■■■□□□□□□□■■□□□□□□□□□□■□□□□□□□□□□□");
				SetCurrentCursorPos(30, 11);
				puts("□□□□■■■■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□□□■□□□□□■□□□□□□□□□□□");
				SetCurrentCursorPos(30, 12);
				puts("□□□□□□□□□□□□□□□□□□□□□■□□□□□□□□□■■■■■□□□□□□□□■□□□□□□□■□□□□■□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 13);
				puts("□□□□□■□□□□□□□□□□□□□□□■□□□□□□□□■□□□□□■□□□□□□■□□□□□□□□□■■■■□□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 14);
				puts("□□□□□■□□□□□□□□□□■■■■■■■■■■■□□□■□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 15);
				puts("□□□□□■■■■■■■■■□□□□□□□□□□□□□□□□□■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 16);
				puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■■□□□■□□■■■■■■■■■□□□□□□");
				SetCurrentCursorPos(30, 17);
				puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□□□■□□□□■□□□■□□□□□□□□");
				SetCurrentCursorPos(30, 18);
				puts("□□□□□□□□□□□□□□□□■■■■■□□□□□□□□□□■□□□□□□□□□□□□■□■□□■■■■□□□□■□□□■□□□□□□□□");
				SetCurrentCursorPos(30, 19);
				puts("□□□□□□□□□□□□□□□■□□□□□■□□□□□□□□■□□□□□□□□□□□□■□□□■□□□□■□□□□■□□□■□□□□□□□□");
				SetCurrentCursorPos(30, 20);
				puts("□□□□□□□□□□□□□□■□□□□□□□■□□□□□□■□□□□□□□□□□□□■□□□□□■□□□■□□□□■□□□■□□□□□□□□");
				SetCurrentCursorPos(30, 21);
				puts("□□□□□□□□□□□□□□■□□□□□□■□□□□□■■□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■■■■□□□□□□");
				SetCurrentCursorPos(30, 22);
				puts("□□□□□□□□□□□□□□■□□□□□□□□□□■■□□□□□□□□□□□□□□□□□■■■■■■■■■□□□□□□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 23);
				puts("□□□□□□□□□□□□□□□■□□□□□□■■■□□□□□□□□□□□□□□□□□□□■□□□□□□□■□□□□□□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 24);
				puts("□□□□□□□□□□□□□□□□■■■■■■□□□□□□□□□□□□□□□□□□□□□□■□□□□□□□■□□□□□□□□□□□□□□□□□");
				SetCurrentCursorPos(30, 25);
				puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■■■■□■■■■■■■■■■■□□□□□");
				SetCurrentCursorPos(30, 26);
				puts("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
			}
		}
	}
}

//int getKeyInput() {
//
//	while (_kbhit() == 0) {
//		int key = _getch();
//		switch (key) {
//		case E:
//			return E;
//		case H:
//			return H;
//		case Q:
//			return Q;
//		}
//	}
//}

void GameExplanation() {
	SetCurrentCursorPos(0, 0);
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　■■■　　　　■■■■■　　　　　　　■■■　■　　　■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　■　　　　■　　　■　　　　　　　■　　　　　　　　■　■■　　　　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　■　　　■　　　■　　　　　■　　　　　　　　　■　■　■　　　　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　■■■　　　　■■■■■　　　　　　　　　　　　　　　■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　■■■　　　　　　　　　　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　■■■■■　　　■　　　■　　　　　　　　　■■■　　　■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　§ 스토리 §\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　 어느 날 손오공의 친구들이 마인부우 일당들에게 납치되었다!! 친구들을 구해내려면 드래곤볼 7개를 모아야 한다!!!\n");
	printf("　　　　　　　　납치된 친구들을 구하기 위해 손오공을 조종해 마인부우 일당들의 추격을 따돌리고 아이템의 도움을 받아 구름을 밟고 올라가며 하늘에 숨겨진 드래곤볼 7개를 모으자!!!\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　§ 조작 방법 §                                                                          § 스테이지 구성 §\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　좌우 방향키 ◀ ▶　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　총 3개의 스테이지로 이루어져 있어요!!\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 　드래곤볼이에요!! 세 개의 스테이지에 숨겨져 있는 드래곤볼 7개를 모으세요!!\n");
	printf("　　　　　　　　§ 등장 인물 §\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 　포탈이에요!!\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 　스테이지 내의 드래곤볼을 다모으면 포탈을 이용해 다음 스테이지로 이동할 수 있어요!!!\n");
	printf("　　　　　　　　　주인공　　　　　　　　　　마인부우의 일당들\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　§ 구름 §　　　　　　　　　　　　　　　　　　　　　　　　　§ 아이템 §　　　　　　　　　　　　　　　　　　　　　　　§ 결계존 §\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　◎◎◎◎◎　일반적인 구름이에요.　　　　　　　　　　　　　　♥ 체력을 한 칸 얻어요!　　　　　　　　　　　　　　　　　　◇◇◇◇◇◇◇◇\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 　　　　　◇　　　　　　◇\n");
	printf("　　　　　　　　　　　　　　　밟으면 더 높게 올라갈 수 있어요!　　　　　　　　　 체력을 잃어요...　　　　　　　　　　　　　　　　　　　　◇　　　　　　◇\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 ◇　　　　　　◇\n");
	printf("　　　　　　　　　　　　　　　밟으면 사라져요!　　　　　　　　　　　　　　　　Ø 마인부우의 일당들의 시간을 멈춰요!　　　　　　　　　　　◇　　　　　　◇\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 　◇　　　　　　◇\n");
	printf("　　　　　　　　　　　　　　　보일 때만 밟을 수 있어요　　　　　　　　　　　　⇔ 특별한 구름들의 종류가 바뀌어요!　　　　　　　　　　　　◇◇◇◇◇◇◇◇\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　밟으면 체력을 잃어요...　　　　　　　　　　　　 ♂ 세이프티존으로 순간이동해요!　　　　　　　　　　　　　　　↑이 구역에 들어가면\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 　마인부우 일당들이 주인공을 보지 못해요!!\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　*** Press enter to go back main menu ***\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	SetCurrentCursorPos(18, 36);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("◎◎◎◎◎");
	SetCurrentCursorPos(18, 38);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("◎◎◎◎◎");
	SetCurrentCursorPos(18, 40);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("◎◎◎◎◎");
	SetCurrentCursorPos(18, 42);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("▲▲▲▲▲");
	SetCurrentCursorPos(78, 36);
	printf("▼");
	SetCurrentCursorPos(108, 24);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("●");
	SetCurrentCursorPos(108, 26);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("★");
	SetCurrentCursorPos(28, 27);
	printf("●");
	SetCurrentCursorPos(28, 28);
	printf("■");
	SetCurrentCursorPos(28, 29);
	printf("▲");
	SetCurrentCursorPos(66, 28);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("●");
	SetCurrentCursorPos(66, 29);
	printf("▼");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	while (1) {
		for (int i = 0; i < 50; i++) {
			if (_kbhit() != 0) {
				int key;
				key = _getch();
				switch (key) {
				case ENTER:
					SetCurrentCursorPos(0, 0);
					for (int i = 1; i <= 49; i++) {
						printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
						Sleep(10);
					}
					printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
					return;
				}
			}
			if (i < 25) {
				SetCurrentCursorPos(18, 40);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf("◎◎◎◎◎");
			}
			else {
				SetCurrentCursorPos(18, 40);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("　　　　　");
			}
			Sleep(10);
		}
	}
}

void printEndScreen() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	int i = 0;
	SetCurrentCursorPos(5, 7);
	printf("	□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("	□□□□■■■■■■□□□□□□■■■□□□□□■□□□□□□□■□□■■■■■■■□□□□□□□□□□□□□□□□\n");
	printf("	□□□■□□□□□□■□□□□■□□□■□□□□■■□□□□□■■□□■□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("	□□□■□□□□□□□□□□■□□□□□■□□□■□■□□□■□■□□■□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("	□□□■□□□□■■■□□■□□□□□□□■□□■□□■□■□□■□□■■■■■■■□□□□□□□□□□□□□□□□\n");
	printf("	□□□■□□□□□□■□□■■■■■■■■■□□■□□□■□□□■□□■□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("	□□□■□□□□□□■□□■□□□□□□□■□□■□□□□□□□■□□■□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("	□□□□■■■■■■□□□■□□□□□□□■□□■□□□□□□□■□□■■■■■■■□□□□□□□□□□□□□□□□\n");
	printf("	□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

	printf("	□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("	□□□□□□□□□□□□□□□□□□□□□□□□■■■□□□□■□□□□□■□□■■■■■■□□■■■■■□□□□□\n");
	printf("	□□□□□□□□□□□□□□□□□□□□□□□■□□□■□□□■□□□□□■□□■□□□□□□□■□□□□■□□□□\n");
	printf("	□□□□□□□□□□□□□□□□□□□□□□■□□□□□■□□■□□□□□■□□■□□□□□□□■□□□□■□□□□\n");
	printf("	□□□□□□□□□□□□□□□□□□□□□□■□□□□□■□□□■□□□■□□□■■■■■■□□■■■■■□□□□□\n");
	printf("	□□□□□□□□□□□□□□□□□□□□□□■□□□□□■□□□■□□□■□□□■□□□□□□□■□□■□□□□□□\n");
	printf("	□□□□□□□□□□□□□□□□□□□□□□□■□□□■□□□□□■□■□□□□■□□□□□□□■□□□■□□□□□\n");
	printf("	□□□□□□□□□□□□□□□□□□□□□□□□■■■□□□□□□□■□□□□□■■■■■■□□■□□□□■□□□□\n");
	printf("	□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("\n\n\n\n");
	printf("						PRESS ENTER TO GO OVER");
	while (1)
		for (int i = 0; i < 50; i++) {
			if (_kbhit() != 0) {
				int key;
				key = _getch();
				switch (key) {
				case ENTER:

					return;
				}
			}
		}
}

void gameClearScreen(void) {
	int i = 0;
	for (int i = 1; i <= 49; i++) {
		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		Sleep(10);
	}
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	SetCurrentCursorPos(0, 0);
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　■■■■■■■■　　■　　　　　　　　　　■　　　　　　　　　　　　　　　■■■■■■■■■　■■■■■■■■■■　　■■■■■■■■　　　■■■■■■■■　　■■■■■■■■■■　　　　　\n");
	printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
	printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
	printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
	printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　\n");
	printf("　　　　■■■■■■■■■■　■　　　　　　　　　　■　　　　　　　　　　　　　　　■■■■■■■■　　　　　　■　　　　　　■■■■■■■■■■　■　　　　　　　　　　■■■■■■■■■■　　　　　\n");
	printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　■　　　　　　　　■　■　　　　■■■■■　■　　　　　　　　　　　　　　\n");
	printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
	printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
	printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
	printf("　　　　■　　　　　　　　■　■■■■■■■■■■　■■■■■■■■■■　　　　　■■■■■■■■■　　　　　　■　　　　　　■　　　　　　　　■　　■■■■■■■■　　■■■■■■■■■■　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■　　■　　　　　　　　　　■■■■■■■■■■　　■■■■■■■■　　■■■■■■■■■　　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■■■■■■■■■■　■■■■■■■■■■　■■■■■■■■■　　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　■　　　　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　■　　　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　■　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■　　■■■■■■■■■■　■■■■■■■■■■　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	SetCurrentCursorPos(86, 48);
	printf("Press enter to return to main menu");
	while (1) {
		for (int j = 0; j < 20; j++) {
			if (_kbhit() != 0) {
				int key;
				key = _getch();
				switch (key) {
				case 13:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

					return 0;
				}
			}
			Sleep(10);
			if (j == 10) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 15);
				SetCurrentCursorPos(0, 2);
				printf("　　　　　■■■■■■■■　　■　　　　　　　　　　■　　　　　　　　　　　　　　　■■■■■■■■■　■■■■■■■■■■　　■■■■■■■■　　　■■■■■■■■　　■■■■■■■■■■　　　　　\n");
				printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
				printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
				printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
				printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　　　　　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　\n");
				printf("　　　　■■■■■■■■■■　■　　　　　　　　　　■　　　　　　　　　　　　　　　■■■■■■■■　　　　　　■　　　　　　■■■■■■■■■■　■　　　　　　　　　　■■■■■■■■■■　　　　　\n");
				printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　■　　　　　　　　■　■　　　　■■■■■　■　　　　　　　　　　　　　　\n");
				printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
				printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
				printf("　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　■　　　　　　　　■　■　　　　　　　　■　■　　　　　　　　　　　　　　\n");
				printf("　　　　■　　　　　　　　■　■■■■■■■■■■　■■■■■■■■■■　　　　　■■■■■■■■■　　　　　　■　　　　　　■　　　　　　　　■　　■■■■■■■■　　■■■■■■■■■■　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■　　■　　　　　　　　　　■■■■■■■■■■　　■■■■■■■■　　■■■■■■■■■　　　■■　　■■　　■■　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■■■■■■■■■■　■■■■■■■■■■　■■■■■■■■■　　　■■　　■■　　■■　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　■　　　　　■■　　■■　　■■　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　■　　　　■■　　■■　　■■　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　■　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　　　■　　　　　　　　　　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■　　■■■■■■■■■■　■■■■■■■■■■　■　　　　　　　　■　■　　　　　　　　■　　■■　　■■　　■■　　　　");
				SetCurrentCursorPos(i * 4, 32);
				printf("　　　　　　■■■■■　　　　　　　");
				SetCurrentCursorPos(i * 4, 33);
				printf("　　　　　■　　　　　■　　　　　　");
				SetCurrentCursorPos(i * 4, 34);
				printf("　　　　　■　　　　　■　　　　　　");
				SetCurrentCursorPos(i * 4, 35);
				printf("　　　　　■　　　　　■　　　　　　");
				SetCurrentCursorPos(i * 4, 36);
				printf("　　　■　　■■■■■　　■　　　　");
				SetCurrentCursorPos(i * 4, 37);
				printf("　　　　■　　　■　　　■　　　　　");
				SetCurrentCursorPos(i * 4, 38);
				printf("　　　　　■■■■■■■　　　　　　");
				SetCurrentCursorPos(i * 4, 39);
				printf("　　　　　　　　■　　　　　　　　　");
				SetCurrentCursorPos(i * 4, 40);
				printf("　　　　　　　　■　　　　　　　　　");
				SetCurrentCursorPos(i * 4, 41);
				printf("　　　　　　　■■■　　　　　　　　");
				SetCurrentCursorPos(i * 4, 42);
				printf("　　　　　　■　　　■　　　　　　　");
				SetCurrentCursorPos(i * 4, 43);
				printf("　　　　　■　　　　　■　　　　　　");
				SetCurrentCursorPos(i * 4, 44);
				printf("　　　　■　　　　　　　■　　　　　");
				SetCurrentCursorPos(i * 4, 45);
				printf("　　　　　　　　　　　　　　　　　　");
				i++;
				if (i == 50) i = 0;
			}
		}
	}
}