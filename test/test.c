#include <stdarg.h>
#include <stdio.h>

int	calc(int a, ...)
{
	va_list	arg;
	va_list	dest;
	int	i;
	int	sum;

	va_start(arg, a);
	i = 0;
	sum = 0;
	while (i < a)
	{
		if (!i)
			va_copy(dest, arg);
		sum += va_arg(arg, int);
		i++;
	}
	printf("%d\n", va_arg(dest, int));
	return (sum);
}
	
int	main(void)
{
	printf("%d\n", calc(3, 13,1,5));
	return (0);
}

