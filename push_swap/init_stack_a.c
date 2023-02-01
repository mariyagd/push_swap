#include "push_swap.h"

t_stack *new_node(char *str)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->content = ft_atoi(str);
    new->index_sorted = 0;
	new->pos = 0;
    new->next = NULL;
    return (new);
}


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
			free_list(&head);
			return (NULL);
        }
        node_backadd(&head, &a);
        i++;
    }
    set_index(&head);
	set_position(&head);
    return (head);
}

t_stack *create_stack_a(char **av, t_stack **a, t_stack **b)
{
    char        **str;
    int         str_case;

    str = NULL;
    str_case = 0;
    str_case = string_case(av);
    if (str_case == one_str_mult_num)
    {
        str = ft_split(*av, 32);
        if (!str)
            return (NULL);
        *a = init_stack_a(str);
        free_string(str);
    }
    else if (str_case == multiple_string)
        *a = init_stack_a(av);
    else if (str_case == one_num)
		error_msg_stop();
    if (!a)
        return (NULL);
	check_if_sorted_and_exit(*a, *b, stack_size(*a));
    return (*a);
}
