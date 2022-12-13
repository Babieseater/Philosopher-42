/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:28:55 by smayrand          #+#    #+#             */
/*   Updated: 2022/12/13 14:48:17 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_dispatch(t_args *data, char **argv)
{
	data->philo_nb = ft_atoi(argv[1]);
	data->death_t = ft_atoi(argv[2]);
	data->eat_t = ft_atoi(argv[3]);
	data->sleep_t = ft_atoi(argv[4]);
	if (argv[5])
		data->cycles_nb = ft_atoi(argv[5]);
	else
		data->cycles_nb = -1;
	ft_input_error_check(data);
	data->death_flag = 0;
	data->time = ft_get_time();
}

int	main(int argc, char **argv)
{
	t_args	data;
	t_philo	*philo;

	philo = NULL;
	if ((argc < 5 || argc > 6) && data.error_flag != 1)
		ft_error("Wrong amount of argument", &data);
	if (data.error_flag != 1)
	{
		ft_isnum(argv, &data);
		ft_dispatch(&data, argv);
	}
	if ((data.philo_nb == 1 || data.death_t == 0) && data.error_flag != 1)
		ft_one(&data);
	else if (data.error_flag != 1)
	{
		philo = ft_philo_init(&data);
		if (!philo)
			return (TRUE);
		ft_cycle_start(philo, &data);
		if (data.fork_nb != 0)
			free (data.fork_nb);
		free(philo->mutex);
		free(philo);
	}
	return (0);
}
