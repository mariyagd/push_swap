/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:10 by mdanchev          #+#    #+#             */
/*   Updated: 2023/01/30 17:27:25 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 * create_stack_a(char **av, t_stack **a);
 * if there are no arguments -> return nothing
 * if there are arguments -> check for errors
 * if there is only one string with one number and no errors
 *		-> create a new node only and exit the program
 *	if there is only one string with multiple numbers inside
 *		-> split the string
 *		-> prepare a linked list
 *		-> free
 *		-> return the linked list
 *	if there are multiple strings
 *		-> prepare a linked list
 *		-> return it
 */


//A CACHER
void	print_index(t_stack *a)
{
	ft_printf("index\n");
	while (a)
	{
		ft_printf("%d\n", a->index_sorted);
		a = a->next;
	}
}
//A CACHER
void	print_stack(t_stack *a)
{
	ft_printf("stack\n");
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
}


void	check_if_sorted_and_exit(t_stack	*s, int size)
{
	int	i;

	i = 1;
	while (s && s->index_sorted == i)
	{
		s = s->next;
		i++;
	}
	if (--i == size)
		exit (0);
}
/*
int	find_max_index(t_stack *s)
{
	t_stack		*ptr;
	int			max;

	ptr = s;
	max = ptr->index_sorted;
	while (ptr)
	{
		if (ptr->index_sorted > ptr->next->index_sorted)
			max = ptr->index_sorted;
		else
			max = ptr->next->index_sorted;
		ptr = ptr->next;
	}
}
*/
void	sort_three(t_stack **s)
{
	t_stack	*middle;
	t_stack	*last;

	middle = (*s)->next;
	last = middle->next;

//	max = find_max_index(t_stack *s);
//	min = find_min_index(t_stack *s);

	if (middle->index_sorted == 1 && (*s)->index_sorted == 3)
		ft_ra(s);
	else if (middle->index_sorted == 1 && (*s)->index_sorted == 2)
		ft_sa(s);
	else if (last->index_sorted == 1 && (*s)->index_sorted == 3)
	{
		ft_sa(s);
		ft_rra(s);
	}
	else if (last->index_sorted == 1)
		ft_rra(s);
	else
	{
		ft_rra(s);
		ft_sa(s);
	}
	check_if_sorted_and_exit(*s, 3);
}


void	short_sorting(t_stack **a)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		ft_sa(a);
		exit(0);
	}
	if (size == 3)
		sort_three(a);
}
/*
int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	av++;
	a = create_stack_a(av, &a);
	if (!a)
		return (0);
	short_sorting(&a);


	//tests
	t_stack	*ptr = a;
	while (ptr!= NULL)
	{
		ft_printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
	ptr = a;
	ft_printf("\n");
	while (ptr!= NULL)
	{
		ft_printf("%d\n", ptr->index_sorted);
		ptr = ptr->next;
	}
}
*/



