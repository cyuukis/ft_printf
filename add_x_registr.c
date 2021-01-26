/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_x_registr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:19:36 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/26 19:19:38 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_x_registr(long a, const char **format)
{
	int		add;
	char	hex;

	add = 0;
	if (a >= 10 && a <= 15)
	{
		if (**format == 'x')
		{
			hex = (char)a + 87;
			add += write(1, &hex, 1);
		}
		else if (**format == 'X')
		{
			hex = (char)a + 55;
			add += write(1, &hex, 1);
		}
	}
	else if (a <= 9)
	{
		hex = (char)a + 48;
		add += write(1, &hex, 1);
	}
	return (add);
}
