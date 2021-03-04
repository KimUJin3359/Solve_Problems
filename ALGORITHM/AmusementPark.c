#include <stdio.h>
#include <stdlib.h>

int time_check[32] = { 0, };
int *times;

long long find_by_binary(int people, int kind)
{
    long long left = 0;
    long long right = 60000000000;
    long long find_time = 0;
    long long people_ride;

    while (left <= right) 
    {
        long long mid = (left + right) / 2;

        people_ride = kind;
        for (int i = 1; i <= 30; i++)
            people_ride += (mid / i) * time_check[i];
        if (people_ride >= people)
        {
            find_time = mid;
            right = mid - 1;
        }
        else if (people_ride < people)
            left = mid + 1;
    }
    return (find_time);
}


int main()
{
    long long find_time;
    int people, kind;
    int ride = 0;

    scanf("%d %d", &people, &kind);
    times = (int *)malloc(sizeof(int) * kind);
    for (int i = 0; i < kind; i++)
    {
        scanf("%d", &times[i]);
        time_check[times[i]]++;
    }
    //for less people than equipments
    if (people <= kind)
    {
        printf("%d", people);
        return (0);
    }
    //for more people than equipments
    find_time = find_by_binary(people, kind);
    //get find_time - 1
    ride += kind;
    for (int i = 1; i <= 30; i++)
        ride += ((find_time - 1) / i) * time_check[i];
    for (int i = 0; i < kind; i++)
    {
        if (!(find_time % times[i]))
            ride++;
        if (ride == people)
        {
            printf("%d", (i + 1));
            break;
        }
    }
    free(times);
    return (0);
}