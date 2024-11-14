/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:14:50 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/14 02:23:14 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_putchar(char	c)
{
	return (write(1, &c, 1));
}

int	ft_puts(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}
