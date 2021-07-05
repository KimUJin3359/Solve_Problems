#include <unistd.h>

int main(int ac, char *av[])
{
	char	judge[256];

	if (ac != 3)
		write(1, "\n", 1);
	else
	{
		for (int i = 0; i < 256; i++)
			judge[i] = 0;
		for (int i = 0; av[1][i]; i++)
			judge[av[1][i]] = 1;
		for (int i = 0; av[2][i]; i++)
			judge[av[2][i]] += 1;
		for (int i = 0; av[1][i]; i++)
		{
			if (judge[av[1][i]] >= 2)
			{
				write(1, (const void *)(&av[1][i]), 1);
				judge[av[1][i]] = 0;
			}
		}
		write(1, "\n", 1);
	}
}
