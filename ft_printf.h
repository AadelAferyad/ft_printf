/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:25:09 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/14 16:10:09 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF
#define FTPRINTF

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct	table_elements
{
	int	(*f)(va_list arg);
} elm;

typedef struct hash_table
{
	int	size;
	int	index;
	char	*sp;
	elm	*table;

} tb;

int ft_printf(const char *s, ...);

tb	*create_table(size_t size);
elm	*create_elements(tb *h_tb);
int	ft_putchar(va_list arg);
int	ft_puts(va_list arg);

#endif
