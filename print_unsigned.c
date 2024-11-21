/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:47:37 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 22:23:18 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_len(long nb)
{
	int	len;

	len = 0;
	if (!nb)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_count_div(int len)
{
	int	div;

	div = 1;
	while (len > 1)
	{
		div *= 10;
		len--;
	}
	return (div);
}

int	ft_writer(unsigned int nb, int div)
{
	int		len;
	char	n;

	len = 0;
	while (div > 0)
	{
		n = ((nb / div) % 10) + 48;
		ft_putchar(n);
		div /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;
	int	div;

	len = ft_count_len(n);
	div = ft_count_div(len);
	return (ft_writer(n, div));
}
