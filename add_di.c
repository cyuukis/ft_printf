/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:21:47 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 19:50:12 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				add_di_one(t_str *str, int minus, char *res, int string)
{
	int add;

	add = 0;
	if (str->precision > -1)
		add += add_di_fl(str, minus, res, string);
	else if (str->fl_precision >= 0 || str->flags_z == 2)
		add += add_di_space(str, string, res, minus);
	else if (str->width > 0)
	{
		string = str->width - string;
		if (minus < 0)
		{
			add += write(1, "-", 1);
			res++;
		}
		add += write(1, res, ft_strlen(res));
		if (string > 0)
			add += add_width_di(' ', string);
	}
	return (add);
}

static	int		add_di_minus(int minus, int di)
{
	if (di < 0)
		minus = 1;
	else
		minus = 0;
	return (minus);
}

int				add_di(t_str *str, int di)
{
	char	*res;
	int		minus;
	int		add;
	int		string;
	char	*tmp;

	add = 0;
	minus = 0;
	res = ft_itoa(di);
	tmp = res;
	string = ft_strlen(res);
	minus = add_di_minus(minus, di);
	if (minus == 1)
		string -= 1;
	if (di == 0 && str->fl_precision == 1 && str->precision == 0)
	{
		free(tmp);
		add += add_width_x(' ', str->width);
		res = ft_strdup("");
		free(res);
		return (add);
	}
	add += add_di_one(str, minus, res, string);
	free(res);
	return (add);
}
