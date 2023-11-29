/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:51:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/28 13:07:06 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

// void    bipa(int *files, t_tokens **kmi, char **env)
// {
//     printf ("%d\t%d\n",files[0], files[1]);
//     t_tokens *ptr;
//     pid_t pid;
//     // int file_of_reading = open ("example.txt", O_CREAT | O_RDWR  , 0777 );

//     ptr = (*kmi);
//     if (pipe (files) == 0)
//         printf ("kmi\n");
//     else
//         printf ("7amid\n");
//     while (ptr->next)
//     {
//         pid = fork();
//         if (pid == 0)
//         {
//             printf ("hide && seek %s\n",ptr->options[0]);
//             printf ("child\n");
//             close(files[0]);
//             dup2 (files[1], STDOUT_FILENO);
//             close (files[1]);
//             execve ("/bin/ls", ptr->options, env);
//         }
//         else
//             printf ("parent\n");
//             // ptr = ptr->next;
//         // if (ptr->next == NULL)
//         // {
//             // printf ("hide && seek %s\n",ptr->options[0]);
//             // pid = fork ();
//             // if (pid == 0)
//             // {
//             //     printf ("child1\n");
//             //     close(files[1]);
//             //     dup2 (files[0], STDIN_FILENO);
//             //     // dup2 (files[0], file_of_reading);
//             //     close (files[0]);
//             //     execve ("/usr/bin/wc", ptr->next->options, env);
//             // }
//         // }
//         ptr = ptr->next;
//     }
// }