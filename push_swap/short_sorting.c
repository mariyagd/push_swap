#include "push_swap.h"

bool	check_if_sorted(t_stack	*s)
{
	int	min;
	int	max;
	
	min = find_min_index(s);
	max = find_max_index(s);
	while (s && s->index_sorted == min)
	{
		min++;
		s = s->next;
	}
	if (--min == max)
		return (true);
	return (false);
}

void	sort_two(t_stack **s1, t_stack **s2, int i)
{
	if (i == stack_a)
	{
		if ((*s1)->index_sorted < (*s1)->next->index_sorted)
			ft_sa(s1);
	}
	else
	{
		if ((*s2)->index_sorted < (*s2)->next->index_sorted)
			ft_sb(s2);
	}
}

void	sort_three(t_stack **s)
{
	int		min;
	int		max;
	
	if (check_if_sorted(*s) == true)
		return ;
	max = find_max_index(*s);
	min = find_min_index(*s);
	if ((*s)->index_sorted == max && \
			(*s)->next->index_sorted == min)
		ft_ra(s);
//	else if ((*s)->next->index_sorted == min && \
//			(*s)->next->next->index_sorted == max)
//		ft_sa(s);
	else if ((*s)->index_sorted == max && \
			(*s)->next->next->index_sorted == min)
	{
		ft_sa(s);
		ft_rra(s);
	}
	else if ((*s)->next->next->index_sorted == min)
		ft_rra(s);
	else if ((*s)->next->index_sorted == min)
		ft_sa(s);
	else
	{
		ft_rra(s);
		ft_sa(s);
	}
}

void	sort_four(t_stack **s1, t_stack **s2)
{
	int			min;

	min = find_min_index(*s1);
	if ((*s1)->index_sorted > (*s1)->next->index_sorted)
	{
		ft_sa(s1);
		if (check_if_sorted(*s1) == true)
			return ;
	}
	if ((*s1)->index_sorted == min)
		ft_pb(s1, s2);
	else
	{
		while ((*s1)->index_sorted != min)
		{
			ft_rra(s1);
			if (check_if_sorted(*s1) == true)
				return ;
		}
		ft_pb(s1, s2);
	}
	if (check_if_sorted(*s1) == false)
		sort_three(s1);
	ft_pa(s1, s2);
}

void	sort_five(t_stack **s1, t_stack **s2)
{
	int			median;
	t_stack		*ptr;
	int			count;

	ptr = find_lastnode(s1);
	count = 1;
	median = find_median(*s1);
	while (ptr->index_sorted < median && count++ != median)
	{
		ft_rra(s1);
		ft_pb(s1, s2);
		ptr = find_lastnode(s1);
	}
	ptr = *s1;
	while (count != median)
	{
		if (ptr->index_sorted < median)
		{
			ft_pb(s1, s2);
			count++;
		}
		else
			ft_ra(s1);
		ptr = *s1;
	}
	if (check_if_sorted(*s1) == false)
		sort_three(s1);
	sort_two(s1, s2, stack_b);
	ft_pa(s1, s2);
	ft_pa(s1, s2);
}

void	short_sorting(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		ft_sa(a);
		exit(0);
	}
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
