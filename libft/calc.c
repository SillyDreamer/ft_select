/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:15:05 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				calc(char *expr)
{
	int		result;
	t_dcl	*t_expr;

	if (ft_check_brackets(expr) == 0)
	{
		write(1, "BAD BRACKETS! ", 14);
		return (0);
	}
	t_expr = make_rpn(expr);
	dcl_begin(&t_expr);
	result = dcl_rpn(t_expr);
	return (result);
}
