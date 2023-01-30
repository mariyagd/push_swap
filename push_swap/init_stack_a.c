#include "push_swap.h"

t_stack *new_node(char *str)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->next = NULL;
    new->content = ft_atoi(str);
    new->index_sorted = 0;
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
            while (head != NULL)
			{
				free_list(&head);
				return (NULL);
			}
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
		free_string(str);
    }
    if (string_case(av) == multiple_string)
        a = init_stack_a(av);
	if (!a)
		return (NULL);
    return (a);
}

t_stack *create_stack_a(char **av, t_stack **a)
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
        *a = prepare_stack_a(str);
        free_string(str);
    }
    else if (str_case == multiple_string)
        *a = prepare_stack_a(av);
    else if (str_case == one_num)
        exit(0);
    if (!a)
        return (NULL);
    check_if_sorted_and_exit(*a, stack_size(*a));
    return (*a);
}
