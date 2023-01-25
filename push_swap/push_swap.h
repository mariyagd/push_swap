#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef	struct s_node
{
	int					index;
	int					flag;
	struct s_list		*next;
	struct s_list		*previous;
}						t_node;

typedef	struct s_all
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		min_a;
	int		median;
	int		length_a;
	int		length_b;
}			t_all;

#endif
