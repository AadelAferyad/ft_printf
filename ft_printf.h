/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:25:09 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/15 13:24:47 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF
#define FTPRINTF

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct	format_specifaier
{
	char	sep;
	int	(*f)(va_list arg);
	struct format_specifaier *next;
} format;

int ft_printf(const char *s, ...);

format	*create_array(size_t size);
int	print_char(va_list arg);
int	print_string(va_list arg);
int	print_integer(va_list arg);
void	fill_map(format *fr);

#endif
