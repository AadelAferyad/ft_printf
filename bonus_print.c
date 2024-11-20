/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:56:58 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/17 19:54:26 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

void	count_len_d(va_list arg, flags *fg)
{
	va_list	temp;
	int	n;

	va_copy(temp, arg);
	n = va_arg(temp, int);
	fg->len_data = ft_count_len(n);
}

void	count_len_u(va_list arg, flags *fg)
{
	va_list	temp;
	int	n;

	va_copy(temp, arg);
	n = va_arg(temp, unsigned int);
	fg->len_data = ft_count_len(n);
}

void	count_len_s(va_list arg, flags *fg)
{
	va_list	temp;
	char	*str;

	va_copy(temp, arg);
	str = va_arg(temp, char *);
	fg->len_data = ft_strlen(str);
}

void	count_len_p(va_list arg, flags *fg)
{
	va_list	temp;
	unsigned long long	ptr;

	va_copy(temp, arg);
	ptr = (unsigned long long) va_arg(temp, void *);
	fg->len_data = print_address_helper(ptr, ON);
}

void	count_len_x(va_list arg, flags *fg)
{
	va_list	temp;
	int	hex;

	va_copy(temp, arg);
	hex = va_arg(temp, int);
	fg->len_data = print_hex(hex, ON, 'a');
}

void	count_len(va_list arg, flags *fg)
{
	char	c;

	c = fg->sp_format;
	if (c == 's')
		count_len_s(arg, fg);
	if (c == 'c')
		fg->len_data = 1;
	if (c == 'd' || c == 'i')
		count_len_d(arg, fg);
	if (c == 'u')
		count_len_u(arg, fg);
	if (c == 'p')
		count_len_p(arg, fg);
	if (c == 'x' || c == 'X')
		count_len_x(arg, fg);
	if (fg->hashtag)
		fg->len_data += 2;
	if (fg->plus && !fg->zero)
		fg->len_data += 1;
}

int	print_flag_char(flags *fg, char c)
{
	int	i;
	int	size;

	i = 0;
	if ((fg->minus || fg->zero) && fg->space)
	{
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

int	print_flag_hashtag(flags *fg)
{
	if (fg->sp_format == 'x')
		return (ft_puts("0x"));
	if (fg->sp_format == 'X')
		return (ft_puts("0x"));
	return (0);
}

int	print_flag_plus(flags *fg, va_list arg)
{
	va_list	tmp;
	int	n;

	va_copy(tmp, arg);
	n = va_arg(tmp, int);
	fg->len_data++;
	if (n < 0)
		return (ft_putchar('-'));
	return (ft_putchar('+'));
}

int	print_flag_minus(flags *fg)
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
		if (n ==  -2147483648)
		{
			count = ft_putchar('2');
			n =  147483648;
		}
		else
			n = -n;
	}
	count += ft_putnbr(n);
	return (count);
}

void	printer(flags *fg, va_list arg, fr *tb)
{
	int	count;
	/**/
	/*printf("hna minus %d, plus %d, space %d, hashtag %d, zero %d, format %c, width : %d\n", fg->minus, fg->plus, fg->space, fg->hashtag, fg->zero, fg->sp_format, fg->width);*/
	count = 0;
	if (fg->space)
		count += print_flag_char(fg, ' ');
	if (fg->hashtag)
		count += print_flag_hashtag(fg);
	if (fg->plus)
		count += print_flag_plus(fg, arg);
	if (fg->zero)
		count += print_flag_char(fg, '0');
	if (fg->plus)
		count += print_nbr_flag_plus(arg);
	else
		count += check_format(FORMAT, fg->sp_format, tb, arg);
	if (fg->minus)
		count += print_flag_minus(fg);
	fg->count = count;
}

int	print_with_flags(flags *fg, va_list arg, fr *tb)
{
	count_len(arg, fg);
	printer(fg, arg, tb);
	return (fg->count);
}
