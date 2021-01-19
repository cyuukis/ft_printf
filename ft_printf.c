/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/19 22:30:43 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		my_parses(va_list arglist, const char **format)
{
	t_str str;

	while (**format == '-' || **format == '0') // флаг
	{
		if (**format == '-')
			str.flags = -1;
		else
		{
			str.flags = 0;
			printf("0");
		}
		format++;
	}
	///////////////////////////////////////////////// ширина
	if (**format == '*')
	{
		str.width = va_arg(arglist, int);
		format++;
	}
	if (**format >= '0' || **format <= '9')
		str.width = ft_atoi(*format);
	while (**format >= '0' || **format <= '9')
		format++;
	///////////////////////////////////////////////// точность
	if (**format == '.')
	{
		str.fl_precision = 1;
		format++;
		if (**format == '*')
		{
			str.precision = va_arg(arglist, int);
		}
		if (**format >= '0' || **format <= '9')
			str.precision = ft_atoi(*format);
		while (**format >= '0' || **format <= '9')
			format++;
	}
	///////////////////////////////////////////////// типы

	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list		arglist;
	int			i;

	i = 0;
	if (format == NULL)
		return (-1);
	va_start(arglist, format);
	while (*format)
	{
		if (*format == '%')
		{
			//printf("1");
			(++format);
			my_parses(arglist, &format);
		}
		else
			i += write(1, format++, 1);
		i++;
	}
	va_end(arglist);
	return (i);
}
