#include<iostream>
#include<fstream>
using namespace std;
const int row = 8, col = 8;
void initialize(char board[row][col]);
void display(char board[row][col]);
bool validmove(char board[row][col], int x, int y);
void move(char board[row][col], int x, int y, int turn, char& sign);
void win(char board[row][col]);
void turnchange(int& turn);
void flip_pieces(char board[row][col], int x, int y, char sign);
void computerMove(char board[row][col], int& x, int& y);
bool check_game(char board[row][col]);

int main()
{
	char board[row][col]{ '.' };
	int turn = 1;
	char sign = 'O';
	int x = 0, y = 0;
	initialize(board);
	int choice;
	do {
		// Menu printing on the screen
		cout << "Please enter your choice" << endl;
		cout << "Press 1 To Play With Human" << endl;
		cout << "Press 2 To Play With Computer" << endl;
		// Add other menu options as needed
		cout << "Press 0 to exit" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			// Code block for letter count
			initialize(board);
			while (check_game(board))
			{
				display(board);
				do
				{
					cout << "Player " << turn << endl;
					cout << "Enter Position in Row ." << endl;
					cin >> x;
					cout << "Enter Position in Column." << endl;
					cin >> y;
					x--;
					y--;



				} while (!validmove(board, x, y));


				move(board, x, y, turn, sign);
				flip_pieces(board, x, y, sign);
				turnchange(turn);
				



				system("cls");
			}
			win(board);
			break;
		case 2:
			// Code block for word count
			initialize(board);
			while (check_game(board))
			{
				display(board);
				if (turn == 1)
				{

					do
					{

						cout << "Player 1" << endl;
						cout << "Enter Position in Row ." << endl;
						cin >> x;
						cout << "Enter Position in Column." << endl;
						cin >> y;
						x--;
						y--;

					} while (!validmove(board, x, y));
				}
				else if (turn == 2)
				{
					computerMove(board, x, y);
				}

				move(board, x, y, turn, sign);
				flip_pieces(board, x, y, sign);
				turnchange(turn);



				system("cls");
			}
			win(board);
			break;

		default:
			if (choice != 0) {
				cout << "Invalid choice, please try again." << endl;
			}
		}
	} while (choice != 0);
	

}
void initialize(char board[row][col])
{
	ifstream read("board.txt");
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			read >> board[i][j];
		}
	}
	read.close();
}
void display(char board[row][col])
{
	cout << "  1  2  3  4  5  6  7  8" << endl;
	for (int i = 0;i < row;i++)
	{
		cout << i + 1 << " ";
		for (int j = 0;j < col;j++)
		{

			cout << board[i][j] << "  ";

		}
		cout << endl;
	}
}
bool validmove(char board[row][col], int x, int y)
{
	if (x >= row || y >= col)
	{
		return false;
	}
	if (board[x][y] != '.')
	{
		return false;
	}
	return true;

}
void move(char board[row][col], int x, int y, int turn, char& sign)
{
	if (turn == 1)
	{
		sign = 'O';
	}
	else if (turn == 2)
	{
		sign = 'X';
	}
	board[x][y] = sign;
}
void win(char board[row][col])
{
	int o_count = 0, x_count = 0;
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (board[i][j] == 'O')
			{
				o_count++;
			}
			else if (board[i][j] == 'X')
			{
				x_count++;
			}
		}
	}
	if (o_count == x_count)
	{
		cout << "Game Draw" << endl;;
	}
	else if (o_count > x_count)
	{
		cout << "Player 1 Win" << endl;
	}
	else if (o_count < x_count)
	{
		cout << "Player 2 Win" << endl;
	}
}
void turnchange(int& turn)
{
	if (turn == 2)
	{
		turn--;
	}
	else if (turn == 1)
	{
		turn++;
	}
}
void flip_pieces(char board[row][col], int x, int y, char sign)
{
	for (int i = y + 1;i < col;i++)
	{
		if (board[x][i] == '.')
		{
			break;
		}
		else if (board[x][i] == sign)
		{
			for (int j = y + 1;j < i;j++)
			{
				board[x][j] = sign;
			}
		}

	}

	for (int i = y - 1;i >= 0;i--)
	{
		if (board[x][i] == '.')
		{
			break;
		}
		else if (board[x][i] == sign)
		{
			for (int j = y - 1;j > i;j--)
			{
				board[x][j] = sign;
			}
		}

	}

	for (int i = x + 1;i < row;i++)
	{
		if (board[i][y] == '.')
		{
			break;
		}
		else if (board[i][y] == sign)
		{
			for (int j = x + 1;j < i;j++)
			{
				board[j][y] = sign;
			}
		}

	}

	for (int i = x - 1;i >= 0;i--)
	{
		if (board[i][y] == '.')
		{
			break;
		}
		else if (board[i][y] == sign)
		{
			for (int j = x - 1;j > i;j--)
			{
				board[j][y] = sign;
			}
		}

	}

	for (int i = x + 1, z = y + 1;i < row || z < col;i++, z++)
	{

		if (board[i][z] == '.')
		{
			break;
		}
		else if (board[i][z] == sign)
		{
			for (int j = x + 1, k = y + 1;j < i || k < z;j++, k++)
			{
				board[j][k] = sign;
			}
		}

	}

	for (int i = x - 1, z = y - 1;i >= 0 || z >= 0;i--, z--)
	{

		if (board[i][z] == '.')
		{
			break;
		}
		else if (board[i][z] == sign)
		{
			for (int j = x - 1, k = y - 1;j > i || k > z;j--, k--)
			{
				board[j][k] = sign;
			}
		}

	}

	for (int i = x + 1, z = y - 1;i < row || z >= 0;i++, z--)
	{

		if (board[i][z] == '.')
		{
			break;
		}
		else if (board[i][z] == sign)
		{
			for (int j = x + 1, k = y - 1;j < i || k > z;j++, k--)
			{
				board[j][k] = sign;
			}
		}

	}

	for (int i = x - 1, z = y + 1;i >= 0 || z < col;i--, z++)
	{

		if (board[i][z] == '.')
		{
			break;
		}
		else if (board[i][z] == sign)
		{
			for (int j = x - 1, k = y + 1;j > i || k < z;j--, k++)
			{
				board[j][k] = sign;
			}
		}

	}
}
void computerMove(char board[row][col], int& x, int& y) {

	//for (int i = x;i < row;i++)
	//{
	//	for (int j = y;j < col;j++)
	//	{
	//		if (board[i][j] == '.')
	//		{
	//			x = i;
	//			y = j;
	//			return;
	//		}
	//		
	//	}
	//}
	//
	//for (int i = 0;i < row;i++)
	//{
	//	for (int j = 0;j < col;j++)
	//	{
	//		if (board[i][j] == '.')
	//		{
	//			x = i;
	//			y = j;
	//			return;
	//		}
	//	}
	//}

	//int bestrow = -1, bestcol = -1;
	//const int size = 8;
	//int totalflips[size]  { 0 };
	//int flips = 0;
	//		
}
bool check_game(char board[row][col])
{

	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (board[i][j] == '.')
			{
				
				return true;
			}
		}
	}
	return false;
}