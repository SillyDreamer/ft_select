/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:23:01 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	int		i;

	if (!s)
		return (NULL);
	s += start;
	i = 0;
	if ((new_s = (char *)malloc(len + 1)))
	{
		while (len)
		{
			new_s[i] = *s;
			i++;
			s++;
			len--;
		}
		new_s[i] = 0;
		return (new_s);
	}
	else
		return (NULL);
}
