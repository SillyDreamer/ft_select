/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:29:18 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_comparator(unsigned char *s1, unsigned char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (!*s2)
		return (1);
	return (0);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_comparator((unsigned char *)haystack, (unsigned char*)needle))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
