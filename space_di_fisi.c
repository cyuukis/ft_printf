/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_di_fisi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:25:17 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 15:25:18 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_width_di(char c, int width)
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

int		space_di_fi(t_str *str, int string, char *res, int minus)
{
	int add;

	add = 0;
	if (str->width > string)
		string = str->width - string - minus;
	if (minus == 1)
	{
		write(1, "-", 1);
		res++;
		add++;
	}
	if (string > 0 && str->precision > -1)
		add += add_width_di('0', string);
	add += write(1, res, ft_strlen(res));
	if (string > 0 && str->width > string)
		add += add_width_di(' ', string);
	return (add);
}

int		space_di_six(t_str *str, int string, char *res)
{
	int add;

	add = 0;
	if (str->flags_s == -1)
	{
		add += write(1, res, ft_strlen(res));
		string = str->width - string;
		if (string > 0)
			add += add_width_di(' ', string);
	}
	else if (str->flags_z == 2 && str->fl_precision != 1)
	{
		string = str->width - string;
		if (string > 0)
			add += add_width_di('0', string);
		add += write(1, res, ft_strlen(res));
	}
	return (add);
}
