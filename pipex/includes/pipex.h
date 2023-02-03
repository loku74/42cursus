/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:22:14 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/09 10:25:47 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

# define IN 0
# define OUT 1

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		pipe_1[2];
	int		pipe_2[2];
	int		*pids;
	char	**paths;
	char	**envp;
}	t_pipex;

// ft_close.c
void	ft_close_pipes(t_pipex *pipex);
void	ft_close_fd(t_pipex *pipex);

// ft_check.c
void	ft_check_files_error(t_pipex *pipex, int argc, char **argv);

// ft_create.c
void	ft_create_paths(t_pipex *pipex, char **envp);
void	ft_create_forks(t_pipex *pipex, int argc, char **argv);

// ft_execute.c
void	ft_init_fd(t_pipex *pipex, char **argv, int i, int argc);

// ft_exit.c
void	ft_exit(t_pipex *pipex);

// ft_free.c
void	ft_free_paths(char **paths);
void	ft_free_cmds(char **cmds);

// ft_utils.c && ft_utils2.c
char	**ft_pipex_split(char *str);
int		is_in(char *str, char *charset);
char	*ft_pipex_strrchr(char *s, int c);

#endif