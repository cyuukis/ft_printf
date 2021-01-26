#include "ft_printf.h"

int		add_x_registr(long a, const char **format)
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