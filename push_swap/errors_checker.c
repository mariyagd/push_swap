#include "push_swap.h"

void no_int_errors(char **str)
{
    char    *s_int_max = "2147483647";
    char    *s_int_max2 = "+2147483647";
    char    *s_int_min = "-2147483648";

    int i;
    int len;

    i = 0;
    len = 0;
    while (str[i] != 0)
    {
        len = ft_strlen(str[i]);
        if (str[i][0] == '-')
        {
            if (len > 11)
                error_msg_stop();
            if (len == 11 && ft_strncmp(s_int_min, str[i], 11) < 0)
                error_msg_stop();
        }
		else if (str[i][0] == '+')
		{
			if (len > 11)
				error_msg_stop();
			if (len == 11 && ft_strncmp(s_int_max2, str[i], 11) < 0)
				error_msg_stop();
		}
        else
        {
            if (len > 10)
                error_msg_stop();
            if (len == 10 && ft_strncmp(s_int_max, str[i], 10) < 0)
                error_msg_stop();
        }
        i++;
    }
}

void no_doubles(char **str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != 0)
    {
        j = 0;
        while (str[j] != 0)
        {
            if (j != i && ft_strlen(str[i]) == ft_strlen(str[j]) && \
					ft_strncmp(str[i], str[j], ft_strlen(str[i])) == 0)
                error_msg_stop();
            j++;

        }
        i++;
    }
}

void no_other_char(char **str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != 0)
    {
        j = 0;
        while(str[i][j] != 0)
        {
           if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
                j++;
            if (!(str[i][j] >= 48 && str[i][j] <= 57))
                error_msg_stop();
            j++;
        }
        i++;
    }
}

void no_errors(char **str)
{
    no_other_char(str);
    no_int_errors(str);
    no_doubles(str);
}
