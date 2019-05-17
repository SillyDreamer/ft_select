/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:40:44 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/26 19:41:25 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			is_key_navigation(long key)
{
	if (key == KEY_DOWN || key == KEY_UP ||
			key == KEY_RIGHT || key == KEY_LEFT)
		return (1);
	return (0);
}

void		space_command(t_arg *node)
{
	node->is_selected = ~node->is_selected;
	print_arg(node);
}
