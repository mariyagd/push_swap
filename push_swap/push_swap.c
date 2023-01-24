#include "libft/icludes/libft.h"

(void)	error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	check_for_errors(char **av)
{
	int count;

	count = 0;
	while(av[count] != 0)
		count++;
	if (count == 1)
		return (1);
	if (count == 2)
	{
		if (check_wich_case() == 0)
		{
			if (errors_one_string() == 0)
				return (0);
			else
				ft_one_string();
		}
		if (check_wich_case == 1)



int	main(int ac, char*av[])
{
	if (ac == 1)
		return (0);
	if (check_for_errors(av) == 0)
		error_message();
	if (check_for_errors(av) == 1)
		return (0);
	if (check_for_errors(av) == 2)
		ft_continue(av);
	return (0);
}

