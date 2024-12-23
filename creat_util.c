/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:18:13 by ewu               #+#    #+#             */
/*   Updated: 2024/12/13 16:13:44 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_thread(t_data *data, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, &ft_monitor, data->philo) != 0)
		ft_clean(data, forks);
	i = 0;
	while (i < data->philo[0].phi_nbr)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &ft_thread_behav,
				&data->philo[i]) != 0)
			ft_clean(data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitor, NULL) != 0)
		ft_clean(data, forks);
	while (i < data->philo[0].phi_nbr)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			ft_clean(data, forks);
		i++;
	}
	return (0);
}

void	*ft_thread_behav(void *val)
{
	t_philo	*philo;

	philo = (t_philo *)val;
	if (philo->phi_id % 2 == 0)
		ft_usleep(1);
	while (!ft_finish(philo))
	{
		if (philo->phi_nbr == 1)
			ft_one_eat(philo);
		else
			ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (val);
}
// while (ft_dead(philo) != 1)
// 	;
// if (philo->phi_nbr == 1 && ft_dead(philo) != 1)
// {
// 	pthread_mutex_lock(philo->l_fork);
// 	ft_print_behav("takes a fork", philo, 0);
// 	// while (ft_dead(philo) != 1)
// 	// {
// 	// }
// 	ft_usleep(philo, philo->time_die);
// 	pthread_mutex_unlock(philo->l_fork);
// }

// int ft_dead(t_philo *philo)
// {
// 	if (philo->meal_nbr == philo->min_meal)
// 		return (1);
// 	pthread_mutex_lock(philo->dead_mtx);
// 	if (*philo->dead_flg == 1)
// 	{
// 		pthread_mutex_unlock(philo->dead_mtx);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(philo->dead_mtx);
// 	if (ft_gettime() - philo->last_meal_time >= philo->time_die)
// 	{
// 		ft_print_behav("died", philo, 1);
// 		return (1); // or return 1 as dead
// 	}
// 	return (0);
// // }
// void *malloc_safe(size_t size)
// {
// 	void *res;

// 	res = malloc(size);
// 	if (res == NULL)
// 		ft_error("Malloc failed.\n");
// 	return (res);
// }
