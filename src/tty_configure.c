/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_configure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:36:45 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/27 02:50:00 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void			set_keypress(int status)
{
	static struct termios	stored_settings;
	static struct termios	new_settings;
	static int				used = 0;

	if (!used)
	{
		used++;
		tcgetattr(0, &stored_settings);
	}
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	if (status)
		tcsetattr(0, TCSANOW, &new_settings);
	else if (!status)
		tcsetattr(0, TCSANOW, &stored_settings);
}

void			init_window(int status)
{
	char	buf[1024];
	char	*termtype;
	int		ok;

	termtype = getenv("TERM");
	ok = tgetent(buf, termtype);
	if (status == 1)
	{
		ft_putstr(VI);
		ft_putstr(VI);
	}
	else
	{
		ft_putstr(TE);
		ft_putstr(VE);
	}
	ft_putstr(CL);
}

void			restart(int n)
{
	char					buf[1024];
	char					buf2[2];
	static struct termios	stored_settings;
	static struct termios	new_settings;

	tgetent(buf, getenv("TERM"));
	tcgetattr(0, &stored_settings);
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings);
	ft_putstr(VI);
	ft_putstr(VI);
	buf2[0] = -62;
	buf2[1] = 0;
	print_all_args_handler(1);
	ioctl(0, TIOCSTI, buf2);
}

void			suspend(int s)
{
	struct termios	t_attr;
	char			susp[2];

	(void)s;
	if (tcgetattr(0, &t_attr) == -1)
		exit(1);
	susp[0] = t_attr.c_cc[VSUSP];
	susp[1] = 0;
	t_attr.c_lflag |= ICANON;
	t_attr.c_lflag |= ECHO;
	t_attr.c_oflag |= OPOST;
	if (tcsetattr(0, TCSADRAIN, &t_attr) == -1)
		exit(1);
	ft_putstr(TE);
	ft_putstr(VE);
	signal(SIGTSTP, SIG_DFL);
	ft_putstr(CL);
	ioctl(0, TIOCSTI, susp);
}

void			signal_handler(void)
{
	signal(SIGINT, ft_select_exit);
	signal(SIGWINCH, print_all_args_handler);
	signal(SIGTSTP, suspend);
	signal(SIGCONT, restart);
}
