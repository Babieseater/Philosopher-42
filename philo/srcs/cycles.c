/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:18:05 by smayrand          #+#    #+#             */
/*   Updated: 2022/12/06 15:28:34 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_sleep(t_philo *philo, long int stopper)
{
	long int	stop;

	while (1)
	{
		stop = stopper - ft_get_time();
		if (stop <= 0)
			break ;
		usleep(50);
		if (ft_starvation(philo, philo->data) == TRUE)
			return ;
		usleep(50);
	}
}

void	*ft_eating(void *placeholder)
{
	t_philo	*philo;

	philo = placeholder;
	if (philo->philo_name % 2 == 0)
		usleep(philo->data->death_t * 100);
		philo->last_meal = philo->data->time;
	while (1)
	{
		if (philo->ate == philo->data->cycles_nb)
			break ;
		ft_eat(philo);
		printf("%lu %d is sleeping.\n", ft_get_ms(philo), philo->philo_name);
		ft_sleep(philo,
			philo->data->sleep_t + philo->data->eat_t + philo->last_meal);
		printf("%lu %d is thinking.\n", ft_get_ms(philo), philo->philo_name);
		ft_sleep(philo, ((philo->last_meal + philo->data->death_t) / 100) * 90);
		philo->ate = philo->ate + 1;
		if (ft_starvation(philo, philo->data) == TRUE)
			return (0);
	}
	return (0);
}

int	ft_cycle_start(t_philo *philo, t_args *data)
{
	int	i;

	i = 0;
	data->fork_nb = malloc(sizeof(pthread_t) * data->philo_nb);
	if (!data->fork_nb)
		return (TRUE);
	while (i < data->philo_nb)
	{
		if (pthread_create(&data->fork_nb[i], NULL,
				&ft_eating, &philo[i]) != FALSE)
			return (TRUE);
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_join(data->fork_nb[i], NULL) != 0)
			return (1);
		i++;
	}
	if (data->death_flag == TRUE)
		printf("%lu %d died.\n",
			ft_get_time() - data->time, data->victim);
	return (FALSE);
}
