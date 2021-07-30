/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pusw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:48:13 by user42            #+#    #+#             */
/*   Updated: 2021/07/29 10:50:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"
#include <stdlib.h>

static t_stack	*ft_lstnew_pusw(int nb)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->nb = nb;
	lst->location = -1;
	lst->next = NULL;
	return (lst);
}

static void	ft_lstadd_back_pusw(t_stack **alst, t_stack *new)
{
	t_stack	*lst;

	if (!alst)
		return ;
	if (*alst)
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}

static int	ft_really_zero(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] == '0')
		i++;
	if (nbr[i] == '\0')
		return (CHECK_OK);
	return (CHECK_ERR);
}

static t_stack *ft_last_a(t_stack *tmp)
{
	if (!tmp)
		return (NULL);
	if (!tmp->next)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_fill_pusw(t_pusw *ptr, char **tab)
{
	t_stack	*tmp;
	int		nb;

	DEB("ft_fill_pusw\n");
	while (*tab)
	{
		nb = ft_atoi_no_overflow(*tab);
		if (nb == 0 && ft_really_zero(*tab) == CHECK_ERR)
			return (ft_clear(ptr, CHECK_ERR));
		tmp = ft_lstnew_pusw(nb);
		if (tmp == NULL)
			return (ft_clear(ptr, CHECK_ERR));
		ft_lstadd_back_pusw(&ptr->a, tmp);
		ptr->size_a++;
		tab++;
	}
	ptr->total_size = ptr->size_a;
	ptr->last_a = ft_last_a(ptr->a);
	DEB("ft_location\n");
	if (ft_location(ptr) == CHECK_ERR)
		return (ft_clear(ptr, CHECK_ERR));
	return (CHECK_OK);
}