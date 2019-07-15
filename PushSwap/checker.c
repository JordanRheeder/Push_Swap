#include "push_swap.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int main(int ac, char *av[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    char    *line;
    line = NULL;
    if (ac < 2)
    {
        ft_putstr("Error: ac< 2\n");
        return (0);
    }
    stack_a = stack_new(ac, av);
    read_input(&stack_a, &stack_b, &line);
    if (sorted(stack_a) && !stack_b)
    {
        //free_stack(stack_a);
        printf("OK!\n");
    }
    print_stack(&stack_a);
    return (0);
}