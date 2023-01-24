/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:06:29 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/10 14:30:07 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init(t_data *data, t_philo **philo)
{
	data->threads = NULL;
	(*philo) = NULL;
}

static void	init_mutex(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->print, NULL);
	while (i < data->n_philo)
	{
		pthread_mutex_init(&philo[i].fork, NULL);
		i++;
	}
}

int	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	philo = (t_philo *) malloc(sizeof(t_philo) * data->n_philo);
	if (philo == NULL)
		return (1);
	data->philos = philo;
	data->threads = (pthread_t *) malloc(sizeof(pthread_t) * data->n_philo);
	if (data->threads == NULL)
		return (free(philo), 2);
	i = 0;
	init_mutex(philo, data);
	get_time();
	while (i < data->n_philo)
	{
		philo[i].philo = i;
		philo[i].last_eat = 0;
		philo[i].eat_count = 0;
		philo[i].status = 1;
		philo[i].data = data;
		if (pthread_create(&data->threads[i], NULL, \
		(void *) routine, &philo[i]) != 0)
			return (free(philo), free(data->threads), 3);
		i++;
	}
	return (0);
}
