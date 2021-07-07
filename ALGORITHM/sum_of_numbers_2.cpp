#include <stdio.h>

int N, M;
int A[10000];

int main()
{
    int start = 0, end = 0;
    int sum = 0;
    int res = 0;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    while (end <= N)
    {
        if (sum < M)
            sum += A[end++];
        else if (sum > M)
            sum -= A[start++];
        else
        {
            res++;
            sum -= A[start++];
        }
    }
    printf("%d", res);
    return (0);
}