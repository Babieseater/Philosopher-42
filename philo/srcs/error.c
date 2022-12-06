/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:02:58 by smayrand          #+#    #+#             */
/*   Updated: 2022/12/06 17:21:25 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_isnum(char **argv, t_args *data)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				ft_error("Arguments not numerical\n", data);
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	ft_error(char *msg, t_args *data)
{
	printf("Error\n%s", msg);
	data->error_flag = 1;
}

int	ft_valid_value(int value)
{
	if (value < 0 || value > 2147483647)
		return (FALSE);
	return (TRUE);
}

void	ft_input_error_check(t_args *data)
{
	if (data->error_flag != 1)
	{
		if (data->philo_nb < 1 || data->philo_nb > 200)
			ft_error("Nb of Philosophers is not valid", data);
		else if (data->cycles_nb == 0)
			ft_error("You need at least one cycle to start", data);
		else if (ft_valid_value(data->eat_t) == FALSE
			|| ft_valid_value(data->sleep_t) == FALSE
			|| ft_valid_value(data->death_t) == FALSE)
			ft_error("Invalid Argument", data);
	}
}
