/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rpn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:51:47 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 09:48:27 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			priority(char c)
{
	if (c == '-')
		return (1);
	else if (c == '+')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (2);
	else if (c == '^')
		return (3);
	return (-1);
}

static void			right_bracket(t_dcl **stack, t_dcl **output_rpn)
{
	while ((*stack)->c != '(' && (*stack)->previous)
	{
		dcl_push_back(output_rpn, dcl_creator((*stack)->c, -1));
		*stack = (*stack)->previous;
	}
	*stack = (*stack)->previous;
	(*stack)->next = NULL;
}

static void			operand_block(t_dcl **stack, t_dcl **output_rpn, char *str)
{
	while (ft_isoperand((*stack)->c) && \
			((priority((*stack)->c) > priority(*str)) || \
			((priority((*stack)->c == priority(*str))) && \
			(is_left_orient((*stack)->c)))))
	{
		dcl_push_back(output_rpn, dcl_creator((*stack)->c, -1));
		*stack = (*stack)->previous;
	}
	(*stack)->next = NULL;
	dcl_push_back(stack, dcl_creator(*str, -1));
	dcl_end(stack);
}

static void			last_block(t_dcl **stack, t_dcl **output_rpn)
{
	dcl_end(stack);
	while ((*stack)->previous)
	{
		dcl_push_back(output_rpn, dcl_creator((*stack)->c, -1));
		*stack = (*stack)->previous;
	}
	dcl_begin(output_rpn);
}

t_dcl				*make_rpn(char *str)
{
	t_dcl		*output_rpn;
	t_dcl		*stack;

	output_rpn = dcl_creator('?', 0);
	stack = dcl_creator('!', 0);
	while (*str)
	{
		if (*str == '(')
		{
			dcl_push_back(&stack, dcl_creator('(', -1));
			dcl_end(&stack);
		}
		else if (*str == ')')
			right_bracket(&stack, &output_rpn);
		else if (('0' <= *str) && (*str <= '9'))
			dcl_push_back(&output_rpn, dcl_creator('\0', *str - '0'));
		else if (ft_isoperand(*str))
			operand_block(&stack, &output_rpn, str);
		str++;
	}
	last_block(&stack, &output_rpn);
	return (output_rpn);
}
