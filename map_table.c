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

void	fill_map(table *tb)
{
	if (!tb)
		return ;
	tb->htb[0].f = ft_putchar;
	tb->htb[1].f = ft_puts;
	tb->htb[2].f = ft_putnbr;
	tb->htb[3].f = NULL;
}

table	*create_table(size_t size)
{
	table	*ptr;

	ptr = ft_calloc(1, sizeof(table));
	if (!ptr)
		return (NULL);
	ptr->size = size;
	return (ptr);
}

elm	*create_elements(table	*tb)
{
	elm	*ptr;

	ptr = ft_calloc(tb->size, sizeof(elm));
	if (!ptr)
		return (NULL);
	tb->htb = ptr;
	return (ptr);
}
