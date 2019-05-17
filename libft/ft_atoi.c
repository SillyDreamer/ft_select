/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:37:48 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sign(long long num)
{
	if (num > 0)
		return (1);
	else if (num < 0)
		return (-1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long long	result;
	int			neg;

	result = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (ft_sign(result) * ft_sign((result * 10 + neg * (*str - '0'))) < 0)
			return (neg == 1 ? -1 : 0);
		result = result * 10 + neg * (*str - '0');
		str++;
	}
	return ((int)(result));
}
