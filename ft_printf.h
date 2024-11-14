/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:25:09 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/14 02:28:07 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF
#define FTPRINTF

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int ft_printf(const char *, ...);

typedef struct	table_elements
{
	int	(*f)(char c);
} elements;
typedef struct hash_table
{
	int	size;
	elements *tb;

} table;

table	*create_table(size_t size);
elements	*create_elements(table *h_tb);
int	ft_putchar(char	c);
int	ft_puts(char *s);

#endif
