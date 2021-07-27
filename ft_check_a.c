/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:28:31 by user42            #+#    #+#             */
/*   Updated: 2021/07/27 19:47:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sb_check_sa(t_pusw *ptr)
{
	int	num_mv;
/*
	if (ptr->a && ptr->a->next
		&& ptr->a->location < ptr->a->next->location)
	{
		ft_sa(ptr);
		num_mv = SS;	
	}
	else
*/		num_mv = SB;
	ft_sb(ptr);
	ft_lstadd_move(&ptr->mv, num_mv);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, num_mv);
}

void	ft_rb_check_ra(t_pusw *ptr)
{
	int	num_mv;
/*
	if (ptr->a && ptr->a->next
		&& ptr->a->location > ptr->last_a->location)
	{
		ft_ra(ptr);
		num_mv = RR;	
	}
	else
*/		num_mv = RB;
	ft_rb(ptr);
	ft_lstadd_move(&ptr->mv, num_mv);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, num_mv);
}

void	ft_rrb_check_rra(t_pusw *ptr)
{
	int	num_mv;

/*	if (ptr->a && ptr->a->next
		&& ptr->a->location > ptr->last_a->location)
	{
		ft_rra(ptr);
		num_mv = RRR;	
	}
	else
*/		num_mv = RRB;
	ft_rrb(ptr);
	ft_lstadd_move(&ptr->mv, num_mv);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, num_mv);
}
