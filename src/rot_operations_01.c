/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_operations_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:27:33 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/15 22:13:31 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *p_node;

	if (!(*stack_b))
		return ;
	p_node = malloc(sizeof(t_stack));
	p_node->num = pop(stack_b);
	if (!(*stack_a))
		p_node->next = NULL;
	else
		p_node->next = *stack_a;
	*stack_a = p_node;
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack *p_node;

	if (!(*stack_a))
		return ;
	p_node = malloc(sizeof(t_stack));
	p_node->num = pop(stack_a);
	if (!(*stack_b))
		p_node->next = NULL;
	else
		p_node->next = *stack_b;
	*stack_b = p_node;
}

void	sa(t_stack **stack_a)
{
	t_stack *tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
}

void	sb(t_stack **stack_b)
{
	t_stack *tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
