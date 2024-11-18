#include "../ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

char	*allocate_arg(char *s)
{
	char	*str;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	return (str);
}


char	*allocate_char(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

int	main(void)
{
	int	i;
	int	a;

	a = 123456;
	char p = 'c';
	char *c = &p;
	char *s = allocate_arg(c);
	printf("%s\n", s);
	return (0);
}
