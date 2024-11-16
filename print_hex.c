/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:42:30 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/15 15:53:07 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(int hex, char c)
{
	int	count;

	count = 0;
	if (hex / 16)
		count += (print_hex(hex / 16, c));
	if (hex % 16 < 10)
		count += ft_putchar((hex % 16) + 48);
	else
		count += ft_putchar((hex % 16) - 10 + c);
	return (count);
}

int	print_hex_lower(va_list arg)
{
	int	hex;

	hex = va_arg(arg, int);
	return (print_hex(hex, 'a'));
}

int	print_hex_upper(va_list arg)
{
	int	hex;

	hex = va_arg(arg, int);
	return (print_hex(hex, 'A'));
}
