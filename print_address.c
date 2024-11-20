/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:44:06 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 22:16:57 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_address_helper(unsigned long long hex, int flag)
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
			p[i++] = hex % 16 - 10 + 'a';
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

int	print_address(va_list arg)
{
	unsigned long long	a;

	a = (unsigned long long) va_arg(arg, void *);
	if (!a)
		return (ft_puts("(nil)"));
	return (ft_puts("0x") + print_address_helper(a, 0));
}
