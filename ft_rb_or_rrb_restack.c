/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_or_rrb_restack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:37:25 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 17:54:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_rb_or_rrb_restack(t_pusw *ptr, int top)
{
	int		i;
	t_stack	*tmp;

	tmp = ptr->b;
	i = 0;
	while (tmp)
	{
		if (tmp->location == top)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (!tmp)
		return (CHECK_ERR);
	if (i < ptr->size_b / 2)
		while (i-- > 0)
			ft_simple_rb(ptr);
	else
		while (i++ < ptr->size_b)
			ft_simple_rrb(ptr);
	return (CHECK_OK);
}
