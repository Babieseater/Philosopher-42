/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:42:16 by smayrand          #+#    #+#             */
/*   Updated: 2022/12/06 15:21:17 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_fork_grab(t_philo *philo, int f)
{
	pthread_mutex_lock(&philo->mutex[f]);
	printf("%lu %d has taken a fork.\n", ft_get_ms(philo), philo->philo_name);
}

void	ft_fork_drop(t_philo *philo, int f1, int f2)
{
	pthread_mutex_unlock(&philo->mutex[f1]);
	pthread_mutex_unlock(&philo->mutex[f2]);
}

int	ft_starvation(t_philo *philo, t_args *input)
{
	if (input->death_flag == TRUE)
		return (TRUE);
	pthread_mutex_lock(&input->starving);
	if (ft_get_time() - philo->last_meal > input->death_t
		&& input->death_flag == 0)
	{
		input->victim = philo->philo_name;
		input->death_flag = TRUE;
		return (TRUE);
	}
	pthread_mutex_unlock(&input->starving);
	return (FALSE);
}

// test required
void	ft_eat(t_philo *philo)
{
	ft_fork_grab(philo, philo->philo_name - 1);
	if (philo->data->philo_nb == 1)
	{
		philo->data->death_flag = 1;
		return ;
	}
	ft_fork_grab(philo, philo->philo_name % philo->data->philo_nb);
	philo->last_meal = ft_get_time();
	printf("%lu %d is eating.\n", ft_get_ms(philo), philo->philo_name);
	ft_sleep(philo, philo->data->eat_t + philo->last_meal);
	ft_fork_drop(philo, philo->philo_name - 1,
		philo->philo_name % philo->data->philo_nb);
}
