#include <iostream>
using namespace std;

int v, e;	//vertex, edge
int f1, f2;
int res;
int tree[10001][2];
int parent1[10001];
int parent2[10001];
int index1 = 0, index2 = 0;

void initialize(int v)
{
	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < 2; j++)
			tree[i][j] = -1;
		parent1[i] = -1;
		parent2[i] = -1;
	}
}

void find_parent1(int node)
{
	if (node == 1)
		return;
	for (int i = 0; i < v; i++)
	{
		if (tree[i][0] == node || tree[i][1] == node)
		{
			parent1[index1++] = i;
			find_parent1(i);
		}
	}
}

void find_parent2(int node)
{
	if (node == 1)
		return;
	for (int i = 0; i < v; i++)
	{
		if (tree[i][0] == node || tree[i][1] == node)
		{
			parent2[index2++] = i;
			find_parent2(i);
		}
	}
}

void prefix(int node)
{
	if (tree[node][0] != -1)
		prefix(tree[node][0]);
	res++;
	if (tree[node][1] != -1)
		prefix(tree[node][1]);
}

int main()
{
	int C;

	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		int i1 = 0, i2 = 0;
		int c_node;

		res = 0;
		index1 = 0;
		index2 = 0;
		cin >> v >> e;
		cin >> f1 >> f2;
		initialize(v);
		//make a tree
		for (int i = 0; i < e; i++)
		{
			int from, to;

			cin >> from >> to;
			if (tree[from][0] == -1)
				tree[from][0] = to;
			else
				tree[from][1] = to;
		}
		//find a parent
		find_parent1(f1);
		find_parent2(f2);
		for (int i = 0; i < index1; i++)
		{
			for (int j = 0; j < index2; j++)
			{
				if (parent1[i] == parent2[j])
				{
					c_node = parent1[i];
					i = index1 + 1;
					break;
				}
			}
		}
		//find a subtree
		prefix(c_node);
		cout << "#" << N << " " << c_node << " " << res << endl;
	}
	return (0);
}