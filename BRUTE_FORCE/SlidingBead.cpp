#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* drop[], int drop_len)
{
	int answer = 0;

	for (int c = 0; c < drop_len; c++)
	{
		int row = 0;
		int col = c;
		int star = 0;

		while (row <= drop_len)
		{
			if (drop[row][col] == '#')
			{
				row++;
				if (row == drop_len)
				{
					answer++;
					break;
				}
			}
			else if (drop[row][col] == '>')
			{
				col++;
				if (col == drop_len)
					break;
			}
			else if (drop[row][col] == '<')
			{
				col--;
				if (col < 0)
					break;
			}
			else if (drop[row][col] == '*')
			{
				star++;
				if (star == 2)
					break;
				else
				{
					row++;
					if (row == drop_len)
					{
						answer++;
						break;
					}
				}
			}
		}
	}
	return (answer);
}

int main()
{
	const char* drop[] = { "######", ">#*###", "####*#", "#<#>>#", ">#*#*<", "######" };
	printf("%d\n", solution(drop, 6));
}