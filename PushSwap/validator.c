#include "libft/libft.h"
#include "push_swap.h"

// cycle through av[], check if it is  > max, < min, 

int     valid_input(int ac, char *av[])
{
    char **args;
    int i;
    int j;

    i = 0;
    if (ac == 2)
    {
        // try split the string to see if it then has valid inputs..
    args = (char **)malloc(sizeof(char *) * (ac - 1));
    args = ft_strsplit(*av, ' ');
    while(args[i][j] != '\0')
    {
        j = 0; //reset j
        while (ft_isdigit(args[i][j]))
            j++;
        if (!(*args))
            return (1);
        i++;
    }
    }
    else if (ac > 2)
    {
        while(*av)
        {
            if (!(ft_isdigit(av[i][j])));
                return (0);
            av++;
        }
    }
}

// find use for getcount
// int		getCount(t_stack *head)
// {
// 	int count = 0;
// 	t_stack *current = head;
// 	while (current != NULL)
// 	{
// 		count++;
// 		current = current->next;
// 	}
// 	return (count);
// }

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
