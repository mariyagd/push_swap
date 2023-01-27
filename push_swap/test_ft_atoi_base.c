#include "libft/includes/libft.h"

int	main(int ac, char **av)
{
	(void)ac;
	ft_printf("%d\n", ft_atoi_base(av[1], 10));
	ft_printf("%d\n", ft_atoi_base(av[1], 16));
	ft_printf("%d\n", ft_atoi_base(av[1], 2));
	return (0);
}

