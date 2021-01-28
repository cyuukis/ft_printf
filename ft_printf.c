/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 16:33:56 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		my_parses_flag(t_str *str, const char **format)
{
	int add;

	add = 0;
	while (**format == '-' || **format == '0')
	{
		if (**format == '0')
			str->flags_z = 2;
		else
			str->flags_s = -1;
		(*format)++;
	}
	if (str->flags_s != -1 && str->flags_z != 2)
		str->flags_s = 1;
	while ((**format >= '\t' && **format <= '\r') || **format == ' ')
	{
		add += write(1, " ", 1);
		(*format)++;
	}
	return (add);
}

static	void	my_parses_width(t_str *s, const char **form, va_list arg)
{
	if (**form == '*')
	{
		s->width = va_arg(arg, int);
		(*form)++;
	}
	if (**form >= '0' && **form <= '9')
	{
		s->width = ft_atoi(*form);
		(*form)++;
	}
	if (s->width < 0)
	{
		s->width *= -1;
		s->fl_width = -1;
	}
	while (**form >= '0' && **form <= '9')
		(*form)++;
}

static	void	my_parses_precision(t_str *s, const char **form, va_list arg)
{
	if (**form == '.')
	{
		s->fl_precision = 1;
		(*form)++;
		if (**form == '*')
		{
			(*form)++;
			s->precision = va_arg(arg, int);
		}
		if (**form >= '0' && **form <= '9')
		{
			s->precision = ft_atoi(*form);
			(*form)++;
		}
		if (s->precision < 0)
			s->fl_precision = 0;
		while (**form >= '0' && **form <= '9')
			(*form)++;
	}
	else
	{
		s->fl_precision = 0;
		s->precision = 0;
	}
}

static	int		my_parses(va_list arglist, const char **format)
{
	t_str	str;
	int		add;

	add = 0;
	if (**format == '\0')
		return (0);
	ft_memset(&str, 0, sizeof(str));
	add += my_parses_flag(&str, format);
	my_parses_width(&str, format, arglist);
	my_parses_precision(&str, format, arglist);
	if (**format == 'c')
		return (add + add_c(&str, va_arg(arglist, int)));
	else if (**format == '%')
		return (add + add_c(&str, '%'));
	else if (**format == 's')
		return (add + add_s(&str, va_arg(arglist, char *)));
	else if (**format == 'd' || **format == 'i')
		return (add + add_di(&str, va_arg(arglist, int)));
	else if (**format == 'p')
		return (add + add_p(&str, (unsigned long)va_arg(arglist, void *)));
	else if (**format == 'u')
		return (add + add_u(&str, va_arg(arglist, unsigned int)));
	else if (**format == 'x' || **format == 'X')
		return (add + add_x(&str, va_arg(arglist, unsigned int), format));
	return (add);
}

int				ft_printf(const char *format, ...)
{
	va_list		arglist;
	int			i;
	int			add;

	i = 0;
	add = 0;
	if (format == NULL)
		return (-1);
	va_start(arglist, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			add += my_parses(arglist, &format);
			if (*format)
				format++;
		}
		else
			i = i + write(1, format++, 1);
	}
	va_end(arglist);
	return (i + add);
}
