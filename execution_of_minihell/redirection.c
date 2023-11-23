/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:02:53 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/23 02:33:20 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

// int	redirection_file(int fd, int type)
// {
// 	if (fd == -1)
// 		return (-1);
// 	if (type == 3)
// 		out_file(fd);
// 	else if (type == 4)
// 		out_over(fd, name);
// 	return (0);
// }

int	out_file(int fd, char **env)
{
	pid_t pid;
	// (void)name;
	if (fd == -1)
		return (-1);
	// write (fd, "lkmaya", 6);
	char **sp = ft_split (" ls -la",  ' ');
	pid = fork ();
	if (pid == 0)
	{
		dup2 (fd, 1);
		execve ("/bin/ls", sp, env);
	}
	close (fd);
	// printf ("hhhhh||hhh\n");
	return (0);
}

// int	out_over(int fd, int type, char *name)
// {
	
// }
