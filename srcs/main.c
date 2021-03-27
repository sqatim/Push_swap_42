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
    if (stack_a == NULL)
        return (new);
    tmp = stack_a;
    while (tmp->next)
        tmp = tmp->next;
    new->previous = tmp;
    tmp->next = new;
    return (stack_a);
}

void swap(t_stack **stack)
{
    t_stack *tmp;
    t_stack *test;

    tmp = (*stack);
    (*stack) = (*stack)->next;
    tmp->next = (*stack)->next;
    tmp->next->previous = tmp;
    (*stack)->previous = NULL;
    (*stack)->next = tmp;
    test = *stack;
}

void reverse(t_stack **stack)
{
    t_stack *tmp;
    t_stack *last;

    tmp = (*stack);
    *stack = (*stack)->next;
    (*stack)->previous = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    tmp->next = NULL;
    tmp->previous = last;
    last->next = tmp;
}

t_stack *create_node(int number)
{
    t_stack *new;

    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    new->next = NULL;
    new->number = number;
    new->previous = NULL;
    return (new);
}
void push(t_stack **first, t_stack **second)
{
    t_stack *new;
    t_stack *tmp;

    if (*second == NULL)
    {
        ft_putendl_fd("Second Tab is empty",1);
        exit(1);
    }
    new = create_node((*second)->number);
    if (*first)
    {
        new->next = *first;
        (*first)->previous = new;
    }
    *first = new;
    if ((*second)->next)
        tmp = (*second)->next;
    printf("{second ==> %d}\n", (*second)->number);
    free(*second);
    *second = NULL;
    if (tmp)
        *second = tmp;
}
void reverse_reverse(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    (*stack)->previous = tmp;
    tmp->next = *stack;
    tmp->previous->next = NULL;
    tmp->previous = NULL;
    *stack = tmp;
}
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stack *tmp_a;
    t_stack *tmp_b;
    t_stack *save;
    int count;
    int index;

    a = NULL;
    count = 2;
    index = 1;
    if (ac > 2)
    {
        while (count <= ac)
        {
            a = allocation(a, ft_atoi(av[index++]));
            count++;
        }
    }
    else
        printf("Hi shi haja mahiya!\n");
    printf("========== before swaap ==========\n");
    tmp_a = a;
    while (tmp_a)
    {
        printf("%d\n", tmp_a->number);
        tmp_a = tmp_a->next;
    }
    push(&b, &a);
    push(&b, &a);
    push(&b, &a);
    push(&b, &a);
    tmp_b = b;
    printf("=======> push b <=======\n");
    while (tmp_b)
    {
        printf("%d\n", tmp_b->number);
        tmp_b = tmp_b->next;
    }

    tmp_a = a;
    printf("=======> a <=======\n");
    while (tmp_a)
    {
        printf("%d\n", tmp_a->number);
        tmp_a = tmp_a->next;
    }

    return (0);
}