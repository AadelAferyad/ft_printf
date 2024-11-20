#include <stdio.h>
#include "../ft_printf.h"



int	main(void)
{
	int	i;


	i = printf("%10d\n", -123);
	printf("%d\n", i);
	i = ft_printf("%10d\n", -123);
	printf("%d\n", i);
	return (0);
}
