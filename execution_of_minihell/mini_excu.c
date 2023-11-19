/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/19 17:22:33 by momihamm         ###   ########.fr       */
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
    // t_node **kmi = take_env (env);
    // print_export (kmi);
    // print_list (kmi);
    env_command (env);
    // printf ("########################################\n");
    // char **wi = ft_split (" 9223372036854775808  ", ' ');
    // int word = num_of_word (" 0 ", ' ');
    // char **fuck = ft_split (" kmi  wennc", ' ');
    // int wordf = num_of_word (" kmi  d ", ' ');
    // ft_exit (wi);
    // // my_echo_n (wi);
    // // cd_command (kmi, wi);
    // // print_export (kmi);
    // // my_pdw ();
    // printf ("########################################\n");
    // export_command (kmi, wi);
    // print_export (kmi);
    // printf ("########################################\n");
    // unset_command (kmi, fuck);
    // print_export (kmi);
    // free_all (wi, word);
    // free_all (fuck, wordf);
    // ft_free_contnue (kmi);
    // ft_free_list (kmi);
    // env_command (env);
}