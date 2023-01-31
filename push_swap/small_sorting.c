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
		


void	small_sorting(t_stack **s1, t_stack **s2, int size_a)
{
	(void)size_a;
	int			median;
	int			count;
	int			i;
	int			j = 0;
	t_stack 	*ptr;
	int			*tab;

	tab = malloc(4 * sizeof(int));
	
//	print_message(*s1, *s2);
	while (stack_size(*s1) > 3 && check_if_sorted(*s1) == false )
	{
		median = median_small_sort(*s1);
		count = count_numbers(*s1, median);
		i = 0;
		tab[j] = count;
		while (i != count && check_if_sorted(*s1) == false && stack_size(*s1) > 3)
		{
			if ((*s1)->index_sorted < median)
			{
				ft_pb(s1, s2);
				i++;
			}
				ft_ra(s1);
		}
		j++;
	}
//	print_message(*s1, *s2);
	sort_three(s1);
//	print_message(*s1, *s2);
	i = 0;
	j = 0;
	int	k = 0;
	ptr = *s2;
	while (*s2)
	{
		if (i + k == tab[j])
		{
			while (k)
			{
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
			ft_rrb(s2);
		else if ((*s2)->next->index_sorted == i)
			ft_sb(s2);
		else if ((*s2)->next->index_sorted > ptr->index_sorted)
			ft_rrb(s2);
		else
		{
			ft_rb(s2);
			k++;
		}
	}

}


	

