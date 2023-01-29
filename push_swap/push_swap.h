#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include "libft/includes/libft.h"

# define one_str_mult_num 1
# define one_num 2
# define multiple_string 3

typedef struct  s_stack
{
    int                 content;
    int                 index_sorted;
//    int                 actual_ind;
    struct s_stack      *next;
}                       t_stack;


void 		no_int_errors(char **str);
void 		no_doubles(char **str);
void 		no_other_char(char **str);
void 		no_errors(char **str);
void    	error_msg_stop(void);
bool		one_string_case(char *av);
int 		string_case(char **av);
void 		sort_int_tab(int **tab, unsigned int size);
t_stack 	*find_lastnode(t_stack **head);
void	    node_backadd(t_stack **head, t_stack **new_node);
//void	    frontadd(t_stack **head, t_stack **new_node);
void	    frontadd_push_op(t_stack **s1, t_stack **s2);
t_stack 	*new_node(char *str);
t_stack 	*init_stack_a(char **str);
t_stack 	*prepare_stack_a(char **av);
int			stack_size(t_stack *ptr);
void    	sort_index(t_stack **head);
void    	set_actual_index(t_stack **a);
t_stack 	*find_before_last(t_stack **a);

//operations
void	push_op(t_stack **s1, t_stack **s2);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **s);
void	ft_rrb(t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrr(t_stack **a, t_stack **b);
void	rotate_op(t_stack **s);
void	ft_rb(t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rr(t_stack **a, t_stack **b);
#endif
