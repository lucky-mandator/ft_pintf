/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saluru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:47:12 by saluru            #+#    #+#             */
/*   Updated: 2021/01/21 11:44:07 by saluru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_operator(char c)
{
	if (c == '-')
		return (1);
	else if (c == '+')
		return (2);
	else
		return (0);
}

static int	is_space(char c)
{
	if (((c == '\t' || c == '\n') || c == '\v') ||
			((c == '\f' || c == '\r') || c == 32))
	{
		return (1);
	}
	return (0);
}

static int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int	result;
	int	operator;

	result = 0;
	operator = 1;
	while (is_space(*str))
		str++;
	if (is_operator(*str))
	{
		if (is_operator(*str) == 1)
			operator = -1;
		str++;
	}
	while (is_number(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * operator);
}
