/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 02:20:31 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 02:31:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_the_greatest(t_stack *tmp, int the_greatest)
{
	while (tmp)
	{
		if (tmp->location > the_greatest)
			return (CHECK_ERR);
		tmp = tmp->next;
	}
	return (CHECK_OK);
}

static int	ft_the_lowest(t_stack *tmp, int the_lowest)
{
	while (tmp)
	{
		if (tmp->location < the_lowest)
			return (CHECK_ERR);
		tmp = tmp->next;
	}
	return (CHECK_OK);
}

int	ft_can_insert(t_pusw *ptr, t_stack *tmp_a, int location, int tmp_prev)
{
	if ((location < tmp_a->location 
		&& location > tmp_prev)
		|| ((ft_the_greatest(ptr->a, location) == CHECK_OK
		|| ft_the_lowest(ptr->a, location) == CHECK_OK)
		&& ft_the_greatest(ptr->a, tmp_prev) == CHECK_OK))
		return (CHECK_OK);
	return (CHECK_ERR);
}
