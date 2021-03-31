#include <iostream>
#include <string>

using namespace std;
string S, T;

void swap_c(char &a, char &b)
{
	char t = a;
	a = b;
	b = t;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S >> T;
	while (S.size() < T.size())
	{
		if (T[T.size() - 1] == 'A')
			T.pop_back();
		else
		{
			T.pop_back();
			for (int i = 0; i < T.size() / 2; i++)
				swap(T[i], T[(T.size() - 1) - i]);
		}
	}
	if (S == T)
		cout << 1;
	else
		cout << 0;
	return (0);
}