#include <stdio.h>
#include <limits.h>
#include "../ft_printf.h"

int	main(void)
{
	int	i;

	i = ft_printf("%x\n", 0);
	printf("len : %d\n", i);
	i = printf("%x\n", 0);
	printf("len : %d\n", i);

	i = ft_printf("%x\n", -1);
	printf("len : %d\n", i);
	i = printf("%x\n", -1);
	printf("len : %d\n", i);

	i = printf("%x\n", -9);
	printf("len : %d\n", i);
	i = ft_printf("%x\n", -9);
	printf("len : %d\n", i);

	i = printf("%x\n", -10);
	printf("len : %d\n", i);
	i = ft_printf("%x\n", -10);
	printf("len : %d\n", i);

	i = printf("%x\n", -11);
	printf("len : %d\n", i);
	i = ft_printf("%x\n", -11);
	printf("len : %d\n", i);
	
	i = printf("%x\n", -14);
	printf("len : %d\n", i);
	i = ft_printf("%x\n", -14);
	printf("len : %d\n", i);
	

	i = printf("%x\n", -15);
	printf("len : %d\n", i);
	i = ft_printf("%x\n", -15);
	printf("len : %d\n", i);

	i = printf("%x\n", -16);
	printf("len : %d\n", i);
	i = ft_printf("%x\n", -16);
	printf("len : %d\n", i);

	i = printf("%x\n", -99);
	printf("len : %d\n", i);
	i = ft_printf("%x\n", -99);
	printf("len : %d\n", i);

	i = printf("%x\n", -100);
	printf("len : %d\n", i);
	i = ft_printf("%x\n", -100);
	printf("len : %d\n", i);

	i = printf("%x\n", -101);
	printf("len : %d\n", i);
	i = ft_printf("%x\n", -101);
	printf("len : %d\n", i);

	printf("%x\n", INT_MIN);
	printf("len : %d\n", i);
	ft_printf("%x\n", INT_MIN);
	printf("len : %d\n", i);

	printf("%x\n", LONG_MAX);
	printf("len : %d\n", i);
	ft_printf("%x\n", LONG_MAX);
	printf("len : %d\n", i);

	printf("%x\n", LONG_MIN);
	printf("len : %d\n", i);
	ft_printf("%x\n", LONG_MIN);
	printf("len : %d\n", i);

	printf("%x\n", UINT_MAX);
	printf("len : %d\n", i);
	ft_printf("%x\n", UINT_MAX);
	printf("len : %d\n", i);

	printf("%x\n", ULONG_MAX);
	printf("len : %d\n", i);
	ft_printf("%x\n", ULONG_MAX);
	printf("len : %d\n", i);

	printf("%x\n", 9223372036854775807LL);
	printf("len : %d\n", i);
	ft_printf("%x\n", 9223372036854775807LL);
	printf("len : %d\n", i);

	printf("%x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("len : %d\n", i);
	ft_printf("%x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("len : %d\n", i);


	printf("%x\n", -42);
	printf("len : %d\n", i);
	ft_printf("%x\n", -42);
	printf("len : %d\n", i);

	return (0);
}
