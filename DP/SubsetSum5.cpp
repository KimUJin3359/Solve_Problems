#include <stdio.h>

int MAP[1024][1024];

int main()
{
    int N, M;
    int b_x, b_y, e_x, e_y;
    int res;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &MAP[i][j]);
            if (j != 0)
                MAP[i][j] += MAP[i][j - 1];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != 0)
                MAP[i][j] += MAP[i - 1][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &b_x, &b_y, &e_x, &e_y);
        res = MAP[e_x - 1][e_y - 1];
        if (b_x >= 2)
            res -= MAP[b_x - 2][e_y - 1];
        if (b_y >= 2)
            res -= MAP[e_x - 1][b_y - 2];
        if (b_x >= 2 && b_y >= 2)
            res += MAP[b_x - 2][b_y - 2];
        printf("%d\n", res);
    }
    return (0);
}