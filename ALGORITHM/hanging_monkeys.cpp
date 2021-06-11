#include <stdio.h>
#include <string.h>
#include <math.h>

int N;
char INPUT[151];

int main()
{
    scanf("%d", &N);
    for (int T = 0; T <= N; T++)
    {
        int max = 0;
        int res = -1;

        memset(INPUT, 0, sizeof(INPUT));
        fgets(INPUT, sizeof(INPUT), stdin);
        if (!T)
            continue;
        for (int i = 0; i < strlen(INPUT); i++)
        {
            if (INPUT[i] == '[')
                max++;
            else if (INPUT[i] == ']')
                max--;
            if (max > res)
                res = max;
        }
        printf("%d\n", (int)pow(2, res));
    }
    return (0);
}