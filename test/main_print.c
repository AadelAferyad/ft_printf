#include "../ft_printf.h"
#include <stdio.h>


int	main(void)
{
	/*ft_printf("hello %c\n %s\n%d\n%d\n%d\n%u\n", 'z', "test", 0, 1337, -1337, -222);*/
	int	i;
	/*i = ft_printf("%c %s %d %u %i %x %X %% %%%c\n%p\n%p", 'c', "hello", 1337, 0, 42, 25512323, 312255923, 65, "t", &i);*/
	i = ft_printf("%p\n%p\n", "hello", &i);
	printf("%d\n\n", i);
	/*i = printf("%c %s %d %u %i %x %X %% %%%c\n%p\n%p", 'c', "hello", 1337, 0, 42, 25512323, 312255923, 65, "t", &i);*/
	i = printf("%p\n%p\n", "hello", &i);
	printf("%d\n\n", i);
	return (0);
}
