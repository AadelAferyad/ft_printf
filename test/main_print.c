#include "../ft_printf.h"
#include <stdio.h>

int	print_hex_lower(int hex)
{
	if (hex / 16)
		print_hex_lower(hex / 16);
	if (hex > 9 && hex < 16)
		return (1 + ft_putchar(hex - 10 + 'a'));
	else
		return (1 + ft_putchar(hex + 48));
	return (0);
}

int	main(void)
{
	/*ft_printf("hello %c\n %s\n%d\n%d\n%d\n%u\n", 'z', "test", 0, 1337, -1337, -222);*/
	print_hex_lower(255);
	printf("\n");
	print_hex_lower(15);
	printf("\n");
	print_hex_lower(5432);
	printf("\n");
	/*printf("%x\n", 14);*/
	return (0);
}
