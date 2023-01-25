#include <stdio.h>
#include "push_swap.h"
//
void	error_msg_stop(void)
{
	ft_printf("Error\n");
	exit(0);
}

bool check_one_string(char *av)
{
	char	**str;
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (av[i] != 0)
	{
		if (av[i] == 32)
			flag++;
		i++;
	}
	if (flag > 0)
	{
		str = ft_split(av, 32);
		no_errors(str);
		return (true);
	}
	else
		return (false);
}

int	check_which_case(char **av)
{
	int	count;

	count = 0;
	while (av[count] != 0)
		count++;
	if (count == 1)
	{
		if (check_one_string(*av) == true)
			return (one_str_mult_num);
		else
			return (one_num);
	}
	else if (count >= 2)
		no_errors(av);
	return (multiple_string);
}

int	main(int ac, char*av[])
{
	if (ac == 1)
		return (0);
	av++;
	if (check_which_case(av) == one_str_mult_num)
		printf("one string multiple numbers\n");
	else if (check_which_case(av) == one_num)
		printf("one number"); //return(0)
	else
		printf("multiple_string");
	return (0);
}

