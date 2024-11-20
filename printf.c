/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:45:38 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 23:11:27 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

int	gen_index_key(char c, t_fr *frm)
{
	int	i;

	i = 0;
	while (frm[i].f)
	{
		if (frm[i].sep == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_format(char *frmt, char c, t_fr *tb, va_list arg)
{
	int	count;
	int	index;

	count = 0;
	if (ft_strchr(frmt, c))
	{
		index = gen_index_key(c, tb);
		if (index == -1)
			return (0);
		count += tb[index].f(arg);
	}
	return (count);
}

int	checker(const char *s, va_list args, t_fr *tb)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[++i])
		{
			count += check_format(FORMAT, s[i], tb, args);
			count += check_flag((char *) &s[i], tb, args);
			i += tb->index;
		}
		else if (s[i])
			count += write(1, &s[i], 1);
		else
			break ;
		i++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	t_fr	*frm;
	int		i;

	i = 0;
	if (!s)
		return (0);
	frm = create_array(12);
	if (!frm)
		return (-1);
	va_start(arg, s);
	fill_map(frm);
	i = checker(s, arg, frm);
	free(frm);
	va_end(arg);
	return (i);
}
