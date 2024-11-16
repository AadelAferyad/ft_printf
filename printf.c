/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:45:38 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/15 13:41:07 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	gen_index_key(char c, format *fr)
{
	int	i;

	i = 0;
	while (fr[i].f)
	{
		if (fr[i].sep == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	checker(const char *s, va_list args, format *tb)
{
	int	i;
	int	index;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[++i] && ft_strchr("csdiupxX%", s[i]))
		{
			index = gen_index_key(s[i], tb);
			if (index == -1)
				return (-1);
			count += tb[index].f(args);
		}
		else if (s[i])
		{
			count += write(1, &s[i], 1);
		}
		else
			break ;
		i++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	arg;
	format	*fr;

	i = 0;
	if (!s)
		return (0);
	fr = create_array(9);
	if (!fr)
		return (-1);
	va_start(arg, s);
	fill_map(fr);
	i = checker(s, arg, fr);
	free(fr);
	va_end(arg);
	return (i);
}
