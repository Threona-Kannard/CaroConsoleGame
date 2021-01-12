#include "Header.h"

using namespace std;

int main(int argc, char** argv)
{
	string player1, player2;
	int Cgame = 0, Cscore = 0;
	int color = 1, sized = 1;
	int check[100][100];
	int minimax[100][100];
	int find[100][100];
	int mode = 1;
	for (int k = 0; k < 100; k++)
	{
		for (int i = 0; i < 100; i++)
		{
			check[k][i] = 0;
		}
	}
	display_splash();
	initialize(argc, argv);
	Menu(sized, color, player1, player2, check, mode, find, minimax, Cgame, Cscore);
	system("pause");
	return 0;
}