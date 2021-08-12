/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_or_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:58:24 by user42            #+#    #+#             */
/*   Updated: 2021/08/12 22:58:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_ra_or_rra(t_pusw *ptr, t_stack *tmp)
{
	if (tmp->location <= ptr->total_size / 2)
		ft_rra_check_rrb(ptr);
	else
		ft_ra_check_rb(ptr);
}