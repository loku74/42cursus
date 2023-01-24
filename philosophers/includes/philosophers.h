/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:10:27 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/17 11:21:55 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data
{
	int				n_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				must_eat;
	pthread_mutex_t	print;
	int				status;
	pthread_t		*threads;
	t_philo			*philos;
};

struct s_philo
{
	int				philo;
	long long		last_eat;
	int				eat_count;
	int				status;
	t_data			*data;
	pthread_mutex_t	fork;
};
// init function(s)
void		init(t_data *data, t_philo **philo);
int			init_philo(t_philo *philo, t_data *data);

// parsing function(s)
int			parsing(int argc, char **argv, t_data *data);

// routine function(s)
void		routine(t_philo *philo);

// utils function(s)
long long	get_time(void);
void		ft_usleep(long long time);
int			print(char *str, t_philo *philo);

#endif