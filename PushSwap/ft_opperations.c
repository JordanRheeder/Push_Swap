#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void    push(t_stack **head, int val)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	node->num = val;
	node->next = *head;
	*head = node;
}

int		pop(t_stack **head)
{
	int	retval = -1;
	t_stack *next_node = NULL;

	if (*head == NULL)
	{
		return (-1);
	}
	next_node = (*head)->next;
	retval = (*head)->num;
	free(*head);
	*head = next_node;
	return (retval);
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

t_stack		*stack_new(int ac, char **av)
{
	t_stack *stack_a;
	int i;

	if (!(stack_a = malloc(sizeof(t_stack))))
	{
		ft_putstr("Error\n"); // remove later
		return (0);
	}
	i = (ac - 1);
	stack_a->num = ft_atoi(av[i]);
	stack_a->next = NULL;
	i--;
	while (i >= 1)
	{
		push(&stack_a, ft_atoi(av[i])); // populating the list
		i--;
	}
	return (stack_a);
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

	first = (*stack_a); // new first node
	last = (*stack_a); // pointing to null
	printf("ra\n"); // remove me later
	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	while (last->next != NULL) // itterate till you find the null pointer.
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
	printf("rb\n"); //remove me later
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
