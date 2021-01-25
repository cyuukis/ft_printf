/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/26 00:22:22 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>



static	int		add_width_di(char c, int width)
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

static	int		add_di_space(t_str *str, int a, char *res, int minus, int di)
{
	int add;

	add = 0;
	if (str->fl_precision == 1)
	{
		if (str->width > a)
			a = str->width - a - minus;
		if (di < 0)
		{
			write(1, "-", 1);
			res++;
		}
		if (a > 0)
			add += add_width_di('0', a);
		add += write(1, res, ft_strlen(res));
	}
	else if (str->flags_s == -1)
	{
		add += write(1, res, ft_strlen(res));
		a = str->width - a;
		if (a > 0)
			add += add_width_di(' ', a);
	}
	return (add);
}

static	int		add_di(t_str *str, int di)
{
	char	*res;
	int		a;
	int		minus;
	int		add;

	add = 0;
	res = ft_itoa(di);
	a = ft_strlen(res);
	if (di < 0)
		minus = 1;
	else
		minus = 0;
	if (str->precision > -1 && str->flags_s == -1)
	{
		
	}
	else if (str->fl_precision == 1 || str->flags_s == -1)
		add_di_space(str, a, res, minus, di);
	else if (str->width > 0)
	{
		a = str->width - a;
		if (a > 0)
			add += add_width_di(' ', a);
		add += write(1, res, ft_strlen(res));
	}
	return (add);
	/*if (str->width == 0 && str->precision == 0)
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
	}*/
}

static	int		add_x_registr(long a, const char **format)
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

static	int		add_x_hex(t_str *str, unsigned int num, const char **format)
{
	long	a;
	int		add;

	add = 0;
	if (num >= 16)
	add += add_x_hex(str, num / 16, format);
	a = num % 16;
	add += add_x_registr(a, format);
	return (add);
}

static	int		add_width_x(char c, int width)
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

static	int		add_x_str(unsigned int num)
{
	int string;

	string = 0;
	while (num >= 16)
	{
		num /= 16;
		string++;
	}
	string++;
	return (string);
}

static	int		add_x_precision(t_str *str, unsigned int num, const char **format)
{
	int	a;
	int	add;
	int string;

	string = 0;
	add = 0;
	a = 0;
	string += add_x_str(num);
	if (num == 0 && str->fl_precision == 1 && str->precision == 0)
	{
		add += add_width_x(' ', str->width);
	}
	else if (str->precision > -1)
	{
		if (str->precision > string)
			a = str->precision - string;
		else
			str->precision = 0;
		if (str->width > (a + string))
			str->width = str->width - string - a;
		else
			str->width = 0;
		if (str->flags_s == 1 || str->flags_z == 2)
		{
			if (str->flags_z == 2 && str->flags_s == -1)
			{
				add += add_width_x('0', a);
				//add += add_x_hex(str, num, format);
				(string != 0 ? add += add_x_hex(str, num, format) : 0);
				add += add_width_x(' ', str->width);
				return (add);
			}
			else
			{
				add += add_width_x(' ', str->width);
				add += add_width_x('0', a);
				//add += add_x_hex(str, num, format);
				(string != 0 ? add += add_x_hex(str, num, format) : 0);
				return (add);
			}
		}
		else if (str->flags_s == -1)
		{
			add += add_width_x('0', a);
			//add += add_x_hex(str, num, format);
			(string != 0 ? add += add_x_hex(str, num, format) : 0);
			add += add_width_x(' ', str->width);
		}
	}
	return (add);
}

static	int		add_x_null(t_str *str, unsigned int num, const char **format)
{
	int add;
	int string;

	string = 0;
	add = 0;
	string += add_x_str(num);
	if (str->width > string)
		str->width = str->width - string;
	else
		str->width = 0;
	add += add_width_x('0', str->width);
	add += add_x_hex(str, num, format);
	return (add);
}

static	int		add_x(t_str *str, unsigned int num, const char **format)
{
	int	add;
	int string;

	string = 0;
	add = 0;
	if (num == 0 && str->precision == 0)
		string = 0;
	if (str->flags_z == 2 && str->fl_precision == 0)
		add += add_x_null(str, num, format);
	else
		add += add_x_precision(str, num, format);
	return (add);
}

static	void	my_parses_flag(t_str *str, const char **format)
{
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
	{
		str->fl_precision = 0;
		str->precision = 0;
	}
}

static	int		my_parses(va_list arglist, const char **format)
{
	t_str str;

	if (**format == '\0')
		return (0);
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
		return (add_u(&str, va_arg(arglist, unsigned int)));*/
	else if (**format == 'x' || **format == 'X')
		return (add_x(&str, va_arg(arglist, unsigned int), format));
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
			if (*format)
				format++;
		}
		else
			i = i + write(1, format++, 1);
	}
	va_end(arglist);
	// printf("\n%d\n", i);
	// printf("%d\n", add);
	return (i + add);
}
