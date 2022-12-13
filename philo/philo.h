/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:54:07 by smayrand          #+#    #+#             */
/*   Updated: 2022/12/13 13:42:58 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/time.h>

enum {
	TRUE = 1,
	FALSE = 0,
	INF = 2147483647
};

typedef struct s_args {
	int				death_t;
	int				eat_t;
	int				sleep_t;
	int				philo_nb;
	int				cycles_nb;
	int				death_flag;
	int				error_flag;
	int				victim;
	int				i;
	long int		time;
	pthread_t		*fork_nb;
	pthread_mutex_t	starving;
}		t_args;

typedef struct s_philo
{
	int				ate;
	int				philo_name;
	long int		last_meal;
	pthread_mutex_t	*mutex;
	t_args			*data;
}					t_philo;

int				ft_one(t_args *data);
int				ft_atoi(char *s);
void			ft_isnum(char **argv, t_args *data);
void			ft_error(char *msg, t_args *data);
void			ft_input_error_check(t_args *data);
long int		ft_get_time(void);
long int		ft_get_ms(t_philo *philo);
pthread_mutex_t	*ft_mutex_init(t_args *data);
t_philo			*ft_philo_init(t_args *data);
int				ft_starvation(t_philo *philo, t_args *data);
int				ft_death_watcher(t_args *data, t_philo *philo);
void			ft_fork_grab(t_philo *philo, int f);
void			ft_fork_drop(t_philo *philo, int f1, int f2);
int				ft_single(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo, long int stopper);
int				ft_cycle_start(t_philo *philo, t_args *data);
void			*ft_eating(void *placeholder);

#endif