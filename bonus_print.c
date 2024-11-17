/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:56:58 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/17 19:54:26 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_printf.h"

void	count_len(void *add, flags *fg)
{
	char	c;

	c = fg->sp_format;
	if (c == 's')
		fg->len_data = ft_strlen((char *)add);
	if (c == 'c')
		fg->len_data = 1;
	if (c == 'd' || c == 'i' || c == 'x' || c == 'u' || c == 'X' || c == 'p')
		fg->len_data = ft_count_len((long) add);
}

int	printer(flags *fg, )

int	print_with_flags(flags *fg, char *s, va_list arg)
{
	va_list	tmp;
	void	*add;
	int		i;

	i = 0;
	va_copy(tmp, arg);
	add = va_arg(tmp, void *);
	count_len(add, fg);
	while (i < 6)
	{

	}
}
