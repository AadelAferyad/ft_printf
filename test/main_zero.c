
#include <stdio.h>
#include "../ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	i;

	i = ft_printf("|%02d|", -1);
	printf("\n%d\n", i);
	i = printf("|%02d|", -1);
	printf("\n%d\n", i);

	i = ft_printf("|%04d|", -14);
	printf("\n%d\n", i);
	i = printf("|%04d|", -14);
	printf("\n%d\n", i);

	i = ft_printf("|%03u|", 1);
	printf("\n%d\n", i);
	i = printf("|%03u|", 1);
	printf("\n%d\n", i);

	i = ft_printf("|%02u|", -10);
	printf("\n%d\n", i);
	i = printf("|%02u|", -10);
	printf("\n%d\n", i);
	return (0);
}
