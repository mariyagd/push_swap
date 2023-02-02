#include <stdio.h>
#include "../push_swap.h"


void	print_message(t_stack *a, t_stack *b)
{
	ft_printf("\n\n");
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

	print_message(a, b);

	ft_pb(&a, &b);
	print_message(a, b);

	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	print_message(a, b);

	ft_ra(&a);
	print_message(a, b);

	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	print_message(a, b);

	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	print_message(a, b);

	ft_rb(&b);
	print_message(a, b);

	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	print_message(a, b);

	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	print_message(a, b);

	ft_ra(&a);
	ft_ra(&a);
	ft_ra(&a);
	ft_ra(&a);
	ft_ra(&a);
	print_message(a, b);

	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	print_message(a, b);

	ft_rrr(&a, &b);
	ft_rrr(&a, &b);
	print_message(a, b);

	ft_rr(&a, &b);
	ft_rr(&a, &b);
	print_message(a, b);

	ft_sa(&a);
	print_message(a, b);

	ft_sb(&b);
	print_message(a, b);

	ft_ss(&a, &b);
	print_message(a, b);

	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	print_message(a, b);

	ft_ss(&a, &b);
	ft_ss(&a, &b);
	ft_ss(&a, &b);
	ft_ss(&a, &b);
	print_message(a, b);

	ft_sb(&b);
	ft_sb(&b);
	ft_sb(&b);
	ft_sb(&b);
	ft_sb(&b);
	ft_sb(&b);
	print_message(a, b);

	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	print_message(a, b);


	ft_sa(&a);
	ft_sa(&a);
	ft_sa(&a);
	ft_sa(&a);
	ft_sa(&a);
	ft_sa(&a);
	ft_sa(&a);
	ft_sa(&a);
	print_message(a, b);

	ft_ss(&a, &b);
	ft_ss(&a, &b);
	ft_ss(&a, &b);
	ft_ss(&a, &b);
	print_message(a, b);
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
