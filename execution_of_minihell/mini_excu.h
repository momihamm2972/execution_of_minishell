/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:55:01 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/01 18:44:20 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXCU_H
# define MINI_EXCU_H

# include <libc.h>

typedef struct node
{
    char **env;
    struct node *next;
}t_node;

/*##################################FUNCTOINS##################################*/
void    my_pdw(void);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *to, const void *from, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void    my_echo_n(char *mess);
void    env_command(char **env);
/*#############################################################################*/

#endif