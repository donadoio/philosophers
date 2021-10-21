/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:39:02 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/21 21:39:15 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_data	*data;
	uint64_t		last_ate;
	pthread_mutex_t	is_eating;
	int				left_fork;
	int				right_fork;
	int				philo_number;
	int				meals_eaten;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	register_ability;
	int				philos_amount;
	int				times_all_eat;
	uint64_t		sleeping_time;
	uint64_t		eating_time;
	uint64_t		time_to_die;
	uint64_t		start;
	int				stop;
}	t_data;

t_data		data_init(void);
void		parse_data(int argc, char **argv, t_data *data);
int			program_init(t_data *data);
int			routine_init(t_data *data);
void		take_action(t_philo *philo, int action);
void		grab_forks(t_philo *philo);
void		start_eating(t_philo *philo);
void		sleep_and_start_thinking(t_philo *philo);

uint64_t	ft_time(void);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		error(char *str);
int			ft_atoi(const char *num);
int			ft_strlen(char *str);
int			ft_str_isnum(char *str);

#endif