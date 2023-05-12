/*
 * testTennisGame.cpp
 *
 *  Created on: 2023年5月6日
 *      Author: Alex
 */

/* Useful CppUTest Assert Functions
 * 	STRCMP_EQUAL(expect, result);
 * 	LONGS_EQUAL(expect, result);
 * 	BYTES_EQUAL(expect, result);
 * 	POINTERS_EQUAL(expect, result);
 *  DOUBLES_EQUAL(expected,actual,threshold);
 */



extern "C"
{
#include <stdio.h>
#include "TennisGame.h"
}

#include "CppUTest/TestHarness.h"

struct Parameter
{
    int player1Score;
    int player2Score;
    const char* expectedScore;
};

TEST_GROUP(testTennisGame)
{

    void setup()
    {
    	TennisGame_init("player1", "player2");
    }

    void teardown()
    {

    }

    void one_game(int player1, int player2, const char * expect) {
    	char strError[80];
    	int p1 = player1;
    	int p2 = player2;
    	char p1_name[] = "Player1";
    	char p2_name[] = "Player2";

    	TennisGame_init(p1_name, p2_name);
    	while (p1 > 0 || p2 > 0) {
    		if (p1 > 0) {
    			TennisGame_wonPoint(p1_name);
    			p1--;
    		}

    		if (p2 > 0) {
    			TennisGame_wonPoint(p2_name);
    			p2--;
    		}
    	}

    	sprintf(strError, "Player1: %i, Player2: %i, the score is incorrect!!!\n", player1, player2);
    	STRCMP_EQUAL_TEXT(expect, TennisGame_getScore(), strError);
    }
};

TEST(testTennisGame, test_multi_games)
{
    struct Parameter param[] = {
    		{ 0, 0, "Love-All" },
			{ 1, 1, "Fifteen-All" },
			{ 2, 2, "Thirty-All" },
			{ 3, 3, "Deuce" },
			{ 4, 4, "Deuce" },
			{ 1, 0, "Fifteen-Love" },
			{ 0, 1, "Love-Fifteen" },
			{ 2, 0, "Thirty-Love" },
			{ 0, 2, "Love-Thirty" },
			{ 3, 0, "Forty-Love" },
			{ 0, 3, "Love-Forty" },
			{ 4, 0, "Win for player1" },
			{ 0, 4, "Win for player2" },
			{ 2, 1, "Thirty-Fifteen" },
			{ 1, 2, "Fifteen-Thirty" },
			{ 3, 1, "Forty-Fifteen" },
			{ 1, 3, "Fifteen-Forty" },
			{ 4, 1, "Win for player1" },
			{ 1, 4, "Win for player2" },
			{ 3, 2, "Forty-Thirty" },
			{ 2, 3, "Thirty-Forty" },
			{ 4, 2, "Win for player1" },
			{ 2, 4, "Win for player2" },
			{ 4, 3, "Advantage player1" },
			{ 3, 4, "Advantage player2" },
			{ 5, 4, "Advantage player1" },
			{ 4, 5, "Advantage player2" },
			{ 15, 14, "Advantage player1" },
			{ 14, 15, "Advantage player2" },
			{ 6, 4, "Win for player1" },
			{ 4, 6, "Win for player2" },
			{ 16, 14, "Win for player1" },
			{ 14, 16, "Win for player2" }, };

    for (int i = 0; i < (int)(sizeof(param) / sizeof(param[0])); i++) {
    	one_game(param[i].player1Score, param[i].player2Score, param[i].expectedScore);
    }
}

TEST(testTennisGame, test_win_for_player2)
{
	char expect[] = "Win for player2";

	one_game(4, 6, expect);
}

TEST(testTennisGame, test_win_for_player1)
{
	char expect[] = "Win for player1";

	one_game(6, 4, expect);
}

TEST(testTennisGame, test_advantage_player2)
{
	char expect[] = "Advantage player2";

	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");

	STRCMP_EQUAL(expect, TennisGame_getScore());
}

TEST(testTennisGame, test_advantage_player1)
{
	char expect[] = "Advantage player1";

	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player1");

	STRCMP_EQUAL(expect, TennisGame_getScore());
}

TEST(testTennisGame, test_4_4)
{
	char expect[] = "Deuce";

	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player1");

	STRCMP_EQUAL(expect, TennisGame_getScore());
}

TEST(testTennisGame, test_3_3)
{
	char expect[] = "Deuce";

	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");

	STRCMP_EQUAL(expect, TennisGame_getScore());
}

TEST(testTennisGame, test_wrong_player)
{
	char expect[] = "Love-All";

	LONGS_EQUAL( -1, TennisGame_wonPoint("player3"));

	STRCMP_EQUAL(expect, TennisGame_getScore());
}

TEST(testTennisGame, test_1_2)
{
	char expect[] = "Fifteen-Thirty";

	TennisGame_wonPoint("player1");
	TennisGame_wonPoint("player2");
	TennisGame_wonPoint("player2");

	STRCMP_EQUAL(expect, TennisGame_getScore());
}

TEST(testTennisGame, test_1_0)
{
	char expect[] = "Fifteen-Love";

	TennisGame_wonPoint("player1");

	STRCMP_EQUAL(expect, TennisGame_getScore());
}

TEST(testTennisGame, init_test)
{
	char expect[] = "Love-All";

	STRCMP_EQUAL(expect, TennisGame_getScore());
}
