/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:08:15 by user42            #+#    #+#             */
/*   Updated: 2021/07/17 17:31:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_sa(t_pusw *ptr)
{
	t_stack *tmp;

	if (!A || !A->next)
		return (CHECK_ERR);
	tmp = A->next->next;
	A->next = A;
	A = tmp;
	return (CHECK_OK);
}

int	ft_pa(t_pusw *ptr)
{

	return (CHECK_OK);
}

int	ft_ra(t_pusw *ptr)
{

	return (CHECK_OK);
}

int	ft_rra(t_pusw *ptr)
{

	return (CHECK_OK);
}