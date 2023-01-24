/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:08:43 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/03 09:35:28 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	check_data(t_data *data)
{
	if (data->n_philo < 1)
	{
		printf("Error while trying to read the number of philosophers\n");
		return (0);
	}
	if (data->time_to_die < 1)
		return (printf("Error while trying to read the time to die\n"), 0);
	if (data->time_to_eat < 1)
		return (printf("Error while trying to read the time to eat\n"), 0);
	if (data->time_to_sleep < 1)
		return (printf("Error while trying to read the time to sleep\n"), 0);
	if (data->must_eat < 1)
		return (printf("Philosophers can't eat that much time\n"), 0);
	return (1);
}

static int	ft_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (str && (str[0] == '-' || str[0] == '+'))
	{
		if (str[0] == '-')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res != (res * 10 + (str[i] - '0') - (str[i] - '0')) / 10)
			return (-2);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (-3);
	return (res);
}

int	parsing(int argc, char **argv, t_data *data)
{
	if (argc == 5 || argc == 6)
	{
		data->status = 1;
		data->n_philo = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		data->must_eat = 1;
		if (argc == 6)
			data->must_eat = ft_atoi(argv[5]);
		if (check_data(data) != 1)
			return (0);
		if (argc != 6)
			data->must_eat = -1;
		return (1);
	}
	return (0);
}
