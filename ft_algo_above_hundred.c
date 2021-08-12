/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_above_hundred.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:18:47 by user42            #+#    #+#             */
/*   Updated: 2021/08/12 22:16:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_algo_above_hundred(t_pusw *ptr)
{
	int		chunk;
	int		top;

	chunk = 1;
	top = ptr->total_size / 11;
	while (ptr->a && chunk <= 12)
	{
		if (ft_ra_or_rra_chunk(ptr, ptr->a, top) == CHECK_OK)
			ft_pb(ptr);
		else
		{
			chunk++;
			top = ptr->total_size / 11 * chunk;
		}
		if (ptr->verbose)
			ft_put_pusw(ptr, -1);
	}
	top = ptr->total_size - 1;
	while (ptr->b)
	{
		ft_rb_or_rrb_restack(ptr, top--);
		ft_pa(ptr);
	}
}