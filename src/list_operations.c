/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:55:58 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/15 22:12:35 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void		free_list(t_stack *stack)
{
	while (stack)
	{
		free(stack);
		stack = stack->next;
	}
}

void		push(t_stack **head, int val)
{
	t_stack *node;

	node = stack_new(val);
	node->next = *head;
	*head = node;
}

t_stack		*stack_new(int val)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	(stack)->num = val;
	(stack)->next = NULL;
	return (stack);
}

void		str_stack_popu(t_stack **stack, char **argv)
{
	static char	**args;
	int			i;

	args = ft_strsplit(argv[1], ' ');
	i = ft_wordcount(argv[1], ' ') - 1;
	while (i >= 0)
	{
		push(stack, ft_atoi(args[i]));
		i--;
	}
}

t_stack		*stack_popu(int argc, char **argv)
{
	t_stack	*stack;
	t_stack *norm;
	int		i;

	stack = NULL;
	norm = NULL;
	if (argc == 2)
	{
		str_stack_popu(&stack, argv);
		norm = normalize(&stack);
		free_list(stack);
		return (norm);
	}
	i = (argc - 1);
	stack = stack_new(ft_atoi(argv[i--]));
	while (i >= 1)
	{
		push(&stack, ft_atoi(argv[i--]));
	}
	norm = normalize(&stack);
	free_list(stack);
	return (norm);
}
