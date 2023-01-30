#include "push_swap.h"

t_stack *find_lastnode(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
    while (ptr != NULL && ptr->next != NULL)
        ptr= ptr->next;
    return (ptr);
}

int stack_size(t_stack *ptr)
{
    int size;

    size = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        size++;
    }
    return (size);
}

/*
void	frontadd(t_stack **head, t_stack **new_node)
{

	if (*head == NULL)
	{
		(*new_node)->next = NULL;
		*head = *new_node;
	}
	else if (*head != NULL)
	{
		(*new_node)->next = *head;
		*head = *new_node;
	}
}
*/
/*
t_stack *find_penultimate(t_stack **s)
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
}*/


