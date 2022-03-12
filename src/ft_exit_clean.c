/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:32 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 14:59:33 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stack_clean(t_stack *a, t_stack *b, t_assist *c)
{
	t_stack		*temp;

	temp = 0;
	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	while (b)
	{
		temp = b->next;
		free(b);
		b = temp;
	}
	if (temp)
		free(temp);
	if (c)
		free(c);
	return (0);
}

void	ft_error(t_stack *a, t_stack *b, t_assist *c)
{
	write(2, "Error\n", 6);
	ft_stack_clean(a, b, c);
	exit(0);
}
