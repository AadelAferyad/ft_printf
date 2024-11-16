/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:14:50 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/15 15:41:21 by aaferyad         ###   ########.fr       */
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
	{
		return (-1);
	}
	return (ft_puts(s));
}


int	print_integer(va_list arg)
{
	int	n;

	n = va_arg(arg, int);
	return (ft_putnbr(n));
}

int	print_unsigned(va_list arg)
{
	unsigned int	n;

	n = (unsigned int) va_arg(arg, unsigned int);
	return (ft_putnbr_unsigned(n));
}
