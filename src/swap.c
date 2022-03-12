/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:00:46 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:00:47 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	ft_sa(t_stack **a, t_operat **oper)
{
	if (!(*a)->next)
		return ;
	ft_swap(a);
	if (!*oper)
		*oper = new_oper("sa\n");
	else
		next_oper(oper, new_oper("sa\n"));
}

void	ft_sb(t_stack **b, t_operat **oper)
{
	if (!(*b)->next)
		return ;
	ft_swap(b);
	if (!*oper)
		*oper = new_oper("sb\n");
	else
		next_oper(oper, new_oper("sb\n"));
}

void	ft_ss(t_stack **a, t_stack **b, t_operat **oper)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	ft_sa(a, oper);
	ft_sb(b, oper);
}
