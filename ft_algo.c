/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:27:05 by user42            #+#    #+#             */
/*   Updated: 2021/07/21 19:36:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_order(t_pusw *ptr) // pensez a check une stack vide
{
	t_stack	*tmp;

	if (ptr->b)
		return (CHECK_ERR);
	tmp = ptr->a;
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
	if (ft_check_order(ptr) != CHECK_OK)
		return ;
	printf("coucou CHECK_OK\n");
}