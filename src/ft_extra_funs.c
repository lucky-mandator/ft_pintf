/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_funs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:45:23 by saluru            #+#    #+#             */
/*   Updated: 2021/02/15 18:50:16 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int x)
{
	int	i;

	i = 0;
	if (!x)
		return (1);
	while (x != 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

char	*ft_c_to_str(char c)
{
	char	*s;

	s = (char*)calloc(2, sizeof(char));
	s[0] = c;
	s[1] = '\0';
	return (s);
}

void	ft_add_sign(t_printf *tab)
{
	if (tab->n < 0)
	{
		tab->len--;
		ft_add_to_buff(tab, "-", 1);
	}
	else if (tab->plus && (tab->n >= 0))
	{
		tab->len--;
		ft_add_to_buff(tab, "+", 1);
	}
	else if (tab->space && !tab->plus && (tab->n >= 0))
	{
		tab->len--;
		ft_add_to_buff(tab, " ", 1);
	}
}

void	ft_add_prefix(t_printf *tab)
{
	if (tab->convert == 'x')
	{
		ft_add_to_buff(tab, "0x", 2);
		tab->len -= 2;
	}
	if (tab->convert == 'X')
	{
		ft_add_to_buff(tab, "0X", 2);
		tab->len -= 2;
	}
}

char	*ft_print_sp(t_printf *tab)
{
	char	*str;
	int		i;

	i = 0;
	if (tab->width < tab->len)
		return (NULL);
	if (!(str = calloc((tab->width - tab->len + 1), sizeof(char))))
		return (NULL);
	if (tab->dot && tab->dot_len > tab->len)
		tab->zero = 0;
	while (i < tab->width - tab->len)
	{
		if (tab->zero)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	tab->sp_len = i;
	str[i] = '\0';
	return (str);
}
