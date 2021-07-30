/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_below_hundred.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:17:25 by user42            #+#    #+#             */
/*   Updated: 2021/07/30 14:22:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_algo_below_hundred(t_pusw *ptr)
{
	int		chunk;
	int		div;
	t_stack	*tmp;
	
	chunk = 0;
	tmp = ptr->a;
	div = ptr->total_size / 5;
	while (chunk < 5)
	{
		while (ft_ra_or_rra_chunk(ptr, tmp, div, chunk) == CHECK_OK)
			;
		ft_pb(ptr);
		chunk++;
	}
}