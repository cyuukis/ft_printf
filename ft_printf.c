/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/27 00:26:33 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static	int		add_di_space(t_str *str, int string, char *res, int minus)
{
	int add;

	add = 0;
	if (str->fl_precision == 1)
	{
		if (str->width > string)
			string = str->width - string - minus;
		if (minus == 1)
		{
			write(1, "-", 1);
			res++;
			add++;
		}
		if (string > 0)
			add += add_width_di('0', string);
		add += write(1, res, ft_strlen(res));
	}
	else if (str->flags_s == -1)
	{
		add += write(1, res, ft_strlen(res));
		string = str->width - string;
		if (string > 0)
			add += add_width_di(' ', string);
	}
	else if (str->flags_z == 2 && str->fl_precision != 1)
	{
		string = str->width - string;
		if (string > 0)
			add += add_width_di('0', string);
		add += write(1, res, ft_strlen(res));
	}
	return (add);
}

static	int		add_di(t_str *str, int di)
{
	char	*res;
	int		a;
	int		minus;
	int		add;
	int		string;

	add = 0;
	res = ft_itoa(di);
	a = 0;
	string = ft_strlen(res);
	if (di < 0)
		minus = 1;
	else
		minus = 0;
	if (di == 0 && str->fl_precision == 1 && str->precision == 0)
	{
		add += add_width_x(' ', str->width);
		res = ft_strdup("");
		return (add);
	}
	if (str->precision > -1)
	{
		if (str->precision > string)
			a = str->precision - string;
		else if (str->precision == 1 && string == 1)
			a = 1;
		else
			str->precision = 0;
		if (str->width > a + string)
			str->width = str->width - string - a;
		else
			str->width = 0;
		if (minus == 1 && str->precision > 0)
		{
			a++;
			str->width--;
		}
		if (str->flags_z == 2 || str->flags_s == 1)
		{
			if (str->flags_z == 2 && str->flags_s == -1)
			{
				if (minus == 1)
				{
					add += write(1, "-", 1);
					res++;
				}
				add += add_width_di('0', a);
				add += write(1, res, ft_strlen(res));
				add += add_width_di(' ', str->width);
				return (add);
			}
			else if ((str->flags_z == 2 || str->flags_s == -1) && str->fl_precision != 1)
			{
				if (minus == 1)
				{
					add += write(1, "-", 1);
					res++;
				}
				add += add_width_di('0', str->width);
				add += write(1, res, ft_strlen(res));
				add += add_width_di(' ', str->precision);
			}
			else if (str->flags_z == 2 && str->fl_precision == 1)
			{
				add += add_width_di(' ', str->width);
				if (minus == 1)
				{
					add += write(1, "-", 1);
					res++;
				}
				add += add_width_di('0', a);
				add += write(1, res, ft_strlen(res));
			}
			else
			{
				add += add_width_di(' ', str->width);
				if (minus == 1)
				{
					add += write(1, "-", 1);
					res++;
				}
				add += add_width_di('0', a);
				add += write(1, res, ft_strlen(res));
			}
		}
		else if (str->flags_s == -1)
		{
			if (minus == 1)
			{
				add += write(1, "-", 1);
				res++;
			}
			add += add_width_di('0', a);
			add += write(1, res, ft_strlen(res));
			add += add_width_di(' ', str->width);
		}
	}
	else if (str->fl_precision == 1 || str->flags_s == -1 || str->flags_z == 2)
		add += add_di_space(str, string, res, minus);
	else if (str->width > 0)
	{
		string = str->width - string;
		if (minus < 0)
		{
			add += write(1, "-", 1);
			res++;
		}
		add += write(1, res, ft_strlen(res));
		if (string > 0)
			add += add_width_di(' ', string);
	}
	return (add);
}

static	int		add_u(t_str *str, unsigned int num)
{
	int		add;
	long	string;
	char	*res;
	int		a;

	add = 0;
	a = 0;
	string = 0;
	res = ft_itoa(num);
	string += ft_strlen(res);
	if (num == 0 && str->fl_precision == 1 && str->precision == 0)
	{
		add += add_width_x(' ', str->width);
		res = ft_strdup("");
		return (add);
	}
	if (str->precision > -1)
	{
		if (str->precision > string)
			a = str->precision - string;
		else if (str->precision == 1 && string == 1)
			a = 1;
		else
			str->precision = 0;
		if (str->width > a + string)
			str->width = str->width - string - a;
		else
			str->width = 0;
		if (str->flags_z == 2 || str->flags_s == 1)
		{
			if (str->flags_z == 2 && str->flags_s == -1)
			{
				add += add_width_di('0', a);
				add += write(1, res, ft_strlen(res));
				add += add_width_di(' ', str->width);
				return (add);
			}
			else if ((str->flags_z == 2 || str->flags_s == -1) && str->fl_precision != 1)
			{
				add += add_width_di('0', str->width);
				add += write(1, res, ft_strlen(res));
				add += add_width_di(' ', str->precision);
			}
			else if (str->flags_z == 2 && str->fl_precision == 1)
			{
				add += add_width_di(' ', str->width);
				add += add_width_di('0', a);
				add += write(1, res, ft_strlen(res));
			}
			else
			{
				add += add_width_di(' ', str->width);
				add += add_width_di('0', a);
				add += write(1, res, ft_strlen(res));
			}
		}
		else if (str->flags_s == -1)
		{
			add += add_width_di('0', a);
			add += write(1, res, ft_strlen(res));
			add += add_width_di(' ', str->width);
		}
	}
	else if (str->fl_precision == 1 || str->flags_s == -1 || str->flags_z == 2)
	{
		if (str->fl_precision == 1)
		{
			if (str->width > string)
				string = str->width - string;
			if (string > 0)
				add += add_width_di('0', string);
			add += write(1, res, ft_strlen(res));
		}
		else if (str->flags_s == -1)
		{
			add += write(1, res, ft_strlen(res));
			string = str->width - string;
			if (string > 0)
				add += add_width_di(' ', string);
		}
		else if (str->flags_z == 2 && str->fl_precision != 1)
		{
			string = str->width - string;
			if (string > 0)
				add += add_width_di('0', string);
			add += write(1, res, ft_strlen(res));
		}
	}
	else if (str->width > 0)
	{
		string = str->width - string;
		add += write(1, res, ft_strlen(res));
		if (string > 0)
			add += add_width_di(' ', string);
	}
	return (add);
}

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

int		add_p_hex(t_str *str, unsigned long num)
{
	long	a;
	int		add;

	add = 0;
	if (num >= 16)
		add += add_p_hex(str, num / 16);
	a = num % 16;
	add += add_p_registr(a);
	return (add);
}

int		add_p_str(unsigned long num)
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

static	int		add_p(t_str *str, unsigned long pointer)
{
	int add;
	//char *res;
	int string;

	string = 0;
	string += add_p_str(pointer);
	// printf("poiter = %lu\n", pointer);
	add = 0;
	if (pointer == 0 && str->fl_precision == 1 && str->precision == 0)
	{
		if (str->width > 0)
			add += add_width_di(' ', str->width - 2);
		add += write(1, "0x", 2);
		//add += write(1, "", 0);
		return (add);
	}
	else if (str->flags_s == -1)
	{
		str->width = str->width - (string + 2);
		add += write(1, "0x", 2);
		add += add_p_hex(str, pointer);
		add += add_width_di(' ', str->width);
	}
	else if (str->flags_z == 2)
	{
		str->width = str->width - (string + 2);
		add += write(1, "0x", 2);
		add += add_p_hex(str, pointer);
		add += add_width_di('0', str->width);
	}
	else if (str->flags_s == 1)
	{
		if (str->precision > string)
			str->precision = str->precision - string;
		else
			str->precision = 0;
		str->width = str->width - (string + 2);
		add += add_width_di(' ', str->width);
		add += write(1, "0x", 2);
		add += add_width_di('0', str->precision);
		add += add_p_hex(str, pointer);
	}


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
	//else
	//	str->width = 0;
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
		//else
		//	str->precision = 0;
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
	else if (**format == 'p')
		return (add_p(&str, (unsigned long)va_arg(arglist, void *)));
	else if (**format == 'u')
		return (add_u(&str, va_arg(arglist, unsigned int)));
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
	return (i + add);
}
