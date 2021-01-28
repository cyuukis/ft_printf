#include "ft_printf.h"

static	int		ft_check(long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		if (n < 0)
			n *= -1;
		n = n / 10;
		i++;
	}
	return (i);
}

static	int		ft_equals(long c)
{
	if (c > 0)
		return (1);
	else
		return (2);
}

static void		ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	str = s;
	i = 0;
	while (n)
	{
		str[i] = '\0';
		i++;
		n--;
	}
}

static void		*ft_calloc(size_t number, size_t size)
{
	char	*s;
	size_t	sum;

	sum = number * size;
	s = (char *)malloc(sum);
	if (!s)
		return (NULL);
	ft_bzero(s, sum);
	return (s);
}

char			*ft_itoa(long n)
{
	size_t				l;
	char				*str;
	long int			number;

	number = n;
	l = (ft_equals(n) + ft_check(number));
	if (!(str = (char *)ft_calloc(l, 1)))
		return (NULL);
	if (number == 0)
		*str = '0';
	if (number < 0)
	{
		*str = '-';
		number *= -1;
	}
	while (number)
	{
		l--;
		str[l - 1] = (number % 10) + 48;
		number = number / 10;
	}
	l = ft_equals(n) + ft_check(n);
	str[l - 1] = '\0';
	return (str);
}