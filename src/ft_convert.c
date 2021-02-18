/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:43:43 by saluru            #+#    #+#             */
/*   Updated: 2021/02/18 11:46:07 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_con_char(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	str = NULL;
	tab->len = 1;
	tab->convert == 'c' ? str = ft_c_to_str(va_arg(ap, int)) : 0;
	tab->convert == '%' ? str = ft_c_to_str('%') : 0;
	sp = ft_print_sp(tab);
	ft_join_all(str, sp, tab);
}

void	ft_con_str(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	if (tab->dot && tab->dot_len < 0)
		tab->dot_len = -tab->dot_len;
	if (!(str = va_arg(ap, char *)))
		str = ft_strdup_l("(null)", tab);
	else
		str = ft_strdup_l(str, tab);
	tab->len = ft_strlen(str);
	sp = ft_print_sp(tab);
	ft_join_all(str, sp, tab);
}

void	ft_con_n(va_list ap, t_printf *tab)
{
	intmax_t	*n;

	if (tab->l_count >= 2)
		n = (intmax_t *)va_arg(ap, long long *);
	else if (tab->l_count == 1)
		n = (intmax_t *)va_arg(ap, long *);
	else if (tab->h_count && ((tab->h_count % 2) == 0))
		n = (intmax_t *)((char *)va_arg(ap, int *));
	else if (tab->h_count && ((tab->h_count % 2) != 0))
		n = (intmax_t *)((short *)va_arg(ap, int *));
	else
		n = (intmax_t *)va_arg(ap, int *);
	if (!n)
		return ;
	*n = tab->ret;
}

void	ft_con_x(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	str = NULL;
	tab->is_int = 1;
	ft_size_u(ap, tab);
	tab->convert == 'x' ? str = ft_itoa_base(tab->u, "0123456789abcdef") : 0;
	tab->convert == 'X' ? str = ft_itoa_base(tab->u, "0123456789ABCDEF") : 0;
	tab->len = ft_strlen(str);
	str = ft_num_precision(str, tab);
	tab->len = ft_strlen(str);
	if (tab->u == 0 && tab->dot && tab->dot_len == 0
		&& !tab->width)
	{
		free(str);
		return ;
	}
	if (tab->u == 0 && tab->dot && tab->dot_len == 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	tab->hash && tab->u ? tab->len += 2 : 0;
	sp = ft_print_sp(tab);
	ft_join_all(str, sp, tab);
}

void	ft_con_p(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	tab->u = va_arg(ap, long unsigned);
	str = ft_itoa_base(tab->u, "0123456789abcdef");
	tab->dot ? tab->zero = 0 : 0;
	tab->len = ft_strlen(str);
	str = ft_num_precision(str, tab);
	tab->len = ft_strlen(str) + 2;
	if (tab->u == 0 && tab->dot && tab->dot_len == 0)
	{
		free(str);
		str = ft_strdup("");
		tab->len -= 1;
	}
	sp = ft_print_sp(tab);
	ft_join_all(str, sp, tab);
}
