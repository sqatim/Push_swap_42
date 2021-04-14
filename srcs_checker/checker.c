#include "checker.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stack *tmp;
    int arg;

    a = NULL;
    b = NULL;
    a = check_affec(ac, av, a, &arg);
    read_instructions(&a, &b, arg);
    tmp = a;
    while (a->next)
    {
        if (a->number > a->next->number || b)
        {
            if (b)
                printf("stack b Not Empty");
            free_2_stack(&a, &b);
            ft_putendl_fd("\033[1;31mKO\033[0m", 1);
            exit(1);
        }
        a = a->next;
    }
    a = tmp;
    free_2_stack(&a, &b);
    ft_putendl_fd("\033[1;32mOK\033[0m", 1);
    return (0);
}