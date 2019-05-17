/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:48:36 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/26 19:40:04 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			print_usage(void)
{
	write(1, "usage: ./ft_select [arg1] [arg2] [arg3] ...\n", 45);
	exit(EXIT_SUCCESS);
}

void			ft_select_interrupt(int exit_param)
{
	init_window(0);
	set_keypress(0);
	kill(getpid(), SIGTSTP);
}

void			ft_select_exit(int exit_param)
{
	init_window(0);
	set_keypress(0);
	exit(EXIT_SUCCESS);
}
