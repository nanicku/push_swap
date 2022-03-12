/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:57 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 14:59:58 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = (*src);
	(*src) = tmp;
}

void	ft_pa(t_stack **a, t_stack **b, t_operat **oper)
{
	if (!*b)
		return ;
	ft_push(a, b);
	if (!*oper)
		*oper = new_oper("pa\n");
	else
		next_oper(oper, new_oper("pa\n"));
}

void	ft_pb(t_stack **a, t_stack **b, t_operat **oper)
{
	if (!*a)
		return ;
	ft_push(b, a);
	if (!*oper)
		*oper = new_oper("pb\n");
	else
		next_oper(oper, new_oper("pb\n"));
}
