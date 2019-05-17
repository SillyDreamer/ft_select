/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:34:34 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/27 04:14:22 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <term.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <signal.h>

/*
**	Defines of needed keys.
*/

# define KEY_BACKSPACE		127
# define KEY_DEL			2117294875
# define KEY_LEFT			4479771
# define KEY_UP				4283163
# define KEY_RIGHT			4414235
# define KEY_DOWN			4348699
# define KEY_ESC			27
# define KEY_TAB			9
# define KEY_SPC			32
# define KEY_ENTER			10

/*
**	Defines of tgetstr arguments
**
** 	so - highlight start
** 	se - highlight end
** 	cl  -screen eraser
** 	cm - cursor change
** 	vi - invisible cursor
** 	ve - visible cursor
** 	ti - begin of terminal
**	te - end of terminal
*/

# define SO (tgetstr("so", NULL))
# define SE (tgetstr("se", NULL))
# define CL (tgetstr("cl", NULL))
# define CM (tgetstr("cm", NULL))
# define VE (tgetstr("ve", NULL))
# define VI (tgetstr("vi", NULL))
# define US (tgetstr("us", NULL))
# define TE (tgetstr("te", NULL))
# define TI (tgetstr("ti", NULL))

typedef struct dirent		t_dirent;

/*
**			t_arg (aka struct s_arg):
**
**			col, row - coordinates at the output
** 			type: 0 - usual file or smth else, 1 - directory,
** 			2 - binary, 3 - symlink
**			is_selected - flag of the
*/

typedef struct s_arg		t_arg;

struct		s_arg
{
	t_arg	*prev;
	t_arg	*next;

	int		col;
	int		row;
	int		type;
	int		is_selected;
	int		is_current;
	int		is_begin;
	int		namelen;
	char	*name;
};

t_arg		*to_first_arg(t_arg *node);
t_arg		*make_t_arg_lst(char **args, char *cur_dir);
void		print_all_args_handler(int n);

int			is_key_navigation(long key);
void		space_command(t_arg *node);
void		init_window(int status);
void		set_keypress(int status);

t_arg		*delete_t_arg(t_arg *arg);
void		print_arg(t_arg *arg);
void		print_all_args(t_arg *arg);
void		move_arg(t_arg **arg, long direction);
int			t_arg_resize(t_arg *node);

void		ft_select_exit(int exit_param);
void		ft_select_interrupt(int exit_param);
void		print_usage(void);

char		**read_directory(char *path);
void		return_value(t_arg *arg);

void		restart(int n);
void		suspend(int s);
void		signal_handler(void);

#endif
