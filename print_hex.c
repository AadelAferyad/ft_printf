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

int	print_hex_lower(int hex)
{
	int	i;

	i = 0;

}

int	print_hex(va_list arg)
{
	int	hex;

	hex = va_arg(arg, int);
	return (print_hex_lower(hex));
}
