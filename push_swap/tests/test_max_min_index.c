#include "../push_swap.h"

int find_max_index(t_stack *s)
{
    t_stack     *ptr;
    int         max;

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
	return (max);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *ptr;

	if (ac == 1)
		return (0);
	a = create_stack_a(av, &a);
	ptr = a;
	while (ptr!= NULL)
	{
		ft_printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
	ft_printf("\n");
	ptr = a;
	while (ptr!= NULL)
	{
		ft_printf("%d\n", ptr->index_sorted);
		ptr = ptr->next;
	}
	ft_printf("MAX INDEX %d\n", find_max_index(a));
	return (0);
}
