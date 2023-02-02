#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "/my_library/includes/libft.h"

// TEST FOR CHECK IF TWO STRINGS ARE DUPLICATED
int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	char	*str1 = argv[1];
	char	*str2 = argv[2];

	if (ft_strlen(str1) == ft_strlen(str2))
	{
		if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0)
			printf("Error\n");
		else
			printf("the two numbers are different");
	}
	else
		printf("the two numbers are different");
	return (0);
}


