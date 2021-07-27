/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:28:31 by user42            #+#    #+#             */
/*   Updated: 2021/07/27 19:48:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sa_check_sb(t_pusw *ptr)
{
	int	num_mv;

	if (ptr->b && ptr->b->next
		&& ptr->b->location < ptr->b->next->location)
	{
		ft_sb(ptr);
		num_mv = SS;	
	}
	else
		num_mv = SA;
	ft_sa(ptr);
	ft_lstadd_move(&ptr->mv, num_mv);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, num_mv);
}

void	ft_ra_check_rb(t_pusw *ptr)
{
	int num_mv;

	if (ptr->b && ptr->b->next
		&& ptr->b->location < ptr->b->next->location)
	{
		ft_rb(ptr);
		num_mv = RR;	
	}
	else
		num_mv = RA;
	ft_ra(ptr);
	ft_lstadd_move(&ptr->mv, num_mv);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, num_mv);
}

void	ft_rra_check_rrb(t_pusw *ptr)
{
	int num_mv;

	if (ptr->b && ptr->b->next
		&& ptr->b->location < ptr->last_b->location)
	{
		ft_rrb(ptr);
		num_mv = RRR;	
	}
	else
		num_mv = RRA;
	ft_rra(ptr);
	ft_lstadd_move(&ptr->mv, num_mv);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, num_mv);
}
