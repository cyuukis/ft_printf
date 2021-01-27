/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_u_fi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:13:42 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 00:14:01 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fl_u_fi(t_str *str, char *res, int a)
{
	int add;

	add = 0;
	add += add_width_di('0', a);
	add += write(1, res, ft_strlen(res));
	add += add_width_di(' ', str->width);
	return (add);
}
