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

void	fill_map(tb *table)
{
	int	i;
	int (*fun[10]) (va_list arg);

	fun[0] = ft_putchar;
	fun[1] = ft_puts;
	fun[2] = NULL;
	i = 0;
	while (i < table->size)
	{
		table->table[i].f = fun[i];  
		i++;
	}
}

tb	*create_table(size_t size)
{
	tb	*ptr;

	ptr = ft_calloc(1, sizeof(tb));
	if (!ptr)
		return (NULL);
	ptr->size = size;
	return (ptr);
}

elm	*create_elements(tb	*h_tb)
{
	elm	*ptr;

	ptr = ft_calloc(h_tb->size, sizeof(elm));
	if (!ptr)
		return (NULL);
	h_tb->table = ptr;
	return (ptr);
}
