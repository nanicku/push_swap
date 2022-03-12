/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_45.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:44 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 14:59:45 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_45(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	ft_mid_element(*a, c, ft_count(a));
	while (ft_count(a) > 3)
	{
		if ((*a)->pos < (*c)->mid)
			ft_pb(a, b, oper);
		else
			ft_ra(a, oper);
	}
	if (*b && (*b)->next && (*b)->pos < (*b)->next->pos)
		ft_sb(b, oper);
	ft_sortthree(a, oper);
	while (*b)
		ft_pa(a, b, oper);
}
