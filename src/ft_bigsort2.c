/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigsort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:23 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 14:59:24 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_part_count(t_stack *head, int item_flag)
{
	int	i;

	i = 0;
	while (head && head->flag == item_flag)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	ft_argv_3(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	int	first;
	int	second;
	int	third;
	int	min;

	first = (*b)->pos;
	second = (*b)->next->pos;
	third = (*b)->next->next->pos;
	min = first;
	if (second < min)
		min = second;
	if (third < min)
		min = third;
	if (min == second)
		ft_sb(b, oper);
	else if (min == third)
		ft_rrb(b, oper);
	ft_push_d(a, b, c, oper);
	if ((*b)->pos > (*b)->next->pos)
		ft_sb(b, oper);
	ft_push_d(a, b, c, oper);
	ft_push_d(a, b, c, oper);
}

void	ft_lessort(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	if ((*b) && ft_count(b) == 3)
		ft_argv_3(a, b, c, oper);
	else if ((*b) && ft_count(b) == 2)
	{
		if ((*b)->pos > (*b)->next->pos)
			ft_sb(b, oper);
		ft_push_d(a, b, c, oper);
		ft_push_d(a, b, c, oper);
	}
	else if ((*b) && ft_count(b) == 1)
		ft_push_d(a, b, c, oper);
}
