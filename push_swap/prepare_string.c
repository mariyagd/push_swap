/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:08:51 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 15:01:19 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	one_string_case(char *av)
{
	char	**str;
	int		i;
	int		flag;

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
		i = 0;
		free_string(str);
		return (true);
	}
	else
		return (false);
}

int	string_case(char **av)
{
	int	count;

	count = 0;
	while (av[count] != 0)
		count++;
	if (count == 1)
	{
		if (one_string_case(*av) == true)
			return (ONE_STR_MULT_NUM);
		else
			return (ONE_NUM);
	}
	else if (count >= 2)
		no_errors(av);
	return (MULTIPLE_STRING);
}
