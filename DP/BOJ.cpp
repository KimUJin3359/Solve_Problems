#include <iostream>
#include <deque>
#define MAX 987654321
using namespace std;

int N;
char INPUT[1000];
int DIS[1000];
deque<int> B;
deque<int> O;
deque<int> J;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		DIS[i] = MAX;
	DIS[0] = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> INPUT[i];
		if (INPUT[i] == 'B')
			B.push_back(i);
		else if (INPUT[i] == 'O')
			O.push_back(i);
		else
			J.push_back(i);
	}
	for (int i = 0; i < N; i++)
	{
		if (INPUT[i] == 'B')
		{
			for (int j = 0; j < J.size(); j++)
			{
				if (J[j] > i)
					break;
				if (DIS[i] > DIS[J[j]] + ((J[j] - i) * (J[j] - i)))
					DIS[i] = DIS[J[j]] + ((J[j] - i) * (J[j] - i));
			}
		}
		else if (INPUT[i] == 'O')
		{
			for (int j = 0; j < B.size(); j++)
			{
				if (B[j] > i)
					break;
				if (DIS[i] > DIS[B[j]] + ((B[j] - i) * (B[j] - i)))
					DIS[i] = DIS[B[j]] + ((B[j] - i) * (B[j] - i));
			}
		}
		else if (INPUT[i] == 'J')
		{
			for (int j = 0; j < O.size(); j++)
			{
				if (O[j] > i)
					break;
				if (DIS[i] > DIS[O[j]] + ((O[j] - i) * (O[j] - i)))
					DIS[i] = DIS[O[j]] + ((O[j] - i) * (O[j] - i));
			}
		}
	}
	if (DIS[N - 1] == MAX)
		cout << -1;
	else
		cout << DIS[N - 1];
	return (0);
}