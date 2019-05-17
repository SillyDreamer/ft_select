/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_brackets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:35:52 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char		opposite_bracket(char c)
{
	if (c == ')')
		return ('(');
	else if (c == ']')
		return ('[');
	else if (c == '}')
		return ('{');
	return ('\0');
}

int				ft_check_brackets(char *str)
{
	t_list *stack;
	t_list *stack2;

	stack = ft_lstnew_unsafe(NULL, 0);
	while (*str)
	{
		if ((*str == '(') || (*str == '[') || (*str == '{'))
		{
			stack2 = ft_lstnew_unsafe((void *)str, 0);
			stack2->next = stack;
			stack = stack2;
		}
		else if (*str == ')')
		{
			if (*((char *)stack->content) == opposite_bracket(*str))
				stack = stack->next;
			else
				return (0);
		}
		str++;
	}
	if (stack->content == NULL)
		return (1);
	return (0);
}
