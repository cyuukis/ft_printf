/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:38:19 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/16 18:07:53 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		arglist;
	m_str		len;
	char		*pointer;

	if (!(len.line = (char *)malloc(sizeof(char) * ft_strlen(format))))
		return (-1);
	va_start(arglist, format);
	while (*format)
	{
		if ((pointer = ft_strchr(format, '%')))
		{
		}
		else
		{
			len.line = ft_strdup(format);
			printf("%s", len.line);
			break ;
		}
	}

	return (0);
}

int main(void)
{
	printf("%d\n", 5);
	ft_printf("%d", 5);
	return (0);
}
