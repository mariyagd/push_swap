#include "push_swap.h"

void	rotate_op(t_stack **s)
{
	t_stack	*end;
	t_stack	*start;

	if (!*s)
		return ;
	if ((*s)->next == NULL)
		return;
	start = *s;
	*s = (*s)->next;
	end = *s;
	while (end->next)
	{
		end = end->next;
	}
	end->next = start;
	start->next = NULL;
}

void	ft_rb(t_stack **b)
{
	rotate_op(b);
}

void	ft_ra(t_stack **a)
{
	rotate_op(a);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	if (*a)
		ft_ra(a);
	if (*b)
		ft_rb(b);
}
