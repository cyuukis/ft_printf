#include "ft_printf.h"

int		add_di_one(t_str *str, int minus, char *res, int string)
{
	int add;

	add = 0;
	if (str->precision > -1)
		add += add_di_fl(str, minus, res, string);
	else if (str->fl_precision >= 0 || str->flags_z == 2)
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

int				add_di(t_str *str, int di)
{
	char	*res;
	//int		a;
	int		minus;
	int		add;
	int		string;

	add = 0;
	res = ft_itoa(di);
	//a = 0;
	string = ft_strlen(res);
	if (di < 0)
	{
		string -= 1;
		minus = 1;
	}
	else
		minus = 0;
	if (di == 0 && str->fl_precision == 1 && str->precision == 0)
	{
		add += add_width_x(' ', str->width);
		res = ft_strdup("");
		return (add);
	}
	add += add_di_one(str, minus, res, string);
	free(res);
	return (add);
}