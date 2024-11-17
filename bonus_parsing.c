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
	return (i);
}

void	set_precision(char *s, flags *fg)
{
	int	i;

	i = 1;
	fg->perc = create_precision();
	if (!fg->perc)
		return ;
	if (s[i] && !ft_strchr("csdiupxX%", s[i]))
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
	while (s[i] && !ft_strchr("csdiupxX%", s[i]))
	{
		schr = ft_strchr(flg, s[i]);
		if (schr && !is_flaged)
			is_flaged = set_flag_to_struct(s[i], fg);
		else if (schr)
			adjust_flag_bool(s[i], fg);
		if (s[i] >= '1' && s[i] <= '0')
			i += set_width(&s[i], fg);
		if (s[i] == '.')
			set_precision(&s[i], fg);
		i++;
	}
	if (s[i])
		fg->sp_format = s[i];
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

void	validate_with_s(flags *fg)
{
	if (fg->hashtag)
		fg->hashtag = 0;
	if (fg->zero)
		fg->zero = 0;
}

void	validate_with_d(flags *fg)
{
	if (fg->hashtag)
		fg->hashtag = 0;
}

void	validate_with_c(flags *fg)
{
	if (fg->hashtag)
		fg->hashtag = 0;
	if (fg->zero)
		fg->zero = 0;
	if (fg->plus)
		fg->plus = 0;
	if (fg->space)
		fg->space = 0;
}

void	validate_with_u(flags *fg)
{
	if (fg->hashtag)
		fg->hashtag = 0;
	if (fg->plus)
		fg->plus = 0;
	if (fg->space)
		fg->space = 0;
}

void	validate_with_x(flags *fg)
{
	if (fg->plus)
		fg->plus = 0;
	if (fg->space)
		fg->space = 0;
}

void	validate_with_p(flags *fg)
{
	if (fg->plus)
		fg->plus = 0;
	if (fg->space)
		fg->space = 0;
	if (fg->zero)
		fg->zero = 0;
	if (fg->hashtag)
		fg->hashtag = 0;
}

void	validate_flags_with_spe(flags *fg)
{
	char	c;

	c = fg->sp_format;
	if (c == 's')
		validate_with_s(fg);
	else if (c == 'c')
		validate_with_c(fg);
	else if (c == 'd')
		validate_with_d(fg);
	else if (c == 'i')
		validate_with_d(fg);
	else if (c == 'u')
		validate_with_u(fg);
	else if (c == 'x')
		validate_with_x(fg);
	else if (c == 'X')
		validate_with_x(fg);
	else if (c == 'p')
		validate_with_x(fg);
}

flags	*check_flag(char *flg, char *s, fr *tb, va_list arg)
{
	flags	*fg;

	fg = create_flags_struct();
	if (!fg)
		return (NULL);
	if (ft_strchr(flg, *s))
	{
		flag_parser(s, flg, fg);
		if (!ft_strchr("csdiupxX%", fg->sp_format))
		{
			garbage_collector(fg);
			return (NULL);
		}
		validate_flags_with_spe(fg);
		validate_percision(fg);
	}
	return (fg);
}
