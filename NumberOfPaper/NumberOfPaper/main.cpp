#include <iostream>

using namespace std;

int SIZE;
int num[3] = { 0, };
int **map;

int get_count(int size, int row, int col)
{
	int small_size = SIZE / 3;
	int flag = 0;
	int val = map[row * small_size][col * small_size];
	int i, j;

	for (i = row * small_size; i < (row + 1) * small_size; i++)
	{
		for (j = col * small_size; j < (col + 1) * small_size; j++)
		{
			if (val != map[i][j])
			{
				i = (row + 1) * small_size + 1;
				break;
			}
		}
	}
	if (i == (row + 1) * small_size && j == (col + 1) * small_size)

		
}

int main()
{
	cin >> SIZE;
	map = new int*[SIZE];
	for (int i = 0; i < SIZE; i++)
		map[i] = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cin >> map[i][j];
	}

}