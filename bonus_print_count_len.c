/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print_count_len.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:35:57 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 23:09:14 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

void	count_len_d(va_list arg, t_flags *fg)
{
	va_list	temp;
	int		n;
	int		count;
	int		tmp;

	va_copy(temp, arg);
	n = va_arg(temp, int);
	count = ft_count_len(n);
	if (n < 0)
		count++;
	if (fg->perc)
	{
		tmp = fg->perc->length - count;
		if (fg->perc->length - count > 0)
			count += tmp;
		fg->perc->length = tmp;
		if (fg->zero)
		{
			fg->zero = OFF;
			fg->space = ON;
		}
	}
	fg->len_data = count;
}

void	count_len_u(va_list arg, t_flags *fg)
{
	va_list	temp;
	unsigned int	n;
	int		count;
	int		tmp;

	va_copy(temp, arg);
	n = va_arg(temp, unsigned int);
	count = ft_count_len(n);
	if (fg->perc)
	{
		tmp = fg->perc->length - count;
		if (fg->perc->length - count > 0)
			count += tmp;
		fg->perc->length = tmp;
	}
	fg->len_data = count;
}

void	count_len_s(va_list arg, t_flags *fg)
{
	va_list	temp;
	char	*str;
	int		len;

	va_copy(temp, arg);
	str = va_arg(temp, char *);
	if (!str)
	{
		len = ft_strlen("(NULL)");
		if (fg->perc->length < 6)
			len = 0;
		fg->len_data = len;
		return ;
	}
	len = ft_strlen(str);
	if (fg->perc && len > fg->perc->length)
		len = fg->perc->length;
	fg->len_data = len;
}

void	count_len_p(va_list arg, t_flags *fg)
{
	va_list				temp;
	unsigned long long	ptr;

	va_copy(temp, arg);
	ptr = (unsigned long long) va_arg(temp, void *);
	fg->len_data = print_address_helper(ptr, ON) + 2;
}

void	count_len_x(va_list arg, t_flags *fg)
{
	va_list			temp;
	unsigned int	hex;

	va_copy(temp, arg);
	hex = va_arg(temp, unsigned int);
	fg->len_data = print_hex(hex, ON, 'a');
}
