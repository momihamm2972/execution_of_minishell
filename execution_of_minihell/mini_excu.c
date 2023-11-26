
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

void    bipa(int *files, t_tokens **kmi, char **env)
{
    printf ("%d\t%d\n",files[0], files[1]);
    if (pipe (files) == 0)
        printf ("kmi\n");
    else
        printf ("7amid\n");
    // t_tokens *ptr;

    // ptr = (*kmi);
    // while (ptr)
    // {
    //     if (ptr->next == NULL)
    //         return;
        pid_t pid = fork();
        if (pid == 0)
        {
            printf ("child\n");
            close(files[0]);
            dup2 (files[1], STDOUT_FILENO);
            close (files[1]);
            execve ("/bin/ls", (*kmi)->options, env);
            // close
        }
        else
            printf ("parent\n");
        pid = fork ();
        if (pid == 0)
        {
            printf ("child1\n");
            close(files[1]);
            dup2 (files[0], STDIN_FILENO);
            close (files[0]);
            if ((*kmi)->i_fd == 91)
                execve ("/usr/bin/tr", (*kmi)->next->options, env);
            else
                execve ("/usr/bin/wc", (*kmi)->next->options, env);
            // close
        }
        else
            printf ("parent1\n");
    //     ptr = ptr->next;
    // }
}

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    (void) env;

    t_tokens *lkmaya;
    t_tokens *chto;
    t_tokens *wiwi;
    lkmaya = malloc (sizeof (t_tokens));
    chto = malloc (sizeof (t_tokens));
    wiwi = malloc (sizeof (t_tokens));
    lkmaya->next = chto;
    chto->next = wiwi;
    // lkmaya->input = ft_strdup ("ls -la");
    lkmaya->cmd = ft_strdup ("ls");
    lkmaya->options = ft_split ("ls -la", ' ');
    // chto->input = ft_strdup ("wc -l");
    chto->cmd = ft_strdup ("wc");
    chto->options = ft_split ("wc -l", ' ');
//    
    // chto->input = ft_strdup ("wc -l");
    wiwi->cmd = ft_strdup ("td");
    wiwi->options = ft_split ("td -d '\n'", ' ');
    wiwi->i_fd =91;
    lkmaya->i_fd =1;
    chto->i_fd =1;

    int files[2];
    files[0] = 1;
    files[1] = open ("money.txt", O_CREAT | O_RDWR, 0777);
    t_tokens *zaba = lkmaya;
    while (zaba)
    {
        if (zaba->next == NULL)
            return (0);
        bipa (files, &zaba, env);
        zaba = zaba->next;
    }

}

