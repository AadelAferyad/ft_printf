#include <stdio.h>
#include "../ft_printf.h"



int	main(void)
{
	int	i;


	i = printf(NULL);
	printf("%d\n", i);
	i = ft_printf(NULL);
	printf("%d\n", i);
	return (0);
}
