/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:45:55 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/17 13:46:09 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list arg)
{
	int	n;

	n = va_arg(arg, int);
	return (ft_putnbr(n));
}

int	print_unsigned(va_list arg)
{
	unsigned int	n;

	n = (unsigned int) va_arg(arg, unsigned int);
	return (ft_putnbr_unsigned(n));
}
