#include <stdio.h>
#include "../ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	i;


	i = ft_printf("|% x|", 0);
	printf("\n%d\n", i);
	i = printf("|% x|", 0);
	printf("\n%d\n", i);

	i = ft_printf("|% p|", &i);
	printf("\n%d\n", i);
	i = printf("|% p|", &i);
	printf("\n%d\n", i);

	i = ft_printf("|% s|", "hello world");
	printf("\n%d\n", i);
	i = printf("|% s|", "hello world");
	printf("\n%d\n", i);

	i = ft_printf("|% i|", 0);
	printf("\n%d\n", i);
	i = printf("|% i|", 0);
	printf("\n%d\n", i);

	i = ft_printf("|% d|", 0);
	printf("\n%d\n", i);
	i = printf("|% d|", 0);
	printf("\n%d\n", i);

	i = ft_printf("|% u|", -1);
	printf("\n%d\n", i);
	i = printf("|% u|", -1);
	printf("\n%d\n", i);

	i = ft_printf("|% d|", 0);
	printf("\n%d\n", i);
	i = printf("|% d|", 0);
	printf("\n%d\n", i);


	i = ft_printf("|%60x|", 0);
	printf("\n%d\n", i);
	i = printf("|%60x|", 0);
	printf("\n%d\n", i);

	i = ft_printf("|%60p|", &i);
	printf("\n%d\n", i);
	i = printf("|%60p|", &i);
	printf("\n%d\n", i);

	i = ft_printf("|%60s|", "hello world");
	printf("\n%d\n", i);
	i = printf("|%60s|", "hello world");
	printf("\n%d\n", i);

	i = ft_printf("|%60i|", 0);
	printf("\n%d\n", i);
	i = printf("|%60i|", 0);
	printf("\n%d\n", i);

	i = ft_printf("|%60%|");
	printf("\n%d\n", i);
	i = printf("|%60%|");
	printf("\n%d\n", i);
	
	i = ft_printf("|% %|");
	printf("\n%d\n", i);
	i = printf("|% %|");
	printf("\n%d\n", i);

	i = ft_printf("|%.10d|hello", LONG_MAX);
	printf("\n%d\n", i);
	i = printf("|%.10d|hello", LONG_MAX);
	printf("\n%d\n", i);
	return (0);
}
