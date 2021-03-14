#include <stdio.h>
using namespace std;

int INPUT[100000];

int main()
{
    int N, M;
    int begin, end;
    int res;
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &INPUT[i]);
        if (i != 0)
            INPUT[i] += INPUT[i - 1];
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &begin, &end);
        if (begin >= 2)
            res = INPUT[end - 1] - INPUT[begin - 2];
        else
            res = INPUT[end - 1];
        printf("%d\n", res);
    }
    return (0);
}