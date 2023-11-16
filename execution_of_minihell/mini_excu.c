/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/16 19:03:40 by momihamm         ###   ########.fr       */
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
    char **wi = ft_split (" 9223 ", ' ');
    int word = num_of_word (" 9223  ", ' ');
    ft_exit (wi);
    printf ("+++%d+++\n", status);
    free_all (wi, word);
}