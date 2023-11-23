/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:02:53 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/23 05:47:35 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

// int	redirection_excution(int fd, int type, char **cmd, char *file)
// {
// 	if (fd == -1)
// 		return (-1);
// 	if (type == 3)
// 		out_file(fd, cmd);
// 	else if (type == 4)
// 		out_over(fd, cmd);
// 	return (0);
// }

int	out_file(int fd, char **env, char **cmd)
{
	pid_t pid;

	if (fd == -1)
		return (-1);
	pid = fork ();
	if (pid == 0)
	{
		dup2 (fd, 1);
		close (fd);
		execve ("/bin/ls", cmd, env);
	}
	return (0);
}

// int	out_over(int fd, int type, char *name)
// {
	
// }
