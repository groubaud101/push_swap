/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/07/17 18:49:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int	ft_check_error(char **tab)
{
	int	i;
	int sign;
	int	max;

	if (tab == NULL)
		return (CHECK_ERR);
	while (*tab)
	{
		i = 0;
		sign = ((*tab)[i] == '-' || (*tab)[i] == '+');
		i += sign;
		max = 10 + sign;
		while ((*tab)[i])
		{
			if (ft_isdigit((*tab)[i]) == 0 || (i >= max))
				return (CHECK_ERR);
			i++;
		}
		tab++;
	}
	return (CHECK_OK);
}

void	ft_push_swap(char **tab)
{
	t_pusw	ptr;

	if (ft_check_error(tab) == CHECK_ERR)
	{
		return (ft_putstr("Error\n")) ;
	}
	ptr = (t_pusw){0, 0, NULL, NULL, NULL, &(ptr.tab)};
	if (ft_init_pusw(&ptr, tab) == CHECK_ERR)
		return (ft_putstr("Error\n"));
	ft_put_pusw(&ptr);
}

int main(int ac, char **av)
{
	char	**tab;

	if (ac == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		ft_push_swap(tab);
		ft_free_tab(tab);
	}
	else
		ft_push_swap(av + 1);
	return (0);	
}