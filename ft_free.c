/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:38:03 by user42            #+#    #+#             */
/*   Updated: 2021/07/20 11:56:08 by user42           ###   ########.fr       */
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

static void	ft_clear_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!(*lst))
		return ;
	tmp = (*lst)->next;
	while (tmp)
	{
		free(*lst);
		*lst = tmp;
		tmp = tmp->next;
	}
	free(*lst);
	*lst = NULL;
}

static void	ft_clear_move(t_move **lst)
{
	t_move	*tmp;

	if (!(*lst))
		return ;
	tmp = (*lst)->next;
	while (tmp)
	{
		free(*lst);
		*lst = tmp;
		tmp = tmp->next;
	}
	free(*lst);
	*lst = NULL;
}

int	ft_clear(t_pusw *ptr, int error)
{
	ft_clear_stack(&A);
	ft_clear_stack(&B);
	ft_clear_move(&MV);
	free(ptr);
	return (error);
}