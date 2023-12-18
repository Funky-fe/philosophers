/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:16:09 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/12/18 14:32:25 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stats
{
	int						philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						meals;
	int						number_philos_ate;
	int						stop;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead_mutex;
	pthread_mutex_t			time_eat_mutex;
	pthread_mutex_t			finish_mutex;
}							t_stats;

typedef struct s_philo
{
	int						id;
	int						finish;
	long int				ms_eat;
	unsigned int			nb_philo_ate;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	t_stats					*pa;
}							t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_stats					s;
}							t_p;

/*		ARGS		*/
int		arg_checker(int argc, char **argv, t_p *p);
void	arg_error();

/*		CHECK		*/
void	stop(t_p *p);
int		check_death(t_philo *ph, int i);

/*		INIT		*/
void	init_mutex(t_p *p);
int		init(t_p *p);

/*		SIMULATION		*/
void	print_action(char *str, t_philo *ph);
void	sleep_think(t_philo *ph);
void	simu(t_philo *ph);

/*		THREADS		*/
void	*is_dead(void	*data);
void	*thread(void *data);
int		threading(t_p *p);

/*		UTILS		*/
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		is_number(char **argv, int i, int j);
long	int	actual_time(void);
void	ft_usleep(long int time_in_ms);

#endif