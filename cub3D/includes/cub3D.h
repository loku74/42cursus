/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:54:05 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/24 09:54:06 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <math.h> // to remove if unused

# define RED			"\033[1;31m"
# define YELLOW			"\033[1;33m"
# define NC				"\033[0m"

typedef enum e_bool		t_bool;
typedef enum e_exit		t_exit;

typedef struct s_data	t_data;
typedef struct s_dict	t_dict;

// FALSE 0, TRUE 1
enum e_bool
{
	FALSE,
	TRUE
};

// SUCCESS 0, ERROR 1
enum e_exit
{
	SUCCESS,
	ERROR
};

struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
};

struct s_data
{
	t_dict	*head;
	int		map_fd;
};

// parsing functions
t_exit	parsing(t_data *data, char **argv, int argc);
t_exit	get_map_info(t_data *data);

// dict functions
t_dict	*create_new_dict(void);
t_exit	add_dict(t_dict *head, char *key_in, char *value_in);
char	*get_value(t_dict *head, char *key);
void	clear_dict(t_dict *head);

// error functions
void	print_error_message(void);
void	print_file_error_message(char *file);
void	print_args_error_message(int argc);
void	print_file_format_error(void);

// utils functions
void	ft_putstr_color_fd(char *str, char *color, int fd, int newline);
t_bool	ft_strrcmp(char *s1, char *s2, int n);
int		len_split(char **split);
int		len_dict(t_dict *dict);
char	*strdup_no_nl(const char *str);

#endif
