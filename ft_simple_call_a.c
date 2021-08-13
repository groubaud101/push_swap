/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_call_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:44:13 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 17:54:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_simple_sa(t_pusw *ptr)
{
	ft_sa(ptr);
	ft_lstadd_move(&ptr->mv, SA);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, SA);
}

void	ft_simple_ra(t_pusw *ptr)
{
	ft_ra(ptr);
	ft_lstadd_move(&ptr->mv, RA);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, RA);
}

void	ft_simple_rra(t_pusw *ptr)
{
	ft_rra(ptr);
	ft_lstadd_move(&ptr->mv, RRA);
	if (ptr->verbose == 1)
		ft_put_pusw(ptr, RRA);
}
