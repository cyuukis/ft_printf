#include "ft_printf.h"

static	int	space_di_o(t_str *str, int string, char *res, int minus)
{
	int add;

	add = 0;
	string = str->width - string;
	if (minus == 1)
	{
		res++;
		string--;
	}
	if (minus == 1)
		add += write(1, "-", 1);
	add += add_width_di('0', string);
	add += write(1, res, ft_strlen(res));
	return (add);
}

static	int	space_di_tw(t_str *str, int string, char *res, int minus)
{
	int add;

	add = 0;
	string = str->width - string;
	if (minus == 1)
		res++;
	if (minus == 1)
		add += write(1, "-", 1);
	add += write(1, res, ft_strlen(res));
	if (string > 0 && str->fl_precision == 0)
		add += add_width_di(' ', string);
	if (str->precision > 0)
		add += add_width_di(' ', string);
	return (add);
}

static	int	space_di_th(t_str *str, int string, char *res, int minus)
{
	int add;

	add = 0;
	string = str->width - string;
	if (minus == 1)
	{
		res++;
		string--;
	}
	if (string > 0)
		add += add_width_di(' ', string);
	if (minus == 1)
		add += write(1, "-", 1);
	add += write(1, res, ft_strlen(res));
	return (add);
}

static	int	space_di_fo(t_str *str, int string, char *res, int minus)
{
	int add;

	add = 0;
	string = str->width - string;
	if (minus == 1)
	{
		res++;
		string--;
	}
	if (minus == 1)
		add += write(1, "-", 1);
	add += write(1, res, ft_strlen(res));
	if (string > 0 && str->fl_precision == 0)
		add += add_width_di(' ', string);
	if (str->precision > 0)
		add += add_width_di(' ', string);
	return (add);
}

int			add_di_space(t_str *str, int string, char *res, int minus)
{
	int add;

	add = 0;
	if (str->flags_z == 2)
	{
		if (str->flags_z == 2 && str->fl_precision == 0 && str->fl_width != -1)
			return (add += space_di_o(str, string, res, minus));
		else if (str->fl_width == -1)
			return (add += space_di_tw(str, string, res, minus));
	}
	else if (str->flags_s == 1)
	{
		if (str->flags_s == 1 && str->fl_precision == 0 && str->fl_width != -1)
			return (add += space_di_th(str, string, res, minus));
		else if (str->fl_width == -1)
			return (add += space_di_fo(str, string, res, minus));
	}
	else if (str->fl_precision >= 0)
		add += space_di_fi(str, string, res, minus);
	else if (str->flags_s == -1)
		add += space_di_six(str, string, res);
	else if (str->flags_z == 2 && str->fl_precision != 1)
		add += space_di_six(str, string, res);
	return (add);
}