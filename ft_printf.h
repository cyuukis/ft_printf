/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:41:53 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/28 20:05:20 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

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

int				ft_printf(const char *string, ...);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(long n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memset(void *dest, int c, size_t n);
int				add_c(t_str *str, char c);
int				add_s(t_str *str, char *c);
int				add_width_c(char c, int width);
int				add_x_precision(t_str *s, unsigned int n, const char **form);
int				add_x(t_str *str, unsigned int num, const char **format);
int				add_x_registr(long a, const char **format);
int				add_width_x(char c, int width);
int				add_x_str(unsigned int num);
int				add_x_hex(t_str *str, unsigned int num, const char **format);
int				add_p_registr(unsigned long a);
int				add_p(t_str *str, unsigned long pointer);
int				add_width_di(char c, int width);
int				add_u(t_str *str, unsigned int num);
int				add_u_fl(t_str *str, char *res, int string);
int				add_u_five(t_str *str, char *res, unsigned int n);
int				add_u_six(t_str *str, int string, char *res);
int				fl_u_fi(t_str *str, char *res, int a);
int				add_di_fl(t_str *str, int minus, char *res, int string);
int				add_di(t_str *str, int di);
int				space_di_fi(t_str *str, int string, char *res, int minus);
int				space_di_six(t_str *str, int string, char *res);
int				add_di_one(t_str *str, int minus, char *res, int string);
int				add_di_space(t_str *str, int string, char *res, int minus);

#endif
