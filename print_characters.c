/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:14:50 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/17 13:47:14 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_char(va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	return (ft_putchar(c));
}

int	print_string(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
		return(ft_puts("(null)"));
	return (ft_puts(s));
}

int	print_percentage(va_list arg)
{
	(void) arg;
	return (ft_putchar('%'));
}

int	print_flags(int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

