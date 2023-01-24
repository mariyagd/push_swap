#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../my_library/includes/libft.h"

// TEST FOR CHECK IF A VALUE IS BIGGER THAN INT_MAX OR SMALLER THAT INT_MIN
int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char	*s_int_max = "2147483647";
	char	*s_int_min = "-2147483647";

	if (argv[1][0] == '-')
	{
		if (ft_strlen(argv[1]) > 11)
				printf("Error\n");
		else if (ft_strlen(argv[1]) == 11)
		{
			if (ft_strncmp(s_int_min, argv[1], 11) < 0)
				printf("is smaller than int_min");
			else
				printf("is an int!");
		}
		else
			printf("is an int!");
	}
	if (argv[1][0] != '-')
	{
		if (ft_strlen(argv[1]) > 10)
				printf("Error\n");
		else if (ft_strlen(argv[1]) == 10)
		{
			if (ft_strncmp(s_int_max, argv[1], 10) < 0)
				printf("is bigger than int_max");
			else
				printf("is an int!");
		}
		else
			printf("is an int!");
	}

	return (0);
}


