#include "ft_printf.h"

static	char	*add_s_str(t_str *str, char *c)
{

	if (str->fl_precision == 1)
	{
		if (str->precision > -1 && c)
			c = ft_substr(c, 0, str->precision);
	}
	else if (str->precision == -1 && c)
	{
		c = ft_strdup(c);
	}
	return (c);
}

static	int		add_width_s(char c, int width)
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

int			add_s(t_str *str, char *c)
{
	int		i;
	int		add;
	char	*string;

	if (!c)
		c = ft_strdup("(null)");
	string = add_s_str(str, c);
	i = ft_strlen(string);
	add = 0;
	if (str->flags_s == -1)
	{
		add += write(1, string, ft_strlen(string));
		add = add + add_width_s(' ', str->width - i);
	}
	else if (str->flags_s == 1)
	{

		add += add_width_s(' ', str->width - i);
		add += write(1, string, ft_strlen(string));
	}
	else if (str->flags_z == 2)
	{
		add += add_width_s('0', str->width - i);
		add += write(1, string, ft_strlen(string));
	}
	else
		add += write(1, string, ft_strlen(string));
	//free(c);
	return (add);
}
