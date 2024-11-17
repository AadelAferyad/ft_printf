/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:44:06 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/17 13:44:32 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_address_helper(unsigned long hex)
{
	int	count;
	int	i;
	char	*p;

	p = malloc(sizeof(char) * 30);
	if (!p)
		return (-1);
	count = 0;
	i = 0;
	while (hex > 0)
	{
		if (hex % 16 < 10)
			p[i] = hex % 16 + 48;
		else
			p[i] = hex % 16 - 10 + 'a';
		hex /= 16;
		i++;
	}
	p[i] = '\0';
	if (ft_reverse(p))
		count = ft_puts(p);
	free(p);
	return (count);
}

int	print_address(va_list arg)
{
	unsigned long	a;

	a = (unsigned long) va_arg(arg, void *);
	if (!a)
		return (ft_puts("(nil)"));
	return (ft_puts("0x") + print_address_helper((unsigned long) a));
}
