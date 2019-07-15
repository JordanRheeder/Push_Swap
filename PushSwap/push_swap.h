#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct      s_stack
{
    int             num;
    struct s_stack  *next;
}                   t_stack;

void				push(t_stack **head, int val);
int					pop(t_stack **head);
void				print_stack(t_stack **stack);
t_stack				*stack_new(int ac, char **av);
int					getCount(t_stack *head);
void				pa(t_stack **dst, t_stack **src);
void				pb(t_stack **dst, t_stack **src);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				ra(t_stack **a);
void				rrb(t_stack **b);
void				rb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void                rr(t_stack **a, t_stack **b);

//
void                read_input(t_stack **stack_a, t_stack **stack_b, char **line);
int                 sorted(t_stack *stack_a);
void                free_stack(t_stack *stack);
int                 check_line(char *line);
int                 check_op(char *line);
void                do_op(t_stack **stack_a, t_stack **stack_b, char *line);

#endif