/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:06:29 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/16 16:27:39 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	free_all(t_data *data)
{
	if (data->philos != NULL)
		free(data->philos);
	if (data->threads != NULL)
		free(data->threads);
}

static void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->print);
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->philos[i].fork);
		i++;
	}
}

static void	wait_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
	destroy_all(data);
}

static int	check_death_or_end(t_philo *philo)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < philo->data->n_philo)
	{
		if (philo[i].eat_count == philo->data->must_eat)
			k++;
		if (philo[i].last_eat + philo->data->time_to_die < get_time() \
		|| k == philo->data->n_philo)
		{
			if (k != philo->data->n_philo)
				printf("%lld %d died\n", get_time(), philo[i].philo + 1);
			philo->data->status = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_data		data;
	int			status;

	if (parsing(argc, argv, &data) == 0)
	{
		printf("Error: launch the program like the example below\n");
		printf("./philo number_of_philosophers time_to_die time_to_" \
			"eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	init(&data, &philo);
	status = data.status;
	if (init_philo(philo, &data))
		return (2);
	while (status)
	{
		pthread_mutex_lock(&data.print);
		status = check_death_or_end(data.philos);
		pthread_mutex_unlock(&data.print);
		usleep(100);
	}
	wait_all(&data);
	free_all(&data);
	return (0);
}
