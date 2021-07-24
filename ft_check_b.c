/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:28:31 by user42            #+#    #+#             */
/*   Updated: 2021/07/24 20:36:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_sa_check_sb(t_pusw *ptr)
{
	char	*move;

	if (ptr->b && ptr->b->next
		&& ptr->b->location < ptr->b->next->location)
	{
		ft_sb(ptr);
		move = "ss";	
	}
	else
		move = "sa";
	ft_sa(ptr);
	ft_lstadd_move(&ptr->mv, move);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, move);
}

int	ft_ra_check_rb(t_pusw *ptr)
{
	char	*move;

	if (ptr->b && ptr->b->next
		&& ptr->b->location < ptr->last_b->location)
	{
		ft_rb(ptr);
		move = "rr";	
	}
	else
		move = "ra";
	ft_ra(ptr);
	ft_lstadd_move(&ptr->mv, move);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, move);
}

int	ft_rra_check_rrb(t_pusw *ptr)
{
	char	*move;

	if (ptr->b && ptr->b->next
		&& ptr->b->location > ptr->last_b->location)
	{
		ft_rrb(ptr);
		move = "rrr";	
	}
	else
		move = "ra";
	ft_ra(ptr);
	ft_lstadd_move(&ptr->mv, move);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, move);
}
