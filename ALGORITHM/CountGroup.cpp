#include <iostream>
using namespace std;

int people, num;
int group[101];
int cnt = 0;

int find_parent(int a)
{
	if (group[a] == a)
		return a;
	else
		return (find_parent(group[a]));
}

void make_group(int a, int b)
{
	if (group[a] == -1)
	{
		group[a] = a;
		cnt++;
	}
	if (group[b] != -1)
	{
		int parent_a = find_parent(a);
		int parent_b = find_parent(b);
		if (parent_a != parent_b)
		{
			group[parent_b] = a;
			cnt--;
		}
	}
	else
		group[b] = find_parent(a);
}

int main()
{
	int C;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		int in1, in2;

		cnt = 0;
		for (int i = 0; i < 101; i++)
			group[i] = -1;
		cin >> people >> num;
		for (int i = 0; i < num; i++)
		{
			cin >> in1 >> in2;
			make_group(in1, in2);
		}
		for (int i = 1; i <= people; i++)
		{
			if (group[i] == -1)
				cnt++;
		}
		cout << "#" << N << " " << cnt << endl;
	}
}