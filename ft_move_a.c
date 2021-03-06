/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:08:15 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 17:44:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_sa(t_pusw *ptr)
{
	t_stack	*second;
	t_stack	*first;
	t_stack	*third;

	if (!ptr->a || !ptr->a->next)
		return (CHECK_ERR);
	second = ptr->a;
	first = ptr->a->next;
	third = ptr->a->next->next;
	ptr->a = first;
	ptr->a->next = second;
	ptr->a->next->next = third;
	if (third && third->next == NULL)
		ptr->last_a = third;
	return (CHECK_OK);
}

int	ft_pa(t_pusw *ptr)
{
	t_stack	*tmp;

	if (!ptr->b)
		return (CHECK_ERR);
	tmp = ptr->b->next;
	ptr->b->next = ptr->a;
	ptr->a = ptr->b;
	ptr->b = tmp;
	ptr->size_b--;
	ptr->size_a++;
	if (!ptr->b)
		ptr->last_b = NULL;
	ft_lstadd_move(&ptr->mv, PA);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, PA);
	return (CHECK_OK);
}

int	ft_ra(t_pusw *ptr)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!ptr->a || !ptr->a->next)
		return (CHECK_ERR);
	tmp = ptr->a;
	first = ptr->a->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ptr->a;
	ptr->a->next = NULL;
	ptr->last_a = ptr->a;
	ptr->a = first;
	return (CHECK_OK);
}

int	ft_rra(t_pusw *ptr)
{
	t_stack	*ex_first;
	t_stack	*last;

	if (!ptr->a || !ptr->a->next)
		return (CHECK_ERR);
	ex_first = ptr->a;
	while (ptr->a->next->next)
		ptr->a = ptr->a->next;
	last = ptr->a->next;
	ptr->a->next = NULL;
	ptr->last_a = ptr->a;
	ptr->a = last;
	ptr->a->next = ex_first;
	return (CHECK_OK);
}
