#include <stdio.h>
#include "../ft_printf.h"



int	main(void)
{
	int	i;


	i = printf("%.15s\n", NULL);
	ft_printf("%d\n", i);
	i = ft_printf("%.15s\n", NULL);
	ft_printf("%d\n", i);

	i = printf("|%10.6s|\n", NULL);
	ft_printf("%d\n", i);
	i = ft_printf("|%10.6s|\n", NULL);
	ft_printf("%d\n", i);
	return (0);
}
