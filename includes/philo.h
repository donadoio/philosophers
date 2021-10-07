#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_data
{
	int philos_amount;
	int	dying_time;
	int	eating_time;
	int	sleeping_time;
	int	minimum_eats;
	uint64_t	start;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	uint64_t		last_ate;
	int				fork;
	char			*name;
	struct s_philo	*previous;
	struct s_philo	*next;
}	t_philo;


void	*routine(void *arg);
int		make_philos(t_data *data, t_philo *philo_data);
int		ft_atoi(const char *num);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);

#endif