/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_x_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:32 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/27 14:42:36 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		add_x_write(int a, t_str *str, unsigned int num, const char **format, int string)
{
	int add;

	add = 0;
	if (str->flags_z == 2 && str->flags_s == -1)
	{
			add += add_width_x('0', a);
		//add += add_x_hex(str, num, format);
		(string != 0 ? add += add_x_hex(str, num, format) : 0);
		add += add_width_x(' ', str->width);
		return (add);
	}
	else
	{
		if (str->fl_width != -1)
			add += add_width_x(' ', str->width);
		add += add_width_x('0', a);
		//add += add_x_hex(str, num, format);
		(string != 0 ? add += add_x_hex(str, num, format) : 0);
		if (str->fl_width == -1)
			add += add_width_x(' ', str->width);
		return (add);
	}
	return (add);
}

static	int		add_flag_s(int a, t_str *str, unsigned int num, const char **format, int string)
{
	int add;

	add = 0;
	add += add_width_x('0', a);
	//add += add_x_hex(str, num, format);
	(string != 0 ? add += add_x_hex(str, num, format) : 0);
	add += add_width_x(' ', str->width);
	return (add);
}

int		add_x_precision(t_str *str, unsigned int num, const char **format)
{
	int	a;
	int	add;
	int string;

	string = 0;
	add = 0;
	a = 0;
	string += add_x_str(num);
	if (num == 0 && str->fl_precision == 1 && str->precision == 0)
		add += add_width_x(' ', str->width);
	else if (str->precision > -1 || str->precision < 0)
	{
		if (str->precision > string)
			a = str->precision - string;
		else
			str->precision = 0;
		if (str->width > (a + string))
			str->width = str->width - string - a;
		else
			str->width = 0;
		if (str->flags_s == 1 || str->flags_z == 2)
			add += add_x_write(a, str, num, format, string);
		else if (str->flags_s == -1)
			add += add_flag_s(a, str, num, format, string);
	}
	return (add);
}
