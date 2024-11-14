/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:45:38 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/14 17:21:55 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	gen_index_key(char c, va_list arg)
{
	int	index;

	if (c == 'c')
		index = 0;
	else if (c == 's')
		index = 1;
	else if (c == 'd')
		index = 2;
	else if (c == 'i')
		index = 3;
	else if (c == 'u')
		index = 4;
	else if (c == 'p')
		index = 5;
	else if (c == 'x')
		index = 6;
	else if (c == 'X')
		index = 7;
	else if (c == '%')
		index = 8;
	else
		index = -1;
	return (index);
}

static int	checker(const char *s, va_list args)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (ft_strchr("csdiupxX%", s[i]))
			{
				gen_index_key(s[i], args);
			}
		}
		i++;
	}
	return
}

int ft_printf(const char *s, ...)
{
	int	i;
	va_list	arg;

	i = 0;
	if (!s)
		return (0);
	va_start(arg, s);
	checker(s, arg);
	va_end(arg);
	checker(s, arg);
}
