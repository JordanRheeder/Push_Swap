#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "push_swap.h"
#include <stdio.h> //remove
int     valid_input(int ac, char **av)
{
    char **args;
    // int i;
    // int j;
    *args = *av;
    printf("%s", *args);
    // i = 0;
    if (ac == 2)
    {
        // try split the string to see if it then has valid inputs..
        //args = (char **)malloc(sizeof(char *) * (ft_word_count(*av, ' ')));
        printf("args: %s\n\n\n", *args);
        args = ft_strsplit(*args, ' ');
        printf("args: %s\n", *args);
        return (0);
    }
    // while(args[i][j] != '\0')
    // {
    //     j = 0; //reset j
    //     while (ft_isdigit(args[i][j]))
    //         j++;
    //     if (!(*args))
    //         return (1);
    //     i++;
    // }
    // }
    // else if (ac > 2)
    // {
    //     while(*av)
    //     {
    //         if (!(ft_isdigit(av[i][j])))
    //             return (0);
    //         av++;
    //     }
    // }
    return (0);
}

int main(int ac, char *av[])
{
    if (ac < 2)
        return 0;
    valid_input(ac, av);
    return (0);
}