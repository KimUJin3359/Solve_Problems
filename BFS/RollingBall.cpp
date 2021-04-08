#include <iostream>
using namespace std;

int RES = 11;
int M, N;
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };
char MAP[10][10];

void DFS(int red_r, int red_c, int blue_r, int blue_c, int cnt)
{
	int r_r, r_c;
	int b_r, b_c;
	int b_inhole;

	if (cnt >= 10 || RES <= cnt)
		return;
	for (int i = 0; i < 4; i++)
	{
		b_inhole = 0;
		// BLUE FIRST
		b_r = blue_r;
		b_c = blue_c;
		while (MAP[b_r + DR[i]][b_c + DC[i]] != '#')
		{
			b_r += DR[i];
			b_c += DC[i];
			if (MAP[b_r][b_c] == 'O')
			{
				b_inhole = 1;
				break;
			}
		}
		if (b_inhole)
			continue;
		// RED SECOND
		r_r = red_r;
		r_c = red_c;
		while (MAP[r_r + DR[i]][r_c + DC[i]] != '#')
		{
			r_r += DR[i];
			r_c += DC[i];
			if (MAP[r_r][r_c] == 'O')
			{
				//cout << "red_r : " << red_r << ", red_c : " << red_c << ", blue_r : " << blue_r << ", blue_c : " << blue_c << ", cnt : " << cnt  << "dir : " << i << endl;
				if (RES > cnt + 1)
					RES = cnt + 1;
				return;
			}
		}
		// IF DUPLICATE
		if (r_r == b_r && r_c == b_c)
		{
			if (i == 0)
			{
				if (red_r < blue_r)
					b_r += 1;
				else
					r_r += 1;
			}
			else if (i == 1)
			{
				if (red_r < blue_r)
					r_r -= 1;
				else
					b_r -= 1;
			}
			else if (i == 2)
			{
				if (red_c < blue_c)
					b_c += 1;
				else
					r_c += 1;
			}
			else
			{
				if (red_c < blue_c)
					r_c -= 1;
				else
					b_c -= 1;
			}
		}
		DFS(r_r, r_c, b_r, b_c, cnt + 1);
	}
}

int main()
{
	int r_r, r_c, b_r, b_c;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	// map input
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 'R')
			{
				r_r = i;
				r_c = j;
				MAP[i][j] = '.';
			}
			if (MAP[i][j] == 'B')
			{
				b_r = i;
				b_c = j;
				MAP[i][j] = '.';
			}
		}
	}
	// DFS
	DFS(r_r, r_c, b_r, b_c, 0);
	if (RES == 11)
		cout << -1;
	else
		cout << RES;
	return (0);
}