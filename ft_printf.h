/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:41:53 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/25 23:27:12 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_str
{
	char		*line;
	int			flags_z;
	int			flags_s;
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
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memset(void *dest, int c, size_t n);
int			add_c(t_str *str, char c);
int			add_s(t_str *str, char *c);
int			add_width_c(char c, int width);
int			add_x_precision(t_str *str, unsigned int num, const char **format);
int			add_x(t_str *str, unsigned int num, const char **format);
int			add_x_registr(long a, const char **format);
int			add_width_x(char c, int width);
int			add_x_str(unsigned int num);
int			add_x_hex(t_str *str, unsigned int num, const char **format);
#endif
