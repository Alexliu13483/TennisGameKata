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
//#include "<<MODULE_HEAD_FILE>>.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(testTennisGame)
{

    void setup()
    {
    	
    }

    void teardown()
    {

    }

};

TEST(testTennisGame, FirstTest)
{
	FAIL("Start a initial test...");
}
