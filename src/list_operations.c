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

void	push(t_stack **head, int val)
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


int		pop(t_stack **head)
{
	int		ret;
	t_stack	*next_node;

	if (*head == NULL)
		return (-1);
	next_node = NULL;
	ret = -1;
	next_node = (*head)->next;
	ret = (*head)->num;
	free(*head);
	*head = next_node;
	return (ret);
}

int		list_length(t_stack **head)
{
	int		cnt;
	t_stack *tmp;
	cnt = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

void	str_stack_popu(t_stack **stack, char **argv)
{
	int		i;
	static char	**args;
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
		while (stack)
		{
			free(stack);
			stack = stack->next;
		}
		return (norm);
	}
	i = (argc - 1);
	stack = stack_new(ft_atoi(argv[i--]));
	while (i >= 1)
	{
		push(&stack, ft_atoi(argv[i--]));
	}
	norm = normalize(&stack);
	while (stack)
	{
		free(stack);
		stack = stack->next;
	}
	return (norm);
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
