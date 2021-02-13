/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:36:17 by saluru            #+#    #+#             */
/*   Updated: 2021/01/26 14:25:39 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*tab;
	int		temp;

	i = 0;
	tab = malloc(size * count);
	temp = size * count;
	while (temp-- > 0)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
