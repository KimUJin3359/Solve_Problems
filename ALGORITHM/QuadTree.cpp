#include <iostream>
#include <string>
using namespace std;

class Tree {
public:
	int size;
	char item;
	Tree *child[4];

	Tree(char c)
	{
		this->item = c;
		this->size = 0;
		for (int i = 0; i < 4; i++)
			child[i] = NULL;
	}

	void append(char c)
	{
		Tree *temp;

		for (int i = 0; i < this->size; i++)
		{
			if (child[i]->item == 'x' && child[i]->size != 4)
			{
				child[i]->append(c);
				return;
			}
		}
		temp = new Tree(c);
		child[this->size] = temp;
		this->size += 1;
	}

	void print(Tree* root)
	{
		if (root->item != 'x')
			cout << root->item;
		else
		{
			cout << root->item;
			print(root->child[2]);
			print(root->child[3]);
			print(root->child[0]);
			print(root->child[1]);
		}
	}
};

//2, 3, 0, 1
int main()
{
	string input;
	Tree *root;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> input;
	root = new Tree(input[0]);
	for (int i = 1; i < input.size(); i++)
		root->append(input[i]);
	root->print(root);
}