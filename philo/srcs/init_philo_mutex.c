/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:20:31 by smayrand          #+#    #+#             */
/*   Updated: 2022/12/06 11:03:27 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*ft_mutex_init(t_args *data)
{
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	if (!mutex)
		return (NULL);
	while (i < data->philo_nb)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
		{
			free(mutex);
			return (NULL);
		}
		i++;
	}
	if (pthread_mutex_init(&data->starving, NULL) != 0)
	{
		free(mutex);
		return (NULL);
	}
	return (mutex);
}

t_philo	*ft_philo_init(t_args *data)
{
	t_philo			*philo;
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	mutex = ft_mutex_init(data);
	if (!mutex)
		return (NULL);
	philo = malloc(sizeof(t_philo) * data->philo_nb + 1);
	if (!philo)
	{
		free(mutex);
		return (NULL);
	}
	while (i < data->philo_nb)
	{
		philo[i].philo_name = i + 1;
		philo[i].data = data;
		philo[i].ate = 0;
		philo[i].last_meal = 0;
		philo[i].mutex = mutex;
		i++;
	}
	return (philo);
}
