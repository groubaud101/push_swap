/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:06:09 by user42            #+#    #+#             */
/*   Updated: 2021/08/02 20:02:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_checker(char **tab)
{

}

int main(int ac, char **av)
{
	char	**tab;

	if (ac == 1)
		return (ft_error());
	tab = ft_attribute_params(av, 0);
	if (!tab || !tab[0])
	{
		ft_free_tab(tab);
		return (ft_error());
	}
	ft_checker(tab);
	ft_free_tab(tab);
	return (0);
}