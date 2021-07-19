/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 21:20:46 by user42            #+#    #+#             */
/*   Updated: 2021/07/19 19:51:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"

void	ft_put_move(t_move *lst)
{
	int		i;

	i = 0;
	if (lst == NULL)
		ft_printf("NULL\n");
	while (lst)
	{
		ft_printf("move %i : |%s|\n", i, lst->move);
		i++;
		lst = lst->next;
	}
	ft_printf("\n");
}

void	ft_put_stack(t_stack *lst)
{
	int		i;

	i = 0;
	if (!lst)
		ft_printf("premier element à NULL\n");
	while (lst)
	{
		ft_printf("elem %i : |%i|\n", i, lst->nb);
		i++;
		lst = lst->next;
	}
}

void	ft_put_pusw(t_pusw *ptr)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ft_printf("Move :\n");
	ft_put_move(ptr->mv);
	tmp_a = A;
	tmp_b = B;
	ft_printf("\t%6c\t%6c\n", 'A', 'B');
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			ft_printf("\t%6i", tmp_a->nb);
			tmp_a = tmp_a->next;
		}
		else
			ft_printf("\t%6s", "");
		if (tmp_b)
		{
			ft_printf("\t%6i\n", tmp_b->nb);
			tmp_b = tmp_b->next;
		}
		else
			ft_printf("\t%6s\n", "");
	}
	ft_printf("\n");
}