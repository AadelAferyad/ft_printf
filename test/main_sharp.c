
#include <stdio.h>
#include "../ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	i;


	i = ft_printf("|%#x|", 0);
	printf("\n%d\n", i);
	i = printf("|%#x|", 0);
	printf("\n%d\n", i);

	return (0);
}
