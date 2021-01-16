/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:41:53 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/16 17:54:58 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	my_str
{
	char		*line;
}				m_str;

int			ft_printf(const char *string, ...);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int ch);
char		*ft_strdup(const char *str);
#endif
