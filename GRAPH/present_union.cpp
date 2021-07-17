#include <stdio.h>

int N, M;
int UNION[1000001];

int get_parent(int el)
{
    if (UNION[el] == -1)
        return (-1);
    if (UNION[el] == el)
        return (el);
    return (get_parent(UNION[el]));
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; i++)
        UNION[i] = -1;
    for (int i = 0; i < M; i++)
    {
        int ord, e1, e2;

        scanf("%d %d %d", &ord, &e1, &e2);
        // ord == 0 -> make union
        if (ord == 0)
        {
            if (e1 == e2) {}
            else if (UNION[e1] == -1)
            {
                if (UNION[e2] == -1)
                {
                    UNION[e1] = e1;
                    UNION[e2] = e1;
                }
                else
                    UNION[e1] = get_parent(e2);
            }
            else
            {
                if (UNION[e2] == -1)
                    UNION[e2] = get_parent(e1);
                else
                    UNION[get_parent(e2)] = UNION[get_parent(e1)];
            }
        }
        // ord == 1 -> judge
        else if (ord == 1)
        {
            if (e1 == e2)
                printf("YES\n");
            else if (get_parent(e1) != -1 &&
                get_parent(e2) != -1 &&
                get_parent(e1) == get_parent(e2))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return (0);
}