#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_info
{
	unsigned long	t_start;
	pthread_mutex_t	print;
	int				death_occurred;
	int				max_eats;
	int				num_philo;
}				t_info;

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	int				last_meal;
	int				max_eat;
	int				is_dead;
	unsigned long	t_start;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print;
	t_info			*info;
}			t_philo;

/*		MAIN		*/
void			pick_forks(t_philo *philo);
void			eat_start(t_philo *philo);
void			*thread_function(void *arg);

/*		INIT		*/
t_philo			*init_philos(int ac, char **av);
t_philo			*init_forks(t_philo *philo, int num_plilo, int i);
int				init_threads(t_philo *philo, int num_philo, int i);
int				args_valid(int ac, char **av);

/*		UTILS		*/
long			ft_atol(char *str);
void			philo_checker(t_philo *philo, int num_philo);
unsigned long	get_time(unsigned long t_start);
int				check_nbr_eats(t_philo *philo);
int				should_philo_die(t_philo *philo);

/*		UTILS 2		*/
void			philo_print(t_philo *philo, const char *str);

#endif