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

	i = ft_printf("%d\n\n", 255);
	return (0);
}
