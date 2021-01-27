/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:13:44 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/27 22:20:17 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		add_p_hex(t_str *str, unsigned long num)
{
	long	a;
	int		add;

	add = 0;
	if (num >= 16)
		add += add_p_hex(str, num / 16);
	a = num % 16;
	add += add_p_registr(a);
	return (add);
}

static	int		add_p_str(unsigned long num)
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

static	int		add_point_one(t_str *str)
{
	int add;

	add = 0;
	if (str->width > 0 && str->flags_s == -1)
	{
		add += write(1, "0x", 2);
		add += add_width_di(' ', str->width - 2);
	}
	else
	{
		add += add_width_di(' ', str->width - 2);
		add += write(1, "0x", 2);
	}
	return (add);
}

static	int		add_point_two(t_str *str, int string, unsigned long pointer)
{
	int	add;

	add = 0;
	if (str->precision > string)
		str->precision = str->precision - string;
	else
		str->precision = 0;
	str->width = str->width - (string + 2);
	if (str->fl_width == -1)
	{
		add += write(1, "0x", 2);
		add += add_width_di('0', str->precision);
		add += add_p_hex(str, pointer);
		add += add_width_di(' ', str->width);
	}
	else
	{
		add += add_width_di(' ', str->width);
		add += write(1, "0x", 2);
		add += add_width_di('0', str->precision);
		add += add_p_hex(str, pointer);
	}
	return (add);
}

int		add_p(t_str *str, unsigned long pointer)
{
	int add;
	int string;

	string = 0;
	string += add_p_str(pointer);
	add = 0;
	if (pointer == 0 && str->fl_precision == 1 && str->precision == 0)
		return (add += add_point_one(str));
	else if (str->flags_s == -1 || str->flags_z == 2)
	{
		str->width = str->width - (string + 2);
		add += write(1, "0x", 2);
		add += add_p_hex(str, pointer);
		if (str->flags_s == -1)
			add += add_width_di(' ', str->width);
		else if (str->flags_z == 2)
			add += add_width_di('0', str->width);
	}
	else if (str->flags_s == 1)
		add += add_point_two(str, string, pointer);
	return (add);
}
