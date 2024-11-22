/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:32:22 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 23:09:38 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

int	print_flag_char(t_flags *fg, char c)
{
	int	i;
	int	size;

	i = 0;
	if (((fg->minus || fg->zero) && fg->space) || (fg->space && !fg->width))
	{
		if (fg->sp_format != 'i' && fg->sp_format != 'd'\
			&& fg->sp_format != 'p')
			return (0);
		fg->len_data++;
		fg->space = OFF;
		return (ft_putchar(' '));
	}
	size = fg->width - fg->len_data;
	while (i < size)
	{
		ft_putchar(c);
		i++;
	}
	fg->len_data += i;
	return (i);
}

int	print_flag_hashtag(t_flags *fg, va_list arg)
{
	char			c;
	va_list			tmp;
	unsigned int	hex;

	c = fg->sp_format;
	if (c != 'x' && c != 'X')
		return (0);
	va_copy(tmp, arg);
	hex = va_arg(tmp, unsigned int);
	if (!hex)
		return (0);
	if (c == 'x')
		return (ft_puts("0x"));
	return (ft_puts("0X"));
}

int	print_flag_plus(t_flags *fg, va_list arg)
{
	va_list	tmp;
	int		n;

	va_copy(tmp, arg);
	n = va_arg(tmp, int);
	fg->len_data++;
	if (n < 0)
		return (ft_putchar('-'));
	return (ft_putchar('+'));
}

int	print_flag_minus(t_flags *fg)
{
	int	i;
	int	size;

	i = 0;
	size = fg->width - fg->len_data;
	while (i < size)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int	print_nbr_flag_plus(va_list arg)
{
	int	n;
	int	count;

	va_copy(arg, arg);
	n = va_arg(arg, int);
	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			count = ft_putchar('2');
			n = 147483648;
		}
		else
			n = -n;
	}
	count += ft_putnbr(n);
	return (count);
}
