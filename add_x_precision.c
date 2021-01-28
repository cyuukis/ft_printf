/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_x_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:32 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 16:46:43 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	add_x_write(int a, t_str *s, unsigned int n, const char **fo)
{
	int	add;
	int	string;

	string = 0;
	add = 0;
	string += add_x_str(n);
	if (s->flags_z == 2 && s->flags_s == -1)
	{
		add += add_width_x('0', a);
		(string != 0 ? add += add_x_hex(s, n, fo) : 0);
		add += add_width_x(' ', s->width);
		return (add);
	}
	else
	{
		if (s->fl_width != -1)
			add += add_width_x(' ', s->width);
		add += add_width_x('0', a);
		(string != 0 ? add += add_x_hex(s, n, fo) : 0);
		if (s->fl_width == -1)
			add += add_width_x(' ', s->width);
		return (add);
	}
	return (add);
}

static	int	add_flag_s(int a, t_str *s, unsigned int n, const char **fo)
{
	int add;
	int	string;

	string = 0;
	add = 0;
	string += add_x_str(n);
	add += add_width_x('0', a);
	(string != 0 ? add += add_x_hex(s, n, fo) : 0);
	add += add_width_x(' ', s->width);
	return (add);
}

static	int	add_flag_one(int a, t_str *s, unsigned int n, const char **fo)
{
	int add;
	int string;

	add = 0;
	string = 0;
	string += add_x_str(n);
	if (s->precision > string)
		a = s->precision - string;
	else
		s->precision = 0;
	if (s->width > (a + string))
		s->width = s->width - string - a;
	else
		s->width = 0;
	if (s->flags_s == 1 || s->flags_z == 2)
		add += add_x_write(a, s, n, fo);
	else if (s->flags_s == -1)
		add += add_flag_s(a, s, n, fo);
	return (add);
}

int			add_x_precision(t_str *str, unsigned int num, const char **format)
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
		add += add_flag_one(a, str, num, format);
	return (add);
}
