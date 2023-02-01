#include "push_swap.h"

/* Here are two main functions 
 * - set_index and set_postion
 *
 *   set_index copies the numbers in a array,
 *   the sort the array and then attribute
 *   the indexes in the linked list. Finally it frees
 *   the table.
 *   
 *   ths two functions are mainly usefule
 *   for linked list creation.
 *
 *   set_position attribute index positions from 0 
 *   starting from the head.
 *
 *   this function is mainly usefull for sorting
 *   less than 10 numbers*/

void	sort_int_tab(int **tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				swap;

	i = 0;
	j = 0;
	if (size == 1 || size == 0)
		return ;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if ((*tab)[j] > (*tab)[j + 1])
			{
				swap = (*tab)[j + 1];
				(*tab)[j + 1] = (*tab)[j];
				(*tab)[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void	sort_index(t_stack **head, int **array, int size)
{
	int			i;
	t_stack		*ptr;

	i = 0;
	*array = (int *)malloc(size * sizeof(int));
	if (!*array)
		return ;
	ptr = *head;
	while (i < size && ptr != NULL)
	{
		(*array)[i] = ptr->content;
		i++;
		ptr = ptr->next;
	}
	sort_int_tab(array, (unsigned int)size);
}

void	set_index(t_stack **head)
{
	int			*array;
	int			size;
	int			i;
	t_stack		*ptr;

	size = stack_size(*head);
	sort_index(head, &array, size);
	if (!array)
		return ;
	ptr = *head;
	i = 0;
	while (i < size)
	{
		if (ptr == NULL)
			ptr = *head;
		if (array[i] == ptr->content)
		{
			ptr->index_sorted = i + 1;
			ptr = *head;
			i++;
		}
		else
			ptr = ptr->next;
	}
	free(array);
}

void	set_position(t_stack **s)
{
	t_stack	*ptr;
	int		i;

	ptr = *s;
	i = 1;
	while (ptr != NULL)
	{
		ptr->pos = i;
		i++;
		ptr = ptr->next;
	}
}
