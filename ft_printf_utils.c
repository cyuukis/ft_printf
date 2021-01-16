/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:45:50 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/16 17:54:47 by cyuuki           ###   ########.fr       */
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
