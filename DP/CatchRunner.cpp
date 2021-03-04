#include <iostream>
#define MAX 987654321
using namespace std;

int map[50][50];
int solve[50][50];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int row, col;
int st_r, st_c;
int T, R;

bool check_dir(int r, int c, int dir)
{
	int temp = map[r + dr[dir]][c + dc[dir]];
	if (dir == 0)
	{
		if (temp == 1 || temp == 2 || temp == 5 || temp == 6)
			return true;
	}
	else if (dir == 1)
	{
		if (temp == 1 || temp == 2 || temp == 4 || temp == 7)
			return true;
	}
	else if (dir == 2)
	{
		if (temp == 1 || temp == 3 || temp == 4 || temp == 5)
			return true;
	}
	else if (dir == 3)
	{
		if (temp == 1 || temp == 3 || temp == 6 || temp == 7)
			return true;
	}
	return (false);
}

void DP(int r, int c, int t)
{
	solve[r][c] = t;
	if (map[r][c] == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (r + dr[i] >= 0 && r + dr[i] < row && c + dc[i] >= 0 && c + dc[i] < col && check_dir(r, c, i))
			{
				if (solve[r + dr[i]][c + dc[i]] > t + 1)
					DP(r + dr[i], c + dc[i], t + 1);
			}
		}
	}
	else if (map[r][c] == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			if (r + dr[i] >= 0 && r + dr[i] < row && check_dir(r, c, i))
			{
				if (solve[r + dr[i]][c + dc[i]] > t + 1)
					DP(r + dr[i], c + dc[i], t + 1);
			}
		}
	}
	else if (map[r][c] == 3)
	{
		for (int i = 2; i < 4; i++)
		{
			if (c + dc[i] >= 0 && c + dc[i] < col && check_dir(r, c, i))
			{
				if (solve[r + dr[i]][c + dc[i]] > t + 1)
					DP(r + dr[i], c + dc[i], t + 1);
			}
		}
	}
	else if (map[r][c] == 4)
	{
		for (int i = 0; i < 4; i += 3)
		{
			if (r + dr[i] >= 0 && r + dr[i] < row && c + dc[i] >= 0 && c + dc[i] < col && check_dir(r, c, i))
			{
				if (solve[r + dr[i]][c + dc[i]] > t + 1)
					DP(r + dr[i], c + dc[i], t + 1);
			}
		}
	}
	else if (map[r][c] == 5)
	{
		for (int i = 1; i < 4; i += 2)
		{
			if (r + dr[i] >= 0 && r + dr[i] < row && c + dc[i] >= 0 && c + dc[i] < col && check_dir(r, c, i))
			{
				if (solve[r + dr[i]][c + dc[i]] > t)
					DP(r + dr[i], c + dc[i], t + 1);
			}
		}
	}
	else if (map[r][c] == 6)
	{
		for (int i = 1; i < 3; i++)
		{
			if (r + dr[i] >= 0 && r + dr[i] < row && c + dc[i] >= 0 && c + dc[i] < col && check_dir(r, c, i))
			{
				if (solve[r + dr[i]][c + dc[i]] > t)
					DP(r + dr[i], c + dc[i], t + 1);
			}
		}
	}
	else if (map[r][c] == 7)
	{
		for (int i = 0; i < 3; i += 2)
		{
			if (r + dr[i] >= 0 && r + dr[i] < row && c + dc[i] >= 0 && c + dc[i] < col && check_dir(r, c, i))
			{
				if (solve[r + dr[i]][c + dc[i]] > t)
					DP(r + dr[i], c + dc[i], t + 1);
			}
		}
	}
}

int main()
{
	int C;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		R = 0;
		cin >> row >> col;
		cin >> st_r >> st_c;
		cin >> T;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> map[i][j];
				solve[i][j] = MAX;
			}
		}
		DP(st_r, st_c, 1);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (solve[i][j] <= T)
					R++;
				if (solve[i][j] == 987654321)
					cout << 0;
				else
					cout << solve[i][j];
			}
			cout << endl;
		}
		cout << "#" << N << " " << R << endl;
	}
}