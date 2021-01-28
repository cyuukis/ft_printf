/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:45:50 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 15:23:13 by cyuuki           ###   ########.fr       */
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

int			ft_atoi(const char *str)
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

void		*ft_memset(void *dest, int c, size_t n)
{
	int		i;
	char	*src;

	src = dest;
	i = 0;
	while (n)
	{
		src[i] = c;
		i++;
		n--;
	}
	return (dest);
}
