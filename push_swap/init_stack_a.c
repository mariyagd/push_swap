/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:29:17 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/15 16:17:18 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*Starts by calling create_stack_a() from main.
 * This function create a linked list that will be the stack a.
 *
 * It works in 4 steps:
 *		1. create_stack_a() determines whether the arguments are single string
 *			or multiple strings. If the argument is  single string, then
 *			it uses ft_split(). As argv is a double pointer (**av), it's a
 *			choice to use ft_split() because it also return a double
 *			pointer(**str).
 *		2. init_stack_a() - creates new node with new_node() and then create
 *			the linked list with node_backadd().
 *		3. set_index() and set_position() - once the linked list is created,
 *			these two functions set the sorted indexes and indexes of the
 *			position
 *		4. At this point the stack a is created. If ft_split was used,
 *			I free **str. Before returning the stack a to the main, I verify
 *			if it's already sorted with check_if_sorted_and_exit().
 *			If it's sorted, I simple close the program.*/

t_stack	*new_node(char *str)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = ft_atoi(str);
	new->index_sorted = 0;
	new->pos = 0;
	new->next = NULL;
	return (new);
}

void	node_backadd(t_stack **head, t_stack **new_node)
{
	t_stack	*lastnode;

	lastnode = NULL;
	if (*head == NULL)
		*head = *new_node;
	else if ((*head)->next == NULL)
		(*head)->next = *new_node;
	else if (!head || !new_node)
		return ;
	else
	{
		lastnode = find_lastnode(head);
		lastnode->next = *new_node;
	}
}

t_stack	*init_stack_a(char **str)
{
	t_stack		*a;
	t_stack		*head;
	int			i;

	i = 1;
	a = new_node(*str);
	if (!a)
		return (NULL);
	head = a;
	while (str[i] != 0)
	{
		a = new_node(str[i]);
		if (!a)
		{
			free_list(&head);
			return (NULL);
		}
		node_backadd(&head, &a);
		i++;
	}
	set_index(&head);
	set_position(&head);
	return (head);
}

t_stack	*create_stack_a(char **av, t_stack **a, t_stack **b)
{
	char	**str;
	int		str_case;

	str = NULL;
	str_case = 0;
	str_case = string_case(av);
	if (str_case == ONE_STR_MULT_NUM)
	{
		str = ft_split(*av, 32);
		if (!str)
			return (NULL);
		*a = init_stack_a(str);
		free_string(str);
	}
	else if (str_case == MULTIPLE_STRING)
		*a = init_stack_a(av);
	else if (str_case == ONE_NUM)
	{
		no_errors(av);
		exit(0);
	}
	if (!a)
		return (NULL);
	check_if_sorted_and_exit(*a, *b, stack_size(*a));
	return (*a);
}
