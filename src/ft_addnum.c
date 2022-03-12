/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:11 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 14:59:12 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_addnum(t_stack **stack, int num)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		ft_putstr("Error");
		exit(0);
	}
	new->next = NULL;
	new->number = num;
	new->pos = 0;
	if (*stack == NULL)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
