#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include "libft/includes/libft.h"

# define one_str_mult_num 1
# define one_num 2
# define multiple_string 3

void no_int_errors(char **str);
void no_doubles(char **str);
void no_other_char(char **str);
void no_errors(char **str);
void    error_msg_stop(void);
bool check_one_string(char *av);
int check_which_case(char **av);
void sort_int_tab(int *tab, unsigned int size);

#endif
