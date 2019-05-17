/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:41:38 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/02/26 12:48:24 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfreeone(t_list **alst)
{
	if (!(alst && *alst))
		return ;
	(*alst)->content_size = 0;
	free((*alst)->content);
	free(*alst);
	*alst = 0;
}
