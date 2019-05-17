/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:59:56 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/26 07:33:23 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*new_s;
	char	*new_s_copy;

	if ((!s1) || (!s2))
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (!(new_s = (char *)malloc(len_1 + len_2 + 1)))
		return (NULL);
	new_s_copy = new_s;
	while (*s1)
	{
		*new_s++ = *s1;
		s1++;
	}
	while (*s2)
	{
		*new_s = *s2;
		s2++;
		new_s++;
	}
	*new_s = 0;
	return (new_s_copy);
}
