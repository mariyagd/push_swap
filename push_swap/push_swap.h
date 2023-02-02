/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:52:03 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 15:06:32 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libft/includes/libft.h"

# define ONE_STR_MULT_NUM	1
# define ONE_NUM			2
# define MULTIPLE_STRING	3
# define DO_RRA				4
# define DO_RA				5
# define DO_RRB				6

typedef struct s_stack
{
	int					content;
	int					index_sorted;
	struct s_stack		*next;
	int					pos;
}						t_stack;

// errors checker
void		negative_int_check(char *str);
void		positive_int_check(char *str);
void		no_int_errors(char **str);
void		no_doubles(char **str);
void		no_other_char(char **str);
void		no_errors(char **str);
void		error_msg_stop(void);

//string cases
bool		one_string_case(char *av);
int			string_case(char **av);

//stack a initialization
t_stack		*create_stack_a(char **av, t_stack **a, t_stack **b);
t_stack		*find_lastnode(t_stack **head);
void		node_backadd(t_stack **head, t_stack **new_node);
t_stack		*new_node(char *str);
t_stack		*init_stack_a(char **str);
t_stack		*prepare_stack_a(char **av);
int			stack_size(t_stack *ptr);
void		set_actual_index(t_stack **a);
t_stack		*find_before_last(t_stack **a);

//free string
void		free_string(char **str);
void		free_list(t_stack **s);

//sort operations
void		sort_int_tab(int **tab, unsigned int size);
void		sort_index(t_stack **head, int **array, int size);
void		set_index(t_stack **head);
void		set_position(t_stack **s);

//check if sorted
void		check_if_sorted_and_exit(t_stack *s1, t_stack *s2, int size);
bool		check_if_sorted(t_stack	*s);

//index max et min
int			find_max_index(t_stack *s);
int			find_min_index(t_stack *s);

//operations
void		frontadd_push_op(t_stack **s1, t_stack **s2);
void		push_op(t_stack **s1, t_stack **s2);
void		ft_pb(t_stack **a, t_stack **b);
void		ft_pa(t_stack **a, t_stack **b);
void		rev_rotate(t_stack **s);
void		ft_rrb(t_stack **b);
void		ft_rra(t_stack **a);
void		ft_rrr(t_stack **a, t_stack **b);
void		rotate_op(t_stack **s);
void		ft_rb(t_stack **b);
void		ft_ra(t_stack **a);
void		ft_rr(t_stack **a, t_stack **b);
void		swap_op(t_stack **s);
void		ft_sa(t_stack **a);
void		ft_sb(t_stack **b);
void		ft_ss(t_stack **a, t_stack **b);

//median
int			find_median(t_stack *s);

//short sorting
void		sort_two(t_stack **s);
void		sort_three(t_stack **s);
void		sort_four(t_stack **s1, t_stack **s2);
void		sort_five(t_stack **s1, t_stack **s2);
void		helper_sort_five(t_stack **s1, t_stack **s2, int median);
void		short_sorting(t_stack **a, t_stack **b, int size);

//small sorting
void		sort_less_than_ten(t_stack **s1, t_stack **s2);
int			find_pos(t_stack *s, int min);

//big sorting
void		big_sorting(t_stack **s1, t_stack **s2);
int			count_numbers(t_stack *s, int median);
int			median_big_sort(t_stack *s);
int			helper_function(t_stack *s, int median);
int			helper(t_stack *s, int ind_search);
void		sort_stack_b(t_stack **s1, t_stack **s2);
void		first_condition(t_stack **s1, t_stack **s2, int median, int *i);
#endif
