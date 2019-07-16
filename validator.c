#include "libft/libft.h"
#include "push_swap.h"
#include "stdio.h"

int     valid_input(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    j = 0;
    printf("%s\n\n", av[1]);
    if (ac == 2)
    {
        while (av[i][j] != '\0')
        {
            while (ft_isdigit(av[i][j]) || ft_iswhitespace(av[i][j]))
            {
                printf("j = %d\n\n", j);
                while (ft_iswhitespace(av[i][j]))
                    j++;
                if (!(ft_isdigit(av[i][j])))
                   return (0);
                if (av[i][j] == '\0')
                   break ;
                j++;
            }
        }
    }
    else if (ac > 2)
    {
    
        while (ft_isdigit(av[i][j]))
        {
            j = 0;
            while (ft_isdigit(av[i][j]) && av[i][j] != '\0')
           {
                j++;
                if (!(ft_isdigit(av[i][j])))
                   return (0);
           }
            i++;
       }
   }
   return (1);
}

int     sorted(t_stack *stack_a)
{
    int temp;

    if (!stack_a)
        return 0;
    while (stack_a->next)
    {
        temp = stack_a->num;
        stack_a = stack_a->next;
        if (temp > stack_a->num && stack_a)
            return 0;
    }
    return (1);
}
