/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:55:01 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/22 03:31:47 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXCU_H
# define MINI_EXCU_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

# include <limits.h>
# include <fcntl.h>

/*###########################GOLOBAL VARIABLE#################################*/

/*############################################################################*/

typedef struct node
{
	char		*key;
	char		*value_of_the_key;
	int			plus;
	int			equl;
	struct node	*next;
}t_node;

/*##################################FUNCTOINS#################################*/
t_node		**take_env(char **env);
t_node		*check_is_exist(t_node **list, char *var);
t_node		*take_key_vlu(char *str);
t_node		*get_node(t_node **list, char *str);
t_node		*ft_lstnew(char *env_val);
t_node		*ft_lstlast(t_node **lst);
t_node		*take_key_vlu(char *str);
t_node		*check_is_exist(t_node **list, char *var);
void		swap_nodes(t_node **my_env);
void		take_out(char *str);
void		print_export(t_node **list);
void		error_export(char *key, char *val);
void		export_remplass(t_node *list, t_node *one);
void		remplace(t_node *list, t_node *one);
void		export_conca(t_node *list, t_node *one);
void		take_last_link(t_node **env, t_node *new);
void		check_link(t_node **my_env, t_node *new);
void		intial(t_node *new, char *str);
void		unset_out_error(char *str);
void		cd_command(t_node **env, char **arg);
void		ft_exit(char **matrix);
void		print_oldpwd(t_node **my_env);
void		ft_lstadd_front(t_node **lst, t_node *new);
char		*ft_frontcpy_p(char *dst, char *src, char del);
void		ft_free_list(t_node **list);
void		ft_free_contnue(t_node **lst);
void		print_list(t_node **list);
void		ft_lstadd_back(t_node **lst, t_node *new);
void		my_pdw(void);
void		*ft_calloc(size_t count, size_t size);
void		my_echo_n(char **argum);
void		env_command(char **env);
void		swap_nodes(t_node **my_env);
void		export_command(t_node **my_env, char **arg);
void		free_all(char **s, int ptrs);
void		print_export(t_node **list);
void		*ft_memcpy(void *to, const void *from, size_t len);
void		make_out(t_node *node);
void		unset_command(t_node **env, char **str);
char		*ft_frontcpy_p(char *dst, char *src, char del);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(char *s1);
char		*ft_strdup(char *s1);
char		*ft_frontcpy(char *dst, char *src, char del);
char		**ft_split(char *s, char c);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_backcpy(char *dst, char *src, char del);
int			is_num_sp(char c);
int			whitout_plus(char c);
int			key_error(t_node *test);
int			how_alpha(char *str);
int			is_ther_plus(char *str);
int			is_equal(char *str);
int			check_nil(t_node **env, char **matrix);
int			unset_error(char *test);
int			ft_strcmp(char *s1, char *s2);
int			num_of_word(char *s, char c);
int			is_ther_the_win_char(char *str, char c, int len);
int			ft_isalpha(int c);
int			arg_path(char *str);
int			ft_lstsize(t_node *lst);
int			ft_len(char *str, char c);
int			ft_isdigit(int c);
long long	ft_atoi(char *str);
size_t		ft_strlen(char *s);




char	*add_plus(char *str);

void	print_2d(char **arr);
char	**make_list_arr(t_node **list);
void	ft_free_matrix_contnt(char **arr);
char    **find_path(t_node *an_node);
void    		let_exec_command(char **path, char **command, char **envment);
char    *ft_path(char *zero, char *cmd);



/*############################################################################*/

#endif