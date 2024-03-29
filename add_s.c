/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:13 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 19:54:02 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*add_s_str(t_str *str, char *c)
{
	char *meow;

	meow = c;
	if (str->fl_precision == 1)
	{
		if (str->precision > -1 && c)
		{
			c = ft_substr(c, 0, str->precision);
			free(meow);
		}
	}
	if (str->fl_width == -1)
	{
		write(1, c, ft_strlen(c));
	}
	return (c);
}

static	int		add_s_one(t_str *str, char *string, int i)
{
	int add;

	add = 0;
	if (str->fl_width != -1)
		add += write(1, string, ft_strlen(string));
	add = add + add_width_di(' ', str->width - i);
	if (str->fl_width == -1)
	{
		if (string)
			free(string);
		return (add + i);
	}
	if (string)
		free(string);
	return (add);
}

static	int		add_s_two(t_str *str, char *string, int i)
{
	int add;

	add = 0;
	add += add_width_di(' ', str->width - i);
	if (str->fl_width != -1)
	{
		add += write(1, string, ft_strlen(string));
		if (string || !string)
			free(string);
	}
	else
	{
		if (string || !string)
			free(string);
		return (add + i);
	}
	return (add);
}

static	int		add_s_three(t_str *str, char *string, int i)
{
	int add;

	add = 0;
	if (str->fl_width != -1)
	{
		add += add_width_di('0', str->width - i);
		add += write(1, string, ft_strlen(string));
		if (string)
			free(string);
	}
	else
	{
		add += add_width_di(' ', str->width - i);
		if (string)
			free(string);
		return (add + i);
	}
	return (add);
}

int				add_s(t_str *str, char *c)
{
	int		i;
	int		add;
	char	*string;
	char	*temp;

	add = 0;
	temp = c;
	if (!c)
		c = ft_strdup("(null)");
	string = add_s_str(str, ft_strdup(c));
	if (!temp)
		free(c);
	i = ft_strlen(string);
	if (str->flags_s == -1)
		return (add += add_s_one(str, string, i));
	else if (str->flags_s == 1)
		return (add += add_s_two(str, string, i));
	else if (str->flags_z == 2)
		return (add += add_s_three(str, string, i));
	else
	{
		add += write(1, string, ft_strlen(string));
		free(string);
	}
	return (add);
}
