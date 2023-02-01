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
		s = s->next;
	}
	while (s && i < middle)
	{
		if (s->index_sorted < median)
			count_lower++;
		i++;
		s = s->next;
	}
	if (count_lower > count_upper)
		return (do_rra);
	else
		return (do_ra);
}

int	helper_function_two(t_stack *s, int median)
{
	int	i;
	int	middle;
	int	count_upper;
	int	count_lower;

	i = 0;
	count_upper = 0;
	count_lower = 0;
	middle = stack_size(s) / 2;
	while (s && i <= middle && s->index_sorted >= median)
	{
		s = s->next;
		i++;
	}
	if (s->index_sorted < median)
		count_upper = i;
	while (s && i <= middle)
		s = s->next;
	while (s && s->index_sorted >= median)
	{
		i++;
		s = s->next;
	}
	if (s && s->index_sorted == median)
		count_lower = i;
	if (count_lower > count_upper)
		return (do_rra);
	else
		return (do_ra);
}


void	small_sorting(t_stack **s1, t_stack **s2, int size_a)
{
	(void)size_a;
	int			median;
	int			count;
	int			i;
	int			j = 0;
	t_stack 	*ptr;
	int			*tab;
	int			k =0;

	tab = ft_calloc(size_a, sizeof(int));
	if (!tab)
		return ;
	while (stack_size(*s1) > 3 && check_if_sorted(*s1) == false )
	{
		median = median_small_sort(*s1);
		count = count_numbers(*s1, median);
		i = 0;
		tab[j] = count;
		k = helper_function(*s1, median);
		while (i != count && check_if_sorted(*s1) == false && stack_size(*s1) > 3)
		{
			ptr = find_lastnode(s1);
			if ((*s1)->index_sorted < median)
			{
				while ((*s1)->index_sorted < median)
				{
					ft_pb(s1, s2);
					i++;
				}
			}
			else if ((*s1)->next->index_sorted < median && stack_size(*s2) >= 2 && (*s2)->index_sorted < (*s2)->next->index_sorted)
			{
				ft_ss(s1, s2);
				ft_pb(s1, s2);
				i++;
			}
			else if ((*s1)->next->index_sorted < median)
			{
				ft_sa(s1);
				ft_pb(s1, s2);
				i++;
			}
		/*	else if (ptr->index_sorted < median)
			{
				ft_rra(s1);
				ft_pb(s1, s2);
				i++;
			}*/
			if (k == do_ra) //&& helper_function_two(*s1, median) == do_ra)
				ft_ra(s1);
			else if (k == do_rra) //&& helper_function_two(*s1, median) == do_rra)
				ft_rra(s1);
		}
		j++;
	}
//	print_message(*s1, *s2);
	sort_three(s1);
//	print_message(*s1, *s2);
	i = 0;
	j = 0;
	k = 0;
	ptr = *s2;
	while (*s2)
	{
		if (i + k == tab[j])
		{
			while (k)
			{
				ft_rrb(s2);
				if ((*s1)->index_sorted == i)
				{
					ft_pa(s1, s2);
					i++;
				}
				ft_rrb(s2);
				k--;
			}
		}
		ptr = find_lastnode(s2);
		i = (*s1)->index_sorted - 1;
		if ((*s2)->index_sorted == i)
		{
			ft_pa(s1, s2);
			i++;
			if (i == tab[j])
				j++;
		}
		else if (ptr->index_sorted == i)
		{
			ft_rrb(s2);
			ft_pa(s1, s2);
		}
		else if ((*s2)->next->index_sorted == i)
		{
			ft_sb(s2);
			ft_pa(s1, s2);
		}
		else
		{
			ft_rb(s2);
			k++;
		}
	}
	free(tab);

}




