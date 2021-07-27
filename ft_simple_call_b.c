/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_call_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:44:13 by user42            #+#    #+#             */
/*   Updated: 2021/07/27 19:53:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_simple_sb(t_pusw *ptr)
{
	ft_sb(ptr);
	ft_lstadd_move(&ptr->mv, SB);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, SB);
}

void	ft_simple_rb(t_pusw *ptr)
{
	ft_rb(ptr);
	ft_lstadd_move(&ptr->mv, RB);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, RB);
}

void	ft_simple_rrb(t_pusw *ptr)
{
	ft_rrb(ptr);
	ft_lstadd_move(&ptr->mv, RRB);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, RRB);
}