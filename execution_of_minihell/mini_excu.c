/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/23 06:49:37 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void    mr()
{
    system ("leaks minihell");
}

// int	execcmd(int fd_in, int fd_out, char **env, char **options, char *in_file, char *out_file, char *main_cmd)
// {
// 	(void) main_cmd;

// 	(void) in_file;
// 	(void) fd_in;
// 	(void) out_file;
// 	pid_t pid;

// 	// if (fd == -1)
// 	// 	return (-1);
// 	pid = fork ();
// 	if (pid == 0)
// 	{
//         // if (fd_in != -2)
//         // {
//         //     dup2 (fd_in, STDIN_FILENO);
//         //     close (fd_in);
//         // }
// 		if (fd_out != -2)
//         {
//             dup2 (fd_out, STDOUT_FILENO);
//             close (fd_out);
//         }
//         execve ("/bin/cat", options, env);///usr/bin/wc"
// 	}
// 	return (0);
// }

int execcmd(int fd_in, int fd_out, char **env, char **options, char *in_file, char *out_file, char *main_cmd)
{
    (void) main_cmd;
    (void) in_file;
    (void) out_file;

    pid_t pid;

    // if (fd == -1)
    //     return (-1);

    pid = fork();
    if (pid == 0)
    {
		if (fd_in != -2 && fd_in > 0)
        {
            dup2(fd_in, STDIN_FILENO);
            close(fd_in);
        }
        if (fd_out != -2 && fd_out > 0)
        {
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        }

        execve("/usr/bin/wc", options, env);
        // Handle execve failure, if needed
        perror("execve");
        exit(EXIT_FAILURE);
    }
    return 0;
}



int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    (void) env;

    char *command = strdup("wc -l");
    char **options = ft_split(command, ' ');
	char *main_cmd = ft_strdup (options[0]);
    char *infile = strdup("Makefile"); //null
    char *outfile = strdup("wcccccccc"); // NULL

    int fd_in =  open (infile, O_RDONLY , 0777); // 4
    int fd_out = open (outfile, O_WRONLY | O_CREAT | O_APPEND , 0777); // 4



    // int fd = open ("lkmaya.txt", O_WRONLY | O_CREAT | O_TRUNC  , 0777);
    // out_file (fd, env, options);
	execcmd (fd_in, fd_out, env,options, infile, outfile, main_cmd);
    // task execute this shit
    // fork : {
        // 1 - check if there is an infile, (fd_in != -2) ==> yes there is, (fd_in == -2 no there is not)
    //         1.1 - if (there is) ==> redirect the standard_in to in_file using dup2
    //     2 - check if there is an infile, (fd_in != -2) ==> yes there is, (fd_in == -2 no there is not)
    //         2.1 - if (there is) ==> redirect the standard_in to in_file using dup2
        
    //     3 - execute using execve()
    // }

}






// unset SECURITYSESSIONID  USER  MallocNanoZone  COMMAND_MODE  PATH HOME  SHELL LaunchInstanceID  __CF_USER_TEXT_ENCODING  XPC_SERVICE_NAME   SSH_AUTH_SOCK XPC_FLAGS LOGNAME  TMPDIR ORIGINAL_XDG_CURRENT_DESKTOP   SHLVL   PWD  OLDPWD  TERM_PROGRAM  TERM_PROGRAM_VERSION  LANG COLORTERM TERM_PROGRAM_VERSION  GIT_ASKPASS   VSCODE_GIT_ASKPASS_NODE VSCODE_GIT_ASKPASS_EXTRA_ARGS  VSCODE_GIT_ASKPASS_MAIN  VSCODE_GIT_IPC_HANDLE   VSCODE_INJECTION   ZDOTDIR  USER_ZDOTDIR  USER_ZDOTDIR  TERM _



// *****update env fach katreje l dossi l9eble makan updatich*****