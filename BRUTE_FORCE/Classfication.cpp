#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
	vector<int> answer;
	vector<int> spec;
	// cpp, java, python (0 ~ 2)
	// backend, frontend (0, 1)
	// junior, senior    (0, 1)
	// chicken, pizza    (0, 1)
	// info to int point
	for (int i = 0; i < info.size(); i++)
	{
		int spec_i = 0;
		const char *str = info[i].c_str();
		char *lan = strtok((char *)str, " ");
		char *stack = strtok(NULL, " ");
		char *career = strtok(NULL, " ");
		char *food = strtok(NULL, " ");
		char *point = strtok(NULL, " ");

		if (strcmp(lan, "java") == 0)
			spec_i += 1;
		else if (strcmp(lan, "python") == 0)
			spec_i += 2;
		spec_i <<= 1;
		if (strcmp(stack, "frontend") == 0)
			spec_i += 1;
		spec_i <<= 1;
		if (strcmp(career, "senior") == 0)
			spec_i += 1;
		spec_i <<= 1;
		if (strcmp(food, "pizza") == 0)
			spec_i += 1;
		spec_i <<= 17;
		spec_i += atoi(point);
		spec.push_back(spec_i);
	}

	// query
	for (int i = 0; i < query.size(); i++)
	{
		int res = 0;
		const char *str = query[i].c_str();
		char *lan = strtok((char *)str, " ");
		strtok(NULL, " ");
		char *stack = strtok(NULL, " ");
		strtok(NULL, " ");
		char *career = strtok(NULL, " ");
		strtok(NULL, " ");
		char *food = strtok(NULL, " ");
		char *point = strtok(NULL, " ");

		for (int j = 0; j < spec.size(); j++)
		{
			int spec_i = spec[j];
			// point
			if (atoi(point) > (spec_i & 0b11111111111111111))
				continue;
			spec_i >>= 17;
			// food
			if (strcmp(food, "pizza") == 0 && ((spec_i & 1) == 0))
				continue;
			else if (strcmp(food, "chicken") == 0 && ((spec_i & 1) == 1))
				continue;
			spec_i >>= 1;
			// carrer
			if (strcmp(career, "senior") == 0 && ((spec_i & 1) == 0))
				continue;
			else if (strcmp(career, "junior") == 0 && ((spec_i & 1) == 1))
				continue;
			spec_i >>= 1;
			// stack
			if (strcmp(stack, "frontend") == 0 && ((spec_i & 1) == 0))
				continue;
			else if (strcmp(stack, "backend") == 0 && ((spec_i & 1) == 1))
				continue;
			spec_i >>= 1;
			// lan
			if (strcmp(lan, "python") == 0 && (spec_i != 2))
				continue;
			else if (strcmp(lan, "java") == 0 && (spec_i != 1))
				continue;
			else if (strcmp(lan, "cpp") == 0 && (spec_i != 0))
				continue;
			res++;
		}
		answer.push_back(res);
	}
	return (answer);
}

int main()
{
	vector<string> info = { "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" }; 
	vector<string> query = { "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" };

	vector<int> sol = solution(info, query);
	for (int i = 0; i < sol.size(); i++)
		cout << sol[i] << " ";
}