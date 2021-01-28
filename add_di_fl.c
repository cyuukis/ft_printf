/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_di_fl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:34:36 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 15:35:00 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		fl_di_o(t_str *str, int minus, char *res, int a)
{
	int add;

	add = 0;
	if (str->flags_z == 2 && str->flags_s == -1)
	{
		if (minus == 1)
		{
			add += write(1, "-", 1);
			res++;
		}
		add += add_width_di('0', a);
		add += write(1, res, ft_strlen(res));
		add += add_width_di(' ', str->width);
		return (add);
	}
	return (add);
}

static	int		fl_di_tw(t_str *str, int minus, char *res)
{
	int add;

	add = 0;
	if (minus == 1)
	{
		add += write(1, "-", 1);
		res++;
	}
	if (str->fl_width != -1)
		add += add_width_di('0', str->width);
	add += write(1, res, ft_strlen(res));
	add += add_width_di(' ', str->precision);
	if (str->fl_width == -1)
		add += add_width_di(' ', str->width);
	return (add);
}

static	int		fl_di_th(t_str *str, int minus, char *res, int a)
{
	int add;

	add = 0;
	if (str->fl_width != -1)
		add += add_width_di(' ', str->width);
	if (minus == 1)
	{
		add += write(1, "-", 1);
		res++;
	}
	add += add_width_di('0', a);
	add += write(1, res, ft_strlen(res));
	if (str->fl_width == -1)
		add += add_width_di(' ', str->width);
	return (add);
}

static	int		fl_di_fo(t_str *str, int minus, char *res, int a)
{
	int add;

	add = 0;
	if (minus == 1)
	{
		add += write(1, "-", 1);
		res++;
	}
	add += add_width_di('0', a);
	add += write(1, res, ft_strlen(res));
	add += add_width_di(' ', str->width);
	return (add);
}

int				add_di_fl(t_str *str, int minus, char *res, int string)
{
	int add;
	int a;

	add = 0;
	a = 0;
	if (str->precision > string)
		a = str->precision - string;
	else
		str->precision = 0;
	if (str->width > a + string)
		str->width = str->width - string - a - minus;
	else
		str->width = 0;
	if (str->flags_z == 2 || str->flags_s == 1)
	{
		if (str->flags_z == 2 && str->flags_s == -1)
			return (add += fl_di_o(str, minus, res, a));
		else if ((str->flags_z == 2) && str->fl_precision != 1)
			add += fl_di_tw(str, minus, res);
		else
			add += fl_di_th(str, minus, res, a);
	}
	else if (str->flags_s == -1)
		add += fl_di_fo(str, minus, res, a);
	return (add);
}
