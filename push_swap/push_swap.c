#include "libft/includes/libft.h"
#include <stdbool.h>
#define one_str_mult_num 1
#define	one_num	2
#define	multiple_string 3
#include <stdio.h>

void	error_msg_stop(void)
{
	ft_printf("Error\n");
	exit(0);
}

void no_int_errors(char	**str)
{
	char    *s_int_max = "2147483647";
	char    *s_int_min = "-2147483648";

	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] != 0)
	{

		len = ft_strlen(str[i]);
		if (str[i][0] == '-')
		{
			if (len > 11)
				error_msg_stop();
			if (len == 11 && ft_strncmp(s_int_min, str[i], 11) < 0)
				error_msg_stop();
		}
		else
		{
			if (len > 10)
				error_msg_stop();
			if (len == 10 && ft_strncmp(s_int_max, str[i], 10) < 0)
				error_msg_stop();
		}
		i++;
	}
}

void no_doubles(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (str[i] != 0)
	{
		j = 0;
		while (j != i && str[i] != str[j] && str[j] != 0)
			j++;
		if (j!= i && str[i] == str[j] && str[j] != 0)
			error_msg_stop();
		i++;
	}
}

void no_other_char(char **str)
{
	int	i;
	int	j;
	char	check;
	char	*str_check;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		j = 0;
		str_check = str[i];
		while(str[i][j] != 0)
		{
			check = str[i][j];
			if (j == 0 && str[i][j] == '-')
				j++;
			if (!(str[i][j] > 48 && str[i][j] < 57))
				error_msg_stop();
			j++;
		}
		i++;
	}
}

void no_errors(char **str)
{
	no_other_char(str);
	no_int_errors(str);
	no_doubles(str);
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

