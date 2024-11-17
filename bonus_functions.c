/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:07:07 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/17 15:48:30 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bonus_printf.h"

flags	*create_flags_struct()
{
	flags	*ptr;

	ptr = ft_calloc(1, sizeof(flags));
	if (!ptr)
		return (NULL);
	ptr->perc = NULL;
	return (ptr);
}

dot	*create_precision()
{
	dot	*ptr;

	ptr = ft_calloc(1, sizeof(dot));
	if (!ptr)
		return (NULL);
	return (ptr);
}
