#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct      s_stack
{
    int             num;
    struct s_stack  *next;
}                   t_stack;

void				push(t_stack **head, int val);
t_stack				*stack_new(int ac, char **av);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

#endif