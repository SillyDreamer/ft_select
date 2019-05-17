/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:16:55 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/02/26 07:33:23 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstfree(t_list **alst)
{
	t_list	*tmp;

	if (!(alst && *alst))
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstfreeone(&(*alst));
		*alst = tmp;
	}
	*alst = 0;
}
