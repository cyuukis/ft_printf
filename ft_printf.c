/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 02:04:55 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//int		add_width_di(char c, int width)
//{
//	int add;
//
//	add = 0;
//	while (add < width)
//	{
//		write(1, &c, 1);
//		add++;
//	}
//	return (add);
//}

//static	int	space_di_o(t_str *str, int string, char *res, int minus)
//{
//	int add;
//
//	add = 0;
//	string = str->width - string;
//	if (minus == 1)
//	{
//		res++;
//		string--;
//	}
//	if (minus == 1)
//		add += write(1, "-", 1);
//	add += add_width_di('0', string);
//	add += write(1, res, ft_strlen(res));
//	return (add);
//}
//
//static	int	space_di_tw(t_str *str, int string, char *res, int minus)
//{
//	int add;
//
//	add = 0;
//	string = str->width - string;
//	if (minus == 1)
//		res++;
//	if (minus == 1)
//		add += write(1, "-", 1);
//	add += write(1, res, ft_strlen(res));
//	if (string > 0 && str->fl_precision == 0)
//		add += add_width_di(' ', string);
//	if (str->precision > 0)
//		add += add_width_di(' ', string);
//	return (add);
//}
//
//static	int	space_di_th(t_str *str, int string, char *res, int minus)
//{
//	int add;
//
//	add = 0;
//	string = str->width - string;
//	if (minus == 1)
//	{
//		res++;
//		string--;
//	}
//	if (string > 0)
//		add += add_width_di(' ', string);
//	if (minus == 1)
//		add += write(1, "-", 1);
//	add += write(1, res, ft_strlen(res));
//	return (add);
//}
//
//static	int	space_di_fo(t_str *str, int string, char *res, int minus)
//{
//	int add;
//
//	add = 0;
//	string = str->width - string;
//	if (minus == 1)
//	{
//		res++;
//		string--;
//	}
//	if (minus == 1)
//		add += write(1, "-", 1);
//	add += write(1, res, ft_strlen(res));
//	if (string > 0 && str->fl_precision == 0)
//		add += add_width_di(' ', string);
//	if (str->precision > 0)
//		add += add_width_di(' ', string);
//	return (add);
//}

//static	int	space_di_fi(t_str *str, int string, char *res, int minus)
//{
//	int add;
//
//	add = 0;
//	if (str->width > string)
//		string = str->width - string - minus;
//	if (minus == 1)
//	{
//		write(1, "-", 1);
//		res++;
//		add++;
//	}
//	if (string > 0 && str->precision > -1)
//		add += add_width_di('0', string);
//	add += write(1, res, ft_strlen(res));
//	if (string > 0 && str->width > string)
//		add += add_width_di(' ', string);
//	return (add);
//}
//
//static	int	space_di_six(t_str *str, int string, char *res)
//{
//	int add;
//
//	add = 0;
//	if (str->flags_s == -1)
//	{
//		add += write(1, res, ft_strlen(res));
//		string = str->width - string;
//		if (string > 0)
//			add += add_width_di(' ', string);
//	}
//	else if (str->flags_z == 2 && str->fl_precision != 1)
//	{
//		string = str->width - string;
//		if (string > 0)
//			add += add_width_di('0', string);
//		add += write(1, res, ft_strlen(res));
//	}
//	return (add);
//}

//static	int		add_di_space(t_str *str, int string, char *res, int minus)
//{
//	int add;
//
//	add = 0;
//	if (str->flags_z == 2)
//	{
//		if (str->flags_z == 2 && str->fl_precision == 0 && str->fl_width != -1)
//			return (add += space_di_o(str, string, res, minus));
//		else if (str->fl_width == -1)
//			return (add += space_di_tw(str, string, res, minus));
//	}
//	else if (str->flags_s == 1)
//	{
//		if (str->flags_s == 1 && str->fl_precision == 0 && str->fl_width != -1)
//			return (add += space_di_th(str, string, res, minus));
//		else if (str->fl_width == -1)
//			return (add += space_di_fo(str, string, res, minus));
//	}
//	else if (str->fl_precision >= 0)
//		add += space_di_fi(str, string, res, minus);
//	else if (str->flags_s == -1)
//		add += space_di_six(str, string, res);
//	else if (str->flags_z == 2 && str->fl_precision != 1)
//		add += space_di_six(str, string, res);
//	return (add);
//}

//static	int		fl_di_o(t_str *str, int minus, char *res, int a)
//{
//	int add;
//
//	add = 0;
//	if (str->flags_z == 2 && str->flags_s == -1)
//	{
//		if (minus == 1)
//		{
//			add += write(1, "-", 1);
//			res++;
//		}
//		add += add_width_di('0', a);
//		add += write(1, res, ft_strlen(res));
//		add += add_width_di(' ', str->width);
//		return (add);
//	}
//	return (add);
//}
//
//static	int		fl_di_tw(t_str *str, int minus, char *res)
//{
//	int add;
//
//	add = 0;
//	if (minus == 1)
//	{
//		add += write(1, "-", 1);
//		res++;
//	}
//	if (str->fl_width != -1)
//		add += add_width_di('0', str->width);
//	add += write(1, res, ft_strlen(res));
//	add += add_width_di(' ', str->precision);
//	if (str->fl_width == -1)
//		add += add_width_di(' ', str->width);
//	return (add);
//}
//
//static	int		fl_di_th(t_str *str, int minus, char *res, int a)
//{
//	int add;
//
//	add = 0;
//	if (str->fl_width != -1)
//		add += add_width_di(' ', str->width);
//	if (minus == 1)
//	{
//		add += write(1, "-", 1);
//		res++;
//	}
//	add += add_width_di('0', a);
//	add += write(1, res, ft_strlen(res));
//	if (str->fl_width == -1)
//		add += add_width_di(' ', str->width);
//	return (add);
//
//}
//
//static	int		fl_di_fo(t_str *str, int minus, char *res, int a)
//{
//	int add;
//
//	add = 0;
//	if (minus == 1)
//	{
//		add += write(1, "-", 1);
//		res++;
//	}
//	add += add_width_di('0', a);
//	add += write(1, res, ft_strlen(res));
//	add += add_width_di(' ', str->width);
//	return (add);
//}

//static	int		add_di_fl(t_str *str, int minus, char *res, int string)
//{
//	int add;
//	int a;
//
//	add = 0;
//	a = 0;
//	if (str->precision > string)
//		a = str->precision - string;
//	else
//		str->precision = 0;
//	if (str->width > a + string)
//		str->width = str->width - string - a - minus;
//	else
//		str->width = 0;
//	if (str->flags_z == 2 || str->flags_s == 1)
//	{
//		if (str->flags_z == 2 && str->flags_s == -1)
//			return (add += fl_di_o(str, minus, res, a));
//		else if ((str->flags_z == 2) && str->fl_precision != 1)
//			add += fl_di_tw(str, minus, res);
//		else
//			add += fl_di_th(str, minus, res, a);
//	}
//	else if (str->flags_s == -1)
//		add += fl_di_fo(str, minus, res, a);
//	return (add);
//}

//static	int		add_di_one(t_str *str, int minus, char *res, int string)
//{
//	int add;
//
//	add = 0;
//	if (str->precision > -1)
//		add += add_di_fl(str, minus, res, string);
//	else if (str->fl_precision >= 0 || str->flags_z == 2)
//		add += add_di_space(str, string, res, minus);
//	else if (str->width > 0)
//	{
//		string = str->width - string;
//		if (minus < 0)
//		{
//			add += write(1, "-", 1);
//			res++;
//		}
//		add += write(1, res, ft_strlen(res));
//		if (string > 0)
//			add += add_width_di(' ', string);
//	}
//	return (add);
//}

//static	int		add_di(t_str *str, int di)
//{
//	char	*res;
//	int		a;
//	int		minus;
//	int		add;
//	int		string;
//
//	add = 0;
//	res = ft_itoa(di);
//	a = 0;
//	string = ft_strlen(res);
//	if (di < 0)
//	{
//		string -= 1;
//		minus = 1;
//	}
//	else
//		minus = 0;
//	if (di == 0 && str->fl_precision == 1 && str->precision == 0)
//	{
//		add += add_width_x(' ', str->width);
//		res = ft_strdup("");
//		return (add);
//	}
//	add += add_di_one(str, minus, res, string);
//	free(res);
//	return (add);
//}

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
