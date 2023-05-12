/*
 * TennisGame.h
 *
 *  Created on: 2023年5月8日
 *      Author: alex.liu
 */

#ifndef TENNISGAME_H_
#define TENNISGAME_H_

char * TennisGame_getScore();
int TennisGame_wonPoint(const char * player);
void TennisGame_init(const char * player1, const char * player2);

#endif /* TENNISGAME_H_ */
