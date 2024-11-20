/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:07:07 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/20 23:06:58 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bonus_printf.h"

t_flags	*create_flags_struct(void)
{
	t_flags	*ptr;

	ptr = ft_calloc(1, sizeof(t_flags));
	if (!ptr)
		return (NULL);
	ptr->perc = NULL;
	return (ptr);
}

t_dot	*create_precision(void)
{
	t_dot	*ptr;

	ptr = ft_calloc(1, sizeof(t_dot));
	if (!ptr)
		return (NULL);
	return (ptr);
}

int	set_flag_to_struct(char c, t_flags *fg)
{
	if (c == '-')
		fg->minus = ON;
	else if (c == '0')
		fg->zero = ON;
	else if (c == '#')
		fg->hashtag = ON;
	else if (c == ' ')
		fg->space = ON;
	else if (c == '+')
		fg->plus = ON;
	else
		return (0);
	return (1);
}
