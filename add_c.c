#include "ft_printf.h"

int add_width_c(char c, int width)
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

int			add_c(t_str *str, char c)
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
			return (i + add);
		}
		else if (str->flags == 1)
		{
			i = add_width_c(' ', str->width);
			add += write(1, &c, 1);
			return (add + i);
		}
	}
	if (str->flags == 2 && str->width >= 0)
	{
		i = add_width_c(' ', str->width);
		add += write(1, &c, 1);
		return (add + i);
	}
	else
		i += write(1, &c, 1);
	return (i);
}