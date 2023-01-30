#include "../libft/includes/libft.h"

int	main(int ac, char **av)
{
	(void)ac;
	int	a = ft_atoi(av[1]);
	ft_printf("binary: %s\n", ft_itoa_base(a, ft_atoi(av[2])));
	ft_printf("binary >> 1: %s\n", ft_itoa_base(a>>1, ft_atoi(av[2])));
	ft_printf("binary >> 2: %s\n", ft_itoa_base(a>>2, ft_atoi(av[2])));
	return (0);
}
