/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/21 18:59:40 by momihamm         ###   ########.fr       */
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
    char **split = ft_split (" ls -al ", ' ');
    // printf ("|%s|",add_plus ("SECURITYSESSIONID"));
    t_node **kmi = take_env (env);
    char **dd = make_list_arr (kmi);
    char **path = find_path (get_node (kmi, "PATH"));
    // print_2d (dd);
    // printf ("################################\n");
    // print_2d (path);
    let_exec_command (path, split, dd);
    // execve (ft_strjoin (path[3], "/ls"), split, env);
    // exec_command (ft_path (path[3], "/ls"), split, env);
    printf ("kmidf\n");
    free_all (split, num_of_word (" ls -al ", ' '));
    ft_free_matrix_contnt (dd);
    ft_free_contnue (kmi);
    ft_free_list (kmi);
}






// unset SECURITYSESSIONID  USER  MallocNanoZone  COMMAND_MODE  PATH HOME  SHELL LaunchInstanceID  __CF_USER_TEXT_ENCODING  XPC_SERVICE_NAME   SSH_AUTH_SOCK XPC_FLAGS LOGNAME  TMPDIR ORIGINAL_XDG_CURRENT_DESKTOP   SHLVL   PWD  OLDPWD  TERM_PROGRAM  TERM_PROGRAM_VERSION  LANG COLORTERM TERM_PROGRAM_VERSION  GIT_ASKPASS   VSCODE_GIT_ASKPASS_NODE VSCODE_GIT_ASKPASS_EXTRA_ARGS  VSCODE_GIT_ASKPASS_MAIN  VSCODE_GIT_IPC_HANDLE   VSCODE_INJECTION   ZDOTDIR  USER_ZDOTDIR  USER_ZDOTDIR  TERM _



// *****update env fach katreje l dossi l9eble makan updatich*****