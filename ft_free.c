/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:38:03 by user42            #+#    #+#             */
/*   Updated: 2021/07/16 22:06:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdlib.h>

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_clear_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !(*lst))
		return (CHECK_ERR);
	tmp = (*lst)->next;
	while (tmp)
	{
		free(*lst);
		*lst = tmp;
		tmp = tmp->next;
	}
	free(*lst);
	*lst = NULL;
	return (CHECK_ERR);
}