#include <iostream>
using namespace std;

int N, M;
int MEM[100];
int COST[100];
//cost 0 to 10000(100 * 100)
int DP[10001][100];

int main()
{
	int i, j;

	cin >> N >> M;
	for (i = 0; i < N; i++)
		cin >> MEM[i];
	for (i = 0; i < N; i++)
		cin >> COST[i];
	for (i = 0; i < 100 * N + 1; i++)
	{
		for (j = 0; j < N; j++)
			DP[i][j] = 0;
	}
	for (i = 0; i < 100 * N + 1; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j == 0)
			{
				if (i - COST[j] >= 0)
					DP[i][j] = MEM[j];
				else
					DP[i][j] = 0;
			}
			else
			{
				if (i - COST[j] >= 0)
					DP[i][j] = (DP[i][j - 1] < MEM[j] + DP[(i - COST[j])][j - 1]) ? MEM[j] + DP[(i - COST[j])][j - 1] : DP[i][j - 1];
				else
					DP[i][j] = DP[i][j - 1];
			}
		}
		if (DP[i][j - 1] >= M)
			break;
	}
	cout << i << endl;
	return (0);
}