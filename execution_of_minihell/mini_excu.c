/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/10 21:12:22 by momihamm         ###   ########.fr       */
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
    atexit (mr);
    // char *st;
    // char *st = av[1];
    char st[1000] = "    _*=kmi  wiiw=lafafa  wiiw+=inkou __=kmi lkmaya  lkmaya=gang   _=hello  ";//lkmaya  wiiw wiiw=14    " ; // ___=hhh       mouad=11 mouad
    char **kmi = ft_split (st, ' ');  
    int words = num_of_word (st, ' ');
    t_node **my_env = take_env (env);
    (void) my_env;
    (void) words;
    export_command (my_env, kmi);
    export_command (my_env, NULL);
    // export_command (my_env, NULL);
    free_all (kmi, words);
    ft_free_contnue (my_env);
    ft_free_list (my_env);
}