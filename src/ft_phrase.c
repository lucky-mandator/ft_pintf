/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phrase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:03:05 by saluru            #+#    #+#             */
/*   Updated: 2021/02/13 19:48:40 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_save_num(char *format, va_list ap, t_printf *tab)
{
	char	*num;
	int		val;

	val = 0;
	num = &format[tab->i];
	if (format[tab->i] >= '0' && format[tab->i] <= '9')
	{
		while(1)
		{
			if(!(format[tab->i + 1] >= '0' && format[tab->i + 1] <= '9'))
				break;
			tab->i++;
		}
	}
	val = atoi(num);
	return (val);
}

void	ft_save_rest(char *format, va_list ap, t_printf *tab)
{
	tab->width = ft_save_num(format, ap, tab);
	if (format[tab->i] == '.')
	{
		tab->dot = 1;
		tab->i++;
		tab->dot_len = ft_save_num(format, ap, tab);
	}
	if (ft_check_sp(format[tab->i]))
	{
		/*
		tab->converter = format[tab.i];
		format[tab.i] == 'd' || format[tab.i] == 'i' ? ft_con_int(ap, tab) : 0;
		format[tab.i] == 'c' ? ft_con_char(ap, tab) : 0;
		format[tab.i] == 's' ? ft_con_str(ap, tab) : 0;
		format[tab.i] == 'p' ? ft_con_p(ap, tab) : 0;
		format[tab.i] == 'u' ? ft_con_u(ap, tab) : 0;
		format[tab.i] == 'x' ? ft_con_x(ap, tab) : 0;
		format[tab.i] == 'X' ? ft_con_x(ap, tab) : 0;
		fromat[tab.i] == '%' ? ft_con_char(ap, tab) : 0;
		format[tab.i] == 'n' ? ft_con_n(ap, tab) : 0;
		*/
		tab->i++;
	}
}

void	ft_save_action(char *format, va_list ap, t_printf *tab)
{
	if (ft_check_flags(format[tab->i]))
	{
		if (format[tab->i] == '-')
		{
			tab->minus = 1;
			tab->zero = 0;
		}
		if(format[tab->i] == ' ')
			tab->space = 1;
		if(format[tab->i] == '#')
			tab->hash = 1;
		if(format[tab->i] == '0' && !tab->minus)
			tab->zero = 1;
		if(format[tab->i] == '+')
			tab->plus = 1;
		tab->i++;
	}
}

void ft_prase(char *format, va_list ap, t_printf *tab)
{
	while (1)
	{
		ft_save_action(format, ap, tab);
		if(!(ft_check_flags(format[tab->i + 1])))
			break;
	}
	ft_save_rest(format, ap, tab);
}
