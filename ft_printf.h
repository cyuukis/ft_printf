/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:41:53 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/21 19:03:50 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_str
{
	char		*line;
	int			flags;
	int			width;
	int			fl_width;
	int			fl_precision;
	int			precision;
}				t_str;

int			ft_printf(const char *string, ...);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int ch);
char		*ft_strdup(const char *str);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
#endif
