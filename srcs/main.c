#include "push_swap.h"

t_stack *allocation(t_stack *stack_a, int nbr)
{
    t_stack *tmp;
    t_stack *new;

    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    new->number = nbr;
    new->next = NULL;
    new->previous = NULL;
    new->last = NULL;
    if (stack_a == NULL)
    {
        return (new);
    }
    tmp = stack_a;
    while (tmp->next)
        tmp = tmp->next;
    new->previous = tmp;
    tmp->next = new;
    stack_a->first = stack_a;
    stack_a->last = new;
    return (stack_a);
}

void swap(t_stack **stack_a)
{
    t_stack *tmp;
    // t_stack *tmp_next;
    // t_stack *tmp_next_next;
    // t_stack *tmp_next;

    tmp = (*stack_a)->next;
    // tmp_next = (*stack_a)->next;
    // tmp_next_next = (*stack_a)->next;

    // (*stack_a)->next->previous = NULL;
    (*stack_a)->next = (*stack_a)->next->next;
    (*stack_a)->next->previous = *stack_a;
    tmp->next = *stack_a;
    tmp->previous = NULL;
    (*stack_a) = tmp;
    (*stack_a)->first = *stack_a;
}
int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *tmp;
    int count;
    int index;

    stack_a = NULL;
    count = 2;
    index = 1;
    if (ac > 2)
    {
        while (count <= ac)
        {
            stack_a = allocation(stack_a, ft_atoi(av[index++]));
            count++;
        }
    }
    else
        printf("Hi shi haja mahiya!\n");
    printf("========== before swaap ==========\n");
    tmp = stack_a;
    while (tmp)
    {
        printf("%d\n", tmp->number);
        tmp = tmp->next;
    }
    swap(&stack_a);
    printf("========== after swaap ==========\n");
    tmp = stack_a;
    while (tmp)
    {
        printf("%d\n", tmp->number);
        tmp = tmp->next;
    }
    return (0);
}