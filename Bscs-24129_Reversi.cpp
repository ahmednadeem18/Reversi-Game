//#include<iostream>
//#include<fstream>
//using namespace std;
//const int row = 8, col = 8;
//Verticesoid initialize(char matrix[row][col]);
//Verticesoid display(char matrix[row][col]);
//bool VerticesalidmoVerticese(char matrix[row][col], int x, int y);
//Verticesoid moVerticese(char matrix[row][col], int x, int y, int turn, char& option);
//Verticesoid win(char matrix[row][col], char option);
//Verticesoid turnchange(int& turn);
//Verticesoid flip_pieces(char matrix[row][col], int x, int y, char option);
//
//int main()
//{
//	char matrix[row][col]{ '.' };
//	int turn = 1;
//	int choice = 1;
//	char option = 'O';
//	int x = 0, y = 0;
//	initialize(matrix);
//	while (true)
//	{
//		display(matrix);
//		do
//		{
//			cout << "Player " <<turn<< endl;
//			cout << "Enter Position in Row ." << endl;
//			cin >> x;
//			cout << "Enter Position in Column." << endl;
//			cin >> y;
//			x--;
//			y--;
//
//
//
//		} while (!VerticesalidmoVerticese(matrix, x, y));
//
//
//		moVerticese(matrix, x, y, turn, option);
//		flip_pieces(matrix, x, y, option);
//		turnchange(turn);
//
//
//
//		system("cls");
//	}
//	return 0;
//}
//Verticesoid initialize(char matrix[row][col])
//{
//	ifstream read("matrix.txt");
//	for (int i = 0;i < row;i++)
//	{
//		for (int j = 0;j < col;j++)
//		{
//			read >> matrix[i][j];
//		}
//	}
//	read.close();
//}
//Verticesoid display(char matrix[row][col])
//{
//	cout << "  1  2  3  4  5  6  7  8"<<endl;
//	for (int i = 0;i < row;i++)
//	{
//		cout << i+1<<" ";
//		for (int j = 0;j < col;j++)
//		{
//			
//			cout << matrix[i][j]<<"  ";
//			
//		}
//		cout << endl;
//	}
//}
//bool VerticesalidmoVerticese(char matrix[row][col], int x, int y)
//{
//	if (x >= row || y >= col)
//	{
//		return false;
//	}
//	if (matrix[x][y] != '.')
//	{
//		return false;
//	}
//	
//	return true;
//
//}
//Verticesoid moVerticese(char matrix[row][col], int x, int y, int turn, char& option)
//{
//	if (turn == 1)
//	{
//		option = 'O';
//	}
//	else if (turn == 2)
//	{
//		option = 'X';
//	}
//	matrix[x][y] = option;
//}
//Verticesoid win(char matrix[row][col], char option)
//{
//	int o_count = 0, x_count = 0;
//	for (int i = 0;i < row;i++)
//	{
//		for (int j = 0;j < col;j++)
//		{
//			if (matrix[i][j] == 'O')
//			{
//				o_count++;
//			}
//			else if (matrix[i][j] == 'X')
//			{
//				x_count++;
//			}
//		}
//	}
//	if (o_count == x_count)
//	{
//		cout << "Game Draw" << endl;;
//	}
//	else if (o_count > x_count)
//	{
//		cout << "Player 1 Win" << endl;
//	}
//	else if (o_count < x_count)
//	{
//		cout << "Player 2 Win" << endl;
//	}
//}
//Verticesoid turnchange(int& turn)
//{
//	if (turn == 2)
//	{
//		turn--;
//	}
//	else if (turn == 1)
//	{
//		turn++;
//	}
//}
//Verticesoid flip_pieces(char matrix[row][col], int x, int y, char option)
//{
//	for (int i = y+1;i < col;i++)
//	{
//		if (matrix[x][i] == '.')
//		{
//			break;
//		}
//		else if (matrix[x][i] == option)
//		{
//			for (int j = y + 1;j < i;j++)
//			{
//				matrix[x][j] = option;
//			}
//		}
//		
//	}
//
//	for (int i = y - 1;i >= 0;i--)
//	{
//		if (matrix[x][i] == '.')
//		{
//			break;
//		}
//		else if (matrix[x][i] == option)
//		{
//			for (int j = y - 1;j > i;j--)
//			{
//				matrix[x][j] = option;
//			}
//		}
//
//	}
//
//	for (int i = x + 1;i < row;i++)
//	{
//		if (matrix[i][y] == '.')
//		{
//			break;
//		}
//		else if (matrix[i][y] == option)
//		{
//			for (int j = x + 1;j < i;j++)
//			{
//				matrix[j][y] = option;
//			}
//		}
//
//	}
//
//	for (int i = x - 1;i >= 0;i--)
//	{
//		if (matrix[i][y] == '.')
//		{
//			break;
//		}
//		else if (matrix[i][y] == option)
//		{
//			for (int j = x - 1;j > i;j--)
//			{
//				matrix[j][y] = option;
//			}
//		}
//
//	}
//	
//	for (int i = x + 1,z=y+1;i < row||z<col;i++,z++)
//	{
//		
//		if (matrix[i][z] == '.')
//		{
//			break;
//		}
//		else if (matrix[i][z] == option)
//		{
//			for (int j = x + 1,k=y+1;j < i||k<z;j++,k++)
//			{
//				matrix[j][k] = option;
//			}
//		}
//		
//	}
//
//	for (int i = x - 1, z = y - 1;i >=0 || z >=0;i--, z--)
//	{
//
//		if (matrix[i][z] == '.')
//		{
//			break;
//		}
//		else if (matrix[i][z] == option)
//		{
//			for (int j = x - 1, k = y - 1;j > i || k > z;j--, k--)
//			{
//				matrix[j][k] = option;
//			}
//		}
//
//	}
//
//	for (int i = x + 1, z = y - 1;i < row || z >=0;i++, z--)
//	{
//
//		if (matrix[i][z] == '.')
//		{
//			break;
//		}
//		else if (matrix[i][z] == option)
//		{
//			for (int j = x + 1, k = y - 1;j < i || k > z;j++, k--)
//			{
//				matrix[j][k] = option;
//			}
//		}
//
//	}
//
//	for (int i = x - 1, z = y + 1;i>=0  || z < col;i--, z++)
//	{
//
//		if (matrix[i][z] == '.')
//		{
//			break;
//		}
//		else if (matrix[i][z] == option)
//		{
//			for (int j = x - 1, k = y + 1;j > i || k < z;j--, k++)
//			{
//				matrix[j][k] = option;
//			}
//		}
//
//	}
//}
////Verticesoid aiMoVerticese(char matrix[row][col], int& x, int& y) {
////
////	char option = 'X';
////	for (int i = 0; i < row; i++) {
////		for (int j = 0; j < col; j++) {
////			if (matrix[i][j] == '-') {
////				matrix[i][j] = option;
////				if (win(matrix, option)) {
////					x = i;
////					y = j;
////					return;
////				}
////				matrix[i][j] = '-';
////			}
////		}
////	}
////	option = 'O';
////	for (int i = 0; i < row; i++) {
////		for (int j = 0; j < col; j++) {
////			if (matrix[i][j] == '-') {
////				matrix[i][j] = option;
////				if (win(matrix, option)) {
////					matrix[i][j] = 'X';
////					x = i;
////					y = j;
////					return;
////				}
////				matrix[i][j] = '-';
////			}
////		}
////	}
////
////	for (int i = 0; i < row; i++) {
////		for (int j = 0; j < col; j++) {
////			if (matrix[i][j] == '-') {
////				x = i;
////				y = j;
////				return;
////			}
////		}
////	}
////}

//#include <iostream>
//using namespace std;
//
//const int MAX = 100; // Maximum number of Vertices
//
//void DFS(int v, int adj[MAX][MAX], bool Visited[], int Vertices) {
//    Visited[v] = true;
//    for (int i = 0; i < Vertices; i++) {
//        if (adj[v][i] && !Visited[i]) {
//            DFS(i, adj, Visited, Vertices);
//        }
//    }
//}
//
//bool isConnected(int adj[MAX][MAX], int Vertices) {
//    bool Visited[MAX] = { false };
//
//    DFS(0, adj, Visited, Vertices);
//
//    for (int i = 0; i < Vertices; i++) {
//        if (!Visited[i]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    int Vertices = 1; // Number of Vertices
//    int adj[MAX][MAX] = { 0 }; // Adjacency matrix
//
//    cout << "Enter number of Vertices" << endl;
//    cin >> Vertices;
//    cout << "Input 1 if there is Relation Between Vertices.\nElse Input 0." << endl;
//    for (int i = 0;i < Vertices;i++)
//    {
//        for (int j = 0;j < Vertices;j++)
//        {
//            cout << "Enter Relation B/W " << i + 1 << " and " << j + 1 << " Vertices" << endl;
//            cin >> adj[i][j];
//        }
//    }
//
//    if (isConnected(adj, Vertices)) {
//        cout << "The graph is connected." << endl;
//    }
//    else {
//        cout << "The graph is not connected." << endl;
//    }
//
//    return 0;
//}


//#include<iostream>
//#include<fstream>
//using namespace std;
//const int row = 8, col = 8;
//void initialize(char matrix[8][8]);
//void display(char matrix[8][8]);
//bool validmove(char matrix[8][8], int x, int y);
//void move(char matrix[8][8], int x, int y, int turn, char& option);
//void win(char matrix[8][8], char option);
//void turnchange(int& turn);
//void flip_pieces(char matrix[8][8], int x, int y, char option);
//void ai(char matrix[8][8], int& x, int& y);
//
//void initialize(char matrix[8][8])
//{
//	ifstream file("file.txt");
//	for (int i = 0;i < row;i++)
//	{
//		for (int j = 0;j < col;j++)
//		{
//			file >> matrix[i][j];
//		}
//	}
//	file.close();
//}
//
//int main()
//{
//	char matrix[row][col]{ '*' };
//	int turn = 1;
//	char option = 'O';
//	int x = 0, y = 0;
//	initialize(matrix);
//	int choice;
//	do {
//		// Menu printing on the screen
//		cout << "from which u want to play" << endl;
//		cout << "press 1 for man" << endl;
//		cout << "Press 2 for ai" << endl;
//		// Add other menu options as needed
//		cout << "Press 0 to exit" << endl;
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			// Code block for letter count
//			while (true)
//			{
//				display(matrix);
//				do
//				{
//					cout << "Player " << turn << endl;
//					cout << "Enter Position in Row ." << endl;
//					cin >> x;
//					cout << "Enter Position in Column." << endl;
//					cin >> y;
//					x--;
//					y--;
//
//
//
//				} while (!validmove(matrix, x, y));
//
//
//				move(matrix, x, y, turn, option);
//				flip_pieces(matrix, x, y, option);
//				turnchange(turn);
//
//
//
//				system("cls");
//			}
//			break;
//		case 2:
//			while (true)
//			{
//
//				display(matrix);
//				if (turn == 1) {
//					do
//					{
//						cout << "Player " << turn << endl;
//						cout << "Enter Position in Row ." << endl;
//						cin >> x;
//						cout << "Enter Position in Column." << endl;
//						cin >> y;
//						x--;
//						y--;
//						
//				
//					} while (!validmove(matrix, x, y));
//				}
//				else if (turn == 2)
//				{
//					ai(matrix, x, y);
//				}
//
//				move(matrix, x, y, turn, option);
//				flip_pieces(matrix, x, y, option);
//				turnchange(turn);
//
//
//
//				system("cls");
//			}
//			break;
//
//		default:
//			if (choice != 0) {
//				cout << "Invalid choice, please try again." << endl;
//			}
//		}
//	} while (choice != 0);
//
//	return 0;
//}
//
//void display(char matrix[8][8])
//{
//	cout << " 12345678" << endl;
//	for (int i = 0;i < row;i++)
//	{
//		cout << i + 1;
//		for (int j = 0;j < col;j++)
//		{
//
//			cout << matrix[i][j];
//
//		}
//		cout << endl;
//	}
//}
//bool validmove(char matrix[8][8], int x, int y)
//{
//	if (x >= row || y >= col)
//	{
//		return false;
//	}
//	if (matrix[x][y] != '*')
//	{
//		return false;
//	}
//	return true;
//
//}
//void move(char matrix[8][8], int x, int y, int turn, char& option)
//{
//	if (turn == 1)
//	{
//		option = 'O';
//	}
//	else if (turn == 2)
//	{
//		option = 'X';
//	}
//	matrix[x][y] = option;
//}
//void win(char matrix[8][8], char option)
//{
//	int player_1 = 0, player_2 = 0;
//	for (int i = 0;i < row;i++)
//	{
//		for (int j = 0;j < col;j++)
//		{
//			if (matrix[i][j] == 'O')
//			{
//				player_1++;
//			}
//			else if (matrix[i][j] == 'X')
//			{
//				player_2++;
//			}
//		}
//	}
//	if (player_1 == player_2)
//	{
//		cout << "Game Draw" << endl;;
//	}
//	else if (player_1 > player_2)
//	{
//		cout << "Player 1 Win" << endl;
//	}
//	else if (player_1 < player_2)
//	{
//		cout << "Player 2 Win" << endl;
//	}
//}
//void turnchange(int& turn)
//{
//	if (turn == 2)
//	{
//		turn--;
//	}
//	else if (turn == 1)
//	{
//		turn++;
//	}
//}
//void flip_pieces(char matrix[8][8], int x, int y, char option)
//{
//	for (int i = x + 1, z = y + 1;i < row || z < col;i++, z++)
//	{
//
//		if (matrix[i][z] == '*')
//		{
//			break;
//		}
//		else if (matrix[i][z] == option)
//		{
//			for (int j = x + 1, k = y + 1;j < i || k < z;j++, k++)
//			{
//				matrix[j][k] = option;
//			}
//		}
//
//	}
//
//	for (int i = x - 1, z = y - 1;i >= 0 || z >= 0;i--, z--)
//	{
//
//		if (matrix[i][z] == '*')
//		{
//			break;
//		}
//		else if (matrix[i][z] == option)
//		{
//			for (int j = x - 1, k = y - 1;j > i || k > z;j--, k--)
//			{
//				matrix[j][k] = option;
//			}
//		}
//
//	}
//
//	for (int i = x + 1, z = y - 1;i < row || z >= 0;i++, z--)
//	{
//
//		if (matrix[i][z] == '*')
//		{
//			break;
//		}
//		else if (matrix[i][z] == option)
//		{
//			for (int j = x + 1, k = y - 1;j < i || k > z;j++, k--)
//			{
//				matrix[j][k] = option;
//			}
//		}
//
//	}
//
//	for (int i = x - 1, z = y + 1;i >= 0 || z < col;i--, z++)
//	{
//
//		if (matrix[i][z] == '*')
//		{
//			break;
//		}
//		else if (matrix[i][z] == option)
//		{
//			for (int j = x - 1, k = y + 1;j > i || k < z;j--, k++)
//			{
//				matrix[j][k] = option;
//			}
//		}
//
//	}
//	for (int i = y + 1;i < col;i++)
//	{
//		if (matrix[x][i] == '*')
//		{
//			break;
//		}
//		else if (matrix[x][i] == option)
//		{
//			for (int j = y + 1;j < i;j++)
//			{
//				matrix[x][j] = option;
//			}
//		}
//
//	}
//
//	for (int i = y - 1;i >= 0;i--)
//	{
//		if (matrix[x][i] == '*')
//		{
//			break;
//		}
//		else if (matrix[x][i] == option)
//		{
//			for (int j = y - 1;j > i;j--)
//			{
//				matrix[x][j] = option;
//			}
//		}
//
//	}
//
//	for (int i = x + 1;i < row;i++)
//	{
//		if (matrix[i][y] == '*')
//		{
//			break;
//		}
//		else if (matrix[i][y] == option)
//		{
//			for (int j = x + 1;j < i;j++)
//			{
//				matrix[j][y] = option;
//			}
//		}
//
//	}
//
//	for (int i = x - 1;i >= 0;i--)
//	{
//		if (matrix[i][y] == '*')
//		{
//			break;
//		}
//		else if (matrix[i][y] == option)
//		{
//			for (int j = x - 1;j > i;j--)
//			{
//				matrix[j][y] = option;
//			}
//		}
//
//	}
//
//
//}
//void ai(char matrix[8][8], int& x, int& y)
//{
//	for (int i = 0; i < 8; i++) {
//		for (int j = 0; j < 8; j++) {
//			if (matrix[i][j] == '*') {
//				
//				x = i;
//				y = j;
//				return;
//			}
//		}
//	}
//}
