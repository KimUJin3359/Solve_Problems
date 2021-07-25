#include <stdio.h>
#include <queue>

using namespace std;

int MAP[9][9];
queue<pair<int, int> > TODO;
int ROW[9] = { 0, };
int COL[9] = { 0, };
int SQUARE[9] = { 0, };
int ROW_VAL[9] = { 45, 45, 45, 45, 45, 45, 45, 45, 45 };
int COL_VAL[9] = { 45, 45, 45, 45, 45, 45, 45, 45, 45 };
int SQUARE_VAL[9] = { 45, 45, 45, 45, 45, 45, 45, 45, 45 };

int main()
{
    // INIT
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++)
        {
            int s_i = (i / 3) * 3 + (j / 3);
            
            scanf("%d", &MAP[i][j]);
            if (!MAP[i][j])
            {
                TODO.push(make_pair(i, j));
                ROW[i]++;
                COL[j]++;
                SQUARE[s_i]++;
            }
            else
            {
                ROW_VAL[i] -= MAP[i][j];
                COL_VAL[j] -= MAP[i][j];
                SQUARE_VAL[s_i] -= MAP[i][j];
            }
        }
    }
    // SOLVE
    while (TODO.size())
    {
        int r = TODO.front().first;
        int c = TODO.front().second;
        int r_i = r / 3;
        int c_i = c / 3;
        int s_i = r_i * 3 + c_i;
        
        TODO.pop();
        if (ROW[r] == 1)
        {
            MAP[r][c] = ROW_VAL[r];
            COL[c]--;
            SQUARE[s_i]--;
            COL_VAL[c] -= ROW_VAL[r];
            SQUARE_VAL[s_i] -= ROW_VAL[r];
        }
        else if (COL[c] == 1)
        {
            MAP[r][c] = COL_VAL[c];
            ROW[r]--;
            SQUARE[s_i]--;
            ROW_VAL[r] -= COL_VAL[c];
            SQUARE_VAL[s_i] -= COL_VAL[c];
        }
        else if (SQUARE[r_i * 3 + c_i] == 1) 
        {
            MAP[r][c] = SQUARE_VAL[s_i];
            ROW[r]--;
            COL[c]--;
            ROW_VAL[r] -= SQUARE_VAL[s_i];
            COL_VAL[c] -= SQUARE_VAL[s_i];
        }
        else
            TODO.push(make_pair(r, c));
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", MAP[i][j]);
        printf("\n");
    }
    return (0);
}