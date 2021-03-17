#include <stdio.h>
#pragma warning(disable : 4996)

int N;
int STAIRS[300];
int DP[300];

int main()
{
	scanf("%d", &N);
	// DP 값은 무조건 해당 index의 계단을 밟았을 때 최대값을 가지고 있음
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &STAIRS[i]);
		if (i == 0)
			DP[i] = STAIRS[i];
		else if (i == 1)
			DP[i] = STAIRS[i] + STAIRS[i - 1];
		else if (i == 2)
			DP[i] = (STAIRS[i - 1] > STAIRS[i - 2]) ? STAIRS[i] + STAIRS[i - 1] : STAIRS[i] + STAIRS[i - 2];
		else
			DP[i] = (DP[i - 2] > DP[i - 3] + STAIRS[i - 1]) ? DP[i - 2] + STAIRS[i] : DP[i - 3] + STAIRS[i - 1] + STAIRS[i];
	}
	// 맨 마지막에 계단은 무조건 밟아야 되기 때문에 결과는 DP[N - 1]이 됨
	printf("%d", DP[N - 1]);
}
