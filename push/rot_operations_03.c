/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_operations_03.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:59:22 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/25 13:00:21 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	rra(t_stack **stack_a)
{
	t_stack *seclast;
	t_stack *last;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
	{
		return ;
	}
	seclast = NULL;
	last = (*stack_a);
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = (*stack_a);
	(*stack_a) = last;
}

void	rrb(t_stack **stack_b)
{
	t_stack *seclast;
	t_stack *last;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	seclast = NULL;
	last = (*stack_b);
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = (*stack_b);
	(*stack_b) = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
