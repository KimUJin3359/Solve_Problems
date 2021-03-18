#include <stdio.h>
#pragma warning(disable : 4996)
using namespace std;

int N, M;
char MAP[1000][1000];
int DP[1000][1000];
int MAX = 0;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		// 맨 첫줄(왼, 위)은 만들 수 있는 최대 사각형 크기가 입력된 사각형 크기
		for (int j = 0; j < M; j++)
		{
			scanf(" %1c", &MAP[i][j]);
			if (i == 0)
			{
				DP[i][j] = MAP[i][j] - '0';
				if (DP[i][j] > MAX)
					MAX = DP[i][j];
			}
			else if (j == 0)
			{
				DP[i][j] = MAP[i][j] - '0';
				if (DP[i][j] > MAX)
					MAX = DP[i][j];
			}
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			if (MAP[i - 1][j] == '0' || MAP[i][j - 1] == '0')
				DP[i][j] = MAP[i][j] - '0';
			else
			{
				if (MAP[i][j] != '0')
				{
					DP[i][j] = (DP[i][j - 1] > DP[i - 1][j - 1]) ? DP[i - 1][j - 1] : DP[i][j - 1];
					DP[i][j] = (DP[i][j] > DP[i - 1][j]) ? DP[i - 1][j] : DP[i][j];
					DP[i][j]++;
					if (MAX < DP[i][j])
						MAX = DP[i][j];
				}
				else
					DP[i][j] = 0;
			}
		}
	}
	printf("%d\n", MAX * MAX);
	return (0);
}