/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:26:40 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 17:28:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <stddef.h>

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

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct s_move
{
	int				num_mv;
	struct s_move	*next;
}t_move;

typedef struct s_pusw
{
	int		verbose;
	int		size_a;
	int		size_b;
	int		total_size;
	t_stack	*a;
	t_stack	*b;
	t_stack	*last_a;
	t_stack	*last_b;
	char	*moves[11];
	t_move	*mv;
	t_index	index;
}t_pusw;


/*
** ft_split_pusw.c
** ft_attribute_params :
**  split the arguments with several parameters
**   and add it with the unique parameter in a argument
**   into a tab
*/
char	**ft_attribute_params(char **av, int verbose);

/*
** ft_push_swap.c
**
** main :
**  Check if the number of arguments is correct and set verbose
**
** ft_push_swap :
**  Control tower
**   ft_check_error, fill the linked lists, run the algo, 
**   display all the final moves and clear the lists
*/
void	ft_push_swap(char **tab, int verbose);

/*
** ft_check_error.c
**
** ft_error :
**  aff "Error\n"
**  return CHECK_ERR
**
** ft_check_error :
**  check if number is longer than 10 (+sign) characters
**  check if value is digit
*/
int		ft_error(void);
int		ft_check_error(char **tab);

/*
** ft_free.c
**
** ft_free_tab :
**  free tab from ft_split
**
** ft_clear :
**  Free stack a and b
**  Free move
*/
void	ft_free_tab(char **tab);
int		ft_clear(t_pusw *ptr, int error);

/*
** ft_fill_pusw.c
**
** ft_fill_pusw :
**  Fill stack a
**  Check if atoi doesn't overflow
**  Set the location of the number in the globality
**   (the min is at 0 and the max is at size_a - 1)
*/
int		ft_fill_pusw(t_pusw *ptr, char **tab);

/*
** ft_location.c
**
** ft_location :
**  Set the location of the number in stack_a in the globality
**   (the min is at 0 and the max is at size_a - 1) 
*/
int		ft_location(t_pusw *ptr);

/*
** ft_move.c
**
** ft_lstadd_move :
**  Add the new move to the linked list t_move
**
** ft_put_move :
**  Display the linked list t_move with \n between node
*/
int		ft_lstadd_move(t_move **mv, int num_mv);
void	ft_put_move(t_pusw *ptr);

/*
** ft_move_a.c
** if verbose, display the stacks when there is change
**
** ft_sa :
**  swap the 2 first node of stack a
**
** ft_pb :
**  push the first node of stack a at the top of stack b
**
** ft_ra :
**  rotate all nodes of stack a,
**   the first becomes the last and second become the first 
**
** ft_rra :
**  rotate all nodes of stack a,
**   the last becomes the first, the before the last become the last
*/
int		ft_sa(t_pusw *ptr);
int		ft_pb(t_pusw *ptr);
int		ft_ra(t_pusw *ptr);
int		ft_rra(t_pusw *ptr);

/*
** ft_move_b.c
** if verbose, display the stacks when there is change
**
** ft_sb :
**  swap the 2 first node of stack b
**
** ft_pa :
**  push the first node of stack b at the top of stack a
**
** ft_rb :
**  rotate all nodes of stack b,
**   the first becomes the last and second become the first 
**
** ft_rrb :
**  rotate all nodes of stack b,
**   the last becomes the first, the before the last become the last
*/
int		ft_sb(t_pusw *ptr);
int		ft_pa(t_pusw *ptr);
int		ft_rb(t_pusw *ptr);
int		ft_rrb(t_pusw *ptr);

/*
** ft_move_both.c
** if verbose, display the stacks when there is change
**
** ft_ss :
**  ft_sa and ft_sb
**
** ft_rr :
**  ft_ra and ft_rb
**
** ft_rra :
**  ft_rra and ft_rrb
*/
int		ft_ss(t_pusw *ptr);
int		ft_rr(t_pusw *ptr);
int		ft_rrr(t_pusw *ptr);

/*
** ft_check_b.c
**
** ft_Xa_check_Xb :
**  Check if the other list need a X modif as well
**   If true, change the Xa move for a XX
**   And add it to move list
*/
void	ft_sa_check_sb(t_pusw *ptr);
void	ft_ra_check_rb(t_pusw *ptr);
void	ft_rra_check_rrb(t_pusw *ptr);

/*
** ft_simple_call_AB.c
**  Call the move
**  ADD it to list move
**   (without checking the other list)
*/
void	ft_simple_sa(t_pusw *ptr);
void	ft_simple_ra(t_pusw *ptr);
void	ft_simple_rra(t_pusw *ptr);

void	ft_simple_sb(t_pusw *ptr);
void	ft_simple_rb(t_pusw *ptr);
void	ft_simple_rrb(t_pusw *ptr);

/*
** ft_verbose.c
**
** ft_put_pusw :
**  Display the last move
**  Then display the stacks a and b with the change
*/
void	ft_put_pusw(t_pusw *ptr, int num_mv);

/*
** ft_algo.c
**
** ft_check_order :
**  Check if stack_a is in the right order
**
**
**
**
**
**
**
**
**
**
*/
int		ft_check_order(t_stack *tmp);
void	ft_algo(t_pusw *ptr);
int		ft_can_insert(t_pusw *pt, t_stack *tmp_a, int location, int tmp_prev);


void	ft_algo_below_five(t_pusw *ptr);

void	ft_algo_three(t_pusw *ptr);

void	ft_algo_below_hundred(t_pusw *ptr);
void	ft_algo_above_hundred(t_pusw *ptr);


void	ft_ra_or_rra(t_pusw *ptr, t_stack *tmp);
int		ft_ra_or_rra_chunk(t_pusw *ptr, t_stack *tmp, int top);
int		ft_ra_or_rra_pa(t_pusw *ptr, t_stack *tmp);
int		ft_rb_or_rrb_restack(t_pusw *ptr, int top);

/*
** ft_optmize_move.c
**  Remove move that cancel each other out
**  (ra and rra, pa and pb)
*/
void	ft_optimize(t_pusw *ptr);

#endif

#define TEST 0
#if TEST
# include <stdio.h>
void	ft_test_move(t_pusw *ptr);
void	do_nothing(char *str, ...);

# define DEBUG 0
# if DEBUG
#  define DEB printf
# else
#  define DEB do_nothing
# endif

# define DEB_OP 0
# if DEB_OP
#  define DEB_O printf
# else
#  define DEB_O do_nothing
# endif

#endif
