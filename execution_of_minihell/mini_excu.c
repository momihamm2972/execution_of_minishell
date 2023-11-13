 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/10 22:22:40 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void    mr()
{
    system ("leaks minihell");
}

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    (void) env;
    // atexit (mr);
    // char *st;
    // char *st = av[1];
    char st[1000] = " tabi3a=m9wed        mouad=$$$   " ; // ___=hhh       mouad=11 mouad
    char fm[1000] = " ORIGINAL_XDG_CURRENT_DESKTOP        COLORTERM  *kdfi TERM   tabi3a " ; // ___=hhh       mouad=11 mouad
    char **kmi = ft_split (st, ' ');  
    char **zb = ft_split (fm, ' ');
    int words = num_of_word (st, ' ');
    t_node **my_env = take_env (env);
    (void) my_env;
    // (void) words;
    // int i =0;
    // t_node *dor;
    // dor = (*my_env);
    // while (dor)
    // {
    //     if (i == 1)
    //         dor->next = NULL;
    //     dor = dor->next;
    //     i++;
    // }
    export_command (my_env, kmi);
    // print_export (my_env);
    export_command (my_env, NULL);
    // unset_command (my_env, "lkmaya");
    // printf ("kmii*iiÏ\n");
    unset_command (my_env, zb);
    printf ("\n**********************jflaksfl***************************\n\n");
    export_command (my_env, NULL);
    // export_command (my_env, NULL);
    // printf ("kmiii|iÏ\n");
    free_all (kmi, words);
    // printf ("km>iiiiÏ\n");
    ft_free_contnue (my_env);
    // printf ("km@@iiiiÏ\n");
    ft_free_list (my_env);
}