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
static const char * player_name[2];

/* Original version
static void points2scoretxt()
{
	char strSeg1[16];
	char strSeg2[16];

	if (player1_points <= 3 && player2_points <= 3) {
		strcpy(strSeg1, strPointScore[player1_points]);
		strcpy(strSeg2, strPointScore[player2_points]);
		strcpy(strScore, strSeg1);
		strcat(strScore, "-");
		if (player1_points == player2_points) {
			if (player1_points < 3)
				strcat(strScore, "All");
			else
				strcpy(strScore, "Deuce");
		} else
			strcat(strScore, strSeg2);
	} else if (player1_points == player2_points) {
		strcpy(strScore, "Deuce");
	} else if (player1_points - player2_points == 1) {
		strcpy(strScore, "Advantage player1");
	} else if (player2_points - player1_points == 1) {
		strcpy(strScore, "Advantage player2");
	} else if (player1_points - player2_points >= 2) {
		strcpy(strScore, "Win for player1");
	} else if (player2_points - player1_points >= 2) {
		strcpy(strScore, "Win for player2");
	}
}
*/

// Refactored Rev.0.1
static void points2scoretxt()
{
	char strSeg1[16];
	char strSeg2[16];

	if (player1_points <= 3 && player2_points <= 3) {
		strcpy(strSeg1, strPointScore[player1_points]);
		strcpy(strSeg2, strPointScore[player2_points]);
		strcpy(strScore, strSeg1);
		strcat(strScore, "-");
		if (player1_points == player2_points) {
			if (player1_points < 3)
				strcat(strScore, "All");
			else
				strcpy(strScore, "Deuce");
		} else
			strcat(strScore, strSeg2);
	} else if (player1_points == player2_points) {
		strcpy(strScore, "Deuce");
	} else {
		int diff = player1_points - player2_points;
		if (diff == 1)
			strcpy(strScore, "Advantage player1");
		else if (diff == -1)
			strcpy(strScore, "Advantage player2");
		else if (diff >= 2)
			strcpy(strScore, "Win for player1");
		else if (diff <= -2)
			strcpy(strScore, "Win for player2");
	}
}

void TennisGame_init(const char * player1, const char * player2)
{
	player1_points = 0;
	player2_points = 0;
	strScore[0] = '\0';
	player_name[0] = player1;
	player_name[1] = player2;
}

int TennisGame_wonPoint(const char * player)
{
	int err = 0;

	if (!strcmp(player, player_name[0]))
		player1_points++;
	else if (!strcmp(player, player_name[1]))
		player2_points++;
	else
		err = -1;

	return err;
}

char * TennisGame_getScore()
{
	points2scoretxt();

	return strScore;
}

