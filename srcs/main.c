#include <philo.h>

t_data	*data_init(char **argv, int argc)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->philos_amount = ft_atoi(argv[1]);
	data->dying_time = ft_atoi(argv[2]);
	data->eating_time = ft_atoi(argv[3]);
	data->sleeping_time = ft_atoi(argv[4]);
	data->philo_dead = 0;
	if (data->philos_amount > 1)
		data->enough_forks = 1;
	else
		data->enough_forks = 0;
	if (argc == 5)
		data->minimum_eats = -1;
	else
		data->minimum_eats = ft_atoi(argv[5]);
	return (data);
}

int	threads_init(t_data *data)
{
	pthread_t	philos[data->philos_amount];
	t_philo		*philo;
	int			i;
	struct timeval current_time;

	philo = NULL;
	philo = philos_init(data);
	i = 0;
	while (i < data->philos_amount)
	{
		pthread_create(&philos[i], NULL, &routine, philo);
		gettimeofday(&current_time, NULL);
		philo->last_ate = current_time.tv_usec;
		philo = philo->next;
		i++;
	}
	return (0);
}

int	format_check(char	**argv)
{
	(void)argv;
	return (1);
}

int	argc_check(int argc)
{
	if (argc == 5)
		return (1);
	else if (argc == 6)
		return (1);
	return (0);
}


int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc_check(argc) == 0 || format_check(argv) == 0 )
		return (1);
	data = NULL;
	data = data_init(argv, argc);
	threads_init(data);
	pthread_mutex_init(&lock, NULL);
	while(data->philo_dead == 0)
		usleep(5);
	pthread_mutex_destroy(&lock);
	return (0);
}