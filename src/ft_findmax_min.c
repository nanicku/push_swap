/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmax_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:37 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 14:59:38 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max_element(t_stack *a)
{
	int		max;

	max = a->pos;
	while (a)
	{
		if (a->pos > max)
			max = a->pos;
		a = a->next;
	}
	return (max);
}

void	ft_mid_element(t_stack *a, t_assist **c, int n)
{
	int		sum;
	t_stack	*temp;
	int		i;

	sum = 0;
	i = 0;
	temp = a;
	if (!c || !a)
		return ;
	while (i < n)
	{
		sum += temp->pos;
		i++;
		temp = temp->next;
	}
	(*c)->mid = sum / n;
	temp = a;
	i = 0;
	(*c)->mid_count = 0;
	while (i++ < n)
	{
		if (temp->pos <= (*c)->mid)
			(*c)->mid_count++;
		temp = temp->next;
	}
}
