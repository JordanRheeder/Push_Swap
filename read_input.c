/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:24 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/25 15:27:07 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	do_op(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strequ(line, "sa"))
		sa(stack_a);
	else if (ft_strequ(line, "sb"))
		sb(stack_b);
	else if (ft_strequ(line, "ss"))
		ss(stack_a, stack_b);
	else if (ft_strequ(line, "pa"))
		pa(stack_a, stack_b);
	else if (ft_strequ(line, "pb"))
		pb(stack_b, stack_a);
	else if (ft_strequ(line, "ra"))
		ra(stack_a);
	else if (ft_strequ(line, "rb"))
		rb(stack_b);
	else if (ft_strequ(line, "rr"))
		rr(stack_a, stack_b);
	else if (ft_strequ(line, "rra"))
		rra(stack_a);
	else if (ft_strequ(line, "rrb"))
		rrb(stack_b);
	else if (ft_strequ(line, "rrr"))
		rrr(stack_a, stack_b);
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
			do_op(a, b, *line);
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
