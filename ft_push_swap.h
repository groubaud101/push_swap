/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:26:40 by user42            #+#    #+#             */
/*   Updated: 2021/07/21 17:59:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stddef.h>

# define CHECK_OK 1
# define CHECK_ERR 0

typedef struct s_index
{
	int	max;
	int	min;
	int	ex_max;
	int	ex_min;
	int	set_min;
	int	set_max;
}t_index;

typedef struct s_stack
{
	int				nb;
	int				location;
	struct s_stack	*next;
}t_stack;

typedef struct s_move
{
	const char		*move;
	struct s_move	*next;
}t_move;

typedef struct s_pusw
{
	int		verbose;
	int		size_a;
	int		size_b;
	t_stack	*a;
	t_stack	*b;
	t_move	*mv;
	t_index	index;
}t_pusw;

int		ft_check_error(char **tab);
void	ft_push_swap(char **tab, int verbose);

void	ft_free_tab(char **tab);
int		ft_clear(t_pusw *ptr, int error);

int		ft_fill_pusw(t_pusw *ptr, char **tab);
int		ft_tab_move(t_pusw *ptr);

int		ft_location(t_pusw *ptr);

int		ft_lstadd_move(t_move **mv, const char *str);
void	ft_put_move(t_move *mv);
void	ft_put_last_move(t_move *mv);

int		ft_sa(t_pusw *ptr);
int		ft_sb(t_pusw *ptr);
int		ft_ss(t_pusw *ptr);
int		ft_pa(t_pusw *ptr);
int		ft_pb(t_pusw *ptr);
int		ft_ra(t_pusw *ptr);
int		ft_rb(t_pusw *ptr);
int		ft_rr(t_pusw *ptr);
int		ft_rra(t_pusw *ptr);
int		ft_rrb(t_pusw *ptr);
int		ft_rrr(t_pusw *ptr);


#define TEST 1
#if TEST
# include <stdio.h>
void	ft_putlst(t_stack *lst);
void	ft_test_move(t_pusw *ptr);
void	ft_put_pusw(t_pusw *ptr);
#endif

#endif