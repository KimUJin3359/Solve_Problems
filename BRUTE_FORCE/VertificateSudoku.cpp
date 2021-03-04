#include <iostream>
using namespace std;

int map[9][9];
int check[9] = { 1, };

void set_check()
{
	for (int i = 0; i < 9; i++)
		check[i] = 1;
}

int check_row()
{
	for (int i = 0; i < 9; i++)
	{
		set_check();
		for (int j = 0; j < 9; j++)
		{
			if (check[(map[i][j] - 1)] == 1)
				check[(map[i][j] - 1)] = 0;
			else
				return (0);
		}
	}
	return (1);
}

int check_col()
{
	for (int i = 0; i < 9; i++)
	{
		set_check();
		for (int j = 0; j < 9; j++)
		{
			if (check[(map[j][i] - 1)] == 1)
				check[(map[j][i] - 1)] = 0;
			else
				return (0);
		}
	}
	return (1);
}

int check_box()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			set_check();
			for (int k = (i * 3); k < (i * 3) + 3; k++)
			{
				for (int t = (j * 3); t < (j * 3) + 3; t++)
				{
					if (check[(map[k][t] - 1)] == 1)
						check[(map[k][t] - 1)] = 0;
					else
						return (0);
				}
			}
		}
	}
	return (1);
}

int main()
{
	int C;

	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cin >> map[i][j];
		}
		if (check_row() && check_col() && check_box())
			cout << "#" << N << " 1" << endl;
		else
			cout << "#" << N << " 0" << endl;
	}
}