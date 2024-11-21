#include <stdio.h>
#include "../ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	i;


	i = ft_printf("|%.10d|", -1);
	printf("\n%d\n", i);
	i = printf("|%.10d|", -1);
	printf("\n%d\n", i);

	i = ft_printf("|%.10d|", 12);
	printf("\n%d\n", i);
	i = printf("|%.10d|", 12);
	printf("\n%d\n", i);

	i = ft_printf("|%.10x|", 10);
	printf("\n%d\n", i);
	i = printf("|%.10x|", 10);
	printf("\n%d\n", i);
	return (0);
}
