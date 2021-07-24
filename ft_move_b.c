/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:28:30 by user42            #+#    #+#             */
/*   Updated: 2021/07/25 00:21:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_sb(t_pusw *ptr)
{
	t_stack *second;
	t_stack *first;
	t_stack *third;

	if (!ptr->b || !ptr->b->next)
		return (CHECK_ERR);
	second = ptr->b;
	first = ptr->b->next;
	third = ptr->b->next->next;
	ptr->b = first;
	ptr->b->next = second;
	ptr->b->next->next = third;
	if (third && third->next == NULL)
		ptr->last_b = third;
	return (CHECK_OK);
}

int	ft_pb(t_pusw *ptr)
{
	t_stack	*tmp;

	if (!ptr->a)
		return (CHECK_ERR);
	tmp = ptr->a->next;
	ptr->a->next = ptr->b;
	ptr->b = ptr->a;
	if (!ptr->last_b)
		ptr->last_b = ptr->b;
	ptr->a = tmp;
	ptr->size_a--;
	ptr->size_b++;
	if (!ptr->a)
		ptr->last_a = NULL;
	ft_lstadd_move(&ptr->mv, "pb");
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, "pb");
	return (CHECK_OK);
}

int	ft_rb(t_pusw *ptr)
{
	t_stack	*tmp;
	t_stack	*first;
	
	if (!ptr->b || !ptr->b->next)
		return (CHECK_ERR);
	tmp = ptr->b;
	first = ptr->b->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ptr->b;
	ptr->b->next = NULL;
	ptr->last_b = ptr->b;
	ptr->b = first;
	return (CHECK_OK);
}

int	ft_rrb(t_pusw *ptr)
{
	t_stack	*ex_first;
	t_stack	*last;
	
	if (!ptr->b || !ptr->b->next)
		return (CHECK_ERR);
	ex_first = ptr->b;
	while (ptr->b->next->next)
		ptr->b = ptr->b->next;
	last = ptr->b->next;
	ptr->b->next = NULL;
	ptr->last_b = ptr->b;
	ptr->b = last;
	ptr->b->next = ex_first;
	return (CHECK_OK);
}
