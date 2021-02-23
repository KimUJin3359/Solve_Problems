#include <iostream>
#include <queue>
#include <deque>
#include <map>
using namespace std;

int N;
priority_queue<long long, vector<long long>, less<long long>> pq;
deque<long long> dq;
map<long long, int> m;
deque<long long>::iterator iter;

int main()
{	
	long long num;
	long long res = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		dq.push_back(num);
		m.insert(make_pair(num, i));
		pq.push(num);
	}
	while (N != 1)
	{
		res += N - (m[pq.top()] + 1);
		for (int i = m[pq.top()]; i < N; i++)
			m[pq.top()] -= 1;
		pq.pop();
		N--;
	}
	cout << res;
	return (0);
}