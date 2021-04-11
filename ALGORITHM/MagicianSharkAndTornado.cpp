#include <iostream>
using namespace std;

int A[499][499];
int PRO[9] = { 5, 10, 10, 7, 7, 2, 2, 1, 1 };
// LEFT, DOWN, RIGHT, UP
int DR[4][9] = { {0, -1, 1, -1, 1, -2, 2, -1, 1}, {2, 1, 1, 0, 0, 0, 0, -1, -1}, {0, -1, 1, -1, 1, -2, 2, -1, 1}, {-2, -1, -1, 0, 0, 0, 0, 1, 1} };
int DC[4][9] = { {-2, -1, -1, 0, 0, 0, 0, 1, 1}, {0, -1, 1, -1, 1, -2, 2, -1, 1}, {2, 1, 1, 0, 0, 0, 0, -1, -1}, {0, -1, 1, -1, 1, -2, 2, -1, 1} };
int DR_R[4] = { 0, 1, 0, -1 };
int DC_C[4] = { -1, 0, 1, 0 };
int DIR = 0;
int N;
int RES = 0;

void change_dir()
{
	if (DIR == 0)
		DIR = 1;
	else if (DIR == 1)
		DIR = 2;
	else if (DIR == 2)
		DIR = 3;
	else
		DIR = 0;
}

void move(int r, int c, int dir)
{
	int sum = 0;
	int pro;

	if (A[r][c] != 0)
	{
		for (int i = 0; i < 9; i++)
		{
			pro = PRO[i] * A[r][c] / 100;
			if (r + DR[dir][i] < 0 || r + DR[dir][i] >= N || c + DC[dir][i] < 0 || c + DC[dir][i] >= N)
				RES += pro;
			else
				A[r + DR[dir][i]][c + DC[dir][i]] += pro;
			sum += pro;
		}
		if (r + DR_R[dir] < 0 || r + DR_R[dir] >= N || c + DC_C[dir] < 0 || c + DC_C[dir] >= N)
			RES += A[r][c] - sum;
		else
			A[r + DR_R[dir]][c + DC_C[dir]] += A[r][c] - sum;
		A[r][c] = 0;
	}
}

int main()
{
	int r, c;

	ios::sync_with_stdio(false);
	cin.tie(0);
	// initialize
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	}
	// move tornado
	r = N / 2;
	c = N / 2;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < i; k++)
			{
				r += DR_R[DIR];
				c += DC_C[DIR];
				move(r, c, DIR);
			}
			change_dir();
		}
	}
	for (int k = 0; k < N; k++)
	{
		r += DR_R[DIR];
		c += DC_C[DIR];
		move(r, c, DIR);
	}
	cout << RES;
	return (0);
}