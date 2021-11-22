
#include <stdio.h>
#include <time.h>
#include <windows.h>


#include "Common.h"
#include "item.h"
#include "NpcTrack.h"
#include "characters.h"

#define MAX 50      // 아이템 최대 갯수

//아이템 박스 초기화
void InititemBox(item* item)   
{
	for (int i = 0; i < MAX; i++)
	{
		item[i].flag = 0;   //초기화 당시 아이템 위치는 보여지면 안됨
		item[i].check = 0;
	}
}

//매 반복문마다 아이템 생성 (총 50개가 끝)
void CreateItem(item* item, int speed1, int speed2)
{
	srand(time(NULL));   //위치 랜덤 생성 위해서
	for (int i = 0; i < MAX; i++)   //MAX_X 아이템 개수 아직 미정
	{
		if (item[i].flag == 0)  //아직 해당 인덱스에 아이템이 없으면
		{
			item[i].x = (rand() % (stage1X-OriginX)*2) + OriginX*2;   //x좌표는 스테이지 상 0~40
			item[i].y = OriginY + 1;
			item[i].itemNum = rand() % 5;   //일단 0~4의 값 부여 아이템 뭐 줄지 생각해야함
			item[i].life = rand() % 10;   // 대기시간
			item[i].speed = rand() % (speed2 - speed1) + speed1;   //개별 스피드 부여
			item[i].flag = 1;
			return;
		}
	}
}

//아이템과 플레이어 충돌 감지
int Detectitem(item *item, player* p)    
{
	for (int i = 0; i < MAX; i++)
	{
		int posX = OriginX + p->x * 2;
		int posY = OriginY + p->y;
		int itemX = OriginX + item[i].x * 2;
		int itemY = OriginY + item[i].y;
		//int dis = getDistance(p->x - item[i].x, p->y - item[i].y);
		int dis = getDistance(posX - itemX, posY - itemY);
		if (dis < 4)
		{
			return 1;
		}
		else return 0;
	}
}

//아이템 떨어짐
void Fallitem(item* item, player* p)
{
	for (int i = 0; i < MAX; i++)
	{
		if (item[i].flag == 1 && item[i].check == 0)   //해당 인덱스에 아이템 있으면 움직임 실행
		{
			if (--item[i].life == 0 && item[i].check == 0)    //현재 아이템 인덱스의 대기시간 턴제로 줄이면서 자신의 순서 기다림
			{
				int detect = Detectitem(item, p);
				if (detect == 1)  //충돌
				{    //왜 충돌 탐지를 못하지?
					//아이템마다의 기능 구현 함수 나중에 추가
					item[i].flag = 0;
					SetCurrentCursorPos(item[i].x, item[i].y);
					printf("  ");
					item[i].check = 1;
					return;
				}



				//대기시간 끝났으면 자신의 스피드만큼 
				item[i].life = item[i].speed;    //speed라는게 결국 턴제. 작을 수록 떨어지는 속도 빨라보임

				SetCurrentCursorPos(item[i].x, item[i].y);
				printf("  ");   //먼저 지워주고

				
				SetCurrentCursorPos(item[i].x, ++item[i].y); //한칸 이동 후 출력
				showItem(item[i].itemNum);
				
				if (item[i].y >= OriginY + stage1Y - 2)   //최대 세로 거리 임시 지정
				{    //최대 거리까지 갔다면 지워주고 flag check 수정
					SetCurrentCursorPos(item[i].x, item[i].y);
					printf("  ");
					item[i].flag = 0;  //다시 화면표시x로 지정
					item[i].check = 1;
				}
			}
		}
	}
}





void showItem(int num)
{
	if (num == 0)
	{
		printf("☎");
	}
	else if (num == 1)
	{
		printf("♣");
	}
	else if (num == 2)
	{
		printf("♪");
	}
	else if (num == 3)
	{
		printf("＠");
	}
	else if (num == 4)
	{
		printf("♨");
	}
}





