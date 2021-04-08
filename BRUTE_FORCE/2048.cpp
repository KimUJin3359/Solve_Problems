#include <iostream>
#include <string.h>
using namespace std;

int MAX = -1;
int N;
int MAP[20][20];


void solve(int cnt, int map[20][20])
{
	if (cnt == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (MAX < map[i][j])
					MAX = map[i][j];
			}
		}
		return;
	}

	int copy[20][20];
	int idx, lst;

	// UP
	memset(copy, 0, sizeof(copy));
	for (int c = 0; c < N; c++)
	{
		idx = 0;
		lst = 0;
		for (int r = 0; r < N; r++)
		{
			if (map[r][c] != 0)
			{
				if (lst == 0)
					lst = map[r][c];
				else
				{
					if (map[r][c] == lst)
					{
						copy[idx++][c] = lst * 2;
						lst = 0;
					}
					else
					{
						copy[idx++][c] = lst;
						lst = map[r][c];
					}
				}
			}
		}
		copy[idx++][c] = lst;
	}
	solve(cnt + 1, copy);

	// DOWN
	memset(copy, 0, sizeof(copy));
	for (int c = 0; c < N; c++)
	{
		idx = N - 1;
		lst = 0;
		for (int r = N - 1; r >= 0; r--)
		{
			if (map[r][c] != 0)
			{
				if (lst == 0)
					lst = map[r][c];
				else
				{
					if (map[r][c] == lst)
					{
						copy[idx--][c] = lst * 2;
						lst = 0;
					}
					else
					{
						copy[idx--][c] = lst;
						lst = map[r][c];
					}
				}
			}
		}
		copy[idx--][c] = lst;
	}
	solve(cnt + 1, copy);

	// LEFT
	memset(copy, 0, sizeof(copy));
	for (int r = 0; r < N; r++)
	{
		idx = 0;
		lst = 0;
		for (int c = 0; c < N; c++)
		{
			if (map[r][c] != 0)
			{
				if (lst == 0)
					lst = map[r][c];
				else
				{
					if (map[r][c] == lst)
					{
						copy[r][idx++] = lst * 2;
						lst = 0;
					}
					else
					{
						copy[r][idx++] = lst;
						lst = map[r][c];
					}
				}
			}
		}
		copy[r][idx++] = lst;
	}
	solve(cnt + 1, copy);

	// RIGHT
	memset(copy, 0, sizeof(copy));
	for (int r = 0; r < N; r++)
	{
		idx = N - 1;
		lst = 0;
		for (int c = N - 1; c >= 0; c--)
		{
			if (map[r][c] != 0)
			{
				if (lst == 0)
					lst = map[r][c];
				else
				{
					if (map[r][c] == lst)
					{
						copy[r][idx--] = lst * 2;
						lst = 0;
					}
					else
					{
						copy[r][idx--] = lst;
						lst = map[r][c];
					}
				}
			}
		}
		copy[r][idx--] = lst;
	}
	solve(cnt + 1, copy);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];
	}
	solve(0, MAP);
	cout << MAX;
	return (0);
}