/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:59:15 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/15 13:37:29 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_map(format	*fr)
{
	if (!fr)
		return ;
	fr[0].f = print_char;
	fr[0].sep = 'c';
	fr[1].f = print_string;
	fr[1].sep = 's';
	fr[2].f = print_integer;
	fr[2].sep = 'd';
	fr[3].f = print_integer;
	fr[3].sep = 'i';
	fr[4].f = print_unsigned;
	fr[4].sep = 'u';
	fr[5].f = print_hex_lower;
	fr[5].sep = 'x';
	fr[6].f = print_hex_upper;
	fr[6].sep = 'X';
	fr[7].f = print_percentage;
	fr[7].sep = '%';
	fr[8].f = print_address;
	fr[8].sep = 'p';
	fr[9].f = NULL;
	fr[9].sep = 0;
}

format	*create_array(size_t size)
{
	format	*ptr;

	ptr = ft_calloc(size, sizeof(format));
	if (!ptr)
		return (NULL);
	return (ptr);
}
