#include <iostream>
using namespace std;

char    NAME[26];
int     TREE[26][2];
int     N;

void preorder(int idx)
{
    cout << NAME[idx];
    if (TREE[idx][0] != -1)
        preorder(TREE[idx][0]);
    if (TREE[idx][1] != -1)
        preorder(TREE[idx][1]);
}

void inorder(int idx)
{
    if (TREE[idx][0] != -1)
        inorder(TREE[idx][0]);
    cout << NAME[idx];
    if (TREE[idx][1] != -1)
        inorder(TREE[idx][1]);
}

void postorder(int idx)
{
    if (TREE[idx][0] != -1)
        postorder(TREE[idx][0]);
    if (TREE[idx][1] != -1)
        postorder(TREE[idx][1]);
    cout << NAME[idx];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 26; i++)
        NAME[i] = 'A' + i;
    for (int i = 0; i < 26; i++)
    {
        TREE[i][0] = -1;
        TREE[i][1] = -1;
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char root, left, right;

        cin >> root >> left >> right;
        if (left != '.')
            TREE[root - 'A'][0] = left - 'A';
        if (right != '.')
            TREE[root - 'A'][1] = right - 'A';
    }
    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
}