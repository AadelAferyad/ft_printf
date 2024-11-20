/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:58:45 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 23:05:07 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PRINTF_H
# define BONUS_PRINTF_H

# include "ft_printf.h"

# define ON 1
# define OFF 0

typedef struct precision_flag
{
	int	length;
	int	is_valid;
}	t_dot;

typedef struct after_format
{
	int		minus;
	int		zero;
	int		hashtag;
	int		space;
	int		plus;
	int		width;
	t_dot	*perc;
	int		count;
	int		len_data;
	int		index;
	char	sp_format;
}	t_flags;

int		check_flag(char *s, t_fr *tb, va_list arg);
int		print_with_flags(t_flags *fg, va_list arg, t_fr *tb);
t_flags	*create_flags_struct(void);
t_dot	*create_precision(void);

int		set_flag_to_struct(char c, t_flags *fg);
t_flags	*flag_parser(char *s, char *flg, t_flags *fg);

int		print_flag_char(t_flags *fg, char c);
int		print_flag_hashtag(t_flags *fg);
int		print_flag_plus(t_flags *fg, va_list arg);
int		print_flag_minus(t_flags *fg);
int		print_nbr_flag_plus(va_list arg);

void	count_len_d(va_list arg, t_flags *fg);
void	count_len_u(va_list arg, t_flags *fg);
void	count_len_s(va_list arg, t_flags *fg);
void	count_len_p(va_list arg, t_flags *fg);
void	count_len_x(va_list arg, t_flags *fg);

int		print_string_with_percision(t_flags *fg, va_list arg);
void	print_percision(t_flags *fg);
#endif
