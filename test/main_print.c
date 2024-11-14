#include "../ft_printf.h"


int	main(void)
{
	ft_printf("hello %c\n %s\n%d\n%d\n%d\n", 'z', "test", 0, 1337, -1337);
	return (0);
}
