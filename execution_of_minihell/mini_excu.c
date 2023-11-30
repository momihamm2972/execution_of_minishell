
#include "mini_excu.h"

void    mr()
{
    system ("leaks minihell");
}

 void    ft_free_tokens(t_tokens **cmdline)
{
    t_tokens *tmp;

    while (*cmdline)
    {
        tmp = *cmdline;
        *cmdline = (*cmdline)->next;
        if (tmp)
        {
            if (tmp->input)
                free(tmp->input);
            if (tmp->options)
                ft_free_matrix_contnt(tmp->options);
            free(tmp);
        }
    }
} 

int	ft_lstsize_token(t_tokens *lst)
{
	t_tokens	*j;
	int			i;

	if (!lst)
		return (0);
	j = lst;
	i = 0;
	while (j != NULL)
	{
		j = lst -> next;
		lst = j;
		i++;
	}
	return (i);
}

int execcmd_red(int fd_in, int fd_out, char **env, char **options, char *in_file, char *out_file, char *main_cmd)
{
    (void) main_cmd;
    (void) in_file;
    (void) out_file;
    (void)fd_in;
    (void)fd_out;

    pid_t pid;
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
        perror("execve");
        exit(EXIT_FAILURE);
    }
    waitpid(pid, NULL, 0);
    return 0;
}

char    *get_path_cmand(char **path, char **command)
{
	// pid_t	pid;
	char	*slash;
	char	*cmd_path;
	int		row;

	row = 0;
	slash = add_slash (command[row]);
	cmd_path = NULL;
	while (path[row])
	{
		if (cmd_path)
			free (cmd_path);
		cmd_path = ft_strjoin (path[row], slash);
		if (access (cmd_path, F_OK) == 0)
		{
			return (cmd_path);
		}
		row++;
	}
	free (cmd_path);
	ft_free_matrix_contnt (path);
	free (slash);
	return (NULL);
}

void	cmd_in_pipe(t_tokens *list, t_node **my_list, int i_fd, int o_fd, char **env)
{
	pid_t	pid;
	char	**matrix;
	char	*cmd_path;

	pid = fork ();
	if (pid == -1)
	{
		perror ("fork");
		exit (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (i_fd != STDIN_FILENO)
		{
			dup2 (i_fd, STDIN_FILENO);
			close (i_fd);
		}
		if (o_fd != STDOUT_FILENO)
		{
			dup2 (o_fd, STDOUT_FILENO);
			close (o_fd);
		}
		matrix = ft_split (get_node (my_list, "PATH")->value_of_the_key, ':');
		cmd_path = get_path_cmand(matrix,list->options);
		if (!cmd_path)
			printf (" command not found: %s\n", list->options[0]);
		execve (cmd_path, list->options, env);
		ft_free_matrix_contnt (matrix);
		exit(EXIT_FAILURE);
	}
	else
		waitpid (pid, NULL, 0);
}


void    bipa(t_tokens **list, t_node **my_list, char **env)
{
    t_tokens	*ptr;
	int			size;
	int			pipat[ft_lstsize_token((*list)) - 1][2];
	int			indx;

    ptr = (*list);
	size = ft_lstsize_token ((*list));
	indx = 0;
	while (indx < size -1)
	{
		pipe(pipat[indx]);
		indx++;
	}
	indx = 0;
    while (ptr && indx < size)
    {
		if (indx == 0)
		{
			cmd_in_pipe (ptr, my_list, 0, pipat[indx][1], env);
			close (pipat[indx][1]);
		}
		else if (indx > 0 && indx < size - 1)
		{
			cmd_in_pipe (ptr, my_list,pipat[indx - 1][0], pipat[indx][1], env);
			close (pipat[indx - 1][0]);
			close (pipat[indx][1]);
		}
		else
		{
			cmd_in_pipe (ptr,my_list, pipat[indx - 1][0], 1, env);
			close (pipat[indx - 1][0]);
		}
		indx++;
		ptr = ptr->next;
    }
}

// void	ft_fre

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    (void) env;
	atexit (mr);
    t_tokens *lkmaya;
    t_tokens *chto;
    t_tokens *wiwi;
    lkmaya = malloc (sizeof (t_tokens));
    chto = malloc (sizeof (t_tokens));
    wiwi = malloc (sizeof (t_tokens));
    lkmaya->next = chto;
    chto->next = wiwi;
    // lkmaya->input = ft_strdup ("ls -la");
    // lkmaya->cmd = ft_strdup ("ls");
    lkmaya->options = ft_split ("ls -la", ' ');
    // chto->input = ft_strdup ("wc -l");
    // chto->cmd = ft_strdup ("wc");
    chto->options = ft_split ("wc -l", ' ');
//    
    // chto->input = ft_strdup ("wc -l");
    // wiwi->cmd = ft_strdup ("wc");
    wiwi->options = ft_split ("wc -l", ' ');
    wiwi->i_fd =91;
    lkmaya->i_fd =1;
    chto->i_fd =1;
    chto->o_fd =5;
    wiwi->next = NULL;
	t_node **the_env = take_env (env);
    // int files[2];
        bipa ( &lkmaya ,the_env, env);
	ft_free_contnue (the_env);
	ft_free_list (the_env);
	ft_free_tokens (&lkmaya);

}

