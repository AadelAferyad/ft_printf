#include "../ft_printf.h"
#include <stdio.h>


int	main(void)
{
	int	i;
	int	a;

	a = 123456;
	/*i = ft_printf("this is a test %d %c %s %i %u %x %X %% %p\n", 120, 'W', "working", 120, -1, 259, 255, &i);*/
	/*ft_printf("%d\n", i);*/
	/*i = printf("this is a test %d %c %s %i %u %x %X %% %p\n", 120, 'W', "working", 120, -1, 259, 255, &i);*/
	/*ft_printf("%d\n", i);*/

	i = printf("%-100da\n\n", a);
	ft_printf("%d\n", i);
	i = ft_printf("%-100sa\n\n", "hello abdo how are u today wth the weather");
	ft_printf("%d\n", i);
	return (0);
}
