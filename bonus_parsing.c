/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:57:02 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 23:07:58 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

void	garbage_collector(t_flags *fg)
{
	if (fg->perc)
		free(fg->perc);
	free(fg);
}

int	validate_percision(t_flags *fg)
{
	char	c;

	c = fg->sp_format;
	if (c != 's' && c != 'd' && c != 'i' && c != 'u' && c != 'x' && c != 'X')
	{
		free(fg->perc);
		fg->perc = NULL;
		return (1);
	}
	return (0);
}

void	validate_flags_with_sp(t_flags *fg, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'm' && fg->minus)
			fg->minus = OFF;
		else if (s[i] == 'z' && fg->zero)
			fg->zero = OFF;
		else if (s[i] == 'h' && fg->hashtag)
			fg->hashtag = OFF;
		else if (s[i] == ' ' && fg->space)
			fg->space = OFF;
		else if (s[i] == 'p' && fg->plus)
			fg->plus = OFF;
		i++;
	}
}

void	validate_flags_with_spe(t_flags *fg)
{
	char	c;

	c = fg->sp_format;
	if (c == 's')
		validate_flags_with_sp(fg, "zhp");
	else if (c == 'c')
		validate_flags_with_sp(fg, "zhp");
	else if (c == 'd')
		validate_flags_with_sp(fg, "h");
	else if (c == 'i')
		validate_flags_with_sp(fg, "h");
	else if (c == 'u')
		validate_flags_with_sp(fg, "hp");
	else if (c == 'x')
		validate_flags_with_sp(fg, "p");
	else if (c == 'X')
		validate_flags_with_sp(fg, "p");
	else if (c == 'p')
		validate_flags_with_sp(fg, "zhp");
}

int	check_flag(char *s, t_fr *tb, va_list arg)
{
	t_flags	*fg;
	int		count;

	fg = create_flags_struct();
	if (!fg)
		return (0);
	if (ft_strchr(FLAGS, *s) || (*s >= '0' && *s <= '9'))
	{
		flag_parser(s, FLAGS, fg);
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
	garbage_collector(fg);
	return (0);
}
