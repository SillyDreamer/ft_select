/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 05:37:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/27 04:12:18 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_arg		*g_lst;
char		g_cur_dir[2048] = "./";

void			print_all_args_handler(int n)
{
	print_all_args(g_lst);
}

static void		prompt(int ac, char **av)
{
	struct ttysize	ts;
	int				start_loading_col;

	ioctl(0, TIOCGSIZE, &ts);
	start_loading_col = ts.ts_cols / 2 - ts.ts_cols / 8;
	if (ac < 2)
		print_usage();
	set_keypress(1);
	init_window(1);
	ft_putstr_fd(tgoto(CM, start_loading_col, ts.ts_lines / 2), STDIN_FILENO);
	while (start_loading_col < ts.ts_cols / 2 + ts.ts_cols / 8)
	{
		usleep(20000);
		write(1, "*", 1);
		start_loading_col++;
	}
	g_lst = make_t_arg_lst(av + 1, NULL);
	print_all_args(g_lst);
}

static void		tab_command(void)
{
	char	**mas;

	if (!g_lst)
		return ;
	ft_strcat(g_cur_dir, g_lst->name);
	if (access(g_cur_dir, 4) == 0 && g_lst->type == 1)
	{
		mas = read_directory(g_cur_dir);
		g_lst = make_t_arg_lst(mas, NULL);
		ft_strcat(g_cur_dir, "/");
		print_all_args(g_lst);
	}
	else
		g_cur_dir[ft_strlen(g_cur_dir) - ft_strlen(g_lst->name)] = 0;
}

static void		backspace_command(void)
{
	char	**mas;

	ft_strcat(g_cur_dir, "..");
	mas = read_directory(g_cur_dir);
	g_lst = make_t_arg_lst(mas, NULL);
	ft_strcat(g_cur_dir, "/");
	print_all_args(g_lst);
}

int				main(int ac, char **av, char **en)
{
	long	key;

	signal_handler();
	prompt(ac, av);
	while (1)
	{
		set_keypress(1);
		key = 0;
		read(STDIN_FILENO, &key, 8);
		if (key == KEY_ESC)
			ft_select_exit(1);
		else if (is_key_navigation(key))
			move_arg(&g_lst, key);
		else if (key == KEY_SPC)
			space_command(g_lst);
		else if (key == KEY_TAB)
			tab_command();
		else if (key == KEY_BACKSPACE)
			backspace_command();
		else if (key == KEY_DEL)
			g_lst = delete_t_arg(g_lst);
		else if (key == KEY_ENTER)
			return_value(g_lst);
	}
}
