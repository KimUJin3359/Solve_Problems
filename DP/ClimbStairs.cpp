#include <stdio.h>

int N;
int STAIRS[300];

int main()
{
    int res = 0;
    int cnt = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &STAIRS[i]);
    res += STAIRS[N - 1];
    for (int i = N - 1; i >= 0; i--)
    {
        if (STAIRS[i - 1] > STAIRS[i - 2])
        {
            if (cnt == 1)
                
        }
    }
}