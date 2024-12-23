/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:24:08 by ewu               #+#    #+#             */
/*   Updated: 2024/12/13 15:57:31 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		ft_error("gettimeofday fail");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(size_t tm)
{
	size_t	start;

	start = ft_gettime();
	while ((ft_gettime() - start) < tm)
	{
		usleep(500);
	}
	return (0);
}
