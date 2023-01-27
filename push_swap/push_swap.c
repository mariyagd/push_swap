#include <stdio.h>
#include "push_swap.h"

typedef	struct	s_node
{
	int		num;
	int		index;
	s_node	*next;
	s_node	*previous;
	int		flag;
}			t_node;

typedef	struct s_stack
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		len_max;
	int		actual_len;
	int		min_a;
	int		min_b;
	int		median;
}			t_stack;

char	**check_case(char **av)
{
	char	**str;

	str = NULL;
	if (check_which_case(av) == one_str_mult_num)
	{
		str = ft_split(*av, 32);
		if (!str)
			return (NULL);
		return (str);
	}
	else if (check_which_case(av) == one_num)
		exit(0);
	else
		return (av);
}

int	count_size_arr(char	**str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

void	fill_index(t_stack **a)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(ptr));
	if (!ptr)
		return ;
	ptr->stack = (*a)->stack;
	ptr->len_max = (*a)->len_max;
	ptr->
	sort_int_tab(ptr->stack, (unsigned int)(*a)->len_max);
	while (i < (*a)->len_max)
	{
		ptr->index = i;
		i++;
	}
	i = 0;
	while (i < (*a)->len_max)
	{
		(*a)->index = ptr->index;
		i++;
	}
	ptr = NULL;
	free (ptr);
}



t_stack	*prepare_a(char	**av)
{
	char	**str;
	int		size;
	int		i;
	t_stack	*a;

	a = malloc(sizeof(a));
	if (!a)
		return (NULL);
	str = check_case(av);
	i = 0;
	if (!str)
		return (NULL);
	size = count_size_arr(str);
	a->stack = malloc(size * sizeof(int));
	if (!a->stack)
		return (NULL);
	while (*str)
	{
		a->stack[i] = ft_atoi(*str);
		i++;
		str++;
	}
	a->len_max = size;
	a->actual_len = size;
	fill_index(&a);
	return (a);
}

int	main(int ac, char*av[])
{
	t_stack	*a;

	if (ac == 1)
		return (0);
	av++;
	a = prepare_a(av);
//	if (check_if_sorted(a, a->len_max, a->actual_len) == true)
//		return (0);

//	check stack a

	int	len;
	int	i = 0;
	len = a->len_max;
	printf("size stack a = %d\n", len);
	printf("stack a = ");
	while(i < len)
	{
		printf("%d ", a->stack[i]);
		i++;
	}
	i = 0;
	printf("\n");
	printf("index sort of stack a = ");
	while (i < len)
	{
		printf("%d ", a->index);
		i++;
	}


	return (0);
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
