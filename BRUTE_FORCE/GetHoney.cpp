#include <iostream>
#include <queue>
using namespace std;

int M[10][10];
int SQUARE[10][10];
int DP[10][10];
int SIZE, N, MAX;
int RES;

//struct compare {
//	bool operator()(pair<int, int> a, pair<int, int> b)
//	{
//		return (DP[a.first][a.second] < DP[b.first][b.second]);
//	}
//};

//priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;

void getMax(int r, int c)
{
	int size = 1 << N;
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		int sum_s = 0;

		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				sum += M[r][c + j];
				sum_s += SQUARE[r][c + j];
			}
		}
		if (sum <= MAX)
		{
			if (DP[r][c] < sum_s)
				DP[r][c] = sum_s;
		}
	}
}

int main()
{
	int C;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;
	for (int T = 1; T <= C; T++)
	{
		RES = 0;
		cin >> SIZE >> N >> MAX;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				cin >> M[i][j];
				SQUARE[i][j] = M[i][j] * M[i][j];
				DP[i][j] = -1;
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j <= SIZE - N; j++)
				getMax(i, j);
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j <= SIZE - N; j++)
			{
				for (int k = i; k < SIZE; k++)
				{
					if (i == k)
					{
						for (int t = j + N; t <= SIZE - N; t++)
							RES = (RES < DP[i][j] + DP[k][t]) ? DP[i][j] + DP[k][t] : RES;
					}
					else
					{
						for (int t = 0; t <= SIZE - N; t++)
							RES = (RES < DP[i][j] + DP[k][t]) ? DP[i][j] + DP[k][t] : RES;
					}
				}
			}
		}
		cout << "#" << T << " " << RES << endl;
	}
	return (0);
}