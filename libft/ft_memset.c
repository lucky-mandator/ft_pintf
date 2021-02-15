/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:44:54 by saluru            #+#    #+#             */
/*   Updated: 2021/01/16 12:41:34 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int letter, size_t size)
{
	unsigned char	*str;

	str = dest;
	while (size-- > 0)
		*str++ = letter;
	return (dest);
}
