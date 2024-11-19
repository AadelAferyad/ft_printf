/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:58:45 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/17 15:49:12 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PRINTF
#define BONUS_PRINTF

#include "ft_printf.h"

# define ON 1
# define OFF 0

typedef struct precision_flag
{
	int	length;
	int	is_valid;
} dot;

typedef struct after_format
{
	int	minus;
	int	zero;
	int	hashtag;
	int	space;
	int	plus;
	int	width;
	dot	*perc;
	int	count;
	int	len_data;
	int	index;
	char	sp_format;
} flags;

int	check_flag(char *flg, char *s, fr *tb, va_list arg);
int	print_with_flags(flags *fg, va_list arg, fr *tb);
flags	*create_flags_struct();
dot	*create_precision();
#endif
