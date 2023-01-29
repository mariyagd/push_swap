#include "push_swap.h"

t_stack *find_lastnode(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
    while (ptr != NULL && ptr->next != NULL)
        ptr= ptr->next;
    return (ptr);
}

//used in ft_pb
//s1 is donor stack
//s2 is the destination stack
void	frontadd_push_op(t_stack **s1, t_stack **s2)
{

	t_stack	*tmp;

	tmp = (*s1)->next;
	if (*s2 == NULL)
	{
		(*s1)->next = NULL;
		*s2 = *s1;
		*s1 = tmp;
	}
	else if (*s2 != NULL)
	{
		(*s1)->next = *s2;
		*s2 = *s1;
		*s1 = tmp;
	}
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

void    node_backadd(t_stack **head, t_stack **new_node)
{
    t_stack *lastnode;

	lastnode = NULL;
    if (*head == NULL)
        *head = *new_node;
	else if ((*head)->next == NULL)
		(*head)->next = *new_node;
    else if (!head || !new_node)
        return ;
    else
    {
        lastnode = find_lastnode(head);
        lastnode->next = *new_node;
    }
}

t_stack *new_node(char *str)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->next = NULL;
    new->content = ft_atoi(str);
    new->index_sorted = 0;
// 	new->actual_ind = 0;
    return (new);
}

t_stack *init_stack_a(char **str)
{
    t_stack *a;
    t_stack *head;
    int i;

    i = 1;
    a = new_node(*str);
    if (!a)
        return (NULL);
    head = a;
    while (str[i] != 0)
    {
        a = new_node(str[i]);
        if (!a)
        {
            head = NULL;
            free (head);
            return (NULL);
        }
        node_backadd(&head, &a);
        i++;
    }
    sort_index(&head);
    return (head);
}

t_stack *prepare_stack_a(char **av)
{
    char    **str;
    t_stack *a;

    str = NULL;
    if (string_case(av) == one_str_mult_num)
    {
        str = ft_split(*av, 32);
        if (!str)
            return (NULL);
        a = init_stack_a(str);
        str = NULL;
        free (str);
    }
    if (string_case(av) == multiple_string)
    {
        a = init_stack_a(av);
    }
    return (a);
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
