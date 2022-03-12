/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:21:00 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:07:05 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	action(char *line, t_stack **a, t_stack **b, t_operat **oper)
{
	if (!(ft_strcmp(line, "ra")))
		ft_ra(a, oper);
	else if (!(ft_strcmp(line, "rb")))
		ft_rb(b, oper);
	else if (!(ft_strcmp(line, "rr")))
		ft_rr(a, b, oper);
	else if (!(ft_strcmp(line, "sa")))
		ft_sa(a, oper);
	else if (!(ft_strcmp(line, "sb")))
		ft_sb(b, oper);
	else if (!(ft_strcmp(line, "ss")))
		ft_ss(a, b, oper);
	else if (!(ft_strcmp(line, "rra")))
		ft_rra(a, oper);
	else if (!(ft_strcmp(line, "rrb")))
		ft_rrb(b, oper);
	else if (!(ft_strcmp(line, "rrr")))
		ft_rrr(a, b, oper);
	else if (!(ft_strcmp(line, "pa")))
		ft_pa(a, b, oper);
	else if (!(ft_strcmp(line, "pb")))
		ft_pb(a, b, oper);
	else
		return (0);
	return (1);
}

static int	checker(t_stack **a, t_stack **b, t_operat **oper)
{
	char	*line;
	int		ret;

	line = "";
	ret = 0;
	while (get_next_line(0, &line) > 0)
	{
		ret = action(line, a, b, oper);
		if (ret == 0)
		{
			write(2, "Error\n", 6);
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}

static void	ft_oper_cl(t_operat *oper)
{
	t_operat	*temp;

	if (oper)
	{
		while (oper)
		{
			temp = oper->next;
			free(oper);
			oper = temp;
		}
		if (temp)
			free(temp);
	}
}

static void	result(t_stack *a, t_stack *b)
{
	if (a && ft_checksort(&a) && !b)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_assist	*c;
	t_operat	*oper;
	int			ret;

	a = NULL;
	b = NULL;
	oper = NULL;
	if (argc < 2)
		return (1);
	c = malloc(sizeof(t_assist));
	if (!c)
		return (0);
	checkerror(argv);
	parser(argv, &a);
	ret = checker(&a, &b, &oper);
	if (ret == 0)
		return (ft_stack_clean(a, b, c));
	result(a, b);
	if (b)
		return (ft_stack_clean(a, b, c));
	ft_stack_clean(a, b, c);
	ft_oper_cl(oper);
	return (0);
}
