/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:26:26 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/02 16:55:46 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

void				push(t_stack **head, int val);
int					pop(t_stack **head);
void				print_stack(t_stack **stack);
t_stack				*stack_popu(int ac, char **av);
t_stack				*str_stack_popu(t_stack *stack, char **argv);
t_stack				*normalise(t_stack **stack);
int					read_input(t_stack **a, t_stack **b, char **line);
int					sorted(t_stack *a);
void				free_stack(t_stack *stack);
int					check_line(char *line);
int					check_op(char *line);
void				do_op(t_stack **a, t_stack **b, char *line);
int					valid_input(int ac, char **av);
int					list_length(t_stack **head);
int					only_digits(char *str);
int					dupe_check(int ac, char **av);
int					avg_of_nodes(t_stack *head);
int					valid_input_int(int ac, char **av);
int					valid_input_string(int ac, char **av);
void				do_sort_3(t_stack **a);
void				do_sort_5(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				ra(t_stack **a);
void				rrb(t_stack **b);
void				rb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);

#endif
