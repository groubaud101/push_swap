/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:31:00 by user42            #+#    #+#             */
/*   Updated: 2021/07/17 19:32:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_ss(t_pusw *ptr)
{
	if (ft_sa(ptr) || ft_sb(ptr))
		return (CHECK_OK);
	return (CHECK_ERR);
}

int		ft_rr(t_pusw *ptr)
{
	if (ft_ra(ptr) || ft_rb(ptr))
		return (CHECK_OK);
	return (CHECK_ERR);
}

int		ft_rrr(t_pusw *ptr)
{
	if (ft_rra(ptr) || ft_rrb(ptr))
		return (CHECK_OK);
	return (CHECK_ERR);
}
