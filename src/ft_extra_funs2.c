/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_funs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:00:23 by saluru            #+#    #+#             */
/*   Updated: 2021/02/20 17:44:45 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_join_all(char *str, char *sp, t_printf *tab)
{
	(tab->is_int && tab->zero) ? ft_add_sign(tab) : 0;
	if (tab->zero && tab->convert == 'p')
	{
		ft_add_to_buff(tab, "0x", 2);
		tab->len -= 2;
	}
	if (tab->hash && tab->u && tab->zero && tab->dot_len < tab->len)
		ft_add_prefix(tab);
	if (sp && !tab->minus)
		ft_add_to_buff(tab, sp, tab->sp_len);
	if (!tab->zero && tab->convert == 'p')
	{
		ft_add_to_buff(tab, "0x", 2);
		tab->len -= 2;
	}
	if (tab->hash && tab->u && !tab->zero && tab->dot_len < tab->len)
		ft_add_prefix(tab);
	if (tab->is_int && !tab->zero)
		ft_add_sign(tab);
	ft_add_to_buff(tab, str, tab->len);
	if (sp && tab->minus)
		ft_add_to_buff(tab, sp, tab->sp_len);
	free(str);
	free(sp);
}

char		*ft_num_precision(char *str, t_printf *tab)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tab->dot)
		return (str);
	if (tab->dot_len < tab->len)
		return (str);
	if (!(tmp = calloc(tab->dot_len + tab->len + 1, sizeof(char))))
		return (NULL);
	while (i < tab->dot_len - tab->len)
	{
		tmp[i] = '0';
		i++;
	}
	while (str[j])
	{
		tmp[i + j] = str[j];
		j++;
	}
	tmp[i + j] = '\0';
	free(str);
	return (tmp);
}

size_t		ft_uintlen(uintmax_t n)
{
	size_t		len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

intmax_t	ft_atoi_base(char *str, char *base)
{
	int			i;
	intmax_t	atoi;
	int			negative;
	int			base_len;

	i = 0;
	atoi = 0;
	negative = 0;
	base_len = ft_strlen(base);
	if (!ft_check_base(base))
		return (FALSE);
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = 1;
		str++;
	}
	while (ft_is_in_stri(*str, base) >= 0)
	{
		atoi = atoi * base_len + ft_is_in_stri(*str, base);
		str++;
	}
	return (negative ? -atoi : atoi);
}
