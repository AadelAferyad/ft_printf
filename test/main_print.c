#include "../ft_printf.h"
#include <stdio.h>
#include <stdlib.h>


int	main(void)
{
	int	i;

	i = printf("%10d|\n", 2);
	ft_printf("%d\n", i);
	i = ft_printf("%10d|\n", 2);
	ft_printf("%d\n", i);
	return (0);
}
