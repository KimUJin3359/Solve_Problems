#include <stdlib.h>
#include <stdio.h>

int **set;

int main()
{
	int num, sum;
	int res = 100001;
	int first = 0;

	scanf("%d %d", &num, &sum);
	set = (int **)malloc(sizeof(int *) * num);
	for (int i = 0; i < num; i++)
		set[i] = (int *)malloc(sizeof(int) * 2);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &set[i][0]);
		if (i == 0)
			set[i][1] = set[i][0];
		else
			set[i][1] = set[i - 1][1] + set[i][0];
		while (set[i][1] >= sum)
		{
			if (res > (i - first + 1))
				res = i - first + 1;
			set[i][1] -= set[first][0];
			first++;
		}
	}
	if (res != 100001)
		printf("%d", res);
	else
		printf("0");
	for (int i = 0; i < num; i++)
		free(set[i]);
	free(set);
	return (0);
}