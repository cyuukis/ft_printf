/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:17:38 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/27 22:26:06 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			add_width_c(char c, int width)
{
	int add;

	add = 1;
	while (add < width)
	{
		write(1, &c, 1);
		add++;
	}
	add--;
	return (add);
}

int			add_c(t_str *str, char c)
{
	int i;
	int add;

	add = 0;
	i = 0;
	if ((str->flags_s == -1 || str->flags_s == 1) && str->width >= 0)
	{
		if (str->flags_s == -1)
		{
			add += write(1, &c, 1);
			i = add_width_c(' ', str->width);
			return (i + add);
		}
		else if (str->flags_s == 1)
		{
			if (str->fl_width != -1)
				i = add_width_c(' ', str->width);
			add += write(1, &c, 1);
			if (str->fl_width == -1)
				i = add_width_c(' ', str->width);
			return (add + i);
		}
	}
	if (str->flags_z == 2 && str->width >= 0)
	{
		if (str->fl_width == -1)
			add += write(1, &c, 1);
		if (str->fl_width == -1)
			i = add_width_c(' ', str->width);
		if (str->fl_width != -1)
			i = add_width_c('0', str->width);
		if (str->fl_width != -1)
			add += write(1, &c, 1);
		return (add + i);
	}
	else
		i += write(1, &c, 1);
	return (i);
}
