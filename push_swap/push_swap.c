#include <stdio.h>
#include "push_swap.h"


t_stack *penultimate(t_stack **s)
{
	t_stack *ptr1;
	t_stack *ptr2;

	ptr1 = NULL;
	ptr2 = NULL;
	ptr1 = *s;
	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
	}
	return (ptr2);
}

void	print_message(t_stack *a, t_stack *b, char *op)
{

	ft_printf("\n[%s]\n\n", op);
	while (a != NULL)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
	ft_printf("----\na\n\n"); 
	while (b != NULL)
	{
		ft_printf("%d\n", b->content);
		b = b->next;
	}
	ft_printf("----\nb\n\n"); 
}


int	main(int ac, char*av[])
{
	t_stack	*a;
	t_stack *b = NULL;

	if (ac == 1)
		return (0);
	av++;
	a = prepare_stack_a(av);
	
	print_message(a, b, "initial stack");

	ft_pb(&a, &b);
	print_message(a, b, "pb");

	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	print_message(a, b, "pb pb pb pb pb pb");

	ft_ra(&a);
	print_message(a, b, "ra");

	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	print_message(a, b, "pa pa pa pa pa pa");

	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	print_message(a, b, "rrr rrr rrr rrr");

	ft_rb(&b);
	print_message(a, b, "rb");
	
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	print_message(a, b, "pb pb pb pb pb pb");
	
	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	print_message(a, b, "rrr rrr rrr rrr");
	
	ft_ra(&a);
	ft_ra(&a);
	ft_ra(&a);
	ft_ra(&a);
	ft_ra(&a);
	print_message(a, b, "ra ra ra ra ra");

	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	print_message(a, b, "pa pa pa pa");

	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	print_message(a, b, "rrr rrr");
	
	ft_rr(&a, &b);
	ft_rr(&a, &b);
	print_message(a, b, "rr rr");
}

/*
int	main(int ac, char*av[])
{
	if (ac == 1)
		return (0);
	av++;
	if (check_which_case(av) == one_str_mult_num)
		printf("one string multiple numbers\n");
	else if (check_which_case(av) == one_num)
		printf("one number"); //return(0)
	else
		printf("multiple_string");
	return (0);
}
*/
