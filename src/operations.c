/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:05:32 by mshad             #+#    #+#             */
/*   Updated: 2021/10/06 12:21:20 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_operat	*new_oper(char *new)
{
	t_operat	*first;

	first = (t_operat *)malloc(sizeof(t_operat));
	first->oper = new;
	first->head = first;
	first->next = NULL;
	first->prew = NULL;
	return (first);
}

void	next_oper(t_operat **oper, t_operat *new)
{
	t_operat	*head;

	if (*oper && oper)
	{
		head = *oper;
		while (head->next)
			head = head->next;
		head->next = new;
		new->next = NULL;
		new->prew = head;
		(*oper)->head = head;
	}
}

static void	sokr(char *s, t_operat **oper)
{
	ft_putstr(s);
	*oper = (*oper)->next->next;
}

void	opt_operations(t_operat **oper)
{
	if ((!ft_strncmp((*oper)->oper, "sa\n", 3) \
		&& !ft_strncmp((*oper)->next->oper, "sb\n", 3)) \
		|| (!ft_strncmp((*oper)->oper, "sb\n", 3) \
		&& !ft_strncmp((*oper)->next->oper, "sa\n", 3)))
		sokr("ss\n", oper);
	else if ((!ft_strncmp((*oper)->oper, "ra\n", 3) \
		&& !ft_strncmp((*oper)->next->oper, "rb\n", 3)) \
		|| (!ft_strncmp((*oper)->oper, "rb\n", 3) && \
		!ft_strncmp((*oper)->next->oper, "ra\n", 3)))
		sokr("rr\n", oper);
	else if ((!ft_strncmp((*oper)->oper, "rra\n", 3) \
		&& !ft_strncmp((*oper)->next->oper, "rrb\n", 3)) \
		|| (!ft_strncmp((*oper)->oper, "rrb\n", 3) \
		&& !ft_strncmp((*oper)->next->oper, "rra\n", 3)))
	{
		ft_putstr("rrr\n");
		*oper = (*oper)->next->next;
	}
	else
	{
		ft_putstr((*oper)->oper);
		*oper = (*oper)->next;
	}
}
