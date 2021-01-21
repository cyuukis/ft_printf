/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/21 23:16:46 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int		add_c(t_str *str, char c)
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
		else
		{
			write(1, c, ft_strlen(c));
			i = str->width - i;
			if (i > 0)
			{
				space = ' ';
				while (i > 0)
				{
					write(1, &space, 1);
					i--;
				}
			}
		}
		/*i = str->width - str->precision;
		if (i > 0)
		{
			space = ' ';
			while (i > 0)
			{
				write(1, &space, 1);
				i--;
			}
		}*/
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
		else
			write(1, c, ft_strlen(c));

		str->precision = 0;
	}
	return (0);
}

static	int		add_di(t_str *str, int di)
{
	char	*res;
	int		i;
	int		a;
	char	space;
	int		w;

	space = ' ';
	i = 0;
	res = ft_itoa(di);
	a = ft_strlen(res);
	if (str->width == 0 && str->precision == 0)
		i += write(1, res, ft_strlen(res));
	else if ((str->flags == 1 || str->flags == 0))
	{
		if (str->flags == 1)
		{
			if (str->precision)
			{
				a = str->precision - a;
				while (a > 0)
				{
					write(1, "0", 1);
					a--;
				}
				write(1, res, ft_strlen(res));
			}
			if (str->width)
			{
				a = str->width - a;
				while (a > 0)
				{
					write(1, " ", 1);
					a--;
				}
				write(1, res, ft_strlen(res));
			}
		}
		if (str->flags == 0 && str->fl_precision == 1)
		{
			space = ' ';
			if (str->precision)
			{
				w = str->width - str->precision;
				if (w > 0)
				{
					while (w > 0)
					{
						write(1, &space, 1);
						w--;
					}
					a = str->precision - a;
					while (a != 0)
					{
						write(1, "0", 1);
						a--;
					}
					w++;
					write(1, res, ft_strlen(res));
				}
				if (w <= 0)
				{
					if (di > 0)
					{
						w = str->precision - a;
						while (w != 0)
						{
							write(1, "0", 1);
							w--;
						}
						write(1, res, ft_strlen(res));
					}
					else
					{
						a--;
						write(1, res, 1);
						res++;
						w = str->precision - a;
						while (w != 0)
						{
							write(1, "0", 1);
							w--;
						}
						write(1, res, ft_strlen(res));
					}
				}
			}
			else if (!str->precision)
			{
				while (a > 0)
				{
					write(1, &space, 1);
					a--;
				}
				write(1, res, ft_strlen(res));
			}
		}
		else if (str->flags == 0 && str->fl_precision != 1)
		{
			a = str->width - a;
			space = '0';
			if (di < 0)
			{
				write(1, res, 1);
				res++;
			}
			while (a > 0)
			{
				write(1, &space, 1);
				a--;
			}
			write(1, res, ft_strlen(res));
		}
	}
	else if (str->width && str->flags == -1)
	{
		if (str->fl_precision == 1 && str->precision)
		{
			if (di < 0)
			{
				write(1, res, 1);
				res++;
			}
			a = str->precision - a;
			while (a > 0)
			{
				space = '0';
				write(1, &space, 1);
				a--;
			}
			write(1, res, ft_strlen(res));
			w = str->width - str->precision;
			while(w != 0)
			{
				write(1, " ", 1);
				w--;
			}
		}
		else if (str->fl_precision == 1 && !str->precision)
		{
			if (di < 0)
			{
				write(1, res, 1);
				res++;
			}
			write(1, res, ft_strlen(res));
			a = str->width - a;
			while (a > 0)
			{
				space = ' ';
				write(1, &space, 1);
				a--;
			}
		}
		else if (str->fl_precision != 1)
		{
			write(1, res, ft_strlen(res));
			if (di < 0)
			{
				write(1, res, 1);
				res++;
			}
			a = str->width - a;
			while (a > 0)
			{
				space = ' ';
				write(1, &space, 1);
				a--;
			}
		}
	}
	return (i);
}

static	void	my_parses_flag(t_str *str, const char **format)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			str->flags = -1;
		else
			str->flags = 0;
		(*format)++;
	}
	if (str->flags != -1 && str->flags != 0)
		str->flags = 1;
}

static	void	my_parses_width(t_str *str, const char **format, va_list arglist)
{
	if (**format == '*')
	{
		str->width = va_arg(arglist, int);
		(*format)++;
	}
	if (**format >= '0' && **format <= '9')
	{
		str->width = ft_atoi(*format);
		(*format)++;
	}
	else
		str->width = 0;
	while (**format >= '0' && **format <= '9')
		(*format)++;
}

static	void	my_parses_precision(t_str *str, const char **format, va_list arglist)
{
	if (**format == '.')
	{
		str->fl_precision = 1;
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			str->precision = va_arg(arglist, int);
		}
		if (**format >= '0' && **format <= '9')
		{
			str->precision = ft_atoi(*format);
			(*format)++;
		}
		else
			str->precision = 0;
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	else
		str->precision = 0;
}

static	int		my_parses(va_list arglist, const char **format)
{
	t_str str;

	///////////////////////////////////////////////// флаг
	my_parses_flag(&str, format);
	///////////////////////////////////////////////// ширина
	my_parses_width(&str, format, arglist);
	///////////////////////////////////////////////// точность
	my_parses_precision(&str, format, arglist);
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
		if (*format == '%')
		{
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
