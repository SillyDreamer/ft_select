/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:26:18 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (*src && len)
	{
		dst[i] = *src;
		i++;
		src++;
		len--;
	}
	while (len)
	{
		dst[i] = 0;
		i++;
		len--;
	}
	return (dst);
}
