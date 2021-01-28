/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:53:35 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 19:33:25 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		add_u_one(t_str *str, int string, char *res)
{
	int add;

	add = 0;
	if (str->flags_z == 2 && str->fl_precision == 0 && str->fl_width != -1)
	{
		string = str->width - string;
		add += add_width_di('0', string);
		add += write(1, res, ft_strlen(res));
	}
	else if (str->fl_width == -1)
	{
		string = str->width - string;
		add += write(1, res, ft_strlen(res));
		if (string > 0 && str->fl_precision == 0)
			add += add_width_di(' ', string);
		if (str->precision > 0)
			add += add_width_di(' ', string);
	}
	return (add);
}

static	int		add_u_two(t_str *str, int string, char *res)
{
	int add;

	add = 0;
	if (str->flags_s == 1 && str->fl_precision == 0 && str->fl_width != -1)
	{
		string = str->width - string;
		if (string > 0)
			add += add_width_di(' ', string);
		add += write(1, res, ft_strlen(res));
	}
	else if (str->fl_width == -1)
	{
		string = str->width - string;
		add += write(1, res, ft_strlen(res));
		if (string > 0 && str->fl_precision == 0)
			add += add_width_di(' ', string);
		if (str->precision > 0)
			add += add_width_di(' ', string);
	}
	return (add);
}

static	int		add_u_three(t_str *str, int string, char *res)
{
	int add;

	add = 0;
	if (str->fl_precision >= 0)
	{
		if (str->width > string)
			string = str->width - string;
		if (string > 0 && str->precision > -1)
			add += add_width_di('0', string);
		add += write(1, res, ft_strlen(res));
	}
	else if (str->flags_z == 2 && str->fl_precision != 1)
	{
		string = str->width - string;
		if (string > 0 && str->precision > -1)
			add += add_width_di('0', string);
		add += write(1, res, ft_strlen(res));
	}
	return (add);
}

static	int		add_u_four(t_str *str, int string, char *res)
{
	int add;

	add = 0;
	if (str->flags_s == -1)
	{
		if (str->precision > string)
			str->precision = str->precision - string;
		else
			str->precision = 0;
		add += write(1, res, ft_strlen(res));
		string = str->width - string;
		if (string > 0 && str->precision > -1)
			add += add_width_di(' ', string);
	}
	else if (str->fl_precision >= 0)
		add += add_u_three(str, string, res);
	else if (str->flags_z == 2 && str->fl_precision != 1)
		add += add_u_three(str, string, res);
	return (add);
}

int				add_u(t_str *str, unsigned int num)
{
	int		add;
	long	string;
	char	*res;

	add = 0;
	string = 0;
	res = ft_itoa(num);
	string += ft_strlen(res);
	if (num == 0 && str->fl_precision == 1 && str->precision == 0)
		return (add += add_u_five(str, res, num));
	if (str->precision > -1)
		add += add_u_fl(str, res, string);
	else if (str->fl_precision >= 0 || str->flags_s == -1 || str->flags_z == 2)
	{
		if (str->flags_z == 2)
			return (add += add_u_one(str, string, res));
		else if (str->flags_s == 1)
			return (add += add_u_two(str, string, res));
		add += add_u_four(str, string, res);
	}
	else if (str->width > 0)
		add += add_u_six(str, string, res);
	free(res);
	return (add);
}
