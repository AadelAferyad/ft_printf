#include "../ft_printf.h"
#include <stdio.h>


int	main(void)
{
	printf("%s\n%", "test");
	ft_printf("hello %c\n %s\n%d\n%d\n%d\n%", 'z', "test", 0, 1337, -1337);
	printf("%i\n", -22);
	return (0);
}
