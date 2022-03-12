/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:00:58 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:00:59 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*get_arr(int *arr, t_stack **stack)
{
	int		j;
	t_stack	*tmp1;

	j = 0;
	arr = malloc(sizeof(int) * ft_count(stack));
	if (!arr)
	{
		ft_putstr("Error");
		exit(0);
	}
	tmp1 = *stack;
	while (tmp1)
	{
		arr[j++] = tmp1->number;
		tmp1 = tmp1->next;
	}
	return (arr);
}

t_stack	*ft_get_pos(t_stack **stack, int *arr, int n)
{
	int		i;
	t_stack	*temp;

	ft_quick_sorting(arr, 0, n - 1);
	temp = *stack;
	while (temp)
	{
		i = 0;
		while (i < n)
		{
			if (temp->number == arr[i])
			{
				temp->pos = i + 1;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
	free(arr);
	return (*stack);
}

void	ft_quick_sorting(int *number, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{	
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
				ft_change(&number[i], &number[j]);
		}
		ft_change(&number[pivot], &number[j]);
		ft_quick_sorting(number, first, j - 1);
		ft_quick_sorting(number, j + 1, last);
	}
}

void	ft_change(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_checksort(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->next && tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
