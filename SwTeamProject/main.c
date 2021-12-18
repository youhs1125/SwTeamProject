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
		//½ÃÀÛÈ­¸é 
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
	//½ÃÀÛÈ­¸é 
	int difficulty = printStartScreen();
	player p;
	DragonBall dgball[3][3];
	StageDoor stageDoor[3];
	cloud sCloud[5];

	NPC* npcArr;
	int npcNum = 1;

	npcArr = (NPC*)malloc(sizeof(NPC) * 3);

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

	for (int i = 0; i < 5; i++)			//±¸¸§ Ãâ·Â
		drawSpecialCloud(&sCloud[i], stageArr[p.stageNum]);

	zone z;
	InitZone(&z);
	safeZone(&z, p.stageNum, stageArr[p.stageNum]);
	printZone(&z, p.stageNum);
	



	//¾ÆÀÌÅÛ °ü·Ã
	int speed1 = 1, speed2 = 5;

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



		//ÇÃ·¹ÀÌ¾î ÀÌµ¿

		jumpFlag = playerJump(&p, &jump, stageArr[p.stageNum]);
		count++;


		if (jumpFlag == 1) //Á¡ÇÁ ¿Ï·á ÈÄ ÀçÁ¡ÇÁ 
		{
			jump = collSpecialCloud(sCloud, &p, stageArr[p.stageNum]);
		}
		else if (jumpFlag == -1) //Ãß¶ôÇÑ °æ¿ì
		{
			//npc »èÁ¦ÇØÁÖ°í À§Ä¡ Àç¼³Á¤
			//deleteNpc(&npcArr, stageArr[p.stageNum]);
			/*npc.x = 1; npc.y = 1*/;


			//ÇÃ·¹ÀÌ¾î »èÁ¦ and À§Ä¡ Àç¼³Á¤ and ±â·Ïº¯°æ
			respawnPlayer(&p, stageArr[p.stageNum],difficulty,&npcArr,&npcNum);

			//?Œë ˆ?´ì–´ ?? œ and ?„ì¹˜ ?¬ì„¤??and ê¸°ë¡ë³€ê²?
			UpdateRecord(&p);
		}

		//µå·¡°ïº¼ and ½ºÅ×ÀÌÁö Á¾·á È®ÀÎ
		if (dragonBallGet(&p, dgball[p.stageNum], stageArr[p.stageNum]) == 1) //µå·¡°ïº¼ À§Ä¡¿Í ÇÃ·¹ÀÌ¾î À§Ä¡ ºñ±³ ÈÄ Á¤º¸ ¾÷µ¥ÀÌÆ®
			UpdateRecord(&p);
		if (checkStageDoor(&p, stageDoor, p.stageNum)) { //µå·¡°ïº¼ ÀüºÎ ¸ðÀ¸°í and ¹® ¾Õ¿¡ ¼­ ÀÖÀ¸¸é ´ÙÀ½ ½ºÅ×ÀÌÁö·Î ÀÌµ¿
			//¸¶Áö¸· ½ºÅ×ÀÌÁö Åë°úÇÏ¸é °ÔÀÓ ³¡³»±â
			if (p.stageNum == 2) {
				gameClearScreen();
				return;
			}
			p.stageNum++;
			nextStageEffect(p.stageNum);
			gotoNextStage(&p, dgball, stageDoor, stageArr[p.stageNum]);
			initSpecialCloud(sCloud, 5, dgball[p.stageNum]);
			for (int i = 0; i < 5; i++)			//±¸¸§ Ãâ·Â
				drawSpecialCloud(&sCloud[i], stageArr[p.stageNum]);
			InititemBox(speed1, speed2);
			initNPC(npcArr, difficulty, p.stageNum, &npcNum);
			safeZone(&z, p.stageNum, stageArr[p.stageNum]);
			printZone(&z, p.stageNum);
			p.x = p.spawnPos[p.stageNum][0];
			p.y = p.spawnPos[p.stageNum][1];
		}

		processKeyInput(&p, stageArr[p.stageNum]);


//		ÇÃ·¹ÀÌ¾î ¿òÁ÷ÀÎ ÈÄ npcÀÌµ¿ ½ÃÀÛ
//		ÃßÀû ¾Ë°í¸®Áò ½ÃÀÛ
		for (int i = 0; i < npcNum; i++) {
			addNpcCnt(&npcArr[i]);
			int dis = min(getDistance(p.x - npcArr[i].x, p.y - npcArr[i].y), getDistance(p.x - npcArr[i].x, p.y + 1 - npcArr[i].y)); //Ä³¸¯ÅÍ¿Í npc»çÀÌÀÇ °Å¸®
			dis = min(dis, getDistance(p.x - npcArr[i].x, p.y + 2 - npcArr[i].y));
			if (dis == 0) {  //ÃÖ¼Ò °Å¸® ·çÆ®2 ÀÌÇÏÀÌ¸é ³¡³»±â.
				deleteNpc(&npcArr[i], stageArr[p.stageNum]);
				deletePlayer(&p, stageArr[p.stageNum]);
				respawnPlayer(&p, stageArr[p.stageNum],difficulty,&npcArr,&npcNum);
			}
			if (npcArr[i].cnt % npcArr[i].npcSpeed == 0) {
				deleteNpc(&npcArr[i], stageArr[p.stageNum]);
				updateNpcPos(&z, &p, &npcArr[i]);
				drawNpc(&npcArr[i]);
			}
			else {
				deleteNpc(&npcArr[i], stageArr[p.stageNum]);
				drawNpc(&npcArr[i]);
			}
		}


		//Ä³¸¯ÅÍ, npc ÀÌÈÄ ¾ÆÀÌÅÛ
		Fallitem(&p, stageArr[p.stageNum], npcArr, sCloud, 5, &z, difficulty, &npcNum);

	}
	system("cls");
	printEndScreen();
}