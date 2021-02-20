#include <iostream>
#include <queue>
//priority_queue<자료형, 구현체, 비교 연산자>
using namespace std;

struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b)
	{
		return a.second < b.second;
	}
};
int main() {
	int C;
	int num;
	int *input;

	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
		int index = 0;
		long long sum = 0;

		cin >> num;
		input = new int[num];
		for (int i = 0; i < num; i++)
		{
			cin >> input[i];
			pq.push({ i,input[i] });
		}
		while (!pq.empty() && index <= (num - 1))
		{	
			while (index < pq.top().first)
			{
				if (input[index] < pq.top().second)
					sum += (pq.top().second - input[index]);
				index++;
			}
			pq.pop();
		}
		while (pq.size())
			pq.pop();
		cout << "#" << N << " " << sum << endl;
		delete input;
	}
	return (0);
}