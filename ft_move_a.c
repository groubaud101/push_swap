/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:08:15 by user42            #+#    #+#             */
/*   Updated: 2021/07/19 19:48:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"

int	ft_sa(t_pusw *ptr)
{
	t_stack *tmp1;
	t_stack *tmp2;
	t_stack *tmp3;

	ft_printf("sa\n");
	if (!A || !A->next)
		return (CHECK_ERR);
	tmp1 = A;
	tmp2 = A->next;
	tmp3 = A->next->next;
	A = tmp2;
	A->next = tmp1;
	A->next->next = tmp3;
	return (CHECK_OK);
}

int	ft_pa(t_pusw *ptr)
{
	t_stack	*tmp;

	ft_printf("pa\n");
	if (!A)
		return (CHECK_ERR);
	tmp = A->next;
	A->next = B;
	B = A;
	A = tmp;

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