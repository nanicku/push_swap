/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:01:42 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:01:43 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				pos;
	int				flag;
	struct s_stack	*next;
}					t_stack;

typedef struct s_operat
{
	char			*oper;
	struct s_operat	*next;
	struct s_operat	*prew;
	struct s_operat	*head;
}				t_operat;

typedef struct s_assist
{
	int				mid;
	int				mid_count;
	int				kol;
	int				elem_count;
	int				flag;
	int				n;
	int				rev_count;
}				t_assist;

int			ft_checksort(t_stack **stack);
void		ft_sorter(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);
void		error(void);
void		ft_addnum(t_stack **stack, int num);
int			ft_count(t_stack **stack);
int			ft_stack_clean(t_stack *a, t_stack *b, t_assist *c);
void		ft_error(t_stack *a, t_stack *b, t_assist *c);
int			ft_max_element(t_stack *a);
void		ft_mid_element(t_stack *a, t_assist **c, int n);
void		ft_sort_45(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);
t_operat	*new_oper(char *new);
void		next_oper(t_operat **oper, t_operat *new);
void		opt_operations(t_operat **oper);
void		ft_pa(t_stack **a, t_stack **b, t_operat **oper);
void		ft_pb(t_stack **a, t_stack **b, t_operat **oper);
void		ft_rra(t_stack **a, t_operat **oper);
void		ft_rrb(t_stack **b, t_operat **oper);
void		ft_rrr(t_stack **a, t_stack **b, t_operat **oper);
void		ft_ra(t_stack **a, t_operat **oper);
void		ft_rb(t_stack **b, t_operat **oper);
void		ft_rr(t_stack **a, t_stack **b, t_operat **oper);
void		ft_sa(t_stack **a, t_operat **oper);
void		ft_sb(t_stack **b, t_operat **oper);
void		ft_ss(t_stack **a, t_stack **b, t_operat **oper);
void		ft_sortthree(t_stack **stack, t_operat **oper);
void		ft_smsort(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);
void		checkerror(char **argv);
void		parser(char **argv, t_stack **stack);
void		ft_change(int *a, int *b);
int			*get_arr(int *arr, t_stack **stack);
t_stack		*ft_get_pos(t_stack **stack, int *arr, int n);
void		ft_quick_sorting(int *number, int first, int last);
void		ft_st_cut(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);
void		ft_b_proc(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);
void		ft_bigsort(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);
void		ft_push_d(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);
int			ft_part_count(t_stack *head, int item_flag);
void		ft_fl_zero(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);
void		ft_lessort(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);
void		ft_argv_3(t_stack **a, t_stack **b, t_assist **c, t_operat **oper);

#endif
