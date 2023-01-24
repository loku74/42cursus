/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:06:47 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/14 18:04:44 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	philo_take_fork(t_philo *philo)
{
	return (!print("has taken a fork", philo));
}

static int	philo_think(t_philo *philo)
{
	return (!print("is thinking", philo));
}

static int	philo_eat(t_philo *philo)
{
	int	status;

	status = print("is eating", philo);
	if (status)
		ft_usleep(philo->data->time_to_eat);
	return (!status);
}

static int	philo_sleep(t_philo *philo)
{
	int	status;

	status = print("is sleeping", philo);
	if (status)
		ft_usleep(philo->data->time_to_sleep);
	return (!status);
}

void	routine(t_philo *philo)
{
	while ((philo->eat_count != philo->data->must_eat \
	|| philo->data->must_eat == -1) && philo->status)
	{
		if (philo_think(philo))
			break ;
		if (philo->philo % 2 == 0)
			usleep(philo->data->n_philo * 100);
		pthread_mutex_lock(&philo->fork);
		if (philo_take_fork(philo))
			break ;
		if (philo->data->n_philo > 1)
			pthread_mutex_lock(&philo->data->philos[(philo->philo + 1) \
			% philo->data->n_philo].fork);
		else
			break ;
		if (philo_take_fork(philo))
			break ;
		if (philo_eat(philo))
			break ;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->data->philos[(philo->philo + 1) \
		% philo->data->n_philo].fork);
		if (philo_sleep(philo))
			break ;
	}
}
