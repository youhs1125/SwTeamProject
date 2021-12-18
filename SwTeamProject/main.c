#include "Common.h"

#include "StageArr.h"
#include "DragonBall.h"
#include "NpcTrack.h"
#include "NextStage.h"
#include "StartScreen.h"
#include "cloud.h"
#include "Item.h"

void gameStart(void);

int main()
{
	int tmpStageArr[3][40][60];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 40; j++)
			for (int k = 0; k < 60; k++)
				tmpStageArr[i][j][k] = stageArr[i][j][k];
	initCmd();
	while (1) {
		system("cls");
		//?œìž‘?”ë©´ 
		gameStart();
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 40; j++)
				for (int k = 0; k < 60; k++)
					stageArr[i][j][k] = tmpStageArr[i][j][k];
	}

	return 0;
}

void gameStart(void) {
	initCmd();
	//?œìž‘?”ë©´ 
	int difficulty = printStartScreen();
	player p;
	DragonBall dgball[3][3];
	StageDoor stageDoor[3];
	cloud sCloud[5];

	NPC *npcArr;
	npcArr = (NPC*)malloc(sizeof(NPC) * 3);
	int npcNum = 1;

	srand((unsigned int)time(NULL));

	int jump = JUMPHEIGHT;
	int gameFlag = 1;
	int jumpFlag = 0;
	int count = 0;

	initPlayer(&p);
	nextStageEffect(p.stageNum);
	printStage();
	
	initNPC(npcArr, difficulty, p.stageNum, &npcNum);
	setDragonBallPos(dgball);

	initSpecialCloud(sCloud, 5, dgball[p.stageNum]);

	printCloud(stageArr[p.stageNum], dgball[p.stageNum]);
	drawPlayer(&p);
	UpdateRecord(&p);


	setStageDoor(stageDoor);
	printStageDoor(stageDoor, stageArr[p.stageNum], p.stageNum);

	for (int i = 0; i < 5; i++)			//êµ¬ë¦„ ì¶œë ¥
		drawSpecialCloud(&sCloud[i], stageArr[p.stageNum]);

	zone z;
	InitZone(&z);
	safeZone(&z, p.stageNum, stageArr[p.stageNum]);
	printZone(&z, p.stageNum);
	



	//?„ì´??ê´€??	int speed1 = 1, speed2 = 5;

	item item[50];
	InititemBox(speed1, speed2);

	while (1)
	{
		if (isGameOver(&p))
			break;

		if (count % 5 == 0)
		{
			for (int i = 0; i < 5; i++)
			{
				deleteSpecialCloud(&sCloud[i], stageArr[p.stageNum]);
			}

			for (int i = 0; i < 5; i++)
				moveCloud(&sCloud[i], stageArr[p.stageNum]);
			
			for (int i = 0; i < 5; i++) {
				drawSpecialCloud(&sCloud[i], stageArr[p.stageNum]);
			}
		}



		//?Œë ˆ?´ì–´ ?´ë™

		jumpFlag = playerJump(&p, &jump, stageArr[p.stageNum]);
		count++;


		if (jumpFlag == 1) //?í”„ ?„ë£Œ ???¬ì ??
		{
			jump = collSpecialCloud(sCloud, &p, stageArr[p.stageNum]);
		}
		else if (jumpFlag == -1) //ì¶”ë½??ê²½ìš°
		{
			//npc ?? œ?´ì£¼ê³??„ì¹˜ ?¬ì„¤??			//deleteNpc(&npcArr, stageArr[p.stageNum]);
			/*npc.x = 1; npc.y = 1*/;

			//?Œë ˆ?´ì–´ ?? œ and ?„ì¹˜ ?¬ì„¤??and ê¸°ë¡ë³€ê²?			respawnPlayer(&p, stageArr[p.stageNum]);
			UpdateRecord(&p);
		}
			respawnPlayer(&p, stageArr[p.stageNum],difficulty,&npcArr,&npcNum);
		//?œëž˜ê³¤ë³¼ and ?¤í…Œ?´ì? ì¢…ë£Œ ?•ì¸
		if (dragonBallGet(&p, dgball[p.stageNum], stageArr[p.stageNum]) == 1) //?œëž˜ê³¤ë³¼ ?„ì¹˜?€ ?Œë ˆ?´ì–´ ?„ì¹˜ ë¹„êµ ???•ë³´ ?…ë°?´íŠ¸
			UpdateRecord(&p);
		if (checkStageDoor(&p, stageDoor, p.stageNum)) { //?œëž˜ê³¤ë³¼ ?„ë? ëª¨ìœ¼ê³?and ë¬??žì— ???ˆìœ¼ë©??¤ìŒ ?¤í…Œ?´ì?ë¡??´ë™
			//ë§ˆì?ë§??¤í…Œ?´ì? ?µê³¼?˜ë©´ ê²Œìž„ ?ë‚´ê¸?			if (p.stageNum == 2) {
				gameClearScreen();
				return;
			}
			p.stageNum++;
			nextStageEffect(p.stageNum);
			gotoNextStage(&p, dgball, stageDoor, stageArr[p.stageNum]);
			initSpecialCloud(sCloud, 5, dgball[p.stageNum]);
			for (int i = 0; i < 5; i++)			//êµ¬ë¦„ ì¶œë ¥
				drawSpecialCloud(&sCloud[i], stageArr[p.stageNum]);
			InititemBox(speed1, speed2);
			initNPC(npcArr, difficulty, p.stageNum, &npcNum);
			safeZone(&z, p.stageNum, stageArr[p.stageNum]);
			printZone(&z, p.stageNum);
			p.x = p.spawnPos[p.stageNum][0];
			p.y = p.spawnPos[p.stageNum][1];
			npcArr = (NPC*)realloc(npcArr, sizeof(NPC) * npcNum);
		}

		processKeyInput(&p, stageArr[p.stageNum]);


//		?Œë ˆ?´ì–´ ?€ì§ì¸ ??npc?´ë™ ?œìž‘
//		ì¶”ì  ?Œê³ ë¦¬ì¦˜ ?œìž‘
		for (int i = 0; i < npcNum; i++) {
			addNpcCnt(&npcArr[i]);
			int dis = min(getDistance(p.x - npcArr[i].x, p.y - npcArr[i].y), getDistance(p.x - npcArr[i].x, p.y + 1 - npcArr[i].y)); //ìºë¦­?°ì? npc?¬ì´??ê±°ë¦¬
			dis = min(dis, getDistance(p.x - npcArr[i].x, p.y + 2 - npcArr[i].y));
			if (dis == 0) {  //ìµœì†Œ ê±°ë¦¬ ë£¨íŠ¸2 ?´í•˜?´ë©´ ?ë‚´ê¸?
				deleteNpc(&npcArr[i], stageArr[p.stageNum]);
				deletePlayer(&p, stageArr[p.stageNum]);
				respawnPlayer(&p, stageArr[p.stageNum]);
			}
			if (npcArr[i].cnt % npcArr[i].npcSpeed == 0) {
				deleteNpc(&npcArr[i], stageArr[p.stageNum]);
				respawnPlayer(&p, stageArr[p.stageNum], difficulty, &npcArr, &npcNum);
				drawNpc(&npcArr[i]);
			}
			else {
				deleteNpc(&npcArr[i], stageArr[p.stageNum]);
				drawNpc(&npcArr[i]);
			}
		}

		//ìºë¦­?? npc ?´í›„ ?„ì´??		Fallitem(&p, stageArr[p.stageNum], npcArr, sCloud, 5, &z);
		Fallitem(&p, stageArr[p.stageNum], npcArr, sCloud, 5, &z, difficulty, &npcNum);
	}
	system("cls");
	printEndScreen();
}