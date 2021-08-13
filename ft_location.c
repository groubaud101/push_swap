/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_location.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 17:56:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

static int	ft_first_run(t_pusw *ptr, t_index *index)
{
	t_stack	*tmp;

	tmp = ptr->a;
	index->min = ptr->a->nb;
	index->max = index->min;
	while (tmp)
	{
		if (tmp->nb < index->min)
			index->min = tmp->nb;
		if (tmp->nb > index->max)
			index->max = tmp->nb;
		tmp = tmp->next;
	}
	index->ex_min = index->min;
	index->ex_max = index->max;
	return (CHECK_OK);
}

static int	ft_set_location(t_pusw *ptr, t_stack *tmp, t_index *index, int i)
{
	if (tmp->nb == index->ex_min)
	{
		if (index->set_min == 1)
			return (CHECK_ERR);
		tmp->location = i;
		index->set_min = 1;
	}
	if (tmp->nb == index->ex_max)
	{
		if (index->set_max == 1)
			return (CHECK_ERR);
		tmp->location = ptr->size_a - i - 1;
		index->set_max = 1;
	}
	return (CHECK_OK);
}

static int	ft_next_location(t_pusw *ptr, t_index *index, int i)
{
	t_stack	*tmp;

	tmp = ptr->a;
	while (tmp && tmp->location != -1)
		tmp = tmp->next;
	if (!tmp)
		return (CHECK_OK);
	index->min = index->ex_max;
	index->max = index->ex_min;
	index->set_min = 0;
	index->set_max = 0;
	while (tmp)
	{
		if (ft_set_location(ptr, tmp, index, i) == CHECK_ERR)
			return (CHECK_ERR);
		if (tmp->nb > index->ex_min && tmp->nb < index->min)
			index->min = tmp->nb;
		if (tmp->nb < index->ex_max && tmp->nb > index->max)
			index->max = tmp->nb;
		tmp = tmp->next;
	}
	index->ex_min = index->min;
	index->ex_max = index->max;
	return (CHECK_OK);
}

int	ft_location(t_pusw *ptr)
{
	int	i;

	i = 0;
	ft_first_run(ptr, &ptr->index);
	while (i <= ptr->size_a / 2)
	{
		if (ft_next_location(ptr, &ptr->index, i) == CHECK_ERR)
			return (CHECK_ERR);
		i = i + 1;
	}
	return (CHECK_OK);
}
