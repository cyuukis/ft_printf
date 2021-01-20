/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/20 23:38:10 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		add_c(t_str *str, char c)
{
	int add;
	char space;

	add = 1;
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
	else
		write(1, &c, 1);
	return (0);
}

static	int		add_s(t_str *str, char *c)
{
	int		i;
	char	space;

	i = ft_strlen(c);
	if (str->flags == -1 && str->width)//принт с -
	{
		if (str->fl_precision == 1 && str->precision > 0)// проверка точки
		{
			write(1, c, str->precision);
		}
		i = str->width - str->precision;
		if (i > 0)
		{
			space = ' ';
			while (i > 0)
			{
				write(1, &space, 1);
				i--;
			}
		}
		str->precision = 0;
	}
	else
	{
		i = str->width - str->precision;
		if (i > 0)
		{
			space = ' ';
			while (i > 0)
			{
				write(1, &space, 1);
				i--;
			}
		}
		if (str->fl_precision == 1 && str->precision > 0)// проверка точки
		{
			write(1, c, str->precision);
		}
		str->precision = 0;
	}
	// if (str->fl_precision == 1)// проверка точки
	// {
	// 	write(1, c, str->precision);
	// }
	return (0);
}

static	int		add_di(t_str *str, int di)
{

}

static	int		my_parses(va_list arglist, const char **format)
{
	t_str str;

	while (**format == '-' || **format == '0') // флаг
	{
		if (**format == '-')
			str.flags = -1;
		else
		{
			str.flags = 0;
			//printf("0");
		}
		(*format)++;
	}
	///////////////////////////////////////////////// ширина
	if (**format == '*')
	{
		str.width = va_arg(arglist, int);
		(*format)++;
	}
	if (**format >= '0' && **format <= '9')
	{
		str.width = ft_atoi(*format);
		(*format)++;
	}
	else
		str.width = 0;
	while (**format >= '0' && **format <= '9')
		(*format)++;
	///////////////////////////////////////////////// точность
	if (**format == '.')
	{
		str.fl_precision = 1;
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			str.precision = va_arg(arglist, int);
		}
		if (**format >= '0' && **format <= '9')
		{
			str.precision = ft_atoi(*format);
			(*format)++;
		}
		else
			str.precision = 0;
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	else
		str.precision = 0;
	///////////////////////////////////////////////// типы
	if (**format == 'c')
		return (add_c(&str, va_arg(arglist, int)));
	else if (**format == '%')
		return (add_c(&str, '%'));
	else if (**format == 's')
		return (add_s(&str, va_arg(arglist, char *)));
	else if (**format == 'd' || **format == 'i')
		return (add_di(&str, va_arg(arglist, int)));
	/*else if (**format == 'p')
		return (add_p(&str, va_arg(arglist, unsigned int)));
	else if (**format == 'u')
		return (add_u(&str, va_arg(arglist, unsigned int)));
	else if (**format == 'x' || **format == 'X')
		return (add_x(&str, va_arg(arglist, unsigned int)));*/
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
		//printf("1");
		if (*format == '%')
		{
			//printf("1");
			++format;
			my_parses(arglist, &format);
			format++;
		}
		else
			i = i + write(1, format++, 1);
	}
	va_end(arglist);
	return (i);
}
