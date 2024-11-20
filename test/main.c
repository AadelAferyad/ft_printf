#include <stdio.h>
#include "../ft_printf.h"



int	main(void)
{
	int	i;


	i = printf("%.5d\n", 12);
	ft_printf("%d\n", i);
	i = ft_printf("%.5d\n", 12);
	ft_printf("%d\n", i);

	i = printf("%10.5d\n", 12);
	ft_printf("%d\n", i);
	i = ft_printf("%10.5d\n", 12);
	ft_printf("%d\n", i);
	return (0);
}
