/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:52:16 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	sub_l;

	if (str == sub || *sub == '\0' || !(sub_l = ft_strlen(sub)))
		return ((char*)(str));
	while (*str && len-- >= sub_l)
	{
		if ((*str == *sub) && ft_strncmp(str, sub, sub_l) == 0)
			return ((char*)str);
		str++;
	}
	return (0);
}
