/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:02:53 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/22 23:27:30 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

// int	redirection_file(int fd, int type, char *name)
// {
// 	if (fd == -1)
// 		return (-1);
// 	if (type == 3)
// 		out_file(fd, name);
// 	else if (type == 4)
// 		out_over(fd, name);
// 	return (0);
// }

int	out_file(int fd, char *name, char **env)
{
    (void) fd;
    (void) name;
    printf ("<%d>//%s\n", fd, name);
	if (fd == -1)
		return (-1);
	write (fd, "lkmaya", 6);
	char **sp = ft_split (" ls -la ",  ' ');
	pid_t pid = fork ();
	// (void)fid;
	if (pid == 0)
	{
		dup2 (fd, 1);
		execve ("/bin/ls", sp, env);
	}
    // int new_fd;
	// dup2 (1, fd);
	printf ("hhhhhhhh\n");
    // new_fd = dup (fd);
	return (0);
}
