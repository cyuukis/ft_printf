/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_u_fs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:56:14 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 15:32:53 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_u_five(t_str *str, char *res, unsigned int n)
{
	int add;

	add = 0;
	if (n == 0 && str->fl_precision == 1 && str->precision == 0)
	{
		add += add_width_x(' ', str->width);
		res = ft_strdup("");
	}
	free(res);
	return (add);
}

int		add_u_six(t_str *str, int string, char *res)
{
	int add;

	add = 0;
	if (str->width > 0)
	{
		string = str->width - string;
		add += write(1, res, ft_strlen(res));
		if (string > 0)
			add += add_width_di(' ', string);
	}
	return (add);
}
