/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:28:30 by user42            #+#    #+#             */
/*   Updated: 2021/07/17 19:34:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_sb(t_pusw *ptr)
{
	t_stack *tmp;

	if (!B || !B->next)
		return (CHECK_ERR);
	tmp = B;
	B = tmp;
	return (CHECK_OK);
}

int	ft_pb(t_pusw *ptr)
{
	if (!B || !B->next)
		return (CHECK_ERR);
	return (CHECK_OK);
}

int	ft_rb(t_pusw *ptr)
{
	if (!B || !B->next)
		return (CHECK_ERR);
	return (CHECK_OK);
}

int	ft_rrb(t_pusw *ptr)
{
	if (!B || !B->next)
		return (CHECK_ERR);
	return (CHECK_OK);
}
