/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 04:40:33 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/27 03:07:06 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_arg		*to_first_arg(t_arg *node)
{
	while (!node->is_begin)
		node = node->next;
	return (node);
}

t_arg		*new_t_arg(char *name)
{
	t_arg	*new;

	new = (t_arg *)malloc(sizeof(t_arg));
	new->prev = NULL;
	new->next = NULL;
	new->namelen = ft_strlen(name);
	new->name = ft_strcpy(ft_strnew(new->namelen), name);
	new->col = 1;
	new->is_selected = 0;
	new->is_current = 0;
	return (new);
}

void		free_t_arg(t_arg *arg)
{
	free(arg->name);
	free(arg);
}

t_arg		*delete_t_arg(t_arg *arg)
{
	t_arg	*copy;
	t_arg	*tmp;

	ft_putstr_fd(tgetstr("cl", 0), 0);
	if (!(arg))
		ft_select_exit(1);
	if (arg->is_begin == 1)
	{
		tmp = arg->next;
		arg->next->is_begin = 1;
		while (tmp != arg)
		{
			tmp->row--;
			tmp = tmp->next;
		}
	}
	arg->prev->next = arg->next;
	(arg)->next->prev = arg->prev;
	arg = arg->next == arg ? NULL : arg->next;
	arg ? arg->is_current = 1 : 0;
	copy = arg;
	arg ? print_all_args(arg) : ft_select_exit(1);
	return (copy);
}

t_arg		*make_t_arg_lst(char **args, char *cur_dir)
{
	t_arg	*node;
	t_arg	*node_cpy;
	int		i;

	if (!args)
		return (NULL);
	i = 0;
	node = new_t_arg(args[i]);
	node->row = i;
	node_cpy = node;
	node->is_current = 1;
	node->is_begin = 1;
	i++;
	while (args[i])
	{
		node->next = new_t_arg(args[i]);
		node->next->prev = node;
		node = node->next;
		node->row = i;
		i++;
	}
	node->next = node_cpy;
	node->next->prev = node;
	return (node_cpy);
}
