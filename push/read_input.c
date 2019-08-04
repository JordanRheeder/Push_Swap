/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:24 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/04 17:08:30 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	do_op(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "sa"))
		sa(a);
	else if (ft_strequ(line, "sb"))
		sb(b);
	else if (ft_strequ(line, "ss"))
		ss(a, b);
	else if (ft_strequ(line, "pa"))
		pa(a, b);
	else if (ft_strequ(line, "pb"))
		pb(b, a);
	else if (ft_strequ(line, "ra"))
		ra(a);
	else if (ft_strequ(line, "rb"))
		rb(b);
	else if (ft_strequ(line, "rr"))
		rr(a, b);
	else if (ft_strequ(line, "rra"))
		rra(a);
	else if (ft_strequ(line, "rrb"))
		rrb(b);
	else if (ft_strequ(line, "rrr"))
		rrr(a, b);
}

int		check_op(char *line)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "sb"))
		return (1);
	else if (ft_strequ(line, "pa") || ft_strequ(line, "pb"))
		return (1);
	else if (ft_strequ(line, "ss"))
		return (1);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rb"))
		return (1);
	else if (ft_strequ(line, "rr") || ft_strequ(line, "rrr"))
		return (1);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrb"))
		return (1);
	return (0);
}

int		check_line(char *line)
{
	if (line)
	{
		if (check_op(line))
			return (1);
		else
			return (0);
	}
	return (0);
}

int		read_input(t_stack **a, t_stack **b, char **line)
{
	while (get_next_line(0, line))
	{
		if (check_line(*line))
		{
			do_op(*line, a, b);
			free(*line);
		}
		else if (!(check_line(*line)))
		{
			free(*line);
			return (0);
		}
	}
	return (1);
}

void    print_do_op(char *op, t_stack **a, t_stack **b)
{
    ft_putendl_fd(op, 1);
    do_op(op, a, b);
}
