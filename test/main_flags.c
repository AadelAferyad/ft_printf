#include <stdio.h>
#include "../ft_printf.h"


int	main(void)
{
	int	i;

	i = printf("%d %i %u %s %c %x %X %p %%\n", -42, 42, 42, "hello", 'A', 0xFF, 0xFF, &i);
	printf("%d\n", i);
	i = ft_printf("%d %i %u %s %c %x %X %p %%\n", -42, 42, 42, "hello", 'A', 0xFF, 0xFF, &i);
	printf("%d\n", i);
	i = printf("%+10d %-10d %#10x %#10X\n", -123, 123, 0xABC, 0xABC);
	printf("%d\n", i);
	i = ft_printf("%+10d %-10d %#10x %#10X\n", -123, 123, 0xABC, 0xABC);
	printf("%d\n", i);

	i = printf("% 10d %010d\n", 123, 123);
	printf("%d\n", i);
	i = ft_printf("% 10d %010d\n", 123, 123);
	printf("%d\n", i);

	i = printf("%.5d %.5i %.5u %.5s %5c %.5x %.5X\n", 123456789, -123456789, 123456789, "hello world", 'A', 0xABCDEF, 0xABCDEF);
	printf("%d\n", i);
	i = ft_printf("%.5d %.5i %.5u %.5s %5c %.5x %.5X\n", 123456789, -123456789, 123456789, "hello world", 'A', 0xABCDEF, 0xABCDEF);
	printf("%d\n", i);

	i = printf("%+010.5d %-10.5d %#010.5x %#010.5X\n", -123, 123, 0xABC, 0xABC);
	printf("%d\n", i);
	i = ft_printf("%+010.5d %-10.5d %#010.5x %#010.5X\n", -123, 123, 0xABC, 0xABC);
	printf("%d\n", i);

	i = printf("%d %d %d\n", 0, -0, 0);
	printf("%d\n", i);
	i = ft_printf("%d %d %d\n", 0, -0, 0);
	printf("%d\n", i);

	i = printf("%s\n", NULL);
	printf("%d\n", i);
	i = ft_printf("%s\n", NULL);
	printf("%d\n", i);

	i = printf("%10.6s\n", NULL);
	printf("%d\n", i);
	i = ft_printf("%10.6s\n", NULL);
	printf("%d\n", i);

	i = printf("%10.6s\n", "hello");
	printf("%d\n", i);
	i = ft_printf("%10.6s\n", "hello");
	printf("%d\n", i);

	i = printf("%10.0s\n", "hello");
	printf("%d\n", i);
	i = ft_printf("%10.0s\n", "hello");
	printf("%d\n", i);

	i = printf("%-10.6s\n", "hello");
	printf("%d\n", i);
	i = ft_printf("%-10.6s\n", "hello");
	printf("%d\n", i);

	i = printf("%10.6s\n", "hello");
	printf("%d\n", i);
	i = ft_printf("%10.6s\n", "hello");
	printf("%d\n", i);

	i = printf("%10.6d\n", 123456789);
	printf("%d\n", i);
	i = ft_printf("%10.6d\n", 123456789);
	printf("%d\n", i);

	i = printf("%10.6d\n", -123456789);
	printf("%d\n", i);
	i = ft_printf("%10.6d\n", -123456789);
	printf("%d\n", i);

	i = printf("%10.6x\n", 0xABCDEF);
	printf("%d\n", i);
	i = ft_printf("%10.6x\n", 0xABCDEF);
	printf("%d\n", i);

	i = printf("%10.6X\n", 0xABCDEF);
	printf("%d\n", i);
	i = ft_printf("%10.6X\n", 0xABCDEF);
	printf("%d\n", i);
	return (0);
}
