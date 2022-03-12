/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:17 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 14:59:18 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_st_cut(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	int	i;

	ft_mid_element(*a, c, ft_part_count(*a, 0));
	i = 0;
	while (i < (*c)->mid_count)
	{
		if ((*a)->pos <= (*c)->mid)
		{
			ft_pb(a, b, oper);
			i++;
		}
		else
		{
			ft_ra(a, oper);
			(*c)->rev_count++;
		}
	}
}

void	ft_b_proc(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	int	item_flag;
	int	i;

	if (!(*b))
		return ;
	(*c)->mid = (ft_max_element(*b) + (*c)->kol) / 2;
	(*c)->flag++;
	i = 0;
	item_flag = (*b)->flag;
	while ((*b) && (*b)->flag == item_flag)
	{
		(*b)->flag = (*c)->flag;
		if ((*b)->pos == (*c)->kol)
			ft_push_d(a, b, c, oper);
		else if ((*b)->pos >= (*c)->mid)
			ft_pa(a, b, oper);
		else
			ft_rb(b, oper);
		i++;
	}
	ft_lessort(a, b, c, oper);
	ft_b_proc(a, b, c, oper);
}

void	ft_fl_zero(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	int	i;

	(*c)->rev_count = 0;
	ft_st_cut(a, b, c, oper);
	i = 0;
	while (i++ < (*c)->rev_count)
		ft_rra(a, oper);
	ft_b_proc(a, b, c, oper);
}

void	ft_bigsort(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	int		item_flag;

	ft_st_cut(a, b, c, oper);
	ft_b_proc(a, b, c, oper);
	while (!ft_checksort(a) || ft_count(a) != (*c)->elem_count)
	{
		if (!(*a)->flag)
			ft_fl_zero(a, b, c, oper);
		item_flag = (*a)->flag;
		while ((*a)->pos != 1 && (*a)->flag != 0 && (*a)->flag == item_flag)
		{
			if ((*a)->next && (*a)->next->pos == (*c)->kol)
				ft_sa(a, oper);
			if ((*a)->pos == (*c)->kol)
			{
				(*a)->flag = -1;
				ft_ra(a, oper);
				(*c)->kol++;
			}
			else
				ft_pb(a, b, oper);
		}
		ft_b_proc(a, b, c, oper);
	}
}

void	ft_push_d(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	(*b)->flag = -1;
	ft_pa(a, b, oper);
	ft_ra(a, oper);
	(*c)->kol++;
}
