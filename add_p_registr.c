/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_p_registr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:14:50 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/27 22:15:00 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_p_registr(unsigned long a)
{
	int		add;
	char	hex;

	add = 0;
	if (a >= 10 && a <= 15)
	{
		hex = (char)a + 87;
		add += write(1, &hex, 1);
	}
	else if (a <= 9)
	{
		hex = (char)a + 48;
		add += write(1, &hex, 1);
	}
	return (add);
}
