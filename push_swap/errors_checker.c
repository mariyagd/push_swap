/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:17:51 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 11:36:04 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* These functions test if the arguments are acceptable
 * while the argument is still a string. If there are no errors,
 * the string is tranformed to a number with ft_atoi().
 *
 * The no_errors() function works in three steps.
 *
 * Steps:
 *		1. no_other_char() - check if all the caracters of the string are numbers
 *			from 0 to 9. The string can start with '+' or '-.'.
 *			These signs can occur only one time and at the beginning
 *			of the string (because of ft_atoi();
 *		2. no_int_errors() - if all the arguments are digits or starts with
 *			'-' or '+', I call the no_int_errors() function which is in file
 *			int_errors_checker.c. This function verifies if the string
 *			can be transformed in a int from -2,147,483,648 to 2,147,483,647
 *		3. no_doubles() - if all the arguments can be transformed in integers,
 *			I check if there are double. As the arguents are still strings,
 *			I use ft_strncmp to do so.
 *
 *	At every step, if an error occurs, I call the error_msg_stop() function
 *	which prints Error to the stderr and exit the program.*/

void	no_doubles(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[j] != 0)
		{
			if (j != i && ft_strlen(str[i]) == ft_strlen(str[j]) && \
					ft_strncmp(str[i], str[j], ft_strlen(str[i])) == 0)
				error_msg_stop();
			j++;
		}
		i++;
	}
}

void	no_other_char(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j] != 0)
		{
			if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
				j++;
			if (!(str[i][j] >= 48 && str[i][j] <= 57))
				error_msg_stop();
			j++;
		}
		i++;
	}
}

void	no_errors(char **str)
{
	no_other_char(str);
	no_int_errors(str);
	no_doubles(str);
}
