/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:16:59 by ewu               #+#    #+#             */
/*   Updated: 2024/12/13 15:51:39 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_valid(char **av)
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) >= MAX_CASE)
		ft_error("Number of philo is invalid.\n");
	if (ft_atoi(av[2]) <= 0)
		ft_error("Time to die is invalid.\n");
	if (ft_atoi(av[3]) <= 0)
		ft_error("Time to eat is invalid.\n");
	if (ft_atoi(av[4]) <= 0)
		ft_error("Time to sleep is invalid.\n");
	if (av[5])
	{
		if (ft_atoi(av[5]) <= 0)
			ft_error("Number of meals is invalid.\n");
	}
}

int	ft_atoi(char *s)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	i = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (sign * res);
}

void	ft_error(char *s)
{
	printf("%s", s);
	exit(EXIT_FAILURE);
}

void	ft_clean(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->dead_mtx);
	pthread_mutex_destroy(&data->print_mtx);
	pthread_mutex_destroy(&data->meal_mtx);
	while (i < data->philo->phi_nbr)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

// pthread_mutex_destroy(philo[i].l_fork);
// pthread_mutex_destroy(philo[i].r_fork);
// pthread_mutex_destroy(forks);
// free(philo->dead_flg);
// free(forks);
// free(dead_mtx); // or add another var: dead
// free(philo);