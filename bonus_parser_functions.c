/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parser_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:30:03 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 23:07:29 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

void	adjust_flag_bool(char c, t_flags *fg)
{
	if (c == '-')
	{
		fg->minus = ON;
		if (fg->zero)
			fg->zero = OFF;
	}
	else if (c == '0' && !fg->minus)
		fg->zero = ON;
}

int	set_width(char *s, t_flags *fg)
{
	int	i;

	i = 0;
	fg->width = ft_atoi(s);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (!fg->minus && !fg->zero && !fg->space)
		fg->space = ON;
	return (i - (i > 0));
}

void	set_precision(char *s, t_flags *fg)
{
	int	i;

	i = 1;
	fg->perc = create_precision();
	if (!fg->perc)
		return ;
	if (s[i] && !ft_strchr(FORMAT, s[i]))
		fg->perc->length = ft_atoi(&s[i]);
}

t_flags	*flag_parser(char *s, char *flg, t_flags *fg)
{
	int		i;
	int		is_flaged;
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
		if ((s[i] >= '1' && s[i] <= '9') && !fg->perc)
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
