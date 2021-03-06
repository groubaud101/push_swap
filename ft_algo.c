/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:27:05 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 17:25:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_order(t_stack *tmp)
{
	if (!tmp)
		return (CHECK_ERR);
	while (tmp->next)
	{
		if (tmp->location > tmp->next->location)
			return (CHECK_ERR);
		tmp = tmp->next;
	}
	return (CHECK_OK);
}

void	ft_algo(t_pusw *ptr)
{
	if (ft_check_order(ptr->a) == CHECK_OK && !ptr->b)
		return ;
	if (ptr->size_a <= 5)
		ft_algo_below_five(ptr);
	else if (ptr->size_a <= 100)
		ft_algo_below_hundred(ptr);
	else
		ft_algo_above_hundred(ptr);
}
