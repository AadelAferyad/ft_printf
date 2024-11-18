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

int	print_flag_char(flags *fg, va_list arg, char c)
{
	int	i;
	int	size;

	i = 0;
	if (fg->minus || fg->zero)
		return (ft_putchar(' '));
	size = fg->width - fg->len_data;
	while (i < size)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int	print_flag_hashtag(flags *fg, va_list arg)
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
	if (n < 0)
		return (ft_putchar('-'));
	return (ft_putchar('+'));
}

int	print_flag_minus(flags *fg, va_list arg)
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
}

int	printer(flags *fg, va_list arg)
{
	if (fg->space)
		print_flag_char(fg, arg, ' ');
	if (fg->hashtag)
		print_flag_hashtag(fg, arg);
	if (fg->plus)
		print_flag_plus(fg, arg);
	if (fg->zero)
		print_flag_char(fg, arg, '0');
	if (fg->minus)
		print_flag_minus(fg, arg);
}

int	print_with_flags(flags *fg, char *s, va_list arg)
{
	va_list	tmp;
	void	*add;
	int		i;

	i = 0;
	va_copy(tmp, arg);
	add = va_arg(tmp, void *);
	count_len(add, fg);
}
