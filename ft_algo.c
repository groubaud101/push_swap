/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:27:05 by user42            #+#    #+#             */
/*   Updated: 2021/07/25 00:36:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_order(t_pusw *ptr)
{
	t_stack	*tmp;

	tmp = ptr->a;
	while (tmp->next)
	{
		DEB("tmp loc : %i, tmp next loc : %i\n",
			tmp->location, tmp->next->location);
		if (tmp->location > tmp->next->location)
			return (CHECK_ERR);
		tmp = tmp->next;
	}
	return (CHECK_OK);
}

void	ft_algo(t_pusw *ptr)
{
	DEB("last_a nb : %i loc(%i)\n",
		ptr->last_a->nb, ptr->last_a->location);

	DEB("let's order\n");
	if (ft_check_order(ptr) == CHECK_OK && !ptr->b)
		return ;
	DEB("it's not in the right order\n");
	if (ptr->size_a <= 5)
		ft_algo_below_five(ptr);
	else if (ptr->size_a <= 100)
		ft_algo_below_hundred(ptr);
	else
		ft_algo_above_hundred(ptr);
	DEB("sorting done\n");
}