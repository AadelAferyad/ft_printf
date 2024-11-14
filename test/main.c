#include <stdio.h>
#include "../ft_printf.h"


int	main(void)
{
	tb	*h_tb;
	elm	*sp;
	size_t	size;

	size = 9;
	h_tb = create_table(size);
	sp = create_elements(h_tb);
	h_tb->tb[0].f = ft_putchar;	
	h_tb->tb[0].f(65);
	return (0);
}
