/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:08:15 by user42            #+#    #+#             */
/*   Updated: 2021/07/20 12:03:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"

int	ft_sa(t_pusw *ptr)
{
	t_stack *tmp1;
	t_stack *tmp2;
	t_stack *tmp3;

	if (!A || !A->next)
		return (CHECK_ERR);
	tmp1 = A;
	tmp2 = A->next;
	tmp3 = A->next->next;
	A = tmp2;
	A->next = tmp1;
	A->next->next = tmp3;
	ft_lstadd_move(ptr, "sa");
	return (CHECK_OK);
}

int	ft_pa(t_pusw *ptr)
{
	t_stack	*tmp;

	if (!A)
		return (CHECK_ERR);
	tmp = A->next;
	A->next = B;
	B = A;
	A = tmp;
	ft_lstadd_move(ptr, "pa");
	return (CHECK_OK);
}

int	ft_ra(t_pusw *ptr)
{
	if (!A || !A->next)
		return (CHECK_ERR);
	return (CHECK_OK);
}

int	ft_rra(t_pusw *ptr)
{
	if (!A || !A->next)
		return (CHECK_ERR);
	return (CHECK_OK);
}