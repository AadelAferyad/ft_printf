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

void	count_len(void *add, flags *fg)
{
	char	c;

	c = fg->sp_format;
	if (c == 's')
		fg->len_data = ft_strlen((char *)add);
	if (c == 'c')
		fg->len_data = 1;
	if (c == 'd' || c == 'i' || c == 'x' || c == 'u' || c == 'X')
		fg->len_data = ft_count_len((long) add);
	if (fg->hashtag)
		fg->len_data += 2;
	if (fg->zero)
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

void	printer(flags *fg, va_list arg, fr *tb)
{
	int	count;
	/**/
	/*printf("hna minus %d, plus %d, space %d, hashtag %d, zero %d, format %c, width : %d\n", fg->minus, fg->plus, fg->space, fg->hashtag, fg->zero, fg->sp_format, fg->width);*/
	count = fg->len_data;
	if (fg->space)
		count += print_flag_char(fg, ' ');
	if (fg->hashtag)
		count += print_flag_hashtag(fg);
	if (fg->plus)
		count += print_flag_plus(fg, arg);
	if (fg->zero)
		count += print_flag_char(fg, '0');
	count += check_format(FORMAT, fg->sp_format, tb, arg);
	if (fg->minus)
		count += print_flag_minus(fg);
	fg->count = count;
}

int	print_with_flags(flags *fg, va_list arg, fr *tb)
{
	va_list	tmp;
	void	*add;

	va_copy(tmp, arg);
	add = va_arg(tmp, void *);
	count_len(add, fg);
	printer(fg, arg, tb);
	return (fg->count);
}
