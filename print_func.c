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

int	print_percentage(va_list arg)
{
	(void) arg;
	return (ft_putchar('%'));
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

/*int	print_address_helper(unsigned long int hex, char c)*/
/*{*/
/*	int	count;*/
/**/
/*	count = 0;*/
/*	if (hex / 16)*/
/*		count += (print_hex(hex / 16, c));*/
/*	if (hex % 16 < 10)*/
/*		count += ft_putchar((hex % 16) + 48);*/
/*	else */
/*		count += ft_putchar((hex % 16) - 10 + c);*/
/*	return (count);*/
/*}*/

int	print_address_helper(unsigned long hex)
{
	int	count;
	int	i;
	char	*p;

	p = malloc(sizeof(char) * 30);
	if (!p)
		return (-1);
	count = 0;
	i = 0;
	while (hex > 0)
	{
		if (hex % 16 < 10)
			p[i] = hex % 16 + 48;
		else
			p[i] = hex % 16 - 10 + 'a';
		hex /= 16;
		i++;
	}
	p[i] = '\0';
	if (ft_reverse(p))
		count = ft_puts(p);
	free(p);
	return (count);
}

int	print_address(va_list arg)
{
	unsigned long	a;

	a = (unsigned long) va_arg(arg, void *);
	if (!a)
		return (ft_puts("(nil)"));
	return (ft_puts("0x") + print_address_helper((unsigned long) a));
}
