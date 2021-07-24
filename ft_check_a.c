/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:28:31 by user42            #+#    #+#             */
/*   Updated: 2021/07/24 23:29:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sb_check_sa(t_pusw *ptr)
{
	char	*move;
/*
	if (ptr->a && ptr->a->next
		&& ptr->a->location < ptr->a->next->location)
	{
		ft_sa(ptr);
		move = "ss";	
	}
	else
*/		move = "sb";
	ft_sb(ptr);
	ft_lstadd_move(&ptr->mv, move);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, move);
}

void	ft_rb_check_ra(t_pusw *ptr)
{
	char	*move;
/*
	if (ptr->a && ptr->a->next
		&& ptr->a->location > ptr->last_a->location)
	{
		ft_ra(ptr);
		move = "rr";	
	}
	else
*/		move = "rb";
	ft_rb(ptr);
	ft_lstadd_move(&ptr->mv, move);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, move);
}

void	ft_rrb_check_rra(t_pusw *ptr)
{
	char	*move;

/*	if (ptr->a && ptr->a->next
		&& ptr->a->location > ptr->last_a->location)
	{
		ft_rra(ptr);
		move = "rrr";	
	}
	else
*/		move = "rrb";
	ft_rrb(ptr);
	ft_lstadd_move(&ptr->mv, move);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, move);
}
