/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:09:45 by ewu               #+#    #+#             */
/*   Updated: 2024/12/13 16:15:07 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_CASE 250

/**
 * take: num of philo; time_to_die; time_to_eat; time_to_sleep;
 * [num of philo must eat]
 * id_phi is the number id, start from (index+1)
 * id_phi == nbr_phi
 */
typedef struct s_philo
{
	pthread_t		thread;
	int				phi_id;
	int				eating;
	int				meal_nbr;
	int				min_meal;
	int				phi_nbr;
	int				*dead_flg;
	size_t			last_meal_time;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			start_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*dead_mtx;
	pthread_mutex_t	*meal_mtx;
	pthread_mutex_t	*print_mtx;
}					t_philo;

typedef struct s_data
{
	int				dead_flg;
	t_philo			*philo;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	dead_mtx;
}					t_data;

// int
void				para_init(pthread_mutex_t *forks, int phi_nbr);
void				data_init(t_philo *philo, t_data *data,
						pthread_mutex_t *forks, char **av);
void				lock_init(t_philo *philo, t_data *data);
void				parsing(t_philo *philo, char **av);

// create utils
void				*ft_thread_behav(void *val);
int					ft_create_thread(t_data *data, pthread_mutex_t *forks);

// monitor
void				*ft_monitor(void *val);
int					check_all_died(t_philo *philo);
int					reach_min_meal(t_philo *philo);
int					ft_dead(t_philo *philo);
int					ft_finish(t_philo *philo);

// behaviour
void				ft_print_behav(int phi_id, char *s, t_philo *philo);
void				ft_one_eat(t_philo *philo);
void				ft_eat(t_philo *philo);
void				ft_think(t_philo *philo);
void				ft_sleep(t_philo *philo);

// io and exit
int					ft_check_digit(char **av);
void				check_valid(char **av);
int					ft_atoi(char *s);
void				ft_error(char *s);
void				ft_clean(t_data *data, pthread_mutex_t *forks);

// philo.c (main)

// time
size_t				ft_gettime(void);
int					ft_usleep(size_t tm);

#endif

// data int and main
// safe create
// void					mtx_action(pthread_mutex_t *mtx, int ACTION);
// monitor
// safe malloc
// void					*malloc_safe(size_t size);
// setter and getter (to fit 25 lines)
// void					set_bool(pthread_mutex_t *mtx, bool *dst, bool flag);
// bool					get_bool(pthread_mutex_t *mtx, bool *flag);
// input and exit
// void				ft_check_syn(t_data *data);
// time
// philo utils
// void					ft_preparation(t_data *data);
// void					*ft_one_philo(t_philo *philo);
// void					*ft_dining(void *val);
// bool					ft_dead(t_philo *philo);