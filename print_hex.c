/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:42:30 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 22:20:07 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(int hex, int flag, char c)
{
	int		count;
	int		i;
	char	*p;

	p = malloc(sizeof(char) * 30);
	if (!p)
		return (-1);
	i = 0;
	while (hex > 0)
	{
		if (hex % 16 < 10)
			p[i++] = hex % 16 + 48;
		else
			p[i++] = hex % 16 - 10 + c;
		hex /= 16;
	}
	p[i] = '\0';
	ft_reverse(p);
	if (!flag)
		count = ft_puts(p);
	else
		count = ft_strlen(p);
	free(p);
	return (count);
}

int	print_hex_lower(va_list arg)
{
	int	hex;

	hex = va_arg(arg, int);
	return (print_hex(hex, 0, 'a'));
}

int	print_hex_upper(va_list arg)
{
	int	hex;

	hex = va_arg(arg, int);
	return (print_hex(hex, 0, 'A'));
}
