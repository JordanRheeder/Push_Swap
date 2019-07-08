#include "push_swap.h"
#include "libft/libft.h"

void	push(t_stack **head, int val)
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
