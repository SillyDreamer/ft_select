/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:26:07 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*my_dst;
	const unsigned char		*my_src;

	if (!dst && !src)
		return (NULL);
	my_dst = (unsigned char *)dst;
	my_src = (unsigned char *)src;
	if (my_src < my_dst)
	{
		while (len)
		{
			len--;
			*(my_dst + len) = *(my_src + len);
		}
	}
	else if (my_dst < my_src)
		ft_memcpy(dst, src, len);
	return (dst);
}
