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

	node = malloc(sizeof(t_stack));
	node->num = val;
	node->next = *head;
	*head = node;
}

void	stack_new(t_stack **stack, int val)
{
	(*stack)->num = val;
	(*stack)->next = NULL;
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

t_stack		*str_stack_popu(t_stack *stack, char **argv)
{
	int		i;
	char	**args;

	stack = malloc(sizeof(t_stack));
	args = ft_strsplit(argv[1], ' ');
	i = ft_wordcount(argv[1], ' ') - 1;
	stack_new(&stack, ft_atoi(args[i]));	
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
		stack = normalize(&stack);
		return (stack);
	}
	i = (argc - 1);
	stack_new(&stack, ft_atoi(argv[i--]));
	while (i >= 1)
		push(&stack, ft_atoi(argv[i--]));
	stack = normalize(&stack);
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
