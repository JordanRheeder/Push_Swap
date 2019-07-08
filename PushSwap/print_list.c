#include "list.h"
#include "libft/libft.h"

void    print_list(t_list *list)
{
    while(list)
    {
        ft_putstr(list->str);
        list = list->next;
    }
}