/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:42:17 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/15 22:11:47 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void    push(t_stack **head, int val)
{
	t_stack *node;

	//node = malloc(sizeof(t_stack));
	node->num = val;
	node->next = *head;
	*head = node;
}

int		pop(t_stack **head)
{
	int	retval;
	t_stack *next_node;

	if (*head == NULL)
		return (-1);
	next_node = NULL;
	retval = -1;
	next_node = (*head)->next;
	retval = (*head)->num;
	free(*head);
	*head = next_node;
	return (retval);
}

t_stack		*stack_new(int argc, char **argv)
{
    t_stack    	*stack;
    char    	**args;
    int			i;

    if (!(stack = malloc(sizeof(t_stack))))
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    if (argc == 2)
    {
        args = ft_strsplit(argv[1], ' ');
        i = ft_wordcount(argv[1], ' ') - 1;
        stack->num = ft_atoi(args[i]);
        stack->next = NULL;
        i--;
        while (i >= 0)
        {
            push(&stack, ft_atoi(args[i]));
            i--;
        }
        return (stack);
    }
    i = (argc - 1);
    stack->num = ft_atoi(argv[i]);
    stack->next = NULL;
    i--;
    while (i >= 1)
    {
        push(&stack, ft_atoi(argv[i]));
        i--;
    }
    return (stack);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		(*stack_b)->next = *stack_a;
		*stack_b = *stack_a;
	}
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack *p_node;

	if (!(*stack_a))
	{
		return ;
	}
	p_node = malloc(sizeof(t_stack));
	p_node->num = pop(stack_a);
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

void	ra(t_stack **stack_a)
{
	t_stack *first;
	t_stack *last;

	first = (*stack_a);
	last = (*stack_a);
	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	(*stack_a) = first->next;
	first->next = NULL;
	last->next = first;
}

void	rb(t_stack **stack_b)
{
	t_stack *first;
	t_stack *last;

	first = (*stack_b);
	last = (*stack_b);
	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	(*stack_b) = first->next;
	first->next = NULL;
	last->next = first;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	print_stack(t_stack **stack)
{
	t_stack *print;

	print = *stack;
	while (print != NULL)
	{
		ft_putnbr(print->num);
		ft_putchar('\n');
		print = print->next;
	}
}

int		getCount(t_stack *head)
{
	int count = 0;
	t_stack *current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
