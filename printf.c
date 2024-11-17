/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:45:38 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/16 17:53:53 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	gen_index_key(char c, fr *frm)
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

char	*set_of_flags(char *s, char *flags, a_fr *holder)
{
	char	*str;
	int	len;

	len = 0;
	while (s[len] && ft_strchr(flags, s[len]))
		len++;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (len > 1)
	{
		holder->combined = 1;
		holder->nflags = len;
	}
	len = 0;
	while (s[len] && ft_strchr(flags, s[len]))
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

a_fr	*is_after_flag_valid(char *s, char *frmt)
{
	int	i;
	a_fr	*ptr;

	ptr = ft_calloc(1, sizeof(a_fr));
	if (!ptr)
		return (NULL);
	i = 1;
	if (s[i])
	{
		ptr->n = ft_atoi(&s[i]);
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (ft_strchr(frmt, s[i]))
			ptr->sp_format = s[i];
		else
		{
			free(ptr);
			return (NULL);
		}
		ptr->index = i;
		ptr->sp_flag = set_of_flags(s, "-0.# +", ptr);
	}
	return (ptr);
}

int	call_flag_funcs(a_fr *data, fr *tb, va_list arg)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (data->sp_flag[i])
	{
		if (data->sp_flag[i] == '-')
		{
			count += tb[gen_index_key(data->sp_format, tb)].f(arg);
			count += print_flags(data->n - count, ' ');
		}
		else if (data->sp_flag[i] == '#')
		{

		}
		i++;
	}
	return (count);
}

a_fr	*flags_parser(char *s, fr *tb, char *frmt, va_list arg)
{
	a_fr	*flag_holder;
	int	count;

	count = 0;
	flag_holder = is_after_flag_valid(s, frmt);
	if (!flag_holder)
		return (NULL);
	count += call_flag_funcs(flag_holder, tb, arg);
	flag_holder->count = count;
	free(flag_holder->sp_flag);
	return (flag_holder);
}

int	check_format(char *frmt, char c, fr *tb, va_list arg)
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

a_fr	*check_flags(char *frmt, char *flags, char *s, fr *tb, va_list arg)
{
	if (ft_strchr(flags, *s))
	{
		return (flags_parser(s, tb, frmt, arg));
	}
	return (NULL);
}

int	checker(const char *s, va_list args, fr *tb)
{
	int	i;
	a_fr	*holder;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[++i] )
		{
			count += check_format("csdiupxX%", s[i], tb, args);
			holder = check_flags("csdiupxX%", "-0.# +", (char *) &s[i], tb, args);
			if (holder)
			{
				count += holder->count;	
				i += holder->index;
				free(holder);
			}
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
	int		i;
	va_list	arg;
	fr	*frm;

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
