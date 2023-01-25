#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include "libft/includes/libft.h"

# define one_str_mult_num 1
# define one_num 2
# define multiple_string 3
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

void no_int_errors(char **str);
void no_doubles(char **str);
void no_other_char(char **str);
void no_errors(char **str);
void    error_msg_stop(void);
bool check_one_string(char *av);
int check_which_case(char **av);


#endif
