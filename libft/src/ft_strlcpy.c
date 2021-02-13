/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:50:36 by saluru            #+#    #+#             */
/*   Updated: 2021/01/23 11:42:37 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t s)
{
	unsigned int		i;
	size_t				len;

	i = 0;
	len = 0;
	if (!dest || !src)
		return (0);
	if (s > 0)
	{
		while (src[i] && --s)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[len])
		len++;
	return (len);
}
