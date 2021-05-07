#include <string>
#include <vector>
#include <iostream>

using namespace std;

string to_lower(string id)
{
	string res;

	for (int i = 0; i < id.size(); i++)
	{
		if (id[i] >= 'A' && id[i] <= 'Z')
			id[i] += 32;
		res.push_back(id[i]);
	}
	return (res);
}

string elim_str(string id)
{
	string res;

	for (int i = 0; i < id.size(); i++)
	{
		if ((id[i] >= 'a' && id[i] <= 'z') || (id[i] >= '0' && id[i] <= '9') || id[i] == '-' || id[i] == '_' || id[i] == '.')
			res.push_back(id[i]);
	}
	return (res);
}

string elim_dup(string id)
{
	string res;

	for (int i = 0; i < id.size(); i++)
	{
		res.push_back(id[i]);
		if (id[i] == '.')
		{
			while (i < id.size() && id[++i] == '.') {}
			i--;
		}
	}
	return (res);
}

string elim_st_end(string id)
{
	string res;

	for (int i = 0; i < id.size(); i++)
	{
		if (i == 0 && id[i] == '.')
			continue;
		if (i == id.size() - 1 && id[i] == '.')
			continue;
		res.push_back(id[i]);
	}
	return (res);
}

string is_empty_str(string id)
{
	string res;

	if (id.size() == 0)
		res.push_back('a');
	else
		res = id;
	return (res);
}

string elim_up_to15(string id)
{
	string res;

	if (id.size() > 15)
		id = id.substr(0, 15);
	res = elim_st_end(id);
	return (res);
}

string insert_up_to3(string id)
{
	string res;

	if (id.size() == 1)
	{
		res.push_back(id[0]);
		res.push_back(id[0]);
		res.push_back(id[0]);
	}
	else if (id.size() == 2)
	{
		res.push_back(id[0]);
		res.push_back(id[1]);
		res.push_back(id[1]);
	}
	else
	{
		for (int i = 0; i < id.size(); i++)
			res.push_back(id[i]);
	}
	return (res);
}

string solution(string new_id) {
	string answer = "";
	// 1. to lower
	answer = to_lower(new_id);
	// 2. eliminate
	answer = elim_str(answer);
	// 3. duplicate .
	answer = elim_dup(answer);
	// 4. elim start, end .
	answer = elim_st_end(answer);
	// 5. is empty
	answer = is_empty_str(answer);
	// 6. elim upper 15
	answer = elim_up_to15(answer);
	// 7. insert up to 3
	answer = insert_up_to3(answer);

	return (answer);
}

int main()
{
	string s[5] = { "...!@BaT#*..y.abcdefghijklm" , "z-+.^." , "=.=" , "123_.def" , 	"abcdefghijklmn.p" };

	for (int i = 0; i < 5; i++)
		cout << solution(s[i]) << endl;
}