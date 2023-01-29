#include "push_swap.h"

void	rev_rotate(t_stack **s)
{
	t_stack	*end;
	t_stack	*prev;
	t_stack	*head;

	if (!*s)
		return ;
	if ((*s)->next == NULL)
		return;
	head = *s;
	end = *s;
	while (end->next)
	{
		prev = end;
		end = end->next;
	}
	prev->next = NULL;
	end->next = head;
	*s = end;
}

void	ft_rrb(t_stack **b)
{
	rev_rotate(b);
}

void	ft_rra(t_stack **a)
{
	rev_rotate(a);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (*a)
		ft_rra(a);
	if (*b)
		ft_rrb(b);
}
