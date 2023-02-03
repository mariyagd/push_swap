/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_errors_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:15:52 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/03 11:44:59 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*The first function to be called is no_int_errors(). This function
 * check whether a string can fit in a int.
 *
 * To do so I use ft_strle()n and ft_strncmp().*/

void	negative_int_check(char *str)
{
	char	*s_int_min;
	int		len;

	if (!str)
		return ;
	s_int_min = "-2147483648";
	len = ft_strlen(str);
	if (len > 11)
		error_msg_stop();
	if (len == 11 && ft_strncmp(s_int_min, str, 11) < 0)
		error_msg_stop();
}

void	positive_int_check(char *str)
{
	char	*s_int_max;
	int		len;

	if (!str)
		return ;
	s_int_max = "+2147483647";
	len = ft_strlen(str);
	if (len > 11)
		error_msg_stop();
	if (len == 11 && ft_strncmp(s_int_max, str, 11) < 0)
		error_msg_stop();
}

void	int_check(char *str)
{
	char	*s_int_max;
	int		i;
	int		len;

	s_int_max = "2147483647";
	i = 0;
	if (!str)
		return ;
	len = ft_strlen(str);
	if (len > 10)
		error_msg_stop();
	if (len == 10 && ft_strncmp(s_int_max, str, 10) < 0)
		error_msg_stop();
}

void	no_int_errors(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != 0)
	{
		if (str[i][0] == '-')
			negative_int_check(str[i]);
		else if (str[i][0] == '+')
			positive_int_check(str[i]);
		else
			int_check(str[i]);
		i++;
	}
}
