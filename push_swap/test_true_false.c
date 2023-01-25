#include <stdio.h>
#include <stdbool.h>

bool check(int a, int b)
{
	if (a > b)
		return (true);
	else
		return (false);
}

int	main(void)
{
	int a = 4;
	int	b = 2;
	if (check(a, b) == true)
		printf("true");
	else
		printf("false");
	return (0);
}
