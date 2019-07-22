#include "libft/libft.h"
#include "push_swap.h"
#include "stdio.h"

int     only_digits(char *str)
{
    while (*str)
    {
        if (!(ft_isdigit(*str)) && (!(ft_iswhitespace(*str))))
            return (0);
        str++;
    }
    return (1);
}

int     dupe_check(int ac, char **av)
{
    char **str;
    int i;
    int j;

    i = 1;
    str = NULL;
    if (ac == 2)
    {
        str = ft_strsplit(av[1], ' ');
        i = 0;
    }
    else
        str = av;
    while (str[i])
    {
        j = 1;
        while(str[i + j] != '\0')
        {
            if (ft_strequ(str[i], str[i + j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int     valid_input(int ac, char **av)
{
    int i;

    if (ac == 2)
    {
        char    **arr;
        int     i;

        arr = ft_strsplit(av[1], ' ');
        i = 0;
        if (!only_digits(av[1]))
            return (0);
        if (!dupe_check(ac, av))
            return (0);
        while (arr[i])
        {
            if (ft_int_overflows(arr[i]))
                return (0);
            i++;
        }
    }
    else if (ac > 2)
    {
        i = 1;
        while (av[i])
        {
            if (!only_digits(av[i]))
                return (0);
            if (ft_int_overflows(av[i]))
                return (0);
            i++;
        }
        if (!dupe_check(ac ,av))
            return (0);
    }
    return (1);
}
int     sorted(t_stack *stack_a)
{
    int temp;

    if (!stack_a)
        return (0);
    while (stack_a->next)
    {
        temp = stack_a->num;
        stack_a = stack_a->next;
        if (temp > stack_a->num && stack_a)
            return (0);
    }
    return (1);
}
