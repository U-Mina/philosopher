/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:45:37 by ewu               #+#    #+#             */
/*   Updated: 2024/12/13 15:49:52 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(t_philo *philo, char **av)
{
	philo->phi_nbr = ft_atoi(av[1]);
	philo->time_die = ft_atoi(av[2]);
	philo->time_eat = ft_atoi(av[3]);
	philo->time_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->min_meal = ft_atoi(av[5]);
	else
		philo->min_meal = -1;
}

void	data_init(t_philo *philo, t_data *data, pthread_mutex_t *forks,
		char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].phi_id = i + 1;
		philo[i].eating = 0;
		philo[i].meal_nbr = 0;
		parsing(&philo[i], av);
		philo[i].start_time = ft_gettime();
		philo[i].last_meal_time = ft_gettime();
		philo[i].print_mtx = &data->print_mtx;
		philo[i].meal_mtx = &data->meal_mtx;
		philo[i].dead_mtx = &data->dead_mtx;
		philo[i].dead_flg = &data->dead_flg;
		philo[i].l_fork = &forks[i];
		if (i == 0)
			philo[i].r_fork = &forks[philo[i].phi_nbr - 1];
		else
			philo[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	para_init(pthread_mutex_t *forks, int phi_nbr)
{
	int	i;

	i = 0;
	while (i < phi_nbr)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	lock_init(t_philo *philo, t_data *data)
{
	data->dead_flg = 0;
	data->philo = philo;
	pthread_mutex_init(&data->dead_mtx, NULL);
	pthread_mutex_init(&data->meal_mtx, NULL);
	pthread_mutex_init(&data->print_mtx, NULL);
}

// void ft_forks(int phi_nbr, pthread_mutex_t *forks)
// {
// 	int i;

// 	i = 0;
// 	while (i < phi_nbr)
// 	{
// 		pthread_mutex_init(&forks[i], NULL);
// 		i++;
// 	}
// }

/**
 * @para: num of philo; time_to_die; time_to_eat; time_to_sleep;
 * [num of philo must eat]
 */
// void	parsing(t_philo *philo, char **av)
// {
// }

// void data_init(t_philo *philo, char **av)
// {
// 	int *dead_flg;

// 	dead_flg = malloc(sizeof(int));
// 	*dead_flg = 0;
// 	pthread_mutex_init(&data->dead_mtx, NULL);
// 	pthread_mutex_init(&data->print_mtx, NULL);
// 	pthread_mutex_init(&data->meal_mtx, NULL);
// }