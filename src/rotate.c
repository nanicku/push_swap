/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:00:32 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:00:33 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*count;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	count = (*stack);
	while (count->next)
		count = count->next;
	count->next = tmp;
	tmp->next = NULL;
}

void	ft_ra(t_stack **a, t_operat **oper)
{
	if (!(*a)->next)
		return ;
	ft_rotate(a);
	if (!*oper)
		*oper = new_oper("ra\n");
	else
		next_oper(oper, new_oper("ra\n"));
}

void	ft_rb(t_stack **b, t_operat **oper)
{
	if (!(*b)->next)
		return ;
	ft_rotate(b);
	if (!*oper)
		*oper = new_oper("rb\n");
	else
		next_oper(oper, new_oper("rb\n"));
}

void	ft_rr(t_stack **a, t_stack **b, t_operat **oper)
{
	if (*a == NULL || (*a)->next == NULL || \
		*b == NULL || (*b)->next == NULL)
		return ;
	ft_ra(a, oper);
	ft_rb(b, oper);
}
