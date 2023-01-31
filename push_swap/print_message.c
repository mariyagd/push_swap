#include "push_swap.h"

void	print_message(t_stack *a, t_stack *b)
{
	t_stack *ptr;

	ptr = a;
	ft_printf("\n\n");
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
	ft_printf("--------\nstack a\n\n");

	ptr = a;
	ft_printf("\n\n");
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->index_sorted);
		ptr = ptr->next;
	}
	ft_printf("--------\nindex a\n\n");
	
	ptr = a;
	ft_printf("\n\n");
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->pos);
		ptr = ptr->next;
	}
	ft_printf("--------\nposition a\n\n");
	
	ptr = b;
	ft_printf("\n\n");
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
	ft_printf("--------\nstack b\n\n");
	ptr = b;
	ft_printf("\n\n");
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->index_sorted);
		ptr = ptr->next;
	}
	ft_printf("--------\nindex b\n\n");
	ptr = b;
	ft_printf("\n\n");
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->pos);
		ptr = ptr->next;
	}
	ft_printf("--------\nposition b\n\n");
}

