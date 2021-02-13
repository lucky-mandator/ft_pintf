/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:17:17 by saluru            #+#    #+#             */
/*   Updated: 2021/02/13 19:32:07 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
# endif

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

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
	int		dot_len;
	char	convert;
}		t_printf;

int		ft_printf(const char *str, ...);
void	ft_init_strct(t_printf *tab);
void	ft_print_normal(t_printf *tab, char *format);
void	ft_dump_buff(t_printf *tab);

size_t	ft_check_sp(char c);
size_t	ft_check_pf(char c);
size_t	ft_check_flags(char c);

void	ft_prase(char *format, va_list ap, t_printf *tab);
void	ft_save_flags(char *format, va_list ap, t_printf *tab);
void	ft_save_action(char *format, va_list ap, t_printf *tab);
void	ft_save_rest(char *format, va_list ap, t_printf *tab);
int		ft_save_num(char *format, va_list ap, t_printf *tab);

void	ft_con_int(va_list ap, t_printf tab);
void	ft_con_char(va_list ap, t_printf tab);
void	ft_con_str(va_list ap, t_printf tab);
void	ft_con_p(va_list ap, t_printf tab);
void	ft_con_u(va_list ap, t_printf tab);
void	ft_con_x(va_list ap, t_printf tab);
void	ft_con_X(va_list ap, t_printf tab);
void	ft_con_n(va_list ap, t_printf tab);

/*
 * libft functions
 */
char		*ft_itoa(int n);
int			ft_atoi(const char *str);

#endif
