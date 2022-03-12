/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:52 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:05:44 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sorter(t_stack **a, t_stack **b, t_assist **c, t_operat **oper)
{
	if (ft_count(a) < 6)
	{
		ft_smsort(a, b, c, oper);
		while ((*oper)->next)
			opt_operations(oper);
		ft_putstr((*oper)->oper);
		return ;
	}
	else
	{
		ft_bigsort(a, b, c, oper);
		while ((*oper)->next)
			opt_operations(oper);
		ft_putstr((*oper)->oper);
		return ;
	}
}		

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_assist	*c;
	t_operat	*oper;

	a = NULL;
	b = NULL;
	oper = NULL;
	if (argc < 2)
		return (0);
	c = malloc(sizeof(t_assist));
	if (!c)
		ft_error(a, b, c);
	checkerror(argv);
	parser(argv, &a);
	if (ft_checksort(&a))
		return (0);
	c->n = argc - 1;
	c->kol = 1;
	c->flag = 0;
	c->elem_count = ft_count(&a);
	ft_sorter(&a, &b, &c, &oper);
	return (0);
}
