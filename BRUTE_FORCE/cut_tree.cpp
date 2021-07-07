#include <stdio.h>
#include <algorithm>

int N, M;
int NUM[1000000];

bool cmp(int a, int b) { return a > b; };

int main()
{
    long long sum = 0;
    int cut = 0;
    int start, end, mid;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &NUM[i]);
    std::sort(NUM, NUM + N, cmp);
    start = 0;
    end = NUM[0];
    while (start <= end)
    {
        sum = 0;
        mid = (start + end) / 2;
        for (int i = 0; i < N; i++)
        {
            if (NUM[i] > mid)
                sum += (NUM[i] - mid);
            else   
                break;
        }
        if (sum >= M)
        {
            if (cut < mid)
                cut = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    printf("%d", cut);
}