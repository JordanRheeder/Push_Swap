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

t_stack     *stack_new(int ac, char **av)
{
	t_stack *stack_a;
	int i;

	if (ac < 2)
		return (0); // output error message?
	if(!(stack_a = malloc(sizeof(t_stack))))
		return (0);
	i = ac;
	stack_a->num = ft_atoi(av[i - 1]);
	stack_a->next = NULL;
	i--;
	while (i >= 1)
	{
		push(&stack_a, ft_atoi(av[i])); // populating the list
		i--;
	}
	return (stack_a);
}

void	pa(t_stack **dst, t_stack **src)
{
	if (*dst && *src)
	{
		(*src)->next = *dst;
		*dst = *src;
	}
}

void	pb(t_stack **dst, t_stack **src)
{
	if (!(dst))
	{
		*dst = malloc(sizeof(t_stack));
		(*dst)->num = (*src)->num;
		(*dst)->next = NULL;
		//Need to free and point to NULL
	}
	else
	{
		(*src)->next = *dst;
		*dst = *src;
	}
}

void    sa(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void      sb(t_stack **b)
{
	t_stack *tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	ra(t_stack **a)
{
	t_stack *first;
	t_stack *last;

	first = (*a)->next; // new first node
	last = (*a); // pointing to null
	printf("ra\n");
	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	while (last->next != NULL) // itterate till you find the null pointer.
		last = last->next;
	(*a)->next = first->next;
	first->next = NULL;
	last->next = first;
}

int main(int ac, char *av[])
{
	t_stack *stack_a;  // actual list a
	t_stack *stack_b; // actual list b
	t_stack *print;  // to display the list
	
	stack_a = stack_new(ac, av);
	print = stack_a; // print points to stack_a to print...
	ra(&print);
	while (print->next != NULL)
	{
		printf("\n %d \n", print->num);
		print = print->next;
	}
	return (0);    
}