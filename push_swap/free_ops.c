/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:11 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/01 17:27:06 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    free_string(char **str)
{
    int i;

    i = 0;
    while(str[i])
        free(str[i++]);
    free(str);
}

void    free_list(t_stack **s)
{
    t_stack *ptr;
    t_stack *tmp;

    ptr = *s;
    tmp = ptr;
    while (ptr != NULL)
    {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
	free(s);
}
