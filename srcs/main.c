#include <philo.h>

pthread_mutex_t	lock;

void	data_init(char **argv, int argc, t_data *data)
{
	data->philos_amount = ft_atoi(argv[1]);
	data->dying_time = ft_atoi(argv[2]);
	data->eating_time = ft_atoi(argv[3]);
	data->sleeping_time = ft_atoi(argv[4]);
	if (argc == 5)
		data->minimum_eats = -1;
	else
		data->minimum_eats = ft_atoi(argv[5]);
	return ;
}

int	threads_init(t_data *data)
{
	pthread_t	philos[data->philos_amount];
	t_philo		philo_data[data->philos_amount];
	int			i;

	make_philos(data, (t_philo *)philo_data);
	i = 0;
	while (i < data->philos_amount)
	{
		pthread_create(&philos[i], NULL, &routine, &philo_data[i]);
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
	t_data	data;

	if (argc_check(argc) == 0 || format_check(argv) == 0 )
		return (1);
	data_init(argv, argc, &data);
	threads_init(&data);
	pthread_mutex_init(&lock, NULL);
	pthread_mutex_destroy(&lock);
	while(1){};
	return (0);
}