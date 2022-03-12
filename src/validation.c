/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:00:51 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:00:52 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_dup(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
				error();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	checkerror(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_strchr("0123456789- ", argv[i][j])
				|| (j > 0 && argv[i][j] == '-' && argv[i][j - 1] != ' ')
				|| (argv[i][j] == '-' && ft_isalpha(argv[i][j + 1])))
				error();
			j++;
		}
		i++;
	}
}

static void	convert_arg(char **tmp, t_stack **stack)
{
	int		i;
	int		res;
	char	*str;

	i = 0;
	while (tmp[i])
	{
		res = ft_atoi((tmp)[i]);
		str = ft_itoa(res);
		if (ft_strncmp(str, tmp[i], ft_strlen(tmp[i])))
			error();
		ft_addnum(stack, res);
		free(tmp[i]);
		free(str);
		i++;
	}
}

void	parser(char **argv, t_stack **stack)
{
	char	**tmp;
	int		i;
	int		*arr;

	arr = NULL;
	i = 1;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		convert_arg(tmp, stack);
		free(tmp);
		i++;
	}
	check_dup(stack);
	arr = get_arr(arr, stack);
	ft_get_pos(stack, arr, ft_count(stack));
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
