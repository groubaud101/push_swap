/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:31:00 by user42            #+#    #+#             */
/*   Updated: 2021/07/27 19:49:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_ss(t_pusw *ptr)
{
	ft_sa(ptr);
	ft_sb(ptr);
	ft_lstadd_move(&ptr->mv, SS);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, SS);
	return (CHECK_ERR);
}

int		ft_rr(t_pusw *ptr)
{
	ft_ra(ptr);
	ft_rb(ptr);
	ft_lstadd_move(&ptr->mv, RR);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, RR);
	return (CHECK_OK);
}

int		ft_rrr(t_pusw *ptr)
{
	ft_rra(ptr);
	ft_rrb(ptr);
	ft_lstadd_move(&ptr->mv, RRR);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, RRR);
	return (CHECK_OK);
}
