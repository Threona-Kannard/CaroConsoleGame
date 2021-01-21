#ifndef _CARO_H_
#define _CARO_H_

#include <cctype>
#include <ctime>
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

void display_splash();
void initialize(int argc, char** argv);
void gotoxy(int x, int y);
void TestColor(int x);
void Rewrite(int check[100][100], int k, int j, int& color);
void Board(int& sized, int& color, int check[100][100]);
int win(int x, int y, int check[100][100], int& mode);
void gameplay(string m, string n, int turn, int x, int y, int& color, int& sized, int check[100][100], int& mode, int find[100][100], int minimax[100][100], int Cgame, int Cscore);
void resetBoard(int check[100][100]);
void loadgame(int &turn2, int &coord_x, int &coord_y, string player1, string player2, int& color, int& sized, int check[100][100], int slot, int Mode, int Cgame, int Cscore);
void PvP(int check[100][100], int& color, int& sized, string player1, string player2, int& mode, int find[100][100], int minimax[100][100], int Cgame, int Cscore);
void Findopp(int x, int y, int check[100][100], int find[100][100]);
void evaluation(int x, int y, int check[100][100], int minimax[100][100]);
void chance(int &j2, int &i2, int find[100][100], int minimax[100][100], int check[100][100]);
void PlayervsCom(int check[100][100], int& color, int& sized, int& mode, int x, int y, int turn, int find[100][100], int minimax[100][100], int Cgame, int Cscore, string player1);
void PvC(int check[100][100], int&color, int& sized, string player, int& mode, int x, int y, int turn, int find[100][100], int minimax[100][100], int Cgame, int Cscore);
void Playerranking(int Cgame, int Cscore, string player);
void Playerstatistic();
void Option(int& sized, int& color, string player1, string player2, int check[100][100], int& mode, int find[100][100], int minimax[100][100], int Cgame, int Cscore);
void Menu(int& sized, int& color, string player1, string player2, int check[100][100], int& mode, int find[100][100], int minimax[100][100], int Cgame, int Cscore);

#endif
