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

typedef struct	format_specifaier
{
	char	sep;
	int	(*f)(va_list arg);
	struct format_specifaier *next;
} format;

int ft_printf(const char *s, ...);

format	*create_array(size_t size);
int	ft_putchar(va_list arg);
int	ft_puts(va_list arg);
int	ft_putnbr(va_list arg);
void	fill_map(format *fr);
int	ft_putnbr(va_list arg);

#endif
