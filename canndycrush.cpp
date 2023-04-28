//ANZLA ASLAM             ROLL NO: 20L_2109
//AQSA ARSHAD             ROLL NO: 20L_1166
#include<iostream>
#include<cstdlib>
#include<cmath>
#include <ctime>
#include<fstream>
using namespace std;
const int rw = 111, yw = 222, gw = 333, bw = 444, ow = 555; 
const int rs = 11, ys = 22, gs = 33, bs = 44, os = 55;
const int r = 1, y = 2, g = 3, b = 4, o = 5; 
const int cb = 0;                                             

  
void comparison_cb_cb(int arr[][50], int i, int j, int size, int& s);
void print(int arr[][50], int size);  

void c_b_shifting(int arr[][50], int i, int j, int size);  

void c_b_plaincandy(int arr[][50], int i, int j, int m, int n, int size, int& s); 
void plainandwrapped(int arr[][50], int i, int j, int size);
void score(int arr[][50], int x, int y, int& s);   


void plainandstripped(int arr[][50], int i, int j, int size);   
void stripwrap(int arr[][50], int i, int j, int m, int n, int& s);                           

void savegame(int arr[][50], int size, int Turns, int Score);                  
void loadgame(int arr[][50], int& size, int& Turns, int& Score);       
void c_b(int arr[][50], int i, int j);
void shifting(int arr[][50], int i, int j); 
void search(int arr[][50], int i, int j, int size);
void comparison_strip(int arr[][50], int i, int j);
void comparison_wrapped(int arr[][50], int i, int j);
void comparison_sc_cb(int arr[][50], int i, int j, int size, int& s);

int main()
{
	srand(time(0));
	int size = 0;
	int scoring = 0, Turns = 20;
	int arr[50][50] = { 0 };
	int i = 0;
	int j = 0;
	int t = 0, t_s = 200;
	cout << " user Enter 1 to resume game or other number to play the game from start = ";
	cin >> t;
	if (t == 1)
	{
		loadgame(arr, size, Turns, scoring);

	}

	else
	{
		cout << " size of the grid : " << endl;
		cin >> size;
		while (size < 9 || size > 50)
		{
			cout << "entered size is not valid please Enter 9 or greater than 9 but not greater than 50 : " << endl;
			cin >> size;
		}


		for (; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				arr[i][j] = rand() % 5 + 1;
			}
		}

		i = 0;
		j = 0;
	}
	search(arr, i, j, size);
	cout << endl;
	print(arr, size);

	int k = 1;
	while ((k != 0) && (Turns >= 0) && (scoring < t_s))
	{
		int i = 0, j = 0;
		int m = 0, n = 0;
		do
		{
			cout << "Enter first candy wich you want to swap ! " << endl;
			cout << "Enter the row number of the candy :  ";
			cin >> i;

			while (!(i >= 0 && i < size))
			{
				cout << "row number is invalid ! please enter row number again : ";
				cin >> i;
			}
			cout << "Enter the column number of the candy :  ";
			cin >> j;

			while (!(j >= 0 && j < size))
			{
				cout << "coulum number is invalid ! please enter column number again : " << endl;
				cin >> j;
			}

			cout << endl;

			cout << "Enter second candy which you want to swap ! " << endl;
			cout << "Enter the row number of the second candy :  ";
			cin >> m;
			while (!(m >= 0 && m < size))
			{
				cout << "the entered row number invalid ! Kindly enter row number again : ";
				cin >> m;
			}
			cout << "Enter the column number :  ";
			cin >> n;
			while (!(n >= 0 && n < size))
			{
				cout << "the entered coulum is invalid ! Kindly enter column number again : " << endl;
				cin >> n;
			}
		}

		while ((!((i == m && n == j - 1) || (i == m && n == j + 1) || (m == i + 1 && n == j) || (m == i - 1 && n == j)))); 


		swap(arr[i][j], arr[m][n]);

		score(arr, i, j, scoring);
		score(arr, m, n, scoring);

		comparison_wrapped(arr, m, n);
		comparison_wrapped(arr, i, j);

		c_b(arr, i, j);
		c_b(arr, m, n);

		c_b_plaincandy(arr, i, j, m, n, size, scoring);

		stripwrap(arr, i, j, m, n, scoring);

		comparison_strip(arr, m, n);
		comparison_strip(arr, i, j);

		plainandstripped(arr, i, j, size);
		plainandstripped(arr, m, n, size);

		plainandwrapped(arr, i, j, size);
		plainandwrapped(arr, m, n, size);

		shifting(arr, m, n);
		shifting(arr, i, j);

		search(arr, m, n, size);
		search(arr, i, j, size);

		print(arr, size);
		Turns--;
		cout << "Target score = " << t_s << endl;
		cout << "Score = " << scoring << endl;
		cout << "remaining Turns = " << Turns;
		cout <<endl<<endl<<"Enter 0 to Exit or any other number to continue = ";
		cin >> k;
		if (k == 0)
		{
			int t = 0;
			cout <<endl<<endl<< "Enter 1 to save game or any other number to exit = ";
			cin >> t;
			if (t == 1)
			{
				savegame(arr, size, Turns, scoring);
			}

		}

	}
	if (scoring >= t_s)
	{
		cout << "You are winner";
	}
	else
	{
		cout << "You are loser";
	}
	exit(0);
}


void shifting(int arr[][50], int i, int j)  
{
	if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2]))
	{
		int x = i;
		if ((i != 0) || (j != 0))
		{

			for (; x > 0; x--)
			{
				for (int y = j; y > j - 3; y--)
				{
					arr[x][y] = arr[x - 1][y];
				}

			}
		}
		if (x == 0)
		{
			for (int y = j; y >= j - 3; y--)
			{
				arr[x][y] = rand() % 5 + 1;
			}
		}
	}

	else if (((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2])))
	{
		int x = i;
		if ((i != 0) || (j != 0))
		{

			for (; x > 0; x--)
			{
				for (int y = j; y < j + 3; y++)
				{
					arr[x][y] = arr[x - 1][y];
				}

			}
		}
		if (x == 0)
		{
			for (int y = j; y < j + 3; y++)
			{
				arr[x][y] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i - 2][j]))
	{
		int x = i;
		for (; x > 2; x--)
		{
			arr[x][j] = arr[x - 3][j];
		}

		for (int x = 2; x >= 0; x--)
		{
			arr[x][j] = rand() % 5 + 1;
		}

	}
	else if ((arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j]))
	{
		int x = i + 3;
		for (; x > 2; x--)
		{
			arr[x][j] = arr[x - 3][j];
		}

		for (int x = 2; x >= 0; x--)
		{
			arr[x][j] = rand() % 5 + 1;
		}
	}
	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j - 1]))
	{
		int x = i;
		if ((i != 0) || (j != 0))
		{

			for (; x > 0; x--)
			{
				for (int y = j - 1; y > j - 4; y--)
				{
					arr[x][y] = arr[x - 1][y];
				}

			}
		}
		if (x == 0)
		{
			for (int y = j - 1; y > j - 4; y--)
			{
				arr[x][y] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i - 1][j]))
	{
		int x = i + 1;
		for (; x > 2; x--)
		{
			arr[x][j] = arr[x - 3][j];
		}

		for (int x = 2; x >= 0; x--)
		{
			arr[x][j] = rand() % 5 + 1;
		}
	}
}

void comparison_strip(int arr[][50], int i, int j)
{     

	if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2]) && (arr[i][j] == arr[i][j + 1]))
	{
		if (arr[i][j] == 1)
		{
			arr[i][j + 1] = 11;
			shifting(arr, i, j);
		}

		else if (arr[i][j] == 2)
		{
			arr[i][j + 1] = 22;
			shifting(arr, i, j);
		}

		else if (arr[i][j] == 3)
		{
			arr[i][j + 1] = 33;
			shifting(arr, i, j);
		}

		else if (arr[i][j] == 4)
		{
			arr[i][j + 1] = 44;
			shifting(arr, i, j);
		}

		else if (arr[i][j] == 5)
		{
			arr[i][j + 1] = 55;
			shifting(arr, i, j);
		}
	}


	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2]) && (arr[i][j] == arr[i][j - 1]))
	{
		if (arr[i][j] == 1)
		{
			arr[i][j - 1] = 11;
			shifting(arr, i, j);
		}

		else if (arr[i][j] == 2)
		{
			arr[i][j - 1] = 22;
			shifting(arr, i, j);
		}


		else if (arr[i][j] == 3)
		{
			arr[i][j - 1] = 33;
			shifting(arr, i, j);
		}
		else if (arr[i][j] == 4)
		{
			arr[i][j - 1] = 44;
			shifting(arr, i, j);
		}
		else if (arr[i][j] == 5)
		{
			arr[i][j - 1] = 55;
			shifting(arr, i, j);
		}
	}



	else if ((arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i - 2][j]) && (arr[i][j] == arr[i + 1][j]))
	{
		if (arr[i][j] == 1)
		{
			arr[i + 1][j] = 11;
			shifting(arr, i, j);
		}

		else if (arr[i][j] == 2)
		{
			arr[i + 1][j] = 22;
			shifting(arr, i, j);
		}

		else if (arr[i][j] == 3)
		{
			arr[i + 1][j] = 33;
			shifting(arr, i, j);
		}

		else if (arr[i][j] == 4)
		{
			arr[i + 1][j] = 44;
			shifting(arr, i, j);
		}

		else if (arr[i][j] == 5)
		{
			arr[i + 1][j] = 55;
			shifting(arr, i, j);
		}
	}

	else if ((arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j]) && arr[i][j] == arr[i - 1][j])
	{
		if (arr[i][j] == 1)
		{
			arr[i - 1][j] = 11;
			shifting(arr, i, j);

		}
		else if (arr[i][j] == 2)
		{
			arr[i - 1][j] = 22;
			shifting(arr, i, j);
		}
		else if (arr[i][j] == 3)
		{
			arr[i - 1][j] = 33;
			shifting(arr, i, j);
		}
		else if (arr[i][j] == 4)
		{
			arr[i - 1][j] = 44;
			shifting(arr, i, j);
		}
		else if (arr[i][j] == 5)
		{
			arr[i - 1][j] = 55;
			shifting(arr, i, j);
		}
	}

	
}

void comparison_wrapped(int arr[][50], int i, int j)
{
	if ((arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2]))
	{
		if (arr[i][j] == 1)
		{
			arr[i + 1][j] = 111;
		}

		else if (arr[i][j] == 2)
		{
			arr[i + 1][j] = 222;
		}
		else if (arr[i][j] == 3)
		{
			arr[i + 1][j] = 333;
		}
		else if (arr[i][j] == 4)
		{
			arr[i + 1][j] = 444;
		}
		else if (arr[i][j] == 5)
		{
			arr[i + 1][j] = 555;
		}
		
		int x = i;
		for (; x != 0; x--)
			arr[x][j] = arr[x - 1][j];
		int y = j + 1;
		for (; y < j + 3; y++)
			arr[i][y] = arr[i - 1][y];
		arr[0][j] = rand() % 5 + 1;
		arr[1][j] = rand() % 5 + 1;
		arr[0][j + 1] = rand() % 5 + 1;
		arr[0][j + 2] = rand() % 5 + 1;
		
	} 
	else if ((arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2]))
	{
		if (arr[i][j] == 1)
		{
			arr[i + 1][j] = 111;
		}

		else if (arr[i][j] == 2)
		{
			arr[i + 1][j] = 222;
		}
		else if (arr[i][j] == 3)
		{
			arr[i + 1][j] = 333;
		}
		else if (arr[i][j] == 4)
		{
			arr[i + 1][j] = 444;
		}
		else if (arr[i][j] == 5)
		{
			arr[i + 1][j] = 555;
		}
		int x = i;
		int y = j - 1;
		for (x; x != 0; x--)
		{
			arr[x][j] = arr[x - 1][j];
		}
		for (y; y > j - 3; y--)
		{
			for (x; x != 0; x++)
			{
				arr[x][y] = arr[x - 1][y];
			}
		}
		arr[0][j] = rand() % 5 + 1;
		arr[1][j] = rand() % 5 + 1;
		arr[0][j - 1] = rand() % 5 + 1;
		arr[0][j - 2] = rand() % 5 + 1;
	}//3
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j]))
	{
		if (arr[i][j] == 1)
		{
			arr[i + 2][j] = 111;
		}

		else if (arr[i][j] == 2)
		{
			arr[i + 2][j] = 222;
		}
		else if (arr[i][j] == 3)
		{
			arr[i + 2][j] = 333;
		}
		else if (arr[i][j] == 4)
		{
			arr[i + 2][j] = 444;
		}
		else if (arr[i][j] == 5)
		{
			arr[i + 2][j] = 555;
		}
		int x = i + 1;
		for (; x != 1; x--)
			arr[x][j] = arr[x - 2][j];
		int y = j - 1;
		for (; y < j + 4; y = y + 2)
		{
			for (x = i; x != 0; x--)
				arr[x][y] = arr[x - 1][y];
		}
		arr[0][j] = rand() % 5 + 1;
		arr[1][j] = rand() % 5 + 1;
		arr[0][j - 1] = rand() % 5 + 1;
		arr[0][j + 1] = rand() % 5 + 1;

	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i - 2][j]))
	{
		if (arr[i][j] == 1)
		{
			arr[i][j - 1] = 111;
		}

		else if (arr[i][j] == 2)
		{
			arr[i][j - 1] = 222;
		}
		else if (arr[i][j] == 3)
		{
			arr[i][j - 1] = 333;
		}
		else if (arr[i][j] == 4)
		{
			arr[i][j - 1] = 444;
		}
		else if (arr[i][j] == 5)
		{
			arr[i][j - 1] = 555;
		}
		int x = i;
		for (; x != 2; x--)
			arr[x][j] = arr[x - 3][j];
		x = j + 1;
		for (; x != 0; x--)
			arr[x][j + 1] = arr[x - 1][j + 1];
		arr[0][j] = rand() % 5 + 1;
		arr[1][j] = rand() % 5 + 1;
		arr[2][j] = rand() % 5 + 1;
		arr[0][j + 1] = rand() % 5 + 1;
	}  
	else if ((arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2]))
	{
		if (arr[i][j] == 1)
		{
			arr[i + 2][j] = 111;
		}

		else if (arr[i][j] == 2)
		{
			arr[i + 2][j] = 222;
		}
		else if (arr[i][j] == 3)
		{
			arr[i + 2][j] = 333;
		}
		else if (arr[i][j] == 4)
		{
			arr[i + 2][j] = 444;
		}
		else if (arr[i][j] == 5)
		{
			arr[i + 2][j] = 555;
		}

		int x = i;
		int y = i + 1;
		for (y; y != 1; y--)
			arr[y][j] = arr[y - 2][j];

		x = i;
		y = j + 1;
		for (y; y < j + 2; y++)
		{
			for (x; x >= 0; x--)
				arr[x][y] = arr[x - 1][y];
		}
		arr[0][j] = rand() % 5 + 1;
		arr[1][j] = rand() % 5 + 1;
		arr[0][j + 1] = rand() % 5 + 1;
		arr[0][j + 2] = rand() % 5 + 1;
	} //6
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2]) && (arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j]))
	{
		if (arr[i][j] == 1)
		{
			arr[i + 2][j] = 111;
		}

		else if (arr[i][j] == 2)
		{
			arr[i + 2][j] = 222;
		}
		else if (arr[i][j] == 3)
		{
			arr[i + 2][j] = 333;
		}
		else if (arr[i][j] == 4)
		{
			arr[i + 2][j] = 444;
		}
		else if (arr[i][j] == 5)
		{
			arr[i + 2][j] = 555;
		}

		int y = i + 1;
		for (y; y != 1; y--)
			arr[y][j] = arr[y - 2][j];

		int	x = i;
		y = j - 1;
		for (y; y > j - 2; y--)
		{
			for (x; x >= 0; x--)
				arr[x][y] = arr[x - 1][y];
		}
		arr[0][j] = rand() % 5 + 1;
		arr[1][j] = rand() % 5 + 1;
		arr[0][j - 1] = rand() % 5 + 1;
		arr[0][j - 2] = rand() % 5 + 1;
	}  //7
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2]) && (arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i - 2][j]))
	{
		if (arr[i][j] == 1)
		{
			arr[i][j] = 111;
		}

		else if (arr[i][j] == 2)
		{
			arr[i][j] = 222;
		}
		else if (arr[i][j] == 3)
		{
			arr[i][j] = 333;
		}
		else if (arr[i][j] == 4)
		{
			arr[i][j] = 444;
		}
		else if (arr[i][j] == 5)
		{
			arr[i][j] = 555;
		}

		int x = i;
		int y = j - 1;
		for (; y > j - 3; y--)
		{
			for (x = i; x > 0; x--)
				arr[x][y] = arr[x - 1][y];
		}
		x = i - 1;
		y = j;
		for (; x != 0; x--)
			arr[x][j] = arr[x - 2][j];
		arr[0][j] = rand() % 5 + 1;
		arr[1][j] = rand() % 5 + 1;
		arr[0][j - 1] = rand() % 5 + 1;
		arr[0][j - 2] = rand() % 5 + 1;
	}//8
	else if ((arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i - 2][j]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2]))
	{
		if (arr[i][j] == 1)
		{
			arr[i][j + 2] = 111;
		}

		else if (arr[i][j] == 2)
		{
			arr[i][j + 2] = 222;
		}
		else if (arr[i][j] == 3)
		{
			arr[i][j + 2] = 333;
		}
		else if (arr[i][j] == 4)
		{
			arr[i][j + 2] = 444;
		}
		else if (arr[i][j] == 5)
		{
			arr[i][j + 2] = 555;
		}
		int x = i;
		for (; x != 2; x--)
			arr[x][j] = arr[x - 3][j];
		for (int y = j + 1; y < j + 2; y++)
		{
			for (x = i; x != 0; x--)
				arr[x][y] = arr[x - 1][y];
		}
		arr[0][j] = rand() % 5 + 1;
		arr[1][j] = rand() % 5 + 1;
		arr[2][j] = rand() % 5 + 1;
		arr[i][j + 1] = rand() % 5 + 1;
	}
}

void search(int arr[][50], int i, int j, int size)
{
	for (int x = size; x >= 0; x--)
	{
		for (int y = 0; y < size; y++)
		{
			if (((arr[x][y] == arr[x][y - 1]) && (arr[x][y] == arr[x][y - 2])) || ((arr[x][y] == arr[x][y + 1]) && (arr[x][y] == arr[x][y + 2])) || ((arr[x][y] == arr[x][y - 1]) && (arr[x][y] == arr[x][y + 1])) || ((arr[x][y] == arr[x + 2][y]) && (arr[x][y] == arr[x + 1][y])) || ((arr[x][y] == arr[x - 2][y]) && (arr[x][y] == arr[x - 1][y])) || ((arr[x][y] == arr[x - 1][y]) && (arr[x][y] == arr[x + 1][y])))
			{
				shifting(arr, x, y);
			}
		}
	}
}



void plainandstripped(int arr[][50], int i, int j, int size)
{
	int temp;
	temp = arr[i][j];
	if ((arr[i][j] == arr[i][j + 1]) && ((arr[i][j] == 1 && arr[i][j + 1] == 1)))
	{
		if (arr[i][j + 2] == 11)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 2] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 1 && arr[i][j - 1] == 1))
	{
		if (arr[i][j - 2] == 11)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 2] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == 2 && arr[i][j + 1] == 2))
	{
		if (arr[i][j + 2] == 22)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 2] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 2 && arr[i][j - 1] == 2))
	{
		if (arr[i][j - 2] == 22)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 2] = rand() % 5 + 1;
			}
		}
	}

	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == 3 && arr[i][j + 1] == 3))
	{
		if (arr[i][j + 2] == 33)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 2] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 3 && arr[i][j - 1] == 3))
	{
		if (arr[i][j - 2] == 33)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 2] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == 4 && arr[i][j + 1] == 4))
	{
		if (arr[i][j + 2] == 44)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 2] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 4 && arr[i][j - 1] == 4))
	{
		if (arr[i][j - 2] == 44)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 2] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == 5 && arr[i][j + 1] == 5))
	{
		if (arr[i][j + 2] == 55)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 2] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 5 && arr[i][j - 1] == 5))
	{
		if (arr[i][j - 2] == 55)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 2] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 1 && arr[i + 1][j] == 1))
	{
		if (arr[i + 2][j] == 11)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 1 && arr[i - 1][j] == 1))
	{
		if (arr[i - 2][j] == 11)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 2 && arr[i + 1][j] == 2))
	{
		if (arr[i + 2][j] == 22)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 2 && arr[i - 1][j] == 2))
	{
		if (arr[i - 2][j] == 22)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 3 && arr[i + 1][j] == 3))
	{
		if (arr[i + 2][j] == 33)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 3 && arr[i - 1][j] == 3))
	{
		if (arr[i - 2][j] == 33)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 4 && arr[i + 1][j] == 4))
	{
		if (arr[i + 2][j] == 44)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 4 && arr[i - 1][j] == 4))
	{
		if (arr[i - 2][j] == 44)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 5 && arr[i + 1][j] == 5))
	{
		if (arr[i + 2][j] == 55)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 5 && arr[i - 1][j] == 5))
	{
		if (arr[i - 2][j] == 55)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 2][a] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 1 && arr[i][j + 2] == 1))
	{
		if (arr[i][j + 1] == 11)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 1 && arr[i][j - 2] == 1))
	{
		if (arr[i][j - 1] == 11)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 2 && arr[i][j + 2] == 2))
	{
		if (arr[i][j + 1] == 22)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 2 && arr[i][j - 2] == 2))
	{
		if (arr[i][j - 1] == 22)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 3 && arr[i][j + 2] == 3))
	{
		if (arr[i][j + 1] == 33)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 3 && arr[i][j - 2] == 3))
	{
		if (arr[i][j - 1] == 33)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 4 && arr[i][j + 2] == 4))
	{
		if (arr[i][j + 1] == 44)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 4 && arr[i][j - 2] == 4))
	{
		if (arr[i][j - 1] == 44)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 5 && arr[i][j + 2] == 5))
	{
		if (arr[i][j + 1] == 55)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j + 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 5 && arr[i][j - 2] == 5))
	{
		if (arr[i][j - 1] == 5)
		{
			for (int a = 0; a < size; a++)
			{
				arr[a][j - 1] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 1 && arr[i + 2][j] == 1))
	{
		if (arr[i + 1][j] == 11)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 1][j] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 1 && arr[i - 2][j] == 1))
	{
		if (arr[i - 1][j] == 11)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 1][j] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 2 && arr[i + 2][j] == 2))
	{
		if (arr[i + 1][j] == 22)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 1][j] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 2 && arr[i - 2][j] == 2))
	{
		if (arr[i - 1][j] == 22)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 1][j] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 3 && arr[i + 2][j] == 3))
	{
		if (arr[i + 1][j] == 33)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 1][j] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 3 && arr[i - 2][j] == 3))
	{
		if (arr[i - 1][j] == 33)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 1][j] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 4 && arr[i + 2][j] == 4))
	{
		if (arr[i + 1][j] == 44)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 1][j] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 4 && arr[i - 2][j] == 4))
	{
		if (arr[i - 1][j] == 44)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 1][j] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 5 && arr[i + 2][j] == 5))
	{
		if (arr[i + 1][j] == 55)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i + 1][j] = rand() % 5 + 1;
			}
		}
	}
	else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 5 && arr[i - 2][j] == 5))
	{
		if (arr[i - 1][j] == 55)
		{
			for (int a = 0; a < size; a++)
			{
				arr[i - 1][j] = rand() % 5 + 1;
			}
		}
	}
}

void stripwrap(int arr[][50], int i, int j, int m, int n, int& s)
{
	if (((arr[i][j] == 111 || arr[i][j] == 222 || arr[i][j] == 333 || arr[i][j] == 444 || arr[i][j] == 555) && (arr[m][n] == 11 || arr[m][n] == 22 || arr[m][n] == 33 || arr[m][n] == 44 || arr[m][n] == 55)) || ((arr[m][n] == 111 || arr[m][n] == 222 || arr[m][n] == 333 || arr[m][n] == 444 || arr[m][n] == 555) && (arr[i][j] == 11 || arr[i][j] == 22 || arr[i][j] == 33 || arr[i][j] == 44 || arr[m][n] == 55)))
	{
		int x = i - 1;
		int y = j - 1;
		int temp = 0;
		int a = i - 1;
		int b = 0;
		s = s + 30 * 40;
		for (temp = 0; temp < 3; temp++, a++)
		{
			for (b = 0; b < 30; b++)
				arr[a][b] = rand() % 5 + 1;
		}
		b = j - 1;
		for (temp = 0; temp < 3; temp++, b++)
		{
			for (a = 0; a < 30; a++)
				arr[a][b] = rand() % 5 + 1;
		}
	}
}

void plainandwrapped(int arr[][50], int i, int j, int size)
{
	int a = i;

	if ((arr[i][j] == arr[i][j + 1]) && ((arr[i][j] == 1 && arr[i][j + 1] == 1)))
	{
		if (arr[i][j + 2] == 111)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 1 && arr[i][j - 1] == 1))
	{
		if (arr[i][j - 2] == 111)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == 2 && arr[i][j + 1] == 2))
	{
		if (arr[i][j + 2] == 222)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 2 && arr[i][j - 1] == 2))
	{
		if (arr[i][j - 2] == 222)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}

	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == 3 && arr[i][j + 1] == 3))
	{
		if (arr[i][j + 2] == 333)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 3 && arr[i][j - 1] == 3))
	{
		if (arr[i][j - 2] == 333)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == 4 && arr[i][j + 1] == 4))
	{
		if (arr[i][j + 2] == 444)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 4 && arr[i][j - 1] == 4))
	{
		if (arr[i][j - 2] == 444)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == 5 && arr[i][j + 1] == 5))
	{
		if (arr[i][j + 2] == 555)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b < j + 4; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == 5 && arr[i][j - 1] == 5))
	{
		if (arr[i][j - 2] == 555)
		{
			for (a = i + 1; a > 2; a--)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j - 3; b < j; b++)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 1 && arr[i + 1][j] == 1))
	{
		if (arr[i + 2][j] == 111)
		{
			for (a = i + 3; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 1 && arr[i - 1][j] == 1))
	{
		if (arr[i - 2][j] == 111)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	
	else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 2 && arr[i - 1][j] == 2))
	{
		if (arr[i - 2][j] == 222)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
    else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 2 && arr[i + 1][j] == 2))
	{
		if (arr[i + 2][j] == 222)
		{
			for (a = i + 3; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
    else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 3 && arr[i - 1][j] == 3))
	{
		if (arr[i - 2][j] == 333)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}

	}
	else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 3 && arr[i + 1][j] == 3))
	{
		if (arr[i + 2][j] == 333)
		{
			for (a = i + 3; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	
	else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 4 && arr[i + 1][j] == 4))
	{
		if (arr[i + 2][j] == 444)
		{
			for (a = i + 3; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 4 && arr[i - 1][j] == 4))
	{
		if (arr[i - 2][j] == 44)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
    else if ((arr[i][j] = arr[i - 1][j]) && (arr[i][j] == 5 && arr[i - 1][j] == 5))
	{
		if (arr[i - 2][j] == 555)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}

	else if ((arr[i][j] = arr[i + 1][j]) && (arr[i][j] == 5 && arr[i + 1][j] == 5))
	{
		if (arr[i + 2][j] == 555)
		{
			for (a = i + 3; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 1 && arr[i][j + 2] == 1))
	{
		if (arr[i][j + 1] == 111)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}

	}
	else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 1 && arr[i][j - 2] == 1))
	{
		if (arr[i][j - 1] == 111)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
    else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 2 && arr[i][j - 2] == 2))
	{
		if (arr[i][j - 1] == 222)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 2 && arr[i][j + 2] == 2))
	{
		if (arr[i][j + 1] == 222)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
    else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 3 && arr[i][j - 2] == 3))
	{
		if (arr[i][j - 1] == 333)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
	
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 3 && arr[i][j + 2] == 3))
	{
		if (arr[i][j + 1] == 333)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 4 && arr[i][j + 2] == 4))
	{
		if (arr[i][j + 1] == 444)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 4 && arr[i][j - 2] == 4))
	{
		if (arr[i][j - 1] == 444)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
    else if ((arr[i][j] == arr[i][j - 2]) && (arr[i][j] == 5 && arr[i][j - 2] == 5))
	{
		if (arr[i][j - 1] == 555)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}
		}
	}
	else if ((arr[i][j] == arr[i][j + 2]) && (arr[i][j] == 5 && arr[i][j + 2] == 5))
	{
		if (arr[i][j + 1] == 555)
		{
			for (a = i - 1; a > 2; a--)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 2; b > j - 1; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
    else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 1 && arr[i - 2][j] == 1))
	{
		if (arr[i - 1][j] == 111)
		{
			for (a = i; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
	
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 1 && arr[i + 2][j] == 1))
	{
		if (arr[i + 1][j] == 111)
		{
			for (a = i + 2; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
    else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 2 && arr[i - 2][j] == 2))
	{
		if (arr[i - 1][j] == 222)
		{
			for (a = i; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
	
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 2 && arr[i + 2][j] == 2))
	{
		if (arr[i + 1][j] == 222)
		{
			for (a = i + 2; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
	
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 3 && arr[i + 2][j] == 3))
	{
		if (arr[i + 1][j] == 333)
		{
			for (a = i + 2; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
	else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 3 && arr[i - 2][j] == 3))
	{
		if (arr[i - 1][j] == 333)
		{
			for (a = i; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
    else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 4 && arr[i - 2][j] == 4))
	{
		if (arr[i - 1][j] == 444)
		{
			for (a = i; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 4 && arr[i + 2][j] == 4))
	{
		if (arr[i + 1][j] == 444)
		{
			for (a = i + 2; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
	
	else if ((arr[i][j] == arr[i + 2][j]) && (arr[i][j] == 5 && arr[i + 2][j] == 5))
	{
		if (arr[i + 1][j] == 555)
		{
			for (a = i + 2; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
	else if ((arr[i][j] == arr[i - 2][j]) && (arr[i][j] == 5 && arr[i - 2][j] == 5))
	{
		if (arr[i - 1][j] == 555)
		{
			for (a = i; a > 2; a--)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = arr[a - 3][b];
				}
			}
		}
		if (a <= 2)
		{
			for (; a <= 0; a++)
			{
				for (int b = j + 1; b > j - 2; b--)
				{
					arr[a][b] = rand() % 5 + 1;
				}
			}

		}
	}
}

void c_b_shifting(int arr[][50], int i, int j, int size)
{
	for (int x = i; i > 0; i--)
	{
		arr[x][j] = arr[x - 1][j];
	}
	arr[0][j] = rand() % 5 + 1;
}

void c_b_plaincandy(int arr[][50], int i, int j, int m, int n, int size, int& s)
{
	if (arr[i][j] == 0 && arr[m][n] == 1)
	{
		for (int x = size; x >= 0; x--)
		{
			for (int y = 0; y < size; y++)
			{
				if (arr[x][y] == 1)
				{

					c_b_shifting(arr, x, y, size);
					s = s + 30;
				}
			}
		}
		arr[i][j] = 2;
	}
	else if (arr[i][j] == 0 && arr[m][n] == 2)
	{
		for (int x = size; x >= 0; x--)
		{
			for (int y = 0; y < size; y++)
			{
				if (arr[x][y] == 2)
				{
					c_b_shifting(arr, x, y, size);
					s = s + 30;

				}
			}
		}
		arr[i][j] = 1;

	}
	else if (arr[i][j] == 0 && arr[m][n] == 3)
	{
		for (int x = size; x >= 0; x--)
		{
			for (int y = 0; y < size; y++)
			{
				if (arr[x][y] == 3)
				{
					c_b_shifting(arr, x, y, size);
					s = s + 40;

				}
			}
		}
		arr[i][j] = 2;
	}
	else if (arr[i][j] == 0 && arr[m][n] == 4)
	{
		for (int x = size; x >= 0; x--)
		{
			for (int y = 0; y < size; y++)
			{
				if (arr[x][y] == 4)
				{
					c_b_shifting(arr, x, y, size);
					s = s + 50;

				}
			}
		}
		arr[i][j] = 2;

	}
	else if (arr[i][j] == 0 && arr[m][n] == 5)
	{
		for (int x = size; x >= 0; x--)
		{
			for (int y = 0; y < size; y++)
			{
				if (arr[x][y] == 5)
				{
					c_b_shifting(arr, x, y, size);
					s = s + 60;

				}
			}
		}
	}
	arr[i][j] = 2;
}

void c_b(int arr[][50], int i, int j)  
{
	int x = i;
	if ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2]) && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
	{
		arr[i][j + 2] = 0;

		for (x = i; x < 0; x--)
		{
			for (int y = j - 1; y < j + 2; y++)
			{
				arr[x][y] = arr[x - 1][y];
			}
		}
		if (x == 0)
		{
			for (int y = j - 1; y < j + 2; y++)
			{
				arr[x][y] = rand() % 5 + 1;
			}
		}

	}
	else if ((arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j]) && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j])
	{
		int y = i + 1;
		arr[i + 2][j] = 0;
		for (y = i + 1; y < 4; y--)
		{
			arr[y][j] = arr[y - 4][j];
		}
		if (y <= 4)
		{
			for (y = i + 1; y < 4; y--)
			{
				arr[y][j] = rand() % 5 + 1;
			}
		}
	}
}


void score(int arr[][50], int x, int y, int& s)
{

	int i = x, j = y;
	if (((arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2])) || ((arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2])) || ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j])) || ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i - 2][j])) || ((arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2])) || ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2]) && (arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j])) || ((arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2]) && (arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i - 2][j])) || ((arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i - 2][j]) && (arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2])))
	{
		if (arr[x][y] == 1 || arr[x][y] == 2)
		{
			s = s + 30 * 5;
		}
		else if (arr[x][y] == 3)
		{
			s = s + 40 * 5;
		}
		else if (arr[x][y] == 4)
		{
			s = s + 50 * 5;
		}
		else if (arr[x][y] == 5)
		{
			s = s + 60 * 5;
		}
	}
	else if (((arr[x][y] == arr[x][y - 1]) && (arr[x][y] == arr[x][y - 2]) && (arr[x][y] == arr[x][y + 1])) || ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2]) && (arr[i][j] == arr[i][j - 1])) || ((arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i - 2][j]) && (arr[i][j] == arr[i + 1][j])) || ((arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 2][j]) && arr[i][j] == arr[i - 1][j]) || ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j - 1]) && (arr[i][j] == arr[i][j - 2])) || ((arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i - 1][j]) && (arr[i][j] == arr[i + 2][j])))
	{
		if (arr[x][y] == 1 || arr[x][y] == 2)
		{
			s = s + 30 * 4;
		}
		else if (arr[x][y] == 3)
		{
			s = s + 40 * 4;
		}
		else if (arr[x][y] == 4)
		{
			s = s + 50 * 4;
		}
		else if (arr[x][y] == 5)
		{
			s = s + 60 * 4;
		}
	}
	else if (((arr[x][y] == arr[x][y - 1]) && (arr[x][y] == arr[x][y - 2])) || ((arr[x][y] == arr[x][y + 1]) && (arr[x][y] == arr[x][y + 2])) || ((arr[x][y] == arr[x][y - 1]) && (arr[x][y] == arr[x][y + 1])) || ((arr[x][y] == arr[x + 2][y]) && (arr[x][y] == arr[x + 1][y])) || ((arr[x][y] == arr[x - 2][y]) && (arr[x][y] == arr[x - 1][y])) || ((arr[x][y] == arr[x - 1][y]) && (arr[x][y] == arr[x + 1][y])))
	{
		if (arr[x][y] == 1 || arr[x][y] == 2)
		{
			s = s + 30 * 3;
		}
		else if (arr[x][y] == 3)
		{
			s = s + 40 * 3;
		}
		else if (arr[x][y] == 4)
		{
			s = s + 50 * 3;
		}
		else if (arr[x][y] == 5)
		{
			s = s + 60 * 3;
		}
	}
}

void print(int arr[][50], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " " << " " << " ";
		}
		cout << endl << endl;
	}

	

}


void savegame(int arr[][50], int size, int Turns, int Score)
{
	int i, j;
	ofstream fout;
	fout.open("saved.txt");

	if (!fout)
		cout << "Error ! File not found.";
	else {
		fout << size;
		fout << endl << Score;
		fout << endl << Turns << endl;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				fout << arr[i][j] << " " << " ";
			}
			fout << endl;
		}


		fout.close();

		cout << "Game Saved";
	}

}
 //for game loading 

void loadgame(int arr[][50], int& size, int& Turns, int& Score)
{
	int i, j, temp;
	ifstream fin;
	fin.open("saved.txt");
	if (!fin)
	{
		cout << "Error ! File not found.";
	}
	else
	{
		fin >> temp;
		size = temp;
		fin >> temp;
		Score = temp;
		fin >> temp;
		Turns = temp;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				fin >> temp;
				arr[i][j] = temp;
			}
		}

		fin.close();

		cout << "Game loaded";
	}
}