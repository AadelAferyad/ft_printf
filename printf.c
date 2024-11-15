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
#include <stdio.h>

int	gen_index_key(char c)
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

static int	checker(const char *s, va_list args, format *tb)
{
	int	i;
	int	index;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (ft_strchr("csdiupxX%", s[i]))
			{
				index = gen_index_key(s[i]);
				if (index == -1)
					return (-1);
				tb[index].f(args);
			}
		}
		else
		{
			write(1, &s[i], 1);
		}
		i++;
	}
	return (i);
}

int ft_printf(const char *s, ...)
{
	int	i;
	va_list	arg;
	format	*fr;

	i = 0;
	if (!s)
		return (0);
	fr = create_array(9);
	va_start(arg, s);
	fill_map(fr);
	i = checker(s, arg, fr);
	va_end(arg);
	return (i);
}
