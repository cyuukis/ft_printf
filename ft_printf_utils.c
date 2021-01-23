/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:45:50 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/23 23:07:11 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*str2;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			str2 = (char *)&str[i];
			return (str2);
		}
		i++;
	}
	if (str[i] == ch)
	{
		str2 = (char *)&str[i];
		return (str2);
	}
	return (NULL);
}

char		*ft_strdup(const char *str)
{
	char	*string;
	size_t	i;

	i = 0;
	i = ft_strlen(str);
	string = (char *)malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (str[i])
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int z;

	i = 0;
	n = 0;
	z = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			z *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (z * n);
}

static	int		ft_check(int n)
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

static	int		ft_equals(int c)
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

char			*ft_itoa(int n)
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

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start > j)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * ((len + 1)));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
