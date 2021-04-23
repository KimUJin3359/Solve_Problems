#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 0 -> 6, 1 -> 2, 2 -> 5, 3 -> 5, 4 -> 4, 5 -> 5, 6 -> 6, 7 -> 3, 8 -> 7, 9 -> 6
int NUM[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int ANS;
int CNT;

void dfs(int cnt)
{
	if (cnt > CNT)
		return;
	else if (cnt == CNT)
	{
		ANS++;
		return;
	}
	for (int i = 0; i < 10; i++)
		dfs(cnt + NUM[i]);
}

int solution(int k)
{
	int answer;

	CNT = k;
	ANS = 0;
	// zero
	if (k == 6)
		ANS++;
	for (int i = 1; i < 10; i++)
		dfs(NUM[i]);
	answer = ANS;
	return (answer);
}

int main()
{
	int result = solution(5);
	printf("%d\n", result);
	result = solution(6);
	printf("%d\n", result);
	result = solution(11);
	printf("%d\n", result);
	result = solution(1);
	printf("%d\n", result);
	return (0);
}