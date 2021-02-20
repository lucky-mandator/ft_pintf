/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phrase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:03:05 by saluru            #+#    #+#             */
/*   Updated: 2021/02/20 17:04:12 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(char *str, va_list ap, t_printf *tab)
{
	if (str[tab->i] == '*')
	{
		if (tab->dot_parsing)
			tab->dot_len = va_arg(ap, int);
		else
			tab->width = va_arg(ap, int);
	}
	if (str[tab->i] == '0' && !tab->minus && !tab->dot_parsing)
		tab->zero = 1;
	if (str[tab->i] > '0' && str[tab->i] <= '9' && !tab->dot_parsing)
		tab->width = ft_atoi_printf(str, &tab->i);
	if (str[tab->i] >= '0' && str[tab->i] <= '9' && tab->dot_parsing)
		tab->dot_len = ft_atoi_printf(str, &tab->i);
	tab->dot_parsing = 0;
	if (str[tab->i] == '-')
	{
		tab->zero = 0;
		tab->minus = 1;
	}
	str[tab->i] == '.' ? ft_set_precision(tab) : 0;
	str[tab->i] == ' ' ? tab->space = 1 : 0;
	str[tab->i] == '+' ? tab->plus = 1 : 0;
	str[tab->i] == '#' ? tab->hash = 1 : 0;
	str[tab->i] == 'l' ? tab->l_count += 1 : 0;
	str[tab->i] == 'h' ? tab->h_count += 1 : 0;
}

int		ft_parse2(char *str, va_list ap, t_printf *tab)
{
	char	*sp;
	char	*c;

	while (!ft_check_sp(str[tab->i]))
	{
		ft_check_flag(str, ap, tab);
		if (str[tab->i + 1] == '\0')
			return (0);
		if (!ft_check_pf(str[tab->i + 1]))
		{
			c = ft_c_to_str(str[tab->i + 1]);
			tab->len = 1;
			tab->minus ? ft_add_to_buff(tab, c, 1) : 0;
			sp = ft_print_sp(tab);
			ft_add_to_buff(tab, sp, tab->sp_len);
			!tab->minus ? ft_add_to_buff(tab, c, 1) : 0;
			free(c);
			free(sp);
			tab->i++;
			return (0);
		}
		tab->i++;
	}
	return (1);
}

void	ft_prase(char *format, va_list ap, t_printf *tab)
{
	tab->i++;
	ft_reset_flags(tab);
	if (!ft_parse2(format, ap, tab))
		return ;
	if (tab->width < 0)
	{
		tab->minus = 1;
		tab->zero = 0;
		tab->width = -tab->width;
	}
	if (tab->dot_len < 0)
		tab->dot = 0;
	tab->dot && tab->dot_len >= 0 ? tab->zero = 0 : 0;
	tab->convert = format[tab->i];
	format[tab->i] == 'c' ? ft_con_char(ap, tab) : 0;
	format[tab->i] == 's' ? ft_con_str(ap, tab) : 0;
	format[tab->i] == 'p' ? ft_con_p(ap, tab) : 0;
	format[tab->i] == 'd' || format[tab->i] == 'i' ? ft_con_int(ap, tab) : 0;
	format[tab->i] == 'u' ? ft_convert_uint(ap, tab) : 0;
	format[tab->i] == 'x' ? ft_con_x(ap, tab) : 0;
	format[tab->i] == 'X' ? ft_con_x(ap, tab) : 0;
	format[tab->i] == '%' ? ft_con_char(ap, tab) : 0;
	format[tab->i] == 'n' ? ft_con_n(ap, tab) : 0;
}
