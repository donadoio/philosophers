/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:38:40 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/21 21:38:40 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	parse_data(int argc, char **argv, t_data *data)
{
	data->philos_amount = ft_atoi(argv[1]);
	data->time_to_die = (uint64_t)(ft_atoi(argv[2]));
	data->eating_time = (uint64_t)(ft_atoi(argv[3]));
	data->sleeping_time = (uint64_t)(ft_atoi(argv[4]));
	if (argc == 6)
		data->times_all_eat = (ft_atoi(argv[5]));
	return ;
}
