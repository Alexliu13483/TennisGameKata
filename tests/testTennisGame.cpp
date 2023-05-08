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
#include "TennisGame.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(testTennisGame)
{

    void setup()
    {
    	TennisGame_init();
    }

    void teardown()
    {

    }

};

TEST(testTennisGame, test_wrong_player)
{
	char expect[] = "Love-All";

	TennisGame_wonPoint("player3");

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
