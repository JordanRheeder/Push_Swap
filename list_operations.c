/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:55:58 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/02 09:51:49 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	push(t_stack **head, int val)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	node->num = val;
	node->next = *head;
	*head = node;
}

int		pop(t_stack **head)
{
	int		retval;
	t_stack	*next_node;

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

int		list_length(t_stack **head)
{
	int		cnt;

	cnt = 0;
	while (*head != NULL)
	{
		*head = (*head)->next;
		cnt++;
	}
	return (cnt);
}

t_stack		*str_stack_popu(t_stack *stack, char **argv)
{
	int		i;
	char	**args;

	stack = malloc(sizeof(t_stack));
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

t_stack		*stack_popu(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	if (!(stack = malloc(sizeof(t_stack))))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (argc == 2)
	{
		stack = str_stack_popu(stack, argv);
		stack = normalise(&stack);
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
	stack = normalise(&stack);
	return (stack);
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
