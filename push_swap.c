#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// implement logic.
// void	sortedInsert(t_stack **head, t_stack *new_head)
// {
// 	t_stack *current;
// 	if (*head == NULL || (*head)->num >= new_head->num)
// 	{
// 		new_head->next = *head;
// 		*head = new_head;
// 	}
// 	else
// 	{
// 		// find the location before the point of insertion
// 		current = *head;
// 		while(current->next != NULL && current->next->num < new_head->num)
// 		{
// 			current = current->next; // point to next
// 		}
// 		new_head->next = current->next;
// 		current->next = new_head;
// 	}
// }

// void	insertionSort(t_stack **head)
// {
// 	t_stack *sorted = NULL;
// 	t_stack *current = *head;
// 	while (current != NULL)
// 	{
// 		t_stack *next = current->next;
// 		sortedInsert(&sorted, current);
// 		current = next;
// 	}
// 	*head = sorted;
// }

int main (int argc, char *argv[])
{
    t_stack	*stack_a;
	t_stack *stack_b;

    char ops[4][4] = {"rra", "ra", "pb"};

    stack_b = NULL;
//    cmds = malloc(sizeof(t_ops) * 4);
    if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
    stack_a = stack_new(argc, argv);
//    ft_putendl_fd(ops[0], 1);
    ft_putendl_fd(ops[1], 1);
//    ft_putendl_fd(ops[2], 1);
//    ft_putendl_fd(ops[2], 1);
    
   // cmds = stackpopulate(2, ops);
    // cmds->op = "sa";
    // cmds->next = NULL;
    // while (cmds != NULL)
    // {
    //     if(check_op(cmds->op))
    //         ft_putstr_fd(cmds->op, 1);
    //     cmds = cmds->next;
    // }
    return (0);
}