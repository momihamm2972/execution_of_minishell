/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:55:01 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/02 14:50:27 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXCU_H
# define MINI_EXCU_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct node
{
    char *key;
    char *value_of_the_key;
    struct node *next;
}t_node;

/*##################################FUNCTOINS##################################*/
t_node	**take_env(char **env);
t_node	*ft_lstnew(char *env_val);
void	ft_lstadd_front(t_node **lst, t_node *new);
int	ft_lstsize(t_node *lst);
int ft_len(char const *str, char c);
t_node	*ft_lstlast(t_node **lst);
void	print_list(t_node **list);
char	*ft_strdup(const char *s1);
void	ft_lstadd_back(t_node **lst, t_node *new);
void    my_pdw(void);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *to, const void *from, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void    my_echo_n(char *mess);
void    env_command(char **env);
char	*ft_frontcpy(char *dst, const char *src, char del);
char	*ft_backcpy(char *dst, const char *src, char del);
/*#############################################################################*/

#endif