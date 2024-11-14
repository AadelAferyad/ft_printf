/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:45:38 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/14 17:21:55 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checker(const char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (ft_strchr("csdiupxX%", s[i]))
			{

			}
		}
		i++;
	}
}

int ft_printf(const char *s, ...)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	checker(s);
}
