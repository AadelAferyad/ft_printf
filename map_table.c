/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:59:15 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/14 17:22:00 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_map(format	*fr)
{
	if (!fr)
		return ;
	fr[0].f = ft_putchar;
	fr[0].sep = 'c';
	fr[1].f = ft_puts;
	fr[1].sep = 's';
	fr[2].f = ft_putnbr;
	fr[2].sep = 'd';
	fr[3].f = NULL;
}

format	*create_array(size_t size)
{
	format	*ptr;

	ptr = ft_calloc(size, sizeof(format));
	if (!ptr)
		return (NULL);
	return (ptr);
}

