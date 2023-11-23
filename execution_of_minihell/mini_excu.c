
#include "mini_excu.h"

void    mr()
{
    system ("leaks minihell");
}

int execcmd(int fd_in, int fd_out, char **env, char **options, char *in_file, char *out_file, char *main_cmd)
{
    (void) main_cmd;
    (void) in_file;
    (void) out_file;
    (void)fd_in;
    (void)fd_out;

    pid_t pid;

    // if (fd == -1)
    // int fd[2];
    // pipe(fd);
    //     return (-1);
    pid = fork();
    if (pid == 0)
    {
		if (fd_in != -2)
        {
            dup2(fd_in, STDIN_FILENO);
            close(fd_in);
        }
        if (fd_out != -2 )
        {
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        }
        
        execve("/bin/cat", options, env);
        
        // Handle execve failure, if needed
        perror("execve");
        exit(EXIT_FAILURE);
    }
    waitpid(pid, NULL, 0);
    return 0;
}



int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    (void) env;

    char *command = strdup("cat ");
    char **options = ft_split(command, ' ');
	char *main_cmd = ft_strdup (options[0]);
    char *infile = strdup("Makefile"); //null
    char *outfile = strdup("wc.txt"); // NULL

    int fd_in =  open (infile, O_RDONLY , 0777); // 4
    int fd_out = open (outfile, O_WRONLY | O_CREAT | O_APPEND , 0777); // 4
    fd_in = -2;
    // int in = dup(STDIN_FILENO);
    // dup2(0, in);
    // ft_fre
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

