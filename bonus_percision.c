/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_percision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:39:08 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 23:08:10 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

int	print_string_with_percision(t_flags *fg, va_list arg)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(arg, char *);
	if (!str)
	{
		if (fg->perc->length > 5)
			i = ft_puts("(null)");
		return (i);
	}
	while (str[i] && i < fg->perc->length)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	print_percision(t_flags *fg)
{
	char	c;

	c = fg->sp_format;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		fg->zero = ON;
	if (c == 'x' || c == 'X')
		fg->perc->length -= fg->len_data;
}
