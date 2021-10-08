#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_data
{
	int philos_amount;
	int	dying_time;
	int	eating_time;
	int	sleeping_time;
	int	minimum_eats;
	int	philo_dead;
	int	enough_forks;
	uint64_t	start;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	uint64_t		last_ate;
	int				fork;
	int				num;
	struct timeval	current_time;
	struct s_philo	*previous;
	struct s_philo	*next;
}	t_philo;

pthread_mutex_t	lock;

void	*routine(void *arg);
t_philo	*philos_init(t_data *data);

int		ft_atoi(const char *num);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
t_philo	**lst_philo_add_back(t_philo **list, t_philo *new);
t_philo	*lst_philo_last(t_philo *last);
t_philo	*lst_philo_new(t_data *data, int i);

#endif