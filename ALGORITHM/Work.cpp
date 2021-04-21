#include <queue>
#include <iostream>
#include <vector>
using namespace std;

#define MIN 987654321

typedef struct  s_order
{
	int idx;
	int req_t;
	int pages;
}				t_order;

typedef struct compare
{
	bool operator()(t_order a, t_order b)
	{
		if (a.pages > b.pages)
			return (true);
		else if (a.pages == b.pages)
		{
			if (a.req_t > b.req_t)
				return (true);
			else
				return (false);
		}
		else
			return (false);
	}
};

priority_queue<t_order, vector<t_order>, compare> PQ;
vector<int> solution(int data[][3], int data_len)
{
	vector<int> answer;
	queue<t_order> temp_q;
	t_order temp;
	int time = 0;
	int min = MIN;

	// push into a queue
	for (int i = 0; i < data_len; i++)
	{
		temp.idx = data[i][0];
		temp.req_t = data[i][1];
		temp.pages = data[i][2];
		PQ.push(temp);
	}
	while (PQ.size())
	{
		temp.idx = PQ.top().idx;
		temp.req_t = PQ.top().req_t;
		temp.pages = PQ.top().pages;
		PQ.pop();

		if (temp.req_t <= time)
		{
			time += temp.pages;
			answer.push_back(temp.idx);
			min = MIN;
			while (temp_q.size())
			{
				PQ.push(temp_q.front());
				temp_q.pop();
			}
		}
		else
		{
			temp_q.push(temp);
			if (min > temp.req_t)
				min = temp.req_t;
		}
		if (PQ.size() == 0 && min > time)
		{
			time = min;
			while (temp_q.size())
			{
				PQ.push(temp_q.front());
				temp_q.pop();
			}
		}
	}
	return (answer);
}

int main()
{
	int data[][3] = { {0, 1, 5}, {1, 2, 4}, {2, 1, 3}, {3, 50, 5}, {4, 10000, 3} };
	vector<int> temp = solution(data, 5);

	for (int i = 0; i < temp.size(); i++)
		cout << temp[i] << " ";
	return (0);
}