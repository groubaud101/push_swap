/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pusw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:48:13 by user42            #+#    #+#             */
/*   Updated: 2021/07/17 18:33:53 by user42           ###   ########.fr       */
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
	if (nbr[i] == '0' && nbr[i + 1] == '\0')
		return (CHECK_OK);
	return (CHECK_ERR);
}

int		ft_tab_move(t_pusw *ptr)
{
	SA = &ft_sa;
	SB = &ft_sb;
	SS = &ft_ss;
	PA = &ft_pa;
	PB = &ft_pb;
	RA = &ft_ra;
	RB = &ft_rb;
	RR = &ft_rr;
	RRA = &ft_rra;
	RRB = &ft_rrb;
	RRR = &ft_rrr;
}

int	ft_init_pusw(t_pusw *ptr, char **tab)
{
	t_stack	*tmp;
	int		nb;

	while (tab[ptr->size_a])
	{
		nb = ft_atoi_no_overflow(tab[ptr->size_a]);
		if (nb == 0 && ft_rSeally_zero(tab[ptr->size_a]) == CHECK_ERR)
			return (ft_clear_stack(&A));
		tmp = ft_lstnew_pusw(nb);
		if (tmp == NULL)
			return (ft_clear_stack(&A));
		ft_lstadd_back_pusw(&ptr->a, tmp);
		ptr->size_a++;
	}
	return (CHECK_OK);
}