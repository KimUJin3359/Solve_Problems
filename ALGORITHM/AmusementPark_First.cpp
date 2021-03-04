/*
어려웠던 점
1. brute-force(시간 초과 : 어디서 시간을 줄여야 할지)
2. 시간 순이 아닌 기구 순서대로의 탑승
if (time_f % i == 0)
	people -= time_check[i];
if (people <= 0)
{
	int count = 1;

	flag = 0;
	for (int j = 0; j < kind; j++)
	{
		if (i == time[j])
		{
			if ((time_check[i] + people) == count)
				printf("%d", (j + 1));
			count++;
		}
	}
	break;
} -> 시간순으로 계산해서 오답
3. 해결방법을 time에 따른 숫자를 처음부터 세서 일일히 비교하면서 빼주는게 아니라
30분까지만 비교해서 비교대상을 줄임 => 64%까지 통과하다 시간초과
4. 내일 도전해볼 방법, count에 따라 kind만큼의 배열에 숫자를 갱신해나가다가 people과 같은 수가 들어가면 종료
*/

#include <stdio.h>
#pragma warning(disable:4996)

int time_check[32] = { 0, };

int main()
{
	int people;
	int kind, time_f;
	int flag = 1;
	int *time;

	scanf("%d %d", &people, &kind);
	time = new int[kind];
	for (int i = 0; i < kind; i++)
	{
		scanf("%d", &time[i]);
		time_check[time[i]]++;
	}
	if (people <= kind)
		printf("%d", people);
	else
	{
		people -= kind;
		time_f = 0;
		while (flag)
		{
			int sum = 0;

			time_f++;
			for (int i = 1; i <= 30; i++)
			{
				if (time_f % i == 0)
					sum += time_check[i];
			}
			people -= sum;
			if (people <= 0)
			{
				int count = 1;

				for (int j = 0; j < kind; j++)
				{
					if (time_f % time[j] == 0)
					{
						if ((sum + people) == count)
						{
							flag = 0;
							printf("%d", (j + 1));
						}
						count++;
					}
					if (!flag)
						break;
				}
				break;
			}
		}
	}
	delete time;
	return (0);
}