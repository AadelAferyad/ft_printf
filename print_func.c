/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:14:50 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/14 02:23:14 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int	ft_putchar(va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	return (write(1, &c, 1));
}

int	ft_puts(va_list arg)
{
	int	i;
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
	{
		printf("NULL\n");
		return (-1);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	_print_nbr_healper_div(int len)
{
	int	i;
	int	div;

	i = 1;
	div = 1;
	while (i < len)
	{
		i++;
		div = div * 10;
	}
	return (div);
}

int	_print_nbr_healper_len(long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	_print_nbr_healper_writer(long n, int div)
{
	char	c;

	while (div > 0)
	{
		c = ((n / div) % 10) + 48;
		write(1, &c, 1);
		div /= 10;
	}
} 

int	ft_putnbr(va_list arg)
{
	long	n;
	int	len;
	int	div;

	n = va_arg(arg, int);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	len = _print_nbr_healper_len(n);
	div = _print_nbr_healper_div(len);
	_print_nbr_healper_writer(n, div);
	return (len + (n < 0));
}
