

// void step_two(t_stack **a, t_stack **b)
// {
//     t_save save;
//     t_tmp tmp;
//     int min;
//     int max;
//     t_tools tool;
//     int operation;
//     int check;
//     int i = 0;

//     tmp = init_tmp(*a, *b);
//     save = search_for_minmax(tmp.a, tmp.b);
//     tmp = init_tmp(*a, *b);
//     tmp = init_tmp(*a, *b);
//     tmp = init_tmp(*a, *b);
//     tool.len_a = count_len_stack(tmp.a);
//     tool.len_b = count_len_stack(tmp.b);
//     tool.med_a = tool.len_a / 2;
//     tool.med_b = tool.len_b / 2;
//     if (tool.len_a % 2 != 0)
//         tool.med_a++;
//     if (tool.len_b % 2 != 0)
//         tool.med_b++;
//     tmp = init_tmp(*a, *b);
//     while (tmp.a || tmp.b)
//     {
//         min = search_for_min(save, tmp.b);
//         max = search_for_max(save, tmp.a);
//         tmp = init_tmp(*a, *b);
//         tool.count_a = count_to_number(tmp.a, max);
//         tool.count_b = count_to_number(tmp.b, min);
//         printf("max ==> %d|\t|min ==> %d|\n", max, min);
//         tool.diff_a = tool.count_a - tool.med_a;
//         tool.diff_b = tool.count_b - tool.med_b;
//         getchar();
//         printf("|count.a ==> %d|\t|med.a ==> |%d|\t|diff_a ==> {%d}\n", tool.count_a, tool.med_a, tool.diff_a);
//         printf("|count.b ==> %d|\t|med.b ==> |%d|\t|diff_b ==> {%d}\n", tool.count_b, tool.med_b, tool.diff_b);
//         tmp = init_tmp(*a, *b);
//         check = which_operation(tmp.a, tmp.b, tool);
//         printf("check ==> {%d}\n", check);
//         getchar();
//         if (check == RREVERSE)
//         {
//             while (tmp.a->number != max && tmp.b->number != min)
//                 rreverse(&tmp.a, &tmp.b);
//             printf("*********************************\n");
//             print(tmp.a, tmp.b);
//             printf("*********************************\n");
//             while (tmp.a->number != max)
//                 reverse(&tmp.a);
//             while (tmp.b->number != min)
//                 reverse(&tmp.b);
//             printf("######################################\n");
//             print(tmp.a, tmp.b);
//             printf("######################################\n");
//             push(&tmp.a, &tmp.b);
//             reverse(&tmp.a);
//             push(&tmp.b, &tmp.a);
//             reverse(&tmp.b);
//             print(tmp.a, tmp.b);
//         printf("{i ==> %d}\n", i++);
//         }
//         *a = tmp.a;
//         *b = tmp.b;
//     }
// }

// void step_one(t_stack **a, t_stack **b)
// {
//     t_stack *tmp;
//     int if_true;
//     int pivot;
//     int index;
//     int calcul;

//     index = 0;
//     if_true = 1;
//     tmp = *a;
//     pivot = search_for_pivot(*a, &calcul);
//     *a = tmp;
//     while (tmp && index < calcul)
//     {
//         if (tmp->number > pivot)
//         {
//             index = 0;
//             if_true = 1;
//             push(&(*b), &tmp);
//         }
//         else
//         {
//             if (if_true == 1)
//             {
//                 calcul = calcul_for_reverse(tmp);
//                 if_true = 0;
//             }
//             reverse(&tmp);
//             index++;
//         }
//     }
//     *a = tmp;
//     print(*a, *b);
// }