#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include "libft/includes/libft.h"

# define one_str_mult_num 1
# define one_num 2
# define multiple_string 3
# define stack_a	4
# define stack_b    5
# define do_rra		6
# define do_ra		7
# define do_rrb		8
typedef struct  s_stack
{
    int                 content;
    int                 index_sorted;
    struct s_stack      *next;
	int					pos;
}                       t_stack;

//A SUPPRIMER
void	print_message(t_stack *a, t_stack *b);
/////////////////////////
///

// errors checker
void 		no_int_errors(char **str);
void 		no_doubles(char **str);
void 		no_other_char(char **str);
void 		no_errors(char **str);
void    	error_msg_stop(void);

//string cases
bool		one_string_case(char *av);
int 		string_case(char **av);

//stack a initialization
t_stack		*create_stack_a(char **av, t_stack **a, t_stack **b);
t_stack 	*find_lastnode(t_stack **head);
void	    node_backadd(t_stack **head, t_stack **new_node);
t_stack 	*new_node(char *str);
t_stack 	*init_stack_a(char **str);
t_stack 	*prepare_stack_a(char **av);
int			stack_size(t_stack *ptr);
void    	set_actual_index(t_stack **a);
t_stack 	*find_before_last(t_stack **a);
void    set_index_position(t_stack **a);

//free string
void		free_string(char **str);
void		free_list(t_stack **s);

//sort operations
void 		sort_int_tab(int **tab, unsigned int size);
void    	sort_index(t_stack **head);

//check if sorted
void	check_if_sorted_and_exit(t_stack *s1, t_stack *s2, int size);

//index max et min
int			find_max_index(t_stack *s);
int			find_min_index(t_stack *s);

//operations
void    	frontadd_push_op(t_stack **s1, t_stack **s2);
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
void    	swap_op(t_stack **s);
void    	ft_sa(t_stack **a);
void    	ft_sb(t_stack **b);
void    	ft_ss(t_stack **a, t_stack **b);


//median
int 		find_median(t_stack *s);

//short sorting
void		sort_three(t_stack **s);
void		sort_four(t_stack **s1, t_stack **s2);
void		sort_five(t_stack **s1, t_stack **s2);
void		short_sorting(t_stack **a, t_stack **b);

void	sort_two(t_stack **s1, t_stack **s2, int i);
bool	check_if_sorted(t_stack	*s);

//SMALL SORTING
void	small_sorting(t_stack **s1, t_stack **s2, int size_a);

void	sort_less_than_ten(t_stack **s1, t_stack **s2);
#endif
