#include "push_swap.h"

int	count_numbers(t_stack *s, int median)
{
	int	count;

	count = 0;
	while(s)
	{
		if (s->index_sorted < median)
			count++;
		s = s->next;
	}
	return (count);
}

int	median_small_sort(t_stack *s)
{
	int	i;
	int	size;
	int	*array;
	t_stack	*ptr;

	i = 0;
	size = stack_size(s);
	ptr = s;
	array = malloc(size * sizeof(int));
	if (!array)
		return 0;
	while (i < size && ptr != NULL)
	{
		array[i] = ptr->index_sorted;
		i++;
		ptr = ptr->next;
	}
	sort_int_tab(&array, (unsigned int)size);
	i = array[size / 4];
	free(array);
	return (i);
}

int	find_pos(t_stack *s, int min)
{
	while (s && s->index_sorted != min)
		s = s->next;
	return (s->pos);
}

void	sort_less_than_ten(t_stack **s1, t_stack **s2)
{
	int	min;
	int	middle;
	int	pos;

	while (stack_size(*s1) > 3 && check_if_sorted(*s1) == false)
	{
		min = find_min_index(*s1);
		middle = stack_size(*s1) / 2;
		pos = find_pos(*s1, min);
		if (pos >= middle)
			while ((*s1)->index_sorted != min && check_if_sorted(*s1) == false)
				ft_rra(s1);
		else
			while ((*s1)->index_sorted != min && check_if_sorted(*s1) == false)
				ft_ra(s1);
		if ((*s1)->index_sorted == min && check_if_sorted(*s1) == false)
		{
			ft_pb(s1, s2);
			set_index_position(s1);
		}
	}
	if (stack_size(*s1) == 3)
		sort_three(s1);
	while(*s2)
		ft_pa(s1, s2);
}


int	helper_function(t_stack *s, int median)
{
	int	i;
	int	middle;
	int	count_upper;
	int	count_lower;

	i = 0;
	count_upper = 0;
	count_lower = 0;
	middle = stack_size(s) / 2;
	while (s && i <= middle)
	{
		if (s->index_sorted < median)
			count_upper++;
		i++;
	}
	while (s && i < middle)
	{
		if (s->index_sorted < median)
			count_lower++;
		i++;
	}
	if (count_lower > count_upper)
		return (do_rra);
	else
		return (do_ra);
}

int	helper(t_stack *s, int ind_search)
{
	int	middle;

	middle = stack_size(s) / 4;
	set_index_position(&s);
	while (s && s->index_sorted != ind_search)
		s = s->next;
	if (s->pos > middle)
		return (do_rrb);
	return 0;
}

void	sort_stack_b(t_stack **s1, t_stack **s2)
{
	t_stack *ptr;
	t_stack *ptr2;
	int		next;
	int		flag = 0;

	ptr = *s2;
	while (*s2)
	{
		ptr2 = find_lastnode(s1);
		ptr = find_lastnode(s2);
		next = (*s1)->index_sorted - 1;
		if (ptr2->index_sorted == next)
			ft_rra(s1);
		else if ((*s2)->index_sorted == next)
			ft_pa(s1, s2);
		else if (ptr->index_sorted == next)
			ft_rrb(s2);
		else if ((*s2)->next->index_sorted == next)
			ft_sb(s2);
		else if (flag == 1 && (*s1)->index_sorted > ptr2->index_sorted && ptr2->index_sorted != find_max_index(*s1))
		{
			ft_pa(s1, s2);
			ft_ra(s1);
		}
		else if (helper(*s2, next) == do_rrb)
			ft_rrb(s2);
		else if (flag == 0)
		{
			ft_pa(s1, s2);
			ft_ra(s1);
			flag = 1;
		}
		else
			ft_rb(s2);
	}
}

void	small_sorting(t_stack **s1, t_stack **s2, int size_a)
{
	(void)size_a;
	int			median;
	int			count;
	int			i;
	int			j = 0;
	t_stack 	*ptr;
	int			k =0;

	while (stack_size(*s1) > 3 && check_if_sorted(*s1) == false )
	{
		median = median_small_sort(*s1);
		count = count_numbers(*s1, median);
		i = 0;
		k = helper_function(*s1, median);
		while (i != count && check_if_sorted(*s1) == false && stack_size(*s1) > 3)
		{
			ptr = find_lastnode(s1);
			if ((*s1)->index_sorted < median)
			{
				ft_pb(s1, s2);
				i++;
				ptr = find_lastnode(s2);
				if (stack_size(*s2) >= 2 && (*s2)->index_sorted < (*s2)->next->index_sorted && \
						(*s2)->index_sorted > median /2 && (*s2)->next->index_sorted > median /2)
					ft_sb(s2);
				if (stack_size(*s2) >= 2 && (*s2)->index_sorted < median / 2)
					ft_rb(s2);
				if (stack_size(*s2) >= 2 && ptr->index_sorted > (*s2)->index_sorted)
					ft_rrb(s2);
			}
			else if ((*s1)->next->index_sorted < median && stack_size(*s2) >= 2 &&\
					(*s2)->index_sorted < (*s2)->next->index_sorted)
			{
				ft_ss(s1, s2);
			}
			else if (stack_size(*s2) >= 2 && (*s2)->index_sorted < (*s2)->next->index_sorted)
				ft_sb(s2);
			else if (ptr->index_sorted < median)
				ft_rra(s1);
			else if (k == do_ra)
				ft_ra(s1);
			else
				ft_rra(s1);
		}
		j++;
	}
	sort_three(s1);
	sort_stack_b(s1, s2);
}



