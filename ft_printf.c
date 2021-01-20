/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/20 00:48:32 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		add_c(t_str *str, char c)
{
	int add;
	char space;

	add = 0;
	if (str->flags == -1 && str->width)
	{
		space = ' ';
		write(1, &c, 1);
		while (add < str->width)
		{
			write(1, &space, 1);
			add++;
		}
	}
	else if (str->flags == 0 && str->width)
	{
		space = '0';
		while (add < str->width)
		{
			write(1, &space, 1);
			add++;
		}
		write(1, &c, 1);
	}
	return (0);
}

static	int		add_s(t_str *str, char *c)
{
	int i;
	int add;
	int a;

	add = 0;
	i = ft_strlen(c);
	if (str->flags == -1 && str->width)
	{
		space = ' ';
		if (str->fl_precision == 1)
		{
			while ((a = str->precision) < 0)
			{
				write(1, c[i], 1);
				a--;
			}
			a = str->width - str->precision;
			if (a > 0)
			{

			}
		}
		while (c[i])
		{
			write(1, c[i], 1);
			i++;
		}
		while (add < str->width)
		{
			write(1, &space, 1);
			add++;
		}
	}
	else if (str->flags == 0 && str->width)
	{
		space = '0';
		while (add < str->width)
		{
			write(1, &space, 1);
			add++;
		}
		write(1, &c, 1);
	}
}

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
		(*format)++;
	}
	///////////////////////////////////////////////// ширина
	if (**format == '*')
	{
		str.width = va_arg(arglist, int);
		(*format)++;
	}
	if (**format >= '0' || **format <= '9')
		str.width = ft_atoi(*format);
	while (**format >= '0' || **format <= '9')
		(*format)++;
	///////////////////////////////////////////////// точность
	if (**format == '.')
	{
		str.fl_precision = 1;
		(*format)++;
		if (**format == '*')
			str.precision = va_arg(arglist, int);
		if (**format >= '0' || **format <= '9')
			str.precision = ft_atoi(*format);
		while (**format >= '0' || **format <= '9')
			(*format)++;
	}
	///////////////////////////////////////////////// типы
	if (**format == 'c')
		return (add_c(&str, va_arg(arglist, int)));
	else if (**format == '%')
		return (add_c(&str, '%'));
	else if (**format == 's')
		return (add_s(&str, arglist));
	else if (**format == 'p')
		return (add_p(&str, arglist));
	else if (**format == 'd' || **format == 'i')
		return (add_di(&str, arglist));
	else if (**format == 'u')
		return (add_u(&str, arglist));
	else if (**format == 'x' || **format == 'X')
		return (add_x(&str, arglist));
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
