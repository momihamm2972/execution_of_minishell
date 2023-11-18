/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/18 20:34:36 by momihamm         ###   ########.fr       */
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
    char **wi = ft_split (" -n -nnnnnnnnnnn -nnnnnnnnnnnnnnnnnnnnnnn kmi -nn ", ' ');
    int word = num_of_word (" -n -nnnnnnnnnnn -nnnnnnnnnnnnnnnnnnnnnnn kmi -nnnnnnnnnnnn ", ' ');
    my_echo_n (wi);
    // printf ("+++%d+++\n", status);
    free_all (wi, word);
}