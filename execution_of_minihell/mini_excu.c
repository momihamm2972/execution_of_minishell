/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/20 00:13:42 by momihamm         ###   ########.fr       */
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
    t_node **kmi = take_env (env);
    // print_export (kmi);
    // print_list (kmi);
    // env_command (env);
    char **wi = ft_split (" kmi  ", ' ');
    int word = num_of_word (" 0 ", ' ');
    // char **fuck = ft_split (" -  ", ' ');
    // int worfd = num_of_word (" 0 ", ' ');
    // my_echo_n (wi);
    // printf ("########################################\n");
    // env_command (env);
    print_list (kmi);
    printf ("#########################################\n");
    cd_command (kmi, wi);
    print_list (kmi);
    // printf ("########################################\n");
    // cd_command (kmi, fuck);
    // env_command (env);
    // printf ("########################################\n");
    // env_command (env);
    free_all (wi, word);
    // free_all (fuck, worfd);
    // free_all (fuck, wordf);
    ft_free_contnue (kmi);
    ft_free_list (kmi);
    // env_command (env);
}










*****update env fach katreje l dossi l9eble makan updatich*****