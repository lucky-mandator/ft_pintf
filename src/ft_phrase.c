/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phrase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:03:05 by saluru            #+#    #+#             */
/*   Updated: 2021/02/15 19:27:18 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_save_num(char *format, t_printf *tab)
{
	char	*num;
	int		val;
	int 	bol;

	val = 0;
	bol = 1;
	num = &format[tab->i];
	if (format[tab->i] >= '0' && format[tab->i] <= '9')
	{
		while(bol)
		{
			if(!(format[tab->i + 1] >= '0' && format[tab->i + 1] <= '9'))
				bol = 0;
			tab->i++;
		}
	}
	val = ft_atoi(num);
	return (val);
}

void	ft_save_rest(char *format, va_list ap, t_printf *tab)
{
	tab->width = ft_save_num(format, tab);
	if (format[tab->i] == '.')
	{
		tab->dot = 1;
		tab->i++;
		tab->dot_len = ft_save_num(format, tab);
	}
	if (ft_check_sp(format[tab->i]))
	{
		tab->convert = format[tab->i];
		format[tab->i] == 'd' || format[tab->i] == 'i' ? ft_con_int(ap, tab) : 0;
		format[tab->i] == 'c' ? ft_con_char(ap, tab) : 0;
		format[tab->i] == 's' ? ft_con_str(ap, tab) : 0;
		format[tab->i] == 'p' ? ft_con_p(ap, tab) : 0;
		format[tab->i] == 'u' ? ft_con_u(ap, tab) : 0;
		format[tab->i] == 'x' ? ft_con_x(ap, tab) : 0;
		format[tab->i] == 'X' ? ft_con_x(ap, tab) : 0;
		format[tab->i] == '%' ? ft_con_char(ap, tab) : 0;
		format[tab->i] == 'n' ? ft_con_n(ap, tab) : 0;
		tab->i++;
	}
}

void	ft_save_action(char *format, t_printf *tab)
{
		if (format[tab->i] == '-')
		{
			tab->minus = 1;
			tab->zero = 0;
		}
		else if(format[tab->i] == ' ')
			tab->space = 1;
		else if(format[tab->i] == '#')
			tab->hash = 1;
		else if(format[tab->i] == '0' && !tab->minus)
			tab->zero = 1;
		else if(format[tab->i] == '+')
			tab->plus = 1;
		tab->i++;
}

void ft_prase(char *format, va_list ap, t_printf *tab)
{
	int	bol;

	bol = 1;
	tab->i++;
	while (bol)
	{
		if(ft_check_flags(format[tab->i]))
			ft_save_action(format, tab);
		else
			bol = 0;
	}
	ft_save_rest(format, ap, tab);
}
