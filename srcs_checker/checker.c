#include "checker.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stack *tmp;

    a = NULL;
    b = NULL;
    a = check_affec(ac, av, a);
    read_instructions(&a, &b);
    tmp = a;
    while (a->next)
    {
        if (a->number > a->next->number || b)
        {
            if (b)
                printf("stack b Not Empty");
            free_2_stack(&a, &b);
            ft_putendl_fd("KO", 1);
            exit(1);
        }
        a = a->next;
    }
    a = tmp;
    free_2_stack(&a, &b);
    ft_putendl_fd("OK", 1);
    return (0);
}