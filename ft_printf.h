/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:41:53 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 00:14:15 by cyuuki           ###   ########.fr       */
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
char		*ft_itoa(long n);
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
int			add_p_registr(unsigned long a);
int			add_p(t_str *str, unsigned long pointer);
int			add_width_di(char c, int width);
int			add_u(t_str *str, unsigned int num);
int			add_u_fl(t_str *str, char *res, int string);
int			add_u_five(t_str *str, char *res, unsigned int n);
int			add_u_six(t_str *str, int string, char *res);
int			fl_u_fi(t_str *str, char *res, int a);
#endif
