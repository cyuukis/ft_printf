/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/24 19:37:49 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int add_width_c(char c, int width)
{
	int add;

	add = 1;
	while (add < width)
	{
		write(1, &c, 1);
		add++;
	}
	add--;
	return (add);
}

static	int		add_c(t_str *str, char c)
{
	int i;
	int add;

	add = 0;
	i = 0;
	if ((str->flags == -1 || str->flags == 1) && str->width >= 0)
	{
		if (str->flags == -1)
		{
			add += write(1, &c, 1);
			i = add_width_c(' ', str->width);
			/*while (add < str->width)
			{
				write(1, &space, 1);
				add++;
			}*/
			return (i + add);
		}
		else if (str->flags == 1)
		{
			i = add_width_c(' ', str->width);
			/*while (add < str->width)
			{
				write(1, &space, 1);
				add++;
			}*/
			add += write(1, &c, 1);
			return (add + i);
		}
	}
	if (str->flags == 0 && str->width >= 0)
	{
		i = add_width_c(' ', str->width);
		/*while (add < str->width)
		{
			write(1, &space, 1);
			add++;
		}*/
		add +=write(1, &c, 1);
		return (add + i);
	}
	else
		i += write(1, &c, 1);
	return (i);
}

static	char	*add_s_str(t_str *str, char *c)
{
	char *s;
	if (str->fl_precision == 1)
	{
		if (str->precision > -1 && c)
			c = ft_substr(c, 0, str->precision);
	}
	else if (str->precision == -1 && c)
	{
		c = ft_strdup(c);
	}
	else if (str->precision == -1 && !c)
	{
		c = ft_strdup("(null)");
	}
	else if (str->precision > -1 && !c)
	{
		s = ft_strdup("(null)");
		return (s);
	}
	return (c);
}

static int add_width_s(char c, int width)
{
	int add;

	add = 0;
	while (add < width)
	{
		write(1, &c, 1);
		add++;
	}
	return (add);
}

static	int		add_s(t_str *str, char *c)
{
	int		i;
	int		add;
	char	*string;

	string = add_s_str(str, c);
	i = ft_strlen(string);
	add = 0;
	if (str->flags == -1)
	{
		add += write(1, string, ft_strlen(string));
		add = add + add_width_s(' ', str->width - i);
	}
	else if (str->flags == 1)
	{
		add += add_width_s(' ', str->width - i);
		add += write(1, string, ft_strlen(string));
	}
	else
		add += write(1, string, ft_strlen(string));
	//free(string);
	return (add);
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
			while (w != 0)
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
	if (str->flags != -1)
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

	ft_memset(&str, 0, sizeof(str));
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
			format++;
		}
		else
			i = i + write(1, format++, 1);
	}
	va_end(arglist);
	return (i + add);
}
