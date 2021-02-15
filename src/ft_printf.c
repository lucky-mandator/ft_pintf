/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 08:45:54 by saluru            #+#    #+#             */
/*   Updated: 2021/02/15 18:57:18 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dump_buff(t_printf *tab)
{
	write(1, tab->buff, tab->buff_count);
	tab->buff_count = 0;
}

void	ft_add_to_buff(t_printf *tab, char *str, int len)
{
	int		i;

	i = 0;
	tab->ret += len;
	while (i < len)
	{
		tab->buff[tab->buff_count] = str[i];
		tab->buff_count++;
		if (tab->buff_count == BUFFER_SIZE)
			ft_dump_buff(tab);
		i++;
	}
}

void	ft_print_normal(t_printf *tab, char *format)
{
	int	len;

	len = 0;
	while (format[tab->i] && format[tab->i] != '%')
	{
		tab->buff[tab->buff_count] = format[tab->i];
		tab->buff_count++;
		len++;
		if (tab->buff_count == BUFFER_SIZE)
			ft_dump_buff(tab);
		tab->i++;
	}
	tab->ret +=len;
	tab->i--;
}

void	ft_init_strct(t_printf *tab)
{
	tab->buff_count = 0;
	tab->i = 0;
	tab->ret = 0;
	tab->minus = 0;
	tab->plus = 0;
	tab->hash = 0;
	tab->space = 0;
	tab->zero = 0;
	tab->width = 0;
	tab->dot = 0;
	tab->dot_len = 0;
	tab->u = 0;
	tab->n = 0;
}

int ft_printf(const char *format, ...)
{
	t_printf	tab;
	va_list		ap;

	ft_init_strct(&tab);
	va_start(ap, format);
	while(format[tab.i])
	{
		
		if(format[tab.i] == '%')
		{
			if (format[tab.i + 1] == '\0')
				break;
			if (ft_check_pf(format[tab.i + 1]))
				ft_prase((char*)format, ap, &tab);
		}
		else
			ft_print_normal(&tab, (char*)format);
		tab.i++;
	}
	va_end(ap);
	ft_dump_buff(&tab);
	return (tab.ret);
}

int main(void)
{
	ft_printf("sai chaitanya%csai", 'D');
}
