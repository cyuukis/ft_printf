/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_u_fl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:12:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 00:13:13 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		fl_u_o(t_str *str, char *res, int a)
{
	int add;

	add = 0;
	if (str->flags_z == 2 && str->flags_s == -1)
	{
		add += add_width_di('0', a);
		add += write(1, res, ft_strlen(res));
		add += add_width_di(' ', str->width);
		return (add);
	}
	else if (str->flags_z == 2 && str->fl_precision != 1)
	{
		if (str->fl_width != -1)
			add += add_width_di('0', str->width);
		add += write(1, res, ft_strlen(res));
		add += add_width_di(' ', str->precision);
		if (str->fl_width == -1)
			add += add_width_di(' ', str->width);
	}
	return (add);
}

static	int		fl_u_t(t_str *str, char *res, int a)
{
	int add;

	add = 0;
	if (str->fl_width == -1)
	{
		add += add_width_di('0', a);
		add += write(1, res, ft_strlen(res));
		add += add_width_di(' ', str->width);
	}
	else
	{
		add += add_width_di(' ', str->width);
		add += add_width_di('0', a);
		add += write(1, res, ft_strlen(res));
	}
	return (add);
}

static	int		fl_u_th(t_str *str, char *res, int a)
{
	int add;

	add = 0;
	if (str->fl_width != -1)
		add += add_width_di(' ', str->width);
	add += add_width_di('0', a);
	add += write(1, res, ft_strlen(res));
	if (str->fl_width == -1)
		add += add_width_di(' ', str->width);
	return (add);
}

static	int		fl_u_fo(t_str *str, char *res, int a)
{
	int add;

	add = 0;
	if (str->flags_z == 2 && str->fl_precision != 1)
		add += fl_u_o(str, res, a);
	else if (str->flags_z == 2 && str->fl_precision == 1)
		add += fl_u_t(str, res, a);
	else
		add += fl_u_th(str, res, a);
	return (add);
}

int				add_u_fl(t_str *str, char *res, int string)
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
		str->width = str->width - string - a;
	else
		str->width = 0;
	if (str->flags_z == 2 || str->flags_s == 1)
	{
		if (str->flags_z == 2 && str->flags_s == -1)
			return (add += fl_u_o(str, res, a));
		return (add += fl_u_fo(str, res, a));
	}
	else if (str->flags_s == -1)
		add += fl_u_fi(str, res, a);
	return (add);
}
