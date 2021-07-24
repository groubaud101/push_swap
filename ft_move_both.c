/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:31:00 by user42            #+#    #+#             */
/*   Updated: 2021/07/24 20:19:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_ss(t_pusw *ptr)
{
	ft_sa(ptr);
	ft_sb(ptr);
	ft_lstadd_move(&ptr->mv, "ss");
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, "ss");
	return (CHECK_ERR);
}

int		ft_rr(t_pusw *ptr)
{
	ft_ra(ptr);
	ft_rb(ptr);
	ft_lstadd_move(&ptr->mv, "rr");
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, "rr");
	return (CHECK_OK);
}

int		ft_rrr(t_pusw *ptr)
{
	ft_rra(ptr);
	ft_rrb(ptr);
	ft_lstadd_move(&ptr->mv, "rrr");
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, "rrr");
	return (CHECK_OK);
}
