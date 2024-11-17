/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array_of_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:49:17 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/17 15:06:53 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_map(fr *frm)
{
	if (!frm)
		return ;
	frm[0].f = print_char;
	frm[0].sep = 'c';
	frm[1].f = print_string;
	frm[1].sep = 's';
	frm[2].f = print_integer;
	frm[2].sep = 'd';
	frm[3].f = print_integer;
	frm[3].sep = 'i';
	frm[4].f = print_unsigned;
	frm[4].sep = 'u';
	frm[5].f = print_hex_lower;
	frm[5].sep = 'x';
	frm[6].f = print_hex_upper;
	frm[6].sep = 'X';
	frm[7].f = print_percentage;
	frm[7].sep = '%';
	frm[8].f = print_address;
	frm[8].sep = 'p';
	frm[9].f = NULL;
	frm[9].sep = 0;
}

fr	*create_array(size_t size)
{
	fr	*ptr;

	ptr = ft_calloc(size, sizeof(fr));
	if (!ptr)
		return (NULL);
	return (ptr);
}
