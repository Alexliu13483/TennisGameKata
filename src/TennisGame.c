/*
 * TennisGame.c
 *
 *  Created on: 2023年5月8日
 *      Author: alex.liu
 */

#include <string.h>

static char strScore[32];
static int player1_points = 0;
static int player2_points = 0;
static char * strPointScore[] = {
			"Love", "Fifteen", "Thirty", "Forty"
		};

static void points2scoretxt()
{
	char strSeg1[16];
	char strSeg2[16];

	if (player1_points < 3 && player2_points < 3) {
		strcpy(strSeg1, strPointScore[player1_points]);
		strcpy(strSeg2, strPointScore[player2_points]);
		strcpy(strScore, strSeg1);
		strcat(strScore, "-");
		if (player1_points == player2_points)
			strcat(strScore, "All");
		else
			strcat(strScore, strSeg2);
	}
}

void TennisGame_init()
{
	player1_points = 0;
	player2_points = 0;
	strcpy(strScore, "Love-All");
}

void TennisGame_wonPoint(const char * player)
{
	if (!strcmp(player, "player1"))
		player1_points++;
	else if (!strcmp(player, "player2"))
		player2_points++;
}

char * TennisGame_getScore()
{
	points2scoretxt();

	return strScore;
}

