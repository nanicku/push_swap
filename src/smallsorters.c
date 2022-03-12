/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsorters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:00:40 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:00:41 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	firstpos(t_stack **stack, t_operat **oper)
{
	ft_ra(stack, oper);
	ft_sa(stack, oper);
	ft_rra(stack, oper);
}

static void	secondpos(t_stack **stack, t_operat **oper)
{
	if ((*stack)->number < (*stack)->next->next->number)
		ft_sa(stack, oper);
	else
		ft_ra(stack, oper);
}

static void	thirdpos(t_stack **stack, t_operat **oper)
{
	if ((*stack)->number > (*stack)->next->number)
		ft_sa(stack, oper);
	ft_rra(stack, oper);
}

void	ft_sortthree(t_stack **stack, t_operat **oper)
{
	if (((*stack)->number < (*stack)->next->number)
		&& (*stack)->number < (*stack)->next->next->number
		&& !ft_checksort(stack))
		firstpos(stack, oper);
	else if (((*stack)->next->number < (*stack)->number)
		&& ((*stack)->next->number < (*stack)->next->next->number))
		secondpos(stack, oper);
	else if (!ft_checksort(stack))
		thirdpos(stack, oper);
}

void	ft_smsort(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	int	count;
	int	sorted;

	sorted = ft_checksort(a);
	count = ft_count(a);
	if (!sorted && count == 2)
		ft_sa(a, oper);
	else if (!sorted && count == 3)
		ft_sortthree(a, oper);
	else
		ft_sort_45(a, b, c, oper);
}
