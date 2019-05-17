/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:54:43 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/27 04:14:16 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

char		**read_directory(char *path)
{
	DIR			*fd;
	t_dirent	*ret;
	char		**new;
	int			i;

	i = 0;
	new = (char**)malloc(sizeof(char*) * 500);
	if (!(fd = opendir(path)))
		return (NULL);
	while ((ret = readdir(fd)))
	{
		if (!ft_strnequ(ret->d_name, ".", 1))
		{
			new[i] = ft_strdup(ret->d_name);
			i++;
		}
	}
	if (!i)
	{
		closedir(fd);
		return (NULL);
	}
	return (new);
}

void		return_value(t_arg *arg)
{
	if (!arg)
		return ;
	init_window(0);
	set_keypress(0);
	while (arg->is_begin != 1)
		arg = arg->next;
	if (arg->is_selected)
	{
		ft_putstr_fd(arg->name, 0);
		write(1, " ", 1);
	}
	arg = arg->next;
	while (arg->is_begin == 0)
	{
		if (arg->is_selected)
		{
			ft_putstr_fd(arg->name, 0);
			write(1, " ", 1);
		}
		arg = arg->next;
	}
	exit(EXIT_SUCCESS);
}
