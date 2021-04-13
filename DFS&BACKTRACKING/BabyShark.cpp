#include <iostream>
using namespace std;

int MAX = 1;
int DR[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int DC[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int MAP[4][4];
int DIR[4][4];
int S_R, S_C;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void change_dir(int *dir)
{
	if (*dir < 7)
		*dir += 1;
	else
		*dir = 0;
}

void DFS(int cnt, int map[4][4], int dir[4][4])
{
	int copy_m[4][4];
	int copy_d[4][4];
	int r, c;
	int idx = 0;
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			copy_m[i][j] = map[i][j];
			copy_d[i][j] = dir[i][j];
		}
	}

	// fish move
	for (int i = 1; i <= 16; i++)
	{
		int spin = 0;

		// find index of num
		for (r = 0; r < 4; r++)
		{
			for (c = 0; c < 4; c++)
				if (copy_m[r][c] == i)
					break;
			if (c != 4)
				break;
		}
		// not found
		if (r == 4 && c == 4)
			continue;
		// check
		while (r + DR[copy_d[r][c]] < 0 || r + DR[copy_d[r][c]] >= 4 || c + DC[copy_d[r][c]] < 0 || c + DC[copy_d[r][c]] >= 4 || copy_m[r + DR[copy_d[r][c]]][c + DC[copy_d[r][c]]] == -1)
		{
			spin++;
			change_dir(&copy_d[r][c]);
			if (spin == 8)
				break;
		}
		if (spin != 8)
		{
			swap(copy_m[r][c], copy_m[r + DR[copy_d[r][c]]][c + DC[copy_d[r][c]]]);
			swap(copy_d[r][c], copy_d[r + DR[copy_d[r][c]]][c + DC[copy_d[r][c]]]);
		}
	}

	// shark
	int temp_r = S_R;
	int temp_c = S_C;
	for (int i = 1; i < 4; i++)
	{
		S_R += DR[dir[temp_r][temp_c]] * i;
		S_C += DC[dir[temp_r][temp_c]] * i;
		if (S_R >= 0 && S_R < 4 && S_C >= 0 && S_C < 4)
		{
			if (copy_m[S_R][S_C] != 0)
			{
				int val = copy_m[S_R][S_C];

				copy_m[S_R][S_C] = -1;
				copy_m[temp_r][temp_c] = 0;
				if (cnt + val > MAX)
					MAX = cnt + val;

			/*	cout << S_R << "," << S_C << endl;
				for (int r = 0; r < 4; r++)
				{
					for (int c = 0; c < 4; c++)
						cout << copy_m[r][c] << " ";
					cout << endl;
				}
				cout << endl;*/

				DFS(cnt + val, copy_m, copy_d);
				copy_m[temp_r][temp_c] = -1;
				copy_m[S_R][S_C] = val;
			}
		}
		S_R -= DR[dir[temp_r][temp_c]] * i;
		S_C -= DC[dir[temp_r][temp_c]] * i;
	}
}

int main()
{
	int val;

	ios::sync_with_stdio(false);
	cin.tie(0);
	// input
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> MAP[i][j] >> DIR[i][j];
			DIR[i][j]--;
		}
	}
	// initialize
	S_R = 0, S_C = 0;
	val = MAP[0][0];
	MAP[0][0] = -1;
	DFS(val, MAP, DIR);
	cout << MAX;
	return (0);
}