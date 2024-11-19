/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:57:02 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/17 17:24:38 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

/*
 * "%-10s", "hey"
 * "%-10#d", 22;
 * "%10c", 'c'
 * */
int	set_flag_to_struct(char c, flags *fg)
{
	if (c == '-')
		fg->minus = 1;
	else if (c == '0')
		fg->zero = 1;
	else if (c == '#')
		fg->hashtag = 1;
	else if (c == ' ')
		fg->space = 1;
	else if (c == '+')
		fg->plus = 1;
	else
		return (1);
	return (0);
}

void	adjust_flag_bool(char c, flags *fg)
{
	if (c == '-')
	{
		fg->minus = 1;
		if (fg->zero)
			fg->zero = 0;
	}
	else if (c == '0' && !fg->minus)
		fg->zero = 1;
}

int	set_width(char *s, flags *fg)
{
	int	i;

	i = 0;
	fg->width = ft_atoi(s);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (!fg->minus && !fg->space)
		fg->space = ON;
	return (i - (i > 0));
}

void	set_precision(char *s, flags *fg)
{
	int	i;

	i = 1;
	fg->perc = create_precision();
	if (!fg->perc)
		return ;
	if (s[i] && !ft_strchr(FORMAT, s[i]))
		fg->perc->length = ft_atoi(&s[i]);
	while (s[i] >= '0' && s[i] <= '9')	
		i++;
}

flags	*flag_parser(char *s, char *flg, flags *fg)
{
	int	i;
	int	is_flaged;
	char	*schr;

	i = 0;
	is_flaged = 0;
	while (s[i] && !ft_strchr(FORMAT, s[i]))
	{
		schr = ft_strchr(flg, s[i]);
		if (schr && !is_flaged)
			is_flaged = set_flag_to_struct(s[i], fg);
		else if (schr)
			adjust_flag_bool(s[i], fg);
		if (s[i] >= '1' && s[i] <= '9')
			i += set_width(&s[i], fg);
		if (s[i] == '.')
			set_precision(&s[i], fg);
		i++;
	}
	if (s[i])
		fg->sp_format = s[i];
	fg->index = i;
	return (fg);
}

void	garbage_collector(flags *fg)
{
	if (fg->perc)
		free(fg->perc);
	free(fg);
}

int	validate_percision(flags *fg)
{
	if (fg->sp_format != 's')
	{
		free(fg->perc);
		fg->perc = NULL;
		return (1);
	}
	return (0);
}

void	validate_flags_with_sp(flags *fg, int m, int z, int h, int space, int p)
{
	if (m && fg->minus)
		fg->minus = OFF;
	if (z && fg->zero)
		fg->zero = OFF;
	if (h && fg->hashtag)
		fg->hashtag = OFF;
	if (space && fg->space)
		fg->space = OFF;
	if (p && fg->plus)
		fg->plus = OFF;
}

void	validate_flags_with_spe(flags *fg)
{
	char	c;

	c = fg->sp_format;
	if (c == 's')
		validate_flags_with_sp(fg, 0, 0, 1, 0, 0);
	else if (c == 'c')
		validate_flags_with_sp(fg, 0, 1, 1, 1, 1);
	else if (c == 'd')
		validate_flags_with_sp(fg, 0, 0, 1, 0, 0);
	else if (c == 'i')
		validate_flags_with_sp(fg, 0, 0, 1, 0, 0);
	else if (c == 'u')
		validate_flags_with_sp(fg, 0, 0, 1, 1, 1);
	else if (c == 'x')
		validate_flags_with_sp(fg, 0, 0, 0, 1, 1);
	else if (c == 'X')
		validate_flags_with_sp(fg, 0, 0, 0, 1, 1);
	else if (c == 'p')
		validate_flags_with_sp(fg, 0, 1, 1, 1, 1);
}

int	check_flag(char *flg, char *s, fr *tb, va_list arg)
{
	flags	*fg;
	int	count;

	fg = create_flags_struct();
	if (!fg)
		return (0);
	if (ft_strchr(flg, *s))
	{
		flag_parser(s, flg, fg);
		if (!ft_strchr(FORMAT, fg->sp_format))
		{
			garbage_collector(fg);
			return (0);
		}
		validate_flags_with_spe(fg);
		validate_percision(fg);
		count = print_with_flags(fg, arg, tb);
		tb[0].index = fg->index;
		garbage_collector(fg);
		return (count);
	}
	return (0);
}
