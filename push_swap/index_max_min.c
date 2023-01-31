#include "push_swap.h"

int	find_max_index(t_stack *s)
{
	t_stack		*ptr;
	int			max;

	ptr = s;
	max = ptr->index_sorted;
	while (ptr)
	{
		if (ptr->index_sorted > max)
			max = ptr->index_sorted;
		ptr = ptr->next;
	}
	return (max);
}

int	find_min_index(t_stack *s)
{
	t_stack		*ptr;
	int			min;

	ptr = s;
	min = ptr->index_sorted;
	while (ptr)
	{
		if (ptr->index_sorted < min)
			min = ptr->index_sorted;
		ptr = ptr->next;
	}
	return (min);
}
