/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcl_rpn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:42:22 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					dcl_is_nu(t_dcl *elem)
{
	if (!(elem->c))
		return (1);
	return (0);
}

static int					dcl_prev_nu(t_dcl *elem)
{
	while (elem)
	{
		if (dcl_is_nu(elem))
		{
			elem->c = '!';
			return (elem->n);
		}
		elem = elem->previous;
	}
	return (0);
}

static void					dcl_oper(int *a, int *b, t_dcl **elem, char oper)
{
	*a = dcl_prev_nu(*elem);
	*b = dcl_prev_nu(*elem);
	(*elem)->c = '\0';
	if (oper == '-')
		(*elem)->n = *b - *a;
	else if (oper == '/')
		(*elem)->n = *b / *a;
	else if (oper == '+')
		(*elem)->n = *b + *a;
	else if (oper == '*')
		(*elem)->n = *b * *a;
}

int							dcl_rpn(t_dcl *elem)
{
	int		a;
	int		b;

	while (elem)
	{
		if (!(dcl_is_nu(elem)))
		{
			if (elem->c == '+')
				dcl_oper(&a, &b, &elem, '+');
			else if (elem->c == '-')
				dcl_oper(&a, &b, &elem, '-');
			else if (elem->c == '/')
				dcl_oper(&a, &b, &elem, '/');
			else if (elem->c == '*')
				dcl_oper(&a, &b, &elem, '*');
		}
		if (!(elem->next))
			return (elem->n);
		elem = elem->next;
	}
	return (0);
}
