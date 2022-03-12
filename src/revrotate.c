/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:00:15 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:00:16 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_revrotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*count;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	count = (*stack);
	while (count->next->next)
		count = count->next;
	tmp = count->next;
	count->next = NULL;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	ft_rra(t_stack **a, t_operat **oper)
{
	if (!(*a)->next)
		return ;
	ft_revrotate(a);
	if (!*oper)
		*oper = new_oper("rra\n");
	else
		next_oper(oper, new_oper("rra\n"));
}

void	ft_rrb(t_stack **b, t_operat **oper)
{
	if (!(*b)->next)
		return ;
	ft_revrotate(b);
	if (!*oper)
		*oper = new_oper("rrb\n");
	else
		next_oper(oper, new_oper("rrb\n"));
}

void	ft_rrr(t_stack **a, t_stack **b, t_operat **oper)
{
	if (*a == NULL || (*a)->next == NULL || \
		*b == NULL || (*b)->next == NULL)
		return ;
	ft_rra(a, oper);
	ft_rrb(b, oper);
}
