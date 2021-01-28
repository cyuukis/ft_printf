/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:22:50 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 15:36:00 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				add_x_hex(t_str *str, unsigned int num, const char **format)
{
	long	a;
	int		add;

	add = 0;
	if (num >= 16)
		add += add_x_hex(str, num / 16, format);
	a = num % 16;
	add += add_x_registr(a, format);
	return (add);
}

int				add_width_x(char c, int width)
{
	int add;

	add = 0;
	while (add < width)
	{
		write(1, &c, 1);
		add++;
	}
	return (add);
}

int				add_x_str(unsigned int num)
{
	int string;

	string = 0;
	while (num >= 16)
	{
		num /= 16;
		string++;
	}
	string++;
	return (string);
}

static	int		add_x_null(t_str *str, unsigned int num, const char **format)
{
	int add;
	int string;

	string = 0;
	add = 0;
	string += add_x_str(num);
	if (str->width > string)
		str->width = str->width - string;
	else
		str->width = 0;
	if (str->fl_width == -1)
	{
		add += add_x_hex(str, num, format);
		add += add_width_x(' ', str->width);
	}
	if (str->fl_width != -1)
	{
		add += add_width_x('0', str->width);
		add += add_x_hex(str, num, format);
	}
	return (add);
}

int				add_x(t_str *str, unsigned int num, const char **format)
{
	int	add;

	add = 0;
	if (str->flags_z == 2 && str->fl_precision == 0)
		add += add_x_null(str, num, format);
	else
		add += add_x_precision(str, num, format);
	return (add);
}
