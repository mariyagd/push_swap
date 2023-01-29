#include "push_swap.h"

void	push_op(t_stack **s1, t_stack **s2)
{
	if (!*s1)
		return ;
	frontadd_push_op(s1, s2);
}


void	ft_pb(t_stack **a, t_stack **b)
{
	push_op(a, b);	
}

void	ft_pa(t_stack **a, t_stack **b)
{
	push_op(b, a);
}
