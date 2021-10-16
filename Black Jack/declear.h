#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#pragma once

#ifndef DECLEAR_H
#define DECLEAR_H

void login();
void playerDrawCard();
void houseDrawCard();
void checkWin();
void resetVariables();
void clearcin();

std::string username;
bool checkUsername = false;
std::string password;
bool checkPassword = false;
int tryAgain;
bool end = false;

std::string playerAnswer;
int firstCard = 0;
int card = 0;
int newPoint = 0;
int points = 0;
int playerMoney = 100;
int playerBet = 0;

int houseFirstCard = 0;
int houseCard = 0;
int houseNewPoint = 0;
int housePoints = 0;
int houseMoney = 100;
int houseBet = 0;

#endif // !DECLEAR
