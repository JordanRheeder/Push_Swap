#include "push_swap.h"

int     sorted(t_stack *a)
{
    int temp;

    if (!a)
        return (0);
    while (a->next)
    {
        temp = a->num;
        a = a->next;
        if (temp > a->num && a)
            return (0);
    }
    return (1);
}