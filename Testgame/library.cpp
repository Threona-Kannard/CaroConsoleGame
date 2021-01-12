#include "Header.h"

void display_splash()
{
	cout << string(10, '\n');
	cout << "                                 " << (char)201;
	for (int i = 0; i <= 40; i++)
		cout << (char)205;
	cout << (char)187 << endl;
	cout << "                                 " << (char)186 << " ";
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < 7; i++)
			cout << (char)219;
		cout << "   ";
	}
	cout << (char)186 << endl;
	cout << "                                 " << (char)186 << " " << (char)219 << (char)219 << "        ";
	cout << (char)219 << (char)219;
	for (int i = 0; i < 5; i++)
	{
		cout << "   " << (char)219 << (char)219;
	}
	cout << "   " << (char)186 << endl;
	cout << "                                 " << (char)186 << " " << (char)219 << (char)219 << "        ";
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i <= 6; i++)
			cout << (char)219;
		cout << "   ";
	}
	cout << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "   " << (char)186 << endl;
	cout << "                                 " << (char)186 << " ";
	for (int i = 0; i <= 6; i++)
		cout << (char)219;
	for (int i = 0; i < 3; i++)
	{
		cout << "   " << (char)219 << (char)219;
	}
	cout << "  " << (char)219 << (char)219 << (char)220 << "   ";
	for (int i = 0; i <= 6; i++)
		cout << (char)219;
	cout << "   " << (char)186 << endl;
	cout << "                                 " << (char)200;
	for (int i = 0; i <= 40; i++)
		cout << (char)205;
	cout << (char)188;
	cout << string(2, '\n');
}
//--------------------------------------------------------------------
void initialize(int argc, char** argv)
{
	string message = "                                      This game is developed by: \n"
		"                                           Huynh Tan Phat \n"
		"                                           Cao Ngoc Son \n"
		"                                           Ngo Minh Khoi \n"
		"                                           Please wait...";
	cout << message << flush;

	// spin some cycles to pretend that the program is loading resources, etc.
	time_t start = time(&start);
	while (difftime(time(NULL), start) < 5.0 /*seconds*/)
	{
	}

	cout << "\r" << string(message.length(), ' ') << "\r" << flush;
}
//--------------------------------------------------------------------
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
//--------------------------------------------------------------------
void TestColor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
//--------------------------------------------------------------------
void Rewrite(int check[100][100], int k, int j, int& color)
{
	int colorX, colorO;
	if (color == 1)
	{
		colorX = 9;
		colorO = 12;
	}
	else
	{
		colorX = 13;
		colorO = 10;
	}
	if (check[k + 1][j + 1] == 0)
		cout << (char)95;
	else
		if (check[k + 1][j + 1] == 1)
		{
			TestColor(colorX);
			cout << (char)88;
		}
		else
		{
			TestColor(colorO);
			cout << (char)79;
		}
	TestColor(15);
}
//--------------------------------------------------------------------
void Board(int& sized, int& color, int check[100][100])
{
	int m, n;
	if (sized == 1)
	{
		m = 49;
		n = 49;
	}
	else
		if (sized == 2)
		{
			m = 29;
			n = 29;
		}
		else
		{
			m = 19;
			n = 19;
		}
	int j, k;
	cout << (char)201;
	for (int i = 0; i <= 2 * m; i++)
		cout << (char)205;
	cout << (char)187;
	cout << endl;
	for (k = 0; k < n; k++)
	{
		cout << (char)186;

		for (j = 0; j < m; j++)
		{
			Rewrite(check, k, j, color);
			cout << (char)179;
		}
		Rewrite(check, k, j, color);
		cout << (char)186;
		cout << endl;
	}
	cout << (char)186;
	for (int f = 0; f < m; f++)
		cout << " " << (char)179;
	if (check[k + 1][j + 1] == 0) cout << " ";
	if (check[k + 1][j + 1] == 1)
	{
		if (color == 1)
			TestColor(9);
		else
			TestColor(13);
		cout << (char)88;
	}
	if (check[k + 1][j + 1] == -1)
	{
		if (color == 1)
			TestColor(12);
		else
			TestColor(10);
		cout << (char)79;
	}
	cout << (char)186;
	cout << endl;
	cout << (char)200;
	for (int q = 0; q <= 2 * m; q++)
		cout << (char)205;
	cout << (char)188;
	cout << endl;
}
//--------------------------------------------------------------------
int win(int x, int y, int check[100][100], int& mode)
{
	int count[4] = { 1, 1, 1, 1 };
	bool stop[8], block[8];
	for (int i = 0; i < 8; i++)
	{
		stop[i] = false;
		block[i] = false;
	}
	if (mode == 1)
	{
		//Normal rule
		for (int i = 1; i <= 4; i++)
		{
			//Vertical
			if (check[y][x] == check[y + i][x] && !stop[0])
				++count[0];
			else
				if (check[y][x] != check[y + i][x])
					stop[0] = false;
			if (check[y][x] == check[y - i][x] && !stop[1])
				++count[0];
			else
				if (check[y][x] != check[y - i][x])
					stop[1] = false;
			//-------------------------------------------------
			// Horizontal
			if (check[y][x] == check[y][x + i] && !stop[2])
				++count[1];
			else
				if (check[y][x] != check[y][x + i])
					stop[2] = false;
			if (check[y][x] == check[y][x - i] && !stop[3])
				++count[1];
			else
				if (check[y][x] != check[y][x - i])
					stop[3] = false;
			//---------------------------------------------------
			//Crossdown from left to right
			if (check[y][x] == check[y + i][x + i] && !stop[4])
				++count[2];
			else
				if (check[y][x] != check[y + i][x + i])
					stop[4] = false;
			if (check[y][x] == check[y - i][x - i] && !stop[5])
				++count[2];
			else
				if (check[y][x] != check[y - i][x - i])
					stop[5] = false;
			//----------------------------------------------------
			//Crossup from left to right
			if (check[y][x] == check[y + i][x - i] && !stop[6])
				++count[3];
			else
				if (check[y][x] != check[y + i][x - i])
					stop[6] = false;
			if (check[y][x] == check[y - i][x + i] && !stop[7])
				++count[3];
			else
				if (check[y][x] != check[y - i][x + i])
					stop[7] = false;
		}
		for (int i = 0; i < 4; ++i)
		{
			if (count[i] == 5)
				return check[y][x];
		}
	}
	else
	{
		//Two-headed blocking
		for (int i = 1; i <= 4; i++)
		{
			// Vertical
			if (check[y][x] == check[y + i][x] && !stop[0])
				++count[0];
			else
				if (check[y][x] != check[y + i][x])
				{
					if (check[y + 1][x] == -check[y][x])
						block[0] = true;
					stop[0] = false;
				}
			if (check[y][x] == check[y - i][x] && !stop[1])
				++count[0];
			else
				if (check[y][x] != check[y - i][x])
				{
					if (check[y - 1][x] == -check[y][x])
						block[1] = true;
					stop[1] = false;
				}
			//------------------------------------------------
			// Horizontal
			if (check[y][x] == check[y][x + i] && !stop[2])
				++count[1];
			else
				if (check[y][x] != check[y][x + i])
				{
					if (check[y][x + 1] == -check[y][x])
						block[2] = true;
					stop[2] = false;
				}
			if (check[y][x] == check[y][x - i] && !stop[3])
				++count[1];
			else
				if (check[y][x] != check[y][x - i])
				{
					if (check[y][x - 1] == -check[y][x])
						block[3] = true;
					stop[3] = false;
				}
			//---------------------------------------------------
			// Crossdown from left to right
			if (check[y][x] == check[y + i][x + i] && !stop[4])
				++count[2];
			else
				if (check[y][x] != check[y + i][x + i])
				{
					if (check[y + 1][x + 1] == -check[y][x])
						block[4] = true;
					stop[4] = false;
				}
			if (check[y][x] == check[y - i][x - i] && !stop[5])
				++count[2];
			else
				if (check[y][x] != check[y - i][x - i])
				{
					if (check[y - 1][x - 1] == -check[y][x])
						block[5] = true;
					stop[5] = false;
				}
			//-----------------------------------------------------
			// Croosup from left to right
			if (check[y][x] == check[y + i][x - i] && !stop[6])
				++count[3];
			else
				if (check[y][x] != check[y + i][x - i])
				{
					if (check[y + 1][x - 1] == -check[y][x])
						block[6] = true;
					stop[6] = false;
				}
			if (check[y][x] == check[y - i][x + i] && !stop[7])
				++count[3];
			else
				if (check[y][x] != check[y - i][x + i])
				{
					if (check[y - 1][x + 1] == -check[y][x])
						block[7] = true;
					stop[7] = false;
				}
		}
		for (int i = 0; i < 4; ++i)
			if (count[i] == 5 && block[2 * i] == false && block[2 * i - 1] == false)
				return check[y][x];
	}
	return 0;
}
//--------------------------------------------------------------------
void gameplay(string m, string n, int turn, int x, int y, int& color, int& sized, int check[100][100], int& mode, int find[100][100], int minimax[100][100], int Cgame, int Cscore)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos;

	Cursor_an_Pos.X = x;
	Cursor_an_Pos.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);

	while (true) {
		int a = _getch();
		switch (a)
		{
		case 119: // W
			Cursor_an_Pos.Y -= 1;
			break;
		case 97: // A
			Cursor_an_Pos.X -= 2;
			break;
		case 100: // D
			Cursor_an_Pos.X += 2;
			break;
		case 115: // S
			Cursor_an_Pos.Y += 1;
			break;
		case 8: //Backspace
			char q;
			gotoxy(0, 49);
			cout << "Do you want to back to the menu? (Y/N): ";
			cin >> q;
			if (q == 'Y')
			{
				system("cls");
				Menu(sized, color, m, n, check, mode,find, minimax, Cgame, Cscore);
			}
			else
				gotoxy(Cursor_an_Pos.X, Cursor_an_Pos.Y);
			break;
		case 32: //Space
			int slot;
			if (sized == 1)
				gotoxy(0, 52);
			else
				if (sized == 2)
					gotoxy(0, 32);
				else
					gotoxy(0, 22);
			char YN;
			cout << "Do you want to save this game? (Y/N): ";
			cin >> YN;
			if (YN == 'Y')
			{
				system("cls");
				cout << " 1 - Slot 1.\n";
				cout << " 2 - Slot 2.\n";
				cout << " 3 - Slot 3.\n";
				cout << "Enter your choice: ";
				cin >> slot;
			}
			else
				gotoxy(Cursor_an_Pos.X, Cursor_an_Pos.Y);
			if (slot == 1)
			{
				ofstream save1("slot1.txt");
				for (int i = 1; i < 100; i++)
				{
					for (int k = 1; k < 100; k++)
					{
						save1 << check[i][k] << " ";
					}
					save1 << endl;
				}
				save1 << m << endl;
				save1 << n << endl; // Save player name
				save1 << turn << endl;
				save1 << Cursor_an_Pos.X << " " << Cursor_an_Pos.Y << endl;
				save1 << color << endl;
				save1 << sized;
				save1.close();
				cout << "Game saved!" << endl;
				system("pause");
				system("cls");
				Board(sized, color, check);
				gameplay(m, n, turn, x, y, color, sized, check, mode, find, minimax, Cgame, Cscore);
			}
			else
			{
				if (slot == 2)
				{
					ofstream save2("slot2.txt");
					for (int i = 1; i < 100; i++)
					{
						for (int k = 1; k < 100; k++)
						{
							save2 << check[i][k] << " ";
						}
						save2 << endl;
					}
					save2 << m << endl;
					save2 << n << endl; // Save player name
					save2 << turn << endl;
					save2 << Cursor_an_Pos.X << " " << Cursor_an_Pos.Y << endl;
					save2 << color << endl;
					save2 << sized;
					save2.close();
					cout << "Game saved!" << endl;
					system("pause");
					system("cls");
					Board(sized, color, check);
					gameplay(m, n, turn, x, y, color, sized, check, mode, find, minimax, Cgame, Cscore);
				}
				else
				{
					ofstream save3("slot3.txt");
					for (int i = 1; i < 100; i++)
					{
						for (int k = 1; k < 100; k++)
						{
							save3 << check[i][k] << " ";
						}
						save3 << endl;
					}
					save3 << m << endl;
					save3 << n << endl; // Save player name
					save3 << turn << endl;
					save3 << Cursor_an_Pos.X << " " << Cursor_an_Pos.Y << endl;
					save3 << color << endl;
					save3 << sized;
					save3.close();
					cout << "Game saved!" << endl;
					system("pause");
					system("cls");
					Board(sized, color, check);
					gameplay(m, n, turn, x, y, color, sized, check, mode, find, minimax, Cgame, Cscore);
				}
			}
			break;
		}

		y = Cursor_an_Pos.Y;
		x = (Cursor_an_Pos.X - 1) / 2 + 1;
		int colorX, colorO;
		if (color == 1)
		{
			colorX = 9;
			colorO = 12;
		}
		else
		{
			colorX = 13;
			colorO = 10;
		}
		if (a == 13 && check[y][x] == 0)
		{
			if (turn == 1)
			{
				check[y][x] = 1;
				TestColor(colorX);
				cout << (char)88;
			}
			else
			{
				check[y][x] = -1;
				TestColor(colorO);
				cout << (char)79;
			}
			turn = -turn;
		}
		TestColor(15);
		if (win(x, y, check, mode) == 1)
		{
			system("cls");
			cout << m << " Win!!" << endl;
			cout << "Do you want to play again??(Enter Y/N): ";
			char f;
			cin >> f;
			if (f == 'Y')
			{
				system("cls");
				resetBoard(check);
				Board(sized, color, check);
				PvP(check, color, sized, m, n, mode, find, minimax, Cgame, Cscore);
			}
			else
			{
				system("cls");
				resetBoard(check);
				Menu(sized, color, m, n, check, mode, find, minimax, Cgame, Cscore);
			}
		}
		if (win(x, y, check, mode) == -1)
		{
			system("cls");
			cout << n << " Win!!" << endl;
			cout << "Do you want to play again??(Enter Y/N): ";
			char f;
			cin >> f;
			if (f == 'Y')
			{
				system("cls");
				resetBoard(check);
				Board(sized, color, check);
				PvP(check, color, sized, m, n, mode, find, minimax, Cgame, Cscore);
			}
			else
			{
				system("cls");
				resetBoard(check);
				Menu(sized, color, m, n, check, mode, find, minimax, Cgame, Cscore);
			}
		}

		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
	}
}
//--------------------------------------------------------------------
void resetBoard(int check[100][100])
{
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			check[i][j] = 0;
		}
	}
}
//--------------------------------------------------------------------
void loadgame(int &turn2, int &coord_x, int &coord_y, string player1, string player2, int& color, int& sized, int check[100][100], int slot, int Mode, int Cgame, int Cscore) 
{
	if (Mode == 1)
	{
		if (slot == 1)
		{
			fstream load1("slot1.txt");
			for (int i = 1; i < 100; ++i) {
				for (int j = 1; j < 100; ++j) {
					load1 >> check[i][j];
				}
			}
			load1 >> player1;
			load1 >> player2; // Player name
			load1 >> turn2;
			load1 >> coord_x >> coord_y;
			load1 >> color;
			load1 >> sized;
			load1.close();
		}
		else
		{
			if (slot == 2)
			{
				fstream load2("slot2.txt");
				for (int i = 1; i < 100; ++i) {
					for (int j = 1; j < 100; ++j) {
						load2 >> check[i][j];
					}
				}
				load2 >> player1;
				load2 >> player2; // Player name
				load2 >> turn2;
				load2 >> coord_x >> coord_y;
				load2 >> color;
				load2 >> sized;
				load2.close();
			}
			else
			{
				fstream load3("slot3.txt");
				for (int i = 1; i < 100; ++i) {
					for (int j = 1; j < 100; ++j) {
						load3 >> check[i][j];
					}
				}
				load3 >> player1;
				load3 >> player2; // Player name
				load3 >> turn2;
				load3 >> coord_x >> coord_y;
				load3 >> color;
				load3 >> sized;
				load3.close();
			}
		}
	}
	else
	{
		if (slot == 1)
		{
			fstream load4("slot4.txt");
			for (int i = 1; i < 100; ++i) {
				for (int j = 1; j < 100; ++j) {
					load4 >> check[i][j];
				}
			}
			load4 >> player1;
			load4 >> player2; // Player name
			load4 >> turn2;
			load4 >> coord_x >> coord_y;
			load4 >> color;
			load4 >> sized;
			load4 >> Cgame;
			load4 >> Cscore;
			load4.close();
		}
		else
		{
			if (slot == 2)
			{
				fstream load5("slot5.txt");
				for (int i = 1; i < 100; ++i) {
					for (int j = 1; j < 100; ++j) {
						load5 >> check[i][j];
					}
				}
				load5 >> player1;
				load5 >> player2; // Player name
				load5 >> turn2;
				load5 >> coord_x >> coord_y;
				load5 >> color;
				load5 >> sized;
				load5 >> Cgame;
				load5 >> Cscore;
				load5.close();
			}
			else
			{
				fstream load6("slot6.txt");
				for (int i = 1; i < 100; ++i) {
					for (int j = 1; j < 100; ++j) {
						load6 >> check[i][j];
					}
				}
				load6 >> player1;
				load6 >> player2; // Player name
				load6 >> turn2;
				load6 >> coord_x >> coord_y;
				load6 >> color;
				load6 >> sized;
				load6 >> Cgame;
				load6 >> Cscore;
				load6.close();
			}
		}
	}
}
//--------------------------------------------------------------------
void PvP(int check[100][100], int& color, int& sized, string player1, string player2, int& mode, int find[100][100], int minimax[100][100], int Cgame, int Cscore)
{
	cout << endl;
	cout << "Enter the name of player 1: ";
	cin >> player1;
	cout << "Enter the name of player 2: ";
	cin >> player2;
	gameplay(player1, player2, 1, 1, 1, color, sized, check, mode, find, minimax, Cgame, Cscore);
	cout << "GAME START!" << endl;
}
//--------------------------------------------------------------------
void Findopp(int x, int y, int check[100][100], int find[100][100]) 
{
	if (check[y + 1][x] == 0) 
		find[y + 1][x] = 1;
	if (check[y][x + 1] == 0) 
		find[y][x + 1] = 1;
	if (check[y + 1][x + 1] == 0) 
		find[y + 1][x + 1] = 1;
	if (check[y - 1][x + 1] == 0)
		find[y - 1][x + 1] = 1;
	if (check[y - 1][x] == 0)
		find[y - 1][x] = 1;
	if (check[y][x - 1] == 0) 
		find[y][x - 1] = 1;
	if (check[y - 1][x - 1] == 0)
		find[y - 1][x - 1] = 1;
	if (check[y + 1][x - 1] == 0) 
		find[y + 1][x - 1] = 1;
}
//--------------------------------------------------------------------
void evaluation(int x, int y, int check[100][100], int minimax[100][100])
{
	int atk[] = { 1, 10, 100, 10000, 1000000 };
	int def[] = { 0, 1, 10, 1000, 100000 };
	int attack = 0, defend = 0;

	//Defend
	int i = 0, count = 0;
	while (i <= 4)
	{
		if (check[y + i][x] == 1)
		{
			++count;
			defend += def[count];
		}
		if (check[y + i][x] == -1)
		{
			defend -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4)
	{
		if (check[y][x + i] == 1)
		{
			++count;
			defend += def[count];
		}
		if (check[y][x + i] == -1)
		{
			defend -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) {
		if (check[y + i][x + i] == 1) 
		{
			++count;
			defend += def[count];
		}
		if (check[y + i][x + i] == -1) 
		{
			defend -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) 
	{
		if (check[y - i][x] == 1) 
		{
			++count;
			defend += def[count];
		}
		if (check[y - i][x] == -1)
		{
			defend -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) {
		if (check[y][x - i] == 1) 
		{
			++count;
			defend += def[count];
		}
		if (check[y][x - i] == -1) 
		{
			defend -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) 
	{
		if (check[y - i][x - i] == 1) 
		{
			++count;
			defend += def[count];
		}
		if (check[y - i][x - i] == -1)
		{
			defend -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) 
	{
		if (check[y + i][x - i] == 1)
		{
			++count;
			defend += def[count];
		}
		if (check[y + i][x - i] == -1)
		{
			defend -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4)
	{
		if (check[y - i][x + i] == 1)
		{
			++count;
			defend += def[count];
		}
		if (check[y - i][x + i] == -1)
		{
			defend -= 10; break;
		}
		++i;
	}
	//--------------------------------------------------
	//Attack
	i = 1, count = 0;
	while (i <= 4)
	{
		if (check[y + i][x] == -1)
		{
			++count;
			attack += atk[count];
		}
		if (check[y + i][x] == 1)
		{
			attack -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) 
	{
		if (check[y][x + i] == -1)
		{
			++count;
			attack += atk[count];
		}
		if (check[y][x + i] == 1) 
		{
			attack -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) 
	{
		if (check[y + i][x + i] == -1) 
		{
			++count;
			attack += atk[count];
		}
		if (check[y + i][x + i] == 1) 
		{
			attack -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) 
	{
		if (check[y - i][x] == -1)
		{
			++count;
			attack += atk[count];
		}
		if (check[y - i][x] == 1)
		{
			attack -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4)
	{
		if (check[y][x - i] == -1)
		{
			++count;
			attack += atk[count];
		}
		if (check[y][x - i] == 1)
		{
			attack -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4)
	{
		if (check[y - i][x - i] == -1) 
		{
			++count;
			attack += atk[count];
		}
		if (check[y - i][x - i] == 1) 
		{
			attack -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) 
	{
		if (check[y + i][x - i] == -1)
		{
			++count;
			attack += atk[count];
		}
		if (check[y + i][x - i] == 1) 
		{
			attack -= 10; break;
		}
		++i;
	}

	i = 1, count = 0;
	while (i <= 4) 
	{
		if (check[y - i][x + i] == -1)
		{
			++count;
			attack += atk[count];
		}
		if (check[y - i][x + i] == 1) 
		{
			attack -= 10; break;
		}
		++i;
	}

	minimax[y][x] = max(attack, defend);
}
//--------------------------------------------------------------------
void change(int &j2, int &i2, int find[100][100], int minimax[100][100], int check[100][100]) 
{
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (find[i][j] == 1) evaluation(i, j, check, minimax);
		}
	}

	int ans = 0;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (minimax[i][j] > ans && find[i][j] == 1) {
				ans = minimax[i][j];
				i2 = i;
				j2 = j;
			}
		}
	}
}
//---------------------------------------------------------------------------
void PlayervsCom(int check[100][100], int& color, int& sized, int& mode,int x, int y, int turn, int find[100][100], int minimax[100][100], int Cgame, int Cscore, string player1)
{
	cout << "Please enter your name : ";
	cin >> player1;
	Cgame++;
	PvC(check, color, sized, player1, mode, x, y, turn, find, minimax, Cgame, Cscore);
}
//---------------------------------------------------------------------------
void Playerranking(int Cgame, int Cscore, string player)
{
	string Name[10] = { "AAA", "AAA", "AAA", "AAA" , "AAA" , "AAA" , "AAA" ,"AAA" , "AAA" , "AAA" };
	int Games[10] = {150, 130, 120, 100, 90, 60, 50, 40, 30, 10};
	int Score[10] = {150, 130, 120, 100, 90, 60, 50, 40, 20, 10};
	int check = 0;
	fstream Name1("Name.txt");
	fstream Game1("match.txt");
	fstream Win1("score.txt");
	for (int i = 0; i < 10; i++)
	{
		Name1 >> Name[i];
		Game1 >> Games[i];
		Win1 >> Score[i];
	}
	Name1.close();
	Game1.close();
	Win1.close();
	for (int i = 0; i <= 9; i++)
	{
		if (Cscore >= Score[i] && check == 0)
		{
			int n = i;
			for (int j = 9; j > n; j--)
			{
				Score[j] = Score[j - 1];
				Name[j] = Name[j - 1];
				Games[j] = Games[j - 1];
			}
			Score[n] = Cscore;
			Name[n] = player;
			Games[n] = Cgame;
			check = 1;
		}
	}
	ofstream NameS("Name.txt");
	ofstream GameS("match.txt");
	ofstream WinS("score.txt");
	for (int i = 0; i < 10; i++)
	{
		NameS << Name[i] << endl;
		GameS << Games[i] << endl;
		WinS << Score[i] << endl;
	}
}
//---------------------------------------------------------------------------
void Playerstatistic()
{
	string Name[10] = { "AAA", "AAA", "AAA", "AAA" , "AAA" , "AAA" , "AAA" ,"AAA" , "AAA" , "AAA" };
	int Games[10] = { 150, 130, 120, 100, 90, 60, 50, 40, 30, 10 };
	int Score[10] = { 150, 130, 120, 100, 90, 60, 50, 40, 20, 10 };
	fstream Name1("Name.txt");
	fstream Game1("match.txt");
	fstream Win1("score.txt");
	for (int i = 0; i < 10; i++)
	{
		Name1 >> Name[i];
		Game1 >> Games[i];
		Win1 >> Score[i];
	}
	Name1.close();
	Game1.close();
	Win1.close();
	cout << "\t\t" << "LEADER BOARD PvC " << endl;
	cout << "Stt\tName\tMatches\t  Win" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "0" << i + 1 << "\t" << Name[i] << "\t" << Games[i] << "\t  " << Score[i] << endl;
	}
	cout << "10" << "\t" << Name[9] << "\t" << Games[9] << "\t  " << Score[9] << endl;
}
//---------------------------------------------------------------------------
void PvC(int check[100][100], int&color, int& sized, string player, int& mode, int x, int y, int turn, int find[100][100], int minimax[100][100], int Cgame, int Cscore)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos;

	Cursor_an_Pos.X = x;
	Cursor_an_Pos.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);

	while (true) {
		int a = _getch();
		switch (a)
		{
		case 119: // W
			Cursor_an_Pos.Y -= 1;
			break;
		case 97: // A
			Cursor_an_Pos.X -= 2;
			break;
		case 100: // D
			Cursor_an_Pos.X += 2;
			break;
		case 115: // S
			Cursor_an_Pos.Y += 1;
			break;
		case 8: //Backspace
			char q;
			gotoxy(0, 49);
			cout << "Do you want to back to the menu? (Y/N): ";
			cin >> q;
			if (q == 'Y')
			{
				system("cls");
				Menu(sized, color, player, "Bot", check, mode, find, minimax, Cgame, Cscore);
			}
			else
				gotoxy(Cursor_an_Pos.X, Cursor_an_Pos.Y);
			break;
		case 32: //Space
			int slot;
			if (sized == 1)
				gotoxy(0, 52);
			else
				if (sized == 2)
					gotoxy(0, 32);
				else
					gotoxy(0, 22);
			char YN;
			cout << "Do you want to save this game? (Y/N): ";
			cin >> YN;
			if (YN == 'Y')
			{
				system("cls");
				cout << " 1 - Slot 1.\n";
				cout << " 2 - Slot 2.\n";
				cout << " 3 - Slot 3.\n";
				cout << "Enter your choice: ";
				cin >> slot;
			}
			else
				gotoxy(Cursor_an_Pos.X, Cursor_an_Pos.Y);
			if (slot == 1)
			{
				ofstream save4("slot4.txt");
				for (int i = 1; i < 100; i++)
				{
					for (int k = 1; k < 100; k++)
					{
						save4 << check[i][k] << " ";
					}
					save4 << endl;
				}
				save4 << player << endl;
				save4 << "Bot" << endl; // Save player name
				save4 << turn << endl;
				save4 << Cursor_an_Pos.X << " " << Cursor_an_Pos.Y << endl;
				save4 << color << endl;
				save4 << sized << endl;
				save4 << Cgame << endl;
				save4 << Cscore;
				save4.close();
				cout << "Game saved!" << endl;
				system("pause");
				system("cls");
				Board(sized, color, check);
				PvC(check, color, sized, player, mode, x, y, turn, find, minimax, Cgame,Cscore);
			}
			else
			{
				if (slot == 2)
				{
					ofstream save5("slot5.txt");
					for (int i = 1; i < 100; i++)
					{
						for (int k = 1; k < 100; k++)
						{
							save5 << check[i][k] << " ";
						}
						save5 << endl;
					}
					save5 << player << endl;
					save5 << "Bot" << endl; // Save player name
					save5 << turn << endl;
					save5 << Cursor_an_Pos.X << " " << Cursor_an_Pos.Y << endl;
					save5 << color << endl;
					save5 << sized << endl;
					save5 << Cgame << endl;
					save5 << Cscore;
					save5.close();
					cout << "Game saved!" << endl;
					system("pause");
					system("cls");
					Board(sized, color, check);
					PvC(check, color, sized, player, mode, x, y, turn, find, minimax, Cgame, Cscore);
				}
				else
				{
					ofstream save6("slot6.txt");
					for (int i = 1; i < 100; i++)
					{
						for (int k = 1; k < 100; k++)
						{
							save6 << check[i][k] << " ";
						}
						save6 << endl;
					}
					save6 << player << endl;
					save6 << "Bot" << endl; // Save player name
					save6 << turn << endl;
					save6 << Cursor_an_Pos.X << " " << Cursor_an_Pos.Y << endl;
					save6 << color << endl;
					save6 << sized << endl;
					save6 << Cgame << endl;
					save6 << Cscore;
					save6.close();
					cout << "Game saved!" << endl;
					system("pause");
					system("cls");
					Board(sized, color, check);
					PvC(check, color, sized, player, mode, x, y, turn, find, minimax, Cgame, Cscore);
				}
			}
			break;
		}

		y = Cursor_an_Pos.Y;
		x = (Cursor_an_Pos.X - 1) / 2 + 1;
		int colorX, colorO;
		if (color == 1)
		{
			colorX = 9;
			colorO = 12;
		}
		else
		{
			colorX = 13;
			colorO = 10;
		}
		if (a == 13 && check[y][x] == 0)
		{
			check[y][x] = turn; find[y][x] = 0;
			TestColor(colorX);
			cout << (char)88;
			turn = -turn;
			TestColor(15);
			if (win(x, y, check, mode) == 1)
			{
				system("cls");
				cout << player << " Win!!" << endl;
				Cscore++;
				cout << "Do you want to play again??(Enter Y/N): ";
				char f;
				cin >> f;
				if (f == 'Y')
				{
					system("cls");
					resetBoard(check);
					Board(sized, color, check);
					Cgame++;
					PvC(check, color, sized, player, mode, x, y, turn, find, minimax, Cgame, Cscore);
				}
				else
				{
					system("cls");
					Playerranking(Cgame, Cscore, player);
					Playerstatistic();
					system("pause");
					system("cls");
					resetBoard(check);
					Menu(sized, color, player, "Bot", check, mode, find, minimax, Cgame, Cscore);
				}
			}
			if (win(x, y, check, mode) == -1)
			{
				system("cls");
				cout << "Bot" << " Win!!" << endl;
				cout << "Do you want to play again??(Enter Y/N): ";
				char f;
				cin >> f;
				if (f == 'Y')
				{

					system("cls");
					resetBoard(check);
					Board(sized, color, check);
					Cgame++;
					PvC(check, color, sized, player, mode, x, y, turn, find, minimax, Cgame, Cscore);
				}
				else
				{
					system("cls");
					Playerranking(Cgame, Cscore, player);
					Playerstatistic();
					system("pause");
					system("cls");
					resetBoard(check);
					Menu(sized, color, player, "Bot", check, mode, find, minimax, Cgame, Cscore);
				}
			}
			Findopp(x, y, check, find);
			change(x, y, find, minimax, check);
			gotoxy((x-1)*2+1, y);
			check[y][x] = turn; find[y][x] = 0;
			TestColor(colorO);
			cout << (char)79;
			turn = -turn;
			TestColor(15);
			Findopp(x, y, check, find);
			if (win(x, y, check, mode) == 1)
			{
				system("cls");
				cout << player << " Win!!" << endl;
				Cscore++;
				cout << "Do you want to play again??(Enter Y/N): ";
				char f;
				cin >> f;
				if (f == 'Y')
				{
					system("cls");
					resetBoard(check);
					Board(sized, color, check);
					Cgame++;
					PvC(check, color, sized, player, mode, x, y, turn, find,minimax, Cgame, Cscore);
				}
				else
				{
					system("cls");
					Playerranking(Cgame, Cscore, player);
					Playerstatistic();
					system("pause");
					system("cls");
					resetBoard(check);
					Menu(sized, color, player, "Bot", check, mode, find, minimax, Cgame, Cscore);
				}
			}
			if (win(x, y, check, mode) == -1)
			{
				system("cls");
				cout << "Bot" << " Win!!" << endl;
				cout << "Do you want to play again??(Enter Y/N): ";
				char f;
				cin >> f;
				if (f == 'Y')
				{
					system("cls");
					resetBoard(check);
					Board(sized, color, check);
					Cgame++;
					PvC(check, color, sized, player, mode, x, y, turn, find, minimax, Cgame, Cscore);
				}
				else
				{
					system("cls");
					Playerranking(Cgame, Cscore, player);
					Playerstatistic();
					system("pause");
					system("cls");
					resetBoard(check);
					Menu(sized, color, player, "Bot", check, mode, find, minimax, Cgame, Cscore);
				}
			}
		}
		TestColor(15);
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
	}
}
//--------------------------------------------------------------------
void Option(int& sized, int& color, string player1, string player2, int check[100][100], int& mode, int find[100][100], int minimax[100][100], int Cgame, int Cscore)
{
	system("cls");
	int option;
	cout << "1 - Sized of the board.\n";
	cout << "2 - Rules of game.\n";
	cout << "3 - Color of XO.\n";
	cout << "4 - Back to Menu.\n";
	cout << "Enter your choice: ";
	cin >> option;
	switch (option)
	{
	case 1:
		system("cls");
		cout << "1 - Large size.\n";
		cout << "2 - Medium size.\n";
		cout << "3 - Small size.\n";
		cout << "Enter the size: ";
		cin >> sized;
		system("cls");
		Option(sized, color, player1, player2, check, mode, find, minimax, Cgame, Cscore);
		break;
	case 2:
		cout << "1 - Normal rule.\n";
		cout << "2 - Two - head blocking rule.\n";
		cout << "Enter your choice: ";
		cin >> mode;
		system("cls");
		Option(sized, color, player1, player2, check, mode, find, minimax, Cgame, Cscore);
		break;
	case 3:
		system("cls");
		cout << "1 - X: ";
		TestColor(9);
		cout << (char)219;
		TestColor(15);
		cout << " & O: ";
		TestColor(12);
		cout << (char)219 << endl;
		TestColor(15);
		cout << "2 - X: ";
		TestColor(13);
		cout << (char)219;
		TestColor(15);
		cout << " & O: ";
		TestColor(10);
		cout << (char)219 << endl;
		TestColor(15);
		cout << "Enter your choice: ";
		cin >> color;
		system("cls");
		Option(sized, color, player1, player2, check, mode, find, minimax, Cgame, Cscore);
		break;
	case 4:
		char ch;
		cout << "Are you sure? (Y/N): ";
		cin >> ch;
		if (ch == 'Y')
		{
			system("cls");
			Menu(sized, color, player1, player2, check, mode, find, minimax, Cgame, Cscore);
		}
		else
		{
			cout << "Press '0' to choose again: ";
			cin >> option;
			system("cls");
			Option(sized, color, player1, player2, check, mode, find, minimax, Cgame, Cscore);
		}
		break;
	default:
		cout << "Not a valid choice.\n";
		cout << "Press '0' to choose again: ";
		cin >> option;
		system("cls");
		Option(sized, color, player1, player2, check, mode, find, minimax, Cgame, Cscore);
		break;
	}
}
//--------------------------------------------------------------------
void Menu(int& sized, int& color, string player1, string player2, int check[100][100], int& mode, int find[100][100], int minimax[100][100],int Cgame, int Cscore)
{
	int choice;
	int turn2, coord_x, coord_y;
	bool gameOn = true;
	while (gameOn != false) {
		cout << "*******************************\n";
		cout << " 1 - PvP mode.\n";
		cout << " 2 - PvC mode.\n";
		cout << " 3 - Option.\n";
		cout << " 4 - Player Statistic.\n";
		cout << " 5 - Load the game.\n";
		cout << " 6 - About us.\n";
		cout << " 7 - Exit.\n";
		cout << " Enter your choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			resetBoard(check);
			Board(sized, color, check);
			PvP(check, color, sized, player1, player2, mode, find, minimax, Cgame, Cscore);
			break;
		case 2:
			system("cls");
			resetBoard(check);
			Board(sized, color, check);
			PlayervsCom(check, color, sized, mode, 1, 1, 1, find, minimax, Cgame, Cscore, player1);
			break;
		case 3:
			Option(sized, color, player1, player2, check, mode, find, minimax, Cgame, Cscore);
			break;
		case 4:
			system("cls");
			Playerstatistic();
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			int Mode;
			cout << " 1 - PvP mode.\n";
			cout << " 2 - PvC mode.\n";
			cin >> Mode;
			if (Mode == 1)
			{
				system("cls");
				int slot;
				cout << " 1 - Slot 1.\n";
				cout << " 2 - Slot 2.\n";
				cout << " 3 - Slot 3.\n";
				cin >> slot;
				if (slot == 1)
					loadgame(turn2, coord_x, coord_y, player1, player2, color, sized, check, 1, 1, Cgame, Cscore);
				else
					if (slot == 2)
						loadgame(turn2, coord_x, coord_y, player1, player2, color, sized, check, 2, 1, Cgame, Cscore);
					else
						loadgame(turn2, coord_x, coord_y, player1, player2, color, sized, check, 3, 1, Cgame, Cscore);
				Board(sized, color, check);
				gotoxy(0, 50);
				cout << "Welcome back " << player1 << " & " << player2 << endl;
				gameplay(player1, player2, turn2, coord_x, coord_y, color, sized, check, mode, find, minimax, Cgame, Cscore);
			}
			else
			{
				system("cls");
				int slot;
				cout << " 1 - Slot 1.\n";
				cout << " 2 - Slot 2.\n";
				cout << " 3 - Slot 3.\n";
				cin >> slot;
				if (slot == 1)
					loadgame(turn2, coord_x, coord_y, player1, player2, color, sized, check, 1, 2, Cgame, Cscore);
				else
					if (slot == 2)
						loadgame(turn2, coord_x, coord_y, player1, player2, color, sized, check, 2, 2, Cgame, Cscore);
					else
						loadgame(turn2, coord_x, coord_y, player1, player2, color, sized, check, 3, 2, Cgame, Cscore);
				Board(sized, color, check);
				gotoxy(0, 50);
				cout << "Welcome back " << player1 << endl;
				PvC(check, color, sized, player1, mode, coord_x, coord_y, turn2, find, minimax, Cgame, Cscore);
			}
			break;
		case 6:
			system("cls");
			cout << "This game is developed by:\n";
			cout << "      Huynh Tan Phat\n";
			cout << "      Ngo Minh Khoi\n";
			cout << "      Cao Ngoc Son\n";
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "End of Program.\n";
			cout << "Thank you for playing!\n";
			system("pause");
			exit(0);
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Press '0' to choice again.\n";
			cin >> choice;
			break;
		}

	}
}