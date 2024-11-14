/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:59:15 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/14 02:25:10 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

table	*create_table(size_t size)
{
	table	*ptr;

	ptr = ft_calloc(1, sizeof(table));
	if (!ptr)
		return (NULL);
	ptr->size = size;
	return (ptr);
}

elements	*create_elements(table *h_tb)
{
	elements	*ptr;

	ptr = ft_calloc(h_tb->size, sizeof(elements));
	if (!ptr)
		return (NULL);
	h_tb->tb = ptr;
	return (ptr);
}
