#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* emails[], int emails_len)
{
	int answer = 0;
	
	for (int num = 0; num < emails_len; num++)
	{
		int flag = 0;	// 0 -> name, 1 -> domain_name, 2 -> topdomain
		
		for (int idx = 0; idx < strlen(emails[num]); idx++)
		{
			if (flag == 0 && (('a' <= emails[num][idx] && emails[num][idx] <= 'z') || emails[num][idx] == '.'))
				continue;
			else if (flag == 0 && emails[num][idx] == '@')
				flag = 1;
			else if (flag == 1 && ('a' <= emails[num][idx] && emails[num][idx] <= 'z'))
				continue;
			else if (flag == 1 && emails[num][idx] == '.')
				flag = 2;
			else if (flag == 2)
			{
				if (strcmp(emails[num] + idx, "com") == 0 || strcmp(emails[num] + idx, "net") == 0 || strcmp(emails[num] + idx, "org") == 0)
					answer++;
				else
					break;
			}
			else
				break;
		}
	}

	return (answer);
}

int main()
{
	const char* emails[] = { "d@co@m.com", "a@abc.com", "b@def.com", "c@ghi.net", "abc.def@x.com", "abc", "abc@defx", "abc@defx.xyz" };
	
	printf("%d\n", solution(emails, 8));
	return (0);
}