/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:46:08 by ewu               #+#    #+#             */
/*   Updated: 2024/12/23 15:05:05 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo			philo[MAX_CASE];
	t_data			data;
	pthread_mutex_t	forks[MAX_CASE];

	if (ac != 5 && ac != 6)
		ft_error("Invalid number of parameter.\n");
	if (ft_check_digit(av))
		ft_error("Input should be positive digits.\n");
	check_valid(av);
	lock_init(philo, &data);
	para_init(forks, ft_atoi(av[1]));
	data_init(philo, &data, forks, av);
	ft_create_thread(&data, forks);
	ft_clean(&data, forks);
	return (0);
}
