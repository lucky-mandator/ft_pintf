/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:17:17 by saluru            #+#    #+#             */
/*   Updated: 2021/02/10 14:24:05 by saluru           ###   ########.fr       */
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
}		t_printf;
int				ft_printf(const char *str, ...);
void	ft_init_struct(t_printf *tab);
void	ft_printf_norm(t_printf *tab,char *format);
void	ft_dump_buff(t_printf *tab);


#endif
