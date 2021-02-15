/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:56:13 by saluru            #+#    #+#             */
/*   Updated: 2021/02/15 20:00:29 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
# endif

#define FALSE 0
#define TRUE 1
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
#include <stdio.h>

typedef struct	s_printf
{
	char	buff[BUFFER_SIZE + 1];
	int		buff_count;
	int		i;
	int		ret;
	int 	minus;
	int		plus;
	int		hash;
	int		space;
	int		zero;
	int		width;
	int		dot;
	int		dot_parsing;
	int		dot_len;
	char	convert;
	int		len;
	int		sp_len;
	int		is_int;
	uintmax_t		u;
	intmax_t		n;
	int		l_count;
	int		h_count;
}		t_printf;

int		ft_printf(const char *str, ...);
void	ft_init_strct(t_printf *tab);
void	ft_print_normal(t_printf *tab, char *format);
void	ft_dump_buff(t_printf *tab);
void	ft_add_to_buff(t_printf *tab, char *str, int len);

size_t	ft_check_sp(char c);
size_t	ft_check_pf(char c);
size_t	ft_check_flags(char c);

void	ft_prase(char *format, va_list ap, t_printf *tab);
void	ft_save_flags(char *format, va_list ap, t_printf *tab);
void	ft_save_action(char *format, t_printf *tab);
void	ft_save_rest(char *format, va_list ap, t_printf *tab);
int		ft_save_num(char *format, t_printf *tab);

char	*ft_print_sp(t_printf *tab);
char	*ft_num_precision(char *str, t_printf *tab);
void	ft_join_all(char *str, char *sp, t_printf *tab);

void	ft_con_int(va_list ap, t_printf *tab);
int		ft_intlen(int x);
void	ft_add_sign(t_printf *tab);

void	ft_con_char(va_list ap, t_printf *tab);
char	*ft_c_to_str(char c);

void	ft_con_str(va_list ap, t_printf *tab);

void	ft_con_p(va_list ap, t_printf *tab);

void	ft_con_u(va_list ap, t_printf *tab);

void	ft_con_x(va_list ap, t_printf *tab);
void	ft_add_prefix(t_printf *tab);

void	ft_con_X(va_list ap, t_printf *tab);

void	ft_con_n(va_list ap, t_printf *tab);

void	ft_reset_flags(t_printf *tab);
void	ft_set_precision(t_printf *tab);
char	*ft_strdup_l(char *s, t_printf *tab);
int		ft_atoi_printf(char *str, int *i);
char	*itoa_printf(intmax_t n);
char	*ft_uitoa(uintmax_t n);
size_t	ft_intlen_base(uintmax_t n, char *base);
intmax_t	ft_atoi_base(char *str, char *base);
size_t	ft_uintlen(uintmax_t n);
void	ft_size_u(va_list ap, t_printf *tab);


/*
 * libft functions
 */
char		*ft_itoa(int n);
int			ft_atoi(const char *str);

#endif
