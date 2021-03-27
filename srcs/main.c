#include "push_swap.h"

void print(t_stack *a, t_stack *b)
{
    t_stack *tmp_a = a;
    t_stack *tmp_b = b;

    printf("|            a            |            b            |\n");
    printf("|---------------------------------------------------|\n");

    while (tmp_a || tmp_b)
    {
        if (tmp_a && tmp_b)
            printf("|            %d            |            %d            |\n", tmp_a->number, tmp_b->number);
        else if (!tmp_a && tmp_b)
            printf("|                         |            %d            |\n", tmp_b->number);
        else if (tmp_a && !tmp_b)
            printf("|            %d            |                         |\n", tmp_a->number);
        // printf("salam\n");
        if (tmp_a)
        {
            // ft_putendl_fd("a", 1);
            // getchar();
            tmp_a = tmp_a->next;
        }
        if (tmp_b)
        {
            // ft_putendl_fd("b", 1);
            // getchar();
            tmp_b = tmp_b->next;
        }
    }
}
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    int count;
    int index;
    char *buffer;

    buffer = (char *)malloc(10);
    a = NULL;
    b = NULL;
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
    {
        printf("Hi shi haja mahiya!\n");
        exit(1);
    }
    while (1)
    {
        read(0, buffer, 10);
        if (!(ft_strncmp(buffer, "sa\n", 3)))
            swap(&a);
        if (!(ft_strncmp(buffer, "sb\n", 3)))
            swap(&b);
        if (!(ft_strncmp(buffer, "ss\n", 3)))
            sswap(a, b);
        if (!(ft_strncmp(buffer, "pa\n", 3)))
            push(&a, &b);
        if (!(ft_strncmp(buffer, "pb\n", 3)))
            push(&b, &a);
        if (!(ft_strncmp(buffer, "ra\n", 3)))
            reverse(&a);
        if (!(ft_strncmp(buffer, "rb\n", 3)))
            reverse(&b);
        if (!(ft_strncmp(buffer, "rr\n", 3)))
            rreverse(a, b);
        if (!(ft_strncmp(buffer, "rra\n", 4)))
            reverse_reverse(&a);
        if (!(ft_strncmp(buffer, "rrb\n", 4)))
            reverse_reverse(&b);
        if (!(ft_strncmp(buffer, "rrr\n", 4)))
            rreverse_reverse(a, b);
        print(a, b);
    }
    return (0);
}