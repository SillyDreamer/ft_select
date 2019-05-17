/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:44:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/26 19:30:43 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern char g_cur_dir[];

void	print_color(t_arg *arg)
{
	struct stat		buf;
	char			dir[2048];

	ft_strcpy(dir, g_cur_dir);
	ft_strcpy(dir + ft_strlen(dir), arg->name);
	lstat(dir, &buf);
	if (S_ISDIR(buf.st_mode))
	{
		ft_putstr_fd("\x1B[34m", 0);
		ft_putstr_fd(arg->name, 0);
		arg->type = 1;
	}
	else if (S_ISLNK(buf.st_mode))
	{
		ft_putstr_fd("\x1B[35m", 0);
		ft_putstr_fd(arg->name, 0);
	}
	else if (!access(arg->name, 1))
	{
		ft_putstr_fd("\x1B[31m", 0);
		ft_putstr_fd(arg->name, 0);
	}
	else
		ft_putstr_fd(arg->name, 0);
	ft_putstr_fd("\x1B[0m", 0);
}

void	print_arg(t_arg *arg)
{
	char buf[1024];

	if (!arg)
		return ;
	tgetent(buf, getenv("TERM"));
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), arg->col, arg->row), STDIN_FILENO);
	if (arg->is_current)
		ft_putstr_fd(tgetstr("us", NULL), 0);
	if (arg->is_selected)
		ft_putstr_fd(tgetstr("so", NULL), 0);
	print_color(arg);
	ft_putstr_fd(tgetstr("ue", NULL), 0);
	ft_putstr_fd(tgetstr("se", NULL), 0);
}

void	print_all_args(t_arg *arg)
{
	set_keypress(1);
	init_window(1);
	if (!arg)
		return ;
	if (!t_arg_resize(arg))
	{
		write(1, "plz make window bigger\n", 24);
		return ;
	}
	while (!arg->is_begin)
		arg = arg->next;
	print_arg(arg);
	arg = arg->next;
	while (!arg->is_begin)
	{
		print_arg(arg);
		arg = arg->next;
	}
}

void	move_arg(t_arg **arg, long direction)
{
	int		cur_row;

	cur_row = (*arg)->row;
	(*arg)->is_current = 0;
	print_arg(*arg);
	if (KEY_UP == direction)
		*arg = (*arg)->prev;
	else if (KEY_DOWN == direction)
		*arg = (*arg)->next;
	else if (KEY_RIGHT == direction)
	{
		*arg = (*arg)->next;
		while ((*arg)->row != cur_row)
			*arg = (*arg)->next;
	}
	else if (KEY_LEFT == direction)
	{
		*arg = (*arg)->prev;
		while ((*arg)->row != cur_row)
			*arg = (*arg)->prev;
	}
	(*arg)->is_current = 1;
	print_arg(*arg);
}
