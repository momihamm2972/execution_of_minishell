/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:55:01 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/05 21:58:52 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXCU_H
# define MINI_EXCU_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct node
{
    char *key;
    char *value_of_the_key;
    // int perv_position;
    // int next_position;
    struct node *next;
}t_node;

/*##################################FUNCTOINS##################################*/
t_node	**take_env(char **env);
t_node	*ft_lstnew(char *env_val);
void	ft_lstadd_front(t_node **lst, t_node *new);
char	*ft_frontcpy_p(char *dst, char *src, char del);
void	ft_free_list(t_node **list);
void	ft_free_contnue(t_node **lst);
int	ft_lstsize(t_node *lst);
int ft_len(char *str, char c);
t_node	*ft_lstlast(t_node **lst);
void	print_list(t_node **list);
char	*ft_strdup(char *s1);
void	ft_lstadd_back(t_node **lst, t_node *new);
void    my_pdw(void);
char	*ft_strdup(char *s1);
void	*ft_memcpy(void *to, const void *from, size_t len);
size_t	ft_strlen(char *s);
int	check_is_exist(t_node **list, char *var);
void	*ft_calloc(size_t count, size_t size);
void    my_echo_n(char *mess);
void    env_command(char **env);
char	*ft_frontcpy(char *dst, char *src, char del);
char	*ft_backcpy(char *dst, char *src, char del);
int	ft_strcmp(char *s1, char *s2);
void    swap_nodes(t_node **my_env);
void    export_command(t_node **my_env, char *arg);
int	is_ther_the_win_char(char *str, char c);
/*#############################################################################*/

#endif