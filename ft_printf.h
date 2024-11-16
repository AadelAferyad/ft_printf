/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:25:09 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/16 17:04:45 by aaferyad         ###   ########.fr       */
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
} fr;

typedef struct after_format
{
	int	n;
	char	sp_flag;
	char	sp_format;
	int	index;
	int	count;
} a_fr;

int ft_printf(const char *s, ...);

fr	*create_array(size_t size);
int	print_char(va_list arg);
int	print_string(va_list arg);
int	print_integer(va_list arg);
void	fill_map(fr *frm);
int	print_unsigned(va_list arg);
int	ft_putnbr_unsigned(unsigned int b);
int	print_hex_upper(va_list arg);
int	print_hex_lower(va_list arg);
int	print_hex(int hex, char c);
int	print_percentage(va_list arg);
int	print_address(va_list arg);

int	print_flags(int n, char c);
#endif
