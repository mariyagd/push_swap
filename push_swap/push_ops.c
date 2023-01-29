#include "push_swap.h"

/* s1 is the stack that will donor a node
 * s2 is the stack that will recieve the donor
 * */

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

void	frontadd_push_op(t_stack **s1, t_stack **s2)
{

	t_stack	*tmp;

	tmp = (*s1)->next;
	if (*s2 == NULL)
	{
		(*s1)->next = NULL;
	}
	else if (*s2 != NULL)
	{
		(*s1)->next = *s2;
	}
	*s2 = *s1;
	*s1 = tmp;
}
