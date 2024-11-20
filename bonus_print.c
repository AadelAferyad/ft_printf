/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:56:58 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 23:08:42 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

void	count_len(va_list arg, t_flags *fg)
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

int	print_flag_zero(t_flags *fg)
{
	int	size;
	int	i;

	i = 0;
	size = fg->width - fg->len_data;
	if (fg->perc)
		size = fg->perc->length;
	while (i < size)
	{
		ft_putchar('0');
		i++;
	}
	fg->len_data += i;
	return (i);
}

void	printer(t_flags *fg, va_list arg, t_fr *tb)
{
	int	count;

	count = 0;
	if (fg->space)
		count += print_flag_char(fg, ' ');
	if (fg->perc)
		print_percision(fg);
	if (fg->hashtag)
		count += print_flag_hashtag(fg);
	if (fg->plus)
		count += print_flag_plus(fg, arg);
	if (fg->zero)
		count += print_flag_zero(fg);
	if (fg->plus)
		count += print_nbr_flag_plus(arg);
	else if (fg->perc && fg->sp_format == 's')
		count += print_string_with_percision(fg, arg);
	else
		count += check_format(FORMAT, fg->sp_format, tb, arg);
	if (fg->minus)
		count += print_flag_minus(fg);
	fg->count = count;
}

int	print_with_flags(t_flags *fg, va_list arg, t_fr *tb)
{
	count_len(arg, fg);
	printer(fg, arg, tb);
	return (fg->count);
}
