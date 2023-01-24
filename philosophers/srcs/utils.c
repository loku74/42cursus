/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:18:37 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/17 11:22:24 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static long long	get_timestamp(void)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	return ((timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000));
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 && s2) || (!s2 && s1))
		return (-1);
	while (i < n - 1 && (s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	if (n && n != i)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

long long	get_time(void)
{
	static long long	start = 0;

	if (!start)
		start = get_timestamp();
	return (get_timestamp() - start);
}

void	ft_usleep(long long time)
{
	long long	until;

	until = get_timestamp() + time;
	while (get_timestamp() < until)
		usleep(100);
}

int	print(char *str, t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->data->print);
	status = philo->data->status;
	philo->status = status;
	if (ft_strncmp(str, "is eating", 9) == 0)
	{
		philo->last_eat = get_time();
		philo->eat_count++;
	}
	if (status)
		printf("%lld %d %s\n", get_time(), philo->philo + 1, str);
	pthread_mutex_unlock(&philo->data->print);
	return (status);
}
