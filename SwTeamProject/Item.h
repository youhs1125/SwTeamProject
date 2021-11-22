
#include "Common.h"


typedef struct item {
	int x;
	int y;
	int flag;       //0,1로 상태 표시 화면에 표시 or 표시x
	int life;       //턴제 형식 대기시간
	int speed;      //개별 문자의 떨어지는 속도
	int itemNum;    //원하는 아이템 넘버
	int check;   //처음 충돌하면 1로 바꿔서 다음 턴부터 지워지도록(안보이도록)
}item;

//아이템 발생 빈도와 속도 달라지도록 설정하자!

void InititemBox(item* item);
void CreateItem(item* item, int speed1, int speed2);
void showItem(int num);
void Fallitem(item* item, player *p);
int Detectitem(item* item, player* p);
void useitem(player* p);


