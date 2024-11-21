#include <stdio.h>
#include "../ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	i;
	i = ft_printf("|%-1d|", 0);
	printf("\n%d\n", i);
	i = printf("|%-1d|", 0);
	printf("\n%d\n", i);

	i = ft_printf("|%-12d|", LONG_MIN);
	printf("\n%d\n", i);
	i = printf("|%-12d|", LONG_MIN);
	printf("\n%d\n", i);
	
	i = ft_printf("|%-1u|", 0);
	printf("\n%d\n", i);
	i = printf("|%-1u|", 0);
	printf("\n%d\n", i);

	i = ft_printf("|%-1u|", -1);
	printf("\n%d\n", i);
	i = printf("|%-1u|", -1);
	printf("\n%d\n", i);

	i = ft_printf("|%-3u|", 1);
	printf("\n%d\n", i);
	i = printf("|%-3u|", 1);
	printf("\n%d\n", i);

	i = ft_printf("|%-4u|", -14);
	printf("\n%d\n", i);
	i = printf("|%-4u|", -14);
	printf("\n%d\n", i);
	return (0);
}
