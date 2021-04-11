#include <queue>
#include <iostream>
using namespace std;

queue <pair<int, int> > QUEUE;
int L[1024];
int A[64][64];	// A : MAP
bool V[64][64];
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };
int N, Q;	// N : size of a map(2 ^ N), Q : number of using a magic
int SIZE;
int SUM = 0;
int MAX = 0;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void spin_map(int size)
{
	size = (1 << size);
	// divide a row
	for (int i = 0; i < SIZE / size; i++)
	{
		// divide a column
		for (int j = 0; j < SIZE / size; j++)
		{
			// spin 
			for (int k = 0; k < size / 2; k++)
			{
				// UP, RIGHT, DOWN, LEFT
				for (int t = k; t < k + size - (2 * k + 1); t++)
					swap(A[k + (i * size)][t + (j * size)], A[t + (i * size)][(size - 1) - k + (j * size)]);
				for (int t = k; t < k + size - (2 * k + 1); t++)
					swap(A[k + (i * size)][t + (j * size)], A[(size - 1) - k + (i * size)][(size - 1) - t + (j * size)]);
				for (int t = k; t < k + size - (2 * k + 1); t++)
					swap(A[k + (i * size)][t + (j * size)], A[(size - 1) - t + (i * size)][k + (j * size)]);
			}
		}
	}
}

void fire()
{
	int size;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			size = 0;
			if (i - 1 >= 0 && A[i - 1][j] != 0)
				size++;
			if (i + 1 < SIZE && A[i + 1][j] != 0)
				size++;
			if (j - 1 >= 0 && A[i][j - 1] != 0)
				size++;
			if (j + 1 < SIZE && A[i][j + 1] != 0)
				size++;
			if (size < 3)
				QUEUE.push({ i, j });
		}
	}
	while (QUEUE.size())
	{
		A[QUEUE.front().first][QUEUE.front().second] = A[QUEUE.front().first][QUEUE.front().second] - 1 > 0 ? A[QUEUE.front().first][QUEUE.front().second] -1 : 0;
		QUEUE.pop();
	}
}

void find_sum()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			SUM += A[i][j];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	SIZE = 1 << N;
	// input
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			cin >> A[i][j];
			V[i][j] = false;
		}
	}
	for (int i = 0; i < Q; i++)
		cin >> L[i];

	// map spin & fire
	for (int i = 0; i < Q; i++)
	{
		spin_map(L[i]);
		fire();
	}

	// get sum of a map
	find_sum();

	// get max size of a part
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int cnt = 0;
			int row, col;

			if (!V[i][j] && A[i][j])
			{
				V[i][j] = true;
				QUEUE.push(make_pair(i, j));
				while (QUEUE.size())
				{
					row = QUEUE.front().first;
					col = QUEUE.front().second;
					cnt++;
					QUEUE.pop();

					for (int k = 0; k < 4; k++)
					{
						if (row + DR[k] >= 0 && row + DR[k] < SIZE && col + DC[k] >= 0 && col + DC[k] < SIZE && !V[row + DR[k]][col + DC[k]] && A[row + DR[k]][col + DC[k]])
						{
							V[row + DR[k]][col + DC[k]] = true;
							QUEUE.push(make_pair(row + DR[k], col + DC[k]));
						}
					}
				}
				if (cnt > MAX)
					MAX = cnt;
			}
		}
	}

	cout << SUM << endl;
	cout << MAX;

	return (0);
}